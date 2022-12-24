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

        ~Socket();

    public:
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

        /** @brief The recvfrom() system calls receiv datagrams on a datagram socket
         * @return Returns 0 on success, or –1 on error */
        ssize_t _recvfrom(int, void *, size_t);

        /** @brief The sendto() system calls send datagrams on a datagram socket
         * @return Returns 0 on success, or –1 on error */
        ssize_t _sendto(int, const void *, size_t) const;

        /** @brief The recvfrom() system calls receiv datagrams on a datagram socket
         * @return Returns 0 on success, or –1 on error */
        ssize_t _recv(int, void *, size_t);

        /** @brief The sendto() system calls send datagrams on a datagram socket
         * @return Returns 0 on success, or –1 on error */
        ssize_t _send(int, const void *, size_t) const;

        static Socket *create_socket(int , int , int);

        std::string get_IP();
        int get_Port();

        int _write(int, const void *, size_t) const;

        int _read(int, void *, size_t);

        int get_master_sfd(){ return master_sfd;}

        int get_active_sfd(){ return active_sfd;}
    }; /*end of class Socket*/

};
#endif // PMVANKERSOCKET_H
