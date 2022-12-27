#ifndef PMVANKERSOCKET_H
#define PMVANKERSOCKET_H

#include "Headers.hpp"
namespace pmvankerSocket
{

#define SOCKET_PORT_NUMBER 4000
#define SOCKET_BACKLOG 10
#define BUFFER_SIZE 1024

    enum
    {
        error = -1,
        success = 0,
    };

    class PMVANKERSOCKET_EXPORT Socket : virtual public std::exception
    {
        /** @brief Communication Socket Domains
         * AF_UNIX: UNIX within kernel on same host sockaddr_un address structure
         * AF_INET: IPv4 network sockaddr_in address structure
         * AF_INET6: IPv6 network sockaddr_in6 address structure*/
        uint8_t domain;
        /** @brief Socket Type
         * SOCK_STREAM: Stream socket that is Sequenced, reliable, connection-based byte streams
         * SOCK_DGRAM: Datagram socket Connectionless, unreliable datagrams of fixed maximum length*/
        uint8_t type;
        /** @brief Socket Protocol
         * IPPROTO_IP: * Dummy protocol for TCP.  */
        uint8_t protocol;
        /** @brief file descriptor obtained from a socket(). */
        u_int32_t port;
        /** @brief file descriptor obtained from a socket(). */
        int master_sfd;
        /** @brief file descriptor obtained from a socket(). */
        int active_sfd;
        /** @brief number of backlogs connection. */
        uint32_t backlog;

        /** @brief Structure specifying the address to which this socket is to be bound. */
        struct sockaddr_in server;
        socklen_t server_len;
        struct sockaddr_in client;
        socklen_t client_len;

        /* Implementation of Singleton Class */
        static Socket *socket_obj;

        Socket() {}                                // Default Constructor
        Socket(int _domain, int _type, int _port); // parameter constructor

        Socket(const Socket &) = delete;
        void operator=(const Socket &) = delete;

    public:
        ~Socket();
        
        /** @brief The socket() call creates a new socket.
         * @return a file descriptor used to refer to the newly created socket. */
        int _socket();

        /** @brief The bind() system call binds a socket to an address
         *  @return Returns 0 on success, or –1 on error */
        int _bind();

        /** @brief The listen() system call marks the stream socket as passive.
         * @return Returns 0 on success, or –1 on error */
        int _listen();

        /** @brief The accept() system call accepts an incoming connection.
         * @return Returns 0 on success, or –1 on error */
        int _accept();

        /** @brief The connect() system call connects the active socket.
         * @return Returns 0 on success, or –1 on error */
        int _connect();

        static Socket *create_socket(int , int , int);

        sockaddr_in get_serverAddr(){ return server; }
        sockaddr_in get_clientAddr(){ return client; }
        int         get_master_sfd(){ return master_sfd; }
        int         get_active_sfd(){ return active_sfd; }
        char*       GET_CLIENT_IP(){ return inet_ntoa(client.sin_addr); }
        int         GET_CLIENT_PORT(){ return ntohs(client.sin_port); }
        char*       GET_SERVER_IP() {return inet_ntoa(server.sin_addr); }
        int         GET_SERVER_PORT(){ return ntohs(server.sin_port); }

        void set_clientAddr(sockaddr_in _client){ client = _client;}
        void set_serverAddr(sockaddr_in _server){ server = _server;}
        int _write(int sfd, const void *data, size_t len) const{ return write(sfd, data, len); }
        int _read(int sfd, void *data, size_t len){ return read(sfd, data, len);}
        
        void close_active_sfd();
        void close_master_sfd();
    }; /*end of class Socket*/

};
#endif // PMVANKERSOCKET_H
