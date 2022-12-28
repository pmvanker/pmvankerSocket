#include "Server.hpp"
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    char buffer[BUFFER_SIZE];
    int sfd = 0;

    Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);
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
    
    sfd = TcpSocket->get_active_sfd();
    while (sfd)
    {
        bzero(buffer, BUFFER_SIZE);
        if (TcpSocket->_read(sfd, buffer, BUFFER_SIZE) <= 0)
        {
            std::cout << "Disconnected" << std::endl;
            sfd = 0;
        }
        std::cout << TcpSocket->GET_CLIENT_IP() << ":" << buffer << std::endl;
    }
    return EXIT_SUCCESS;
}