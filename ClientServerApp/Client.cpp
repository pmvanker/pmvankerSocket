#include "Client.hpp"
#include <cstring>
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    std::cout << "Client Start" << std::endl;
    Socket *TcpSocket = Socket::create_socket(AF_INET, SOCK_STREAM, PORT);
    TcpSocket->_connect();
    std::cout << "Connected to Server" << std::endl;

    char buffer[BUFFER_SIZE];
    while (1)
    {
        std::cout << "Send Message:" << std::endl;
        bzero(buffer, BUFFER_SIZE);
        std::cin.getline(buffer, BUFFER_SIZE);
        TcpSocket->_write(TcpSocket->get_master_sfd(), buffer, strlen(buffer));
    }

    return EXIT_SUCCESS;
}