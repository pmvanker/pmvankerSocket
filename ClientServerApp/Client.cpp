#include "Client.hpp"
using namespace pmvankerSocket;
#define PORT 4000
int main()
{
    std::cout << "Client Start" << std::endl;
    Socket *TcpSocket =  Socket::create_socket(AF_INET,SOCK_STREAM,PORT);
    
    if(TcpSocket->_socket() == success)
        std::cout << "Client Socket Created" << std::endl;
    if(TcpSocket->_connect() == success)
        std::cout << "Client Socket Connected" << std::endl;

    while(1)
	{
        std::string key_input;
        std::cout << "Send Message:" << std::endl;
        std::cin >> key_input;
        TcpSocket->write_master_sfd((void*)key_input.c_str(),key_input.size());
	}
    
    return EXIT_SUCCESS;
}