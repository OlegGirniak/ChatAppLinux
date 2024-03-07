#include "Server.h"

#define PORT (2222)
string LOCAL_IP_ADDRESS("127.0.0.1");

int main(int argc, char* argv[])
{
    sockaddr_in server_socket_info{};

    server_socket_info.sin_family = AF_INET;
    server_socket_info.sin_addr.s_addr = inet_addr(LOCAL_IP_ADDRESS.c_str());
    server_socket_info.sin_port = htons(PORT);

    int server_socket = create_socket();

    bind_socket(server_socket, &server_socket_info);

    listen_socket(server_socket);

    accept_new_client(server_socket);

}