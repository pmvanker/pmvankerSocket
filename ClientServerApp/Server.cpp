#include "Server.hpp"
#include <cstring>
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    std::cout << "Server Start" << std::endl;

    Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);
    TcpSocket->_bind();
    TcpSocket->_listen();
    std::cout << "Waiting for Client" << std::endl;
    TcpSocket->_accept();
    std::cout << "Connected" << std::endl;

    char buffer[BUFFER_SIZE];
    while (TcpSocket->get_active_sfd())
    {
        bzero(buffer, BUFFER_SIZE);
        if (TcpSocket->_read(TcpSocket->get_active_sfd(), buffer, BUFFER_SIZE) > 0)
        {
            if (TcpSocket->get_active_sfd())
                std::cout << "Message :" << buffer << std::endl;
        }
        else
        {
            std::cout << "Disconnected" << std::endl;
            TcpSocket->close_active_sfd();
        }
    }

    return EXIT_SUCCESS;
}