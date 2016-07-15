#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <pthread.h>

#include "Processing.h"

#define len_buffer_receive 200

typedef struct sockaddr_in server_struct;





int build_server(char* ip, int port);
void bind_socket(int socket, struct sockaddr_in server);
pthread_t* new_thread(pthread_t name_thread, int socket);
char* infinity_receive(int socket);
void send_to(int socket, char* msg);

// int standby_accept_connection(int* socket_desc);
// void send_message(int* socket, char* message);
void* test_thread(void* socket);
void fake_thread_client(int sock);
void* thread_serveur(void* sock);