#include "Client.h"

#define SERVER_PORT (2222)
string SERVER_IP("127.0.0.1");

int main()
{
    int client_socket = create_socket();

    sockaddr_in server_addr{};

    server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP.c_str());

    connect_to_server(client_socket, &server_addr);

    thread send_thread = thread(send_to_server, client_socket, &server_addr);

    thread recv_thread = thread(recv_from_server, client_socket, &server_addr);

    send_thread.join();

    recv_thread.join();

    return 0;
}