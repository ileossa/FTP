#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

typedef struct sockaddr_in server_struct;

int build_server();
void bind_socket(int socket, struct sockaddr_in server);
void infinity_receive(int socket);
void send_to(int socket, char* msg);
// int standby_accept_connection(int* socket_desc);
// void send_message(int* socket, char* message);