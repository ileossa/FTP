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

int* build_server( char* ip, int port);
int* standby_accept_connection(int* socket_desc);
void send_message(int* socket, char* message);