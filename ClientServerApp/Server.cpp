#include "Server.hpp"
#include<cstring>
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    std::cout << "Server Start" << std::endl;

    Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);
    if (TcpSocket->_socket() == success)
        std::cout << "Server Socket Created" << std::endl;
    if (TcpSocket->_bind() == success)
        std::cout << "Server Socket Binded" << std::endl;
    if (TcpSocket->_listen() == success)
        std::cout << "Server Socket listening" << std::endl;
    if (TcpSocket->_accept() == success)
        std::cout << "Server Socket accepted" << std::endl;

    std::cout << "New Connection Socket ip :" << TcpSocket->get_IP()
              << " Port: " << TcpSocket->get_Port() << std::endl;

    std::string data;
    char buffer[BUFFER_SIZE];
    while (1)
    {
        bzero(buffer,BUFFER_SIZE);
        TcpSocket->_read(TcpSocket->get_active_sfd(), buffer, BUFFER_SIZE);
        data.assign(buffer);
        std::cout << "Message :" << data << std::endl;
    }

    return EXIT_SUCCESS;
}