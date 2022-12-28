#include "Client.hpp"
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    char buffer[BUFFER_SIZE];
    int sfd = 0;

    Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);
    TcpSocket->_connect();

    sfd = TcpSocket->get_master_sfd();

    while (sfd)
    {
        bzero(buffer, BUFFER_SIZE);
        std::cout << "CLIENT :";
        std::cin.getline(buffer, BUFFER_SIZE);
        if (TcpSocket->_write(TcpSocket->get_master_sfd(), buffer, strlen(buffer)) < 0)
        {
            std::cout << "Disconnected" << std::endl;
            sfd = 0;
        }
    }

    return EXIT_SUCCESS;
}