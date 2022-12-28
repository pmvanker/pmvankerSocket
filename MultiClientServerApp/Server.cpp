#include "Server.hpp"
using namespace pmvankerSocket;
#define PORT 4000

Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);

void HandleChildProcess()
{
    char buffer[BUFFER_SIZE];

    int sfd = TcpSocket->get_active_sfd();
    
    if(sfd <= 0)
    {
        _exit(EXIT_FAILURE);
    }

    //set of socket descriptors 
    fd_set readfds;
    //clear the socket set 
    FD_ZERO(&readfds);  
    //add master socket to set 
    FD_SET(sfd, &readfds);  

    while( true )
    {
        auto activity = select(sfd + 1, &readfds, NULL, NULL, NULL);

        if(activity < 0)
        {
            _exit(EXIT_FAILURE);
        }

        if(FD_ISSET(sfd, &readfds))
        {
            bzero(buffer, BUFFER_SIZE);
            if (TcpSocket->_read(sfd, buffer, BUFFER_SIZE) <= 0)
            {
                TcpSocket->close_active_sfd();
                _exit(EXIT_FAILURE);
            }
            std::cout << TcpSocket->GET_CLIENT_IP() << ":" << buffer << std::endl;
        }
    }
}


int main()
{
    std::cout << "Server IP:PORT\t"
              << TcpSocket->GET_SERVER_IP() << ":"
              << TcpSocket->GET_SERVER_PORT() << std::endl;
    TcpSocket->_bind();
    TcpSocket->_listen();

    std::cout << "Waiting for Client" << std::endl;
    TcpSocket->_accept();
    std::cout << "Connected IP:PORT\t"
              << TcpSocket->GET_CLIENT_IP() << ":"
              << TcpSocket->GET_CLIENT_PORT() << std::endl;
    
    //set of socket descriptors 
    fd_set readfds;
    //clear the socket set 
    FD_ZERO(&readfds);  
    //add master socket to set 
    FD_SET(TcpSocket->get_master_sfd(), &readfds);  
    
    while(1)
    {
        auto activity = select(TcpSocket->get_master_sfd() + 1, &readfds, NULL, NULL, NULL);

        if(activity < 0)
        {
            std::cout << "select error" << std::endl;
            break;
        }

        if(FD_ISSET(TcpSocket->get_master_sfd(), &readfds))
        {
            TcpSocket->_accept();
            switch( fork() )
            {
                case -1:
                        std::cout << "Chind Creation Failed" << std::endl;
                        TcpSocket->close_active_sfd();
                        break;
                case 0:
                        TcpSocket->close_master_sfd();
                        HandleChildProcess();
                        _exit(EXIT_SUCCESS);

                default:
                        TcpSocket->close_active_sfd();
                        break;                
            }
        }
    }
    return EXIT_SUCCESS;
}