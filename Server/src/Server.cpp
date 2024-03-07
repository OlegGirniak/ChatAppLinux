#include "Server.h"

vector<thread> thread_pool;
mutex client_sockets_mutex;
vector<pair<int, sockaddr_in>> client_sockets;


int create_socket()
{
    int server_socket{};

    assert(!((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) && ("Couldn't create socket"));
    cout << "Server socket created +" << endl;
    
    return server_socket;
}

void bind_socket(int server_socket, sockaddr_in* server_socket_info)
{
    assert(!(bind(server_socket, (struct sockaddr*)server_socket_info, sizeof(sockaddr_in))) && "Couldn't bind socket");
    cout << "Server socket binded +" << endl;
}

void listen_socket(int server_socket)
{
    assert(!(listen(server_socket, 10)) && "Couldn't listen socket");
    cout << "Server socket listen + " << endl;
}

void socket_procces(int client_socket, sockaddr_in client_addr)
{
    char buffer[1024]{};
    int buffer_size = 1024;

    cout << "Client socket info: ip(" << client_addr.sin_family << "), port(" << client_addr.sin_port << ")" << endl;

    cout << "Current thread id: " << std::this_thread::get_id() << endl;

    while (true)
    {
        int bytes_received = recv(client_socket, buffer, buffer_size, 0);

        if (bytes_received > 0)
        {
            for (int i = 0; i < bytes_received; i++)
            {
                cout << buffer[i];
            }
            cout << endl;

            // send all clients
            for (auto& client : client_sockets)
            {
                if (client.first != client_socket)
                {
                    send(client.first, buffer, buffer_size, 0);
                }
            }

        }
        else
        {
            cout << "Client disconnected" << endl;
            break;
        }

        memset(buffer, 0, buffer_size);
    }

    close(client_socket);
    {
        lock_guard<mutex> lock(client_sockets_mutex);
        for (auto it = client_sockets.begin(); it != client_sockets.end(); ++it)
        {
            if (it->first == client_socket)
            {
                client_sockets.erase(it);
                break;
            }
        }
    }
}

void accept_new_client(int server_socket)
{
    struct sockaddr_in client_addr;
    socklen_t size_client_addr = sizeof(sockaddr_in);
    int client_socket;

    while (true)
    {
        assert((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &size_client_addr)) != -1);
        cout << "New socket connection | + |" << endl;

        {
            lock_guard<mutex> lock(client_sockets_mutex);
            client_sockets.push_back(make_pair(client_socket, client_addr));
        }

        thread_pool.push_back(move(thread(socket_procces, client_socket, client_addr)));

        cout << "count conn: " << client_sockets.size() << endl;
    }
}
