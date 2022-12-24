#include "Server.hpp"
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    std::cout << "Server Start" << std::endl;
    
    Socket *TcpSocket =  Socket::create_socket(AF_INET,SOCK_STREAM,PORT);
    if(TcpSocket->_socket()==success)
        std::cout << "Server Socket Created" << std::endl;
    if(TcpSocket->_bind()==success)
        std::cout << "Server Socket Binded" << std::endl;
    if(TcpSocket->_listen()==success)
        std::cout << "Server Socket listening" << std::endl;
    if(TcpSocket->_accept()==success)
        std::cout << "Server Socket accepted" << std::endl;
    
    std::cout << "New Connection Socket ip :" << TcpSocket->get_IP() 
              << " Port: " << TcpSocket->get_Port() << std::endl;

    char data[100];
    while (1)
    {
        TcpSocket->read_active_sfd(data,100);
        std::cout << "Message :"<< data << std::endl;
    }
    
    return EXIT_SUCCESS;
}