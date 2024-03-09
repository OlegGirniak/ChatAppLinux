#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <condition_variable>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::thread;
using std::mutex;
using std::vector;
using std::pair;
using std::move;
using std::getline;

int create_socket();

void connect_to_server(int client_socket, sockaddr_in* server_addr);

void send_to_server(int client_socket, sockaddr_in* server_addr);

void recv_from_server(int client_socket, sockaddr_in* server_addr);



