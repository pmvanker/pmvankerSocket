#include "Socket.hpp"
namespace pmvankerSocket
{
    Socket *Socket::socket_obj = nullptr;

    int Socket::_socket()
    {
        master_sfd = socket(domain, type, protocol);
        if (master_sfd < 0)
            return error;
        return success;
    }

    int Socket::_bind()
    {
        server.sin_family = domain;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        if ((bind(master_sfd, (sockaddr *)&server, sizeof(server))) < 0)
            return error;
        return success;
    }

    int Socket::_listen()
    {
        if ((listen(master_sfd, backlog)) < 0)
            return error;
        return success;
    }

    int Socket::_accept()
    {
        active_sfd = accept(master_sfd, (struct sockaddr *)&client, &client_len);
        if (active_sfd < 0)
            return error;
        return success;
    }

    int Socket::_connect()
    {
        server.sin_family = domain;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        if ((connect(master_sfd, (struct sockaddr *)&server, server_len)) < 0)
            return error;
        return success;
    }

    ssize_t Socket::_recvfrom(int sfd, void *data, size_t len)
    {
        if ((recvfrom(sfd, data, len, 0, (struct sockaddr *)&client, &client_len)) < 0)
        {
            data = nullptr;
            return error;
        }

        return success;
    }

    ssize_t Socket::_sendto(int sfd, const void *data, size_t len) const
    {
        if ((sendto(sfd, data, len, 0, (struct sockaddr *)&client, client_len)) < 0)
            return error;

        return success;
    }

    ssize_t Socket::_recv(int sfd, void *_data, size_t len)
    {
        if ((recv(sfd, &_data, len, 0)) < 0)
        {
            _data = nullptr;
            return error;
        }

        return success;
    }

    ssize_t Socket::_send(int sfd,const void *data, size_t len) const
    {
        if ((send(sfd, &data, len, 0)) < 0)
            return error;

        return success;
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
        try
        {
            _socket();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    Socket::~Socket()
    {
        if (master_sfd != 0)
            close(master_sfd);

        if (active_sfd != 0)
            close(active_sfd);

        delete socket_obj;
    } // Default Destructor

    Socket *Socket::create_socket(int _domain, int _type, int _port)
    {
        if (socket_obj == nullptr)
            socket_obj = new Socket(_domain, _type, _port);
        return socket_obj;
    }

    std::string Socket::get_IP()
    {
        std::string ip;
        ip.assign(inet_ntoa(client.sin_addr));
        return ip;
    }
    int Socket::get_Port()
    {
        return ntohs(client.sin_port);
    }

    int Socket::_write(int sfd, const void *data, size_t len) const
    {
        if ((write(sfd, data, len)) < 0)
            return error;
        return success;
    }

    int Socket::_read(int sfd, void *data, size_t len)
    {
        int ret = read(sfd, data, len);
        if (ret <= 0)
        {
            data = nullptr;
            close(active_sfd);
            active_sfd = 0;
            return error;
        }
        return success;
    }

};
