#include "Socket.hpp"
namespace pmvankerSocket
{
    Socket *Socket::socket_obj = nullptr;

    int Socket::_socket()
    {
        return master_sfd = socket(domain, type, protocol);
    }

    int Socket::_bind()
    {
        server.sin_family = domain;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        return bind(master_sfd, (sockaddr *)&server, sizeof(server));
    }

    int Socket::_listen()
    {
        return listen(master_sfd, backlog);
    }

    int Socket::_accept()
    {
        return active_sfd = accept(master_sfd, (struct sockaddr *)&client, &client_len);
    }

    int Socket::_connect()
    {
        server.sin_family = domain;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        return connect(master_sfd, (struct sockaddr *)&server, server_len);
    }

    Socket::Socket(int _domain, int _type, int _port) : domain(_domain),
                                                        type(_type),
                                                        protocol(IPPROTO_IP),
                                                        port(_port),
                                                        master_sfd(0),
                                                        active_sfd(0),
                                                        backlog(SOCKET_BACKLOG),
                                                        server_len(sizeof(server)),
                                                        client_len(sizeof(client))
    {
        _socket();
    }

    Socket::~Socket()
    {
        close_active_sfd();
        close_master_sfd();
        delete socket_obj;
    } // Default Destructor

    Socket *Socket::create_socket(int _domain, int _type, int _port)
    {
        if (socket_obj == nullptr)
            socket_obj = new Socket(_domain, _type, _port);
        return socket_obj;
    }

    void Socket::close_active_sfd()
    {
        if (active_sfd)
        {
            close(active_sfd);
            active_sfd = 0;
        }
    }

    void Socket::close_master_sfd()
    {
        if (master_sfd)
        {
            close(master_sfd);
            master_sfd = 0;
        }
    }

};
