#include "Client.h"

#define SIZE (1024)

int create_socket()
{
    int client_socket{};

    assert(!((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) && ("Couldn't create socket"));
	cout << "Client socket created + " << endl;

    return client_socket;

}

void connect_to_server(int client_socket, sockaddr_in* server_addr)
{
    assert(!(connect(client_socket, (sockaddr*)server_addr, sizeof(*server_addr))));
	cout << "Connect to server + " << endl;
}

void send_to_server(int client_socket, sockaddr_in *server_addr)
{
    string message;

    while (message != "Exit")
	{
		getline(cin, message);

		assert((send(client_socket, message.c_str(), message.size(), 0)) != -1);

		cout << "Messages is sent" << endl;
	}

    close(client_socket);

    exit(0);
}

void recv_from_server(int client_socket, sockaddr_in *server_addr)
{
    char buffer[SIZE]{};

	while (true)
	{
		int bytes_received = recv(client_socket, buffer, SIZE, 0);

		if (bytes_received > 0)
		{
			for (int i = 0; i < strlen(buffer); i++)
			{
				cout << buffer[i];
			}
			cout << endl;
		}

		memset(buffer, 0, SIZE);
	}
}
