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
using std::endl;
using std::string;
using std::thread;
using std::mutex;
using std::vector;
using std::pair;
using std::move;
using std::ref;
using std::lock_guard;
using std::lock;
using std::make_pair;



int create_socket();

void bind_socket(int server_socket, sockaddr_in* server_socket_info);

void listen_socket(int server_socket);

void socket_procces(int server_socket, sockaddr_in server_socket_info);

void accept_new_client(int server_socket);