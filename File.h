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

#define download_port 6666
#define upload_port 5555



void upload_file();
void download_file();
void open_socket();
void close_socket();