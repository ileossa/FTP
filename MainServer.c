#include "Server.h"
#include "Credentials.h"
#include "Chiffrement.h"
#include "Commandes.h"

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


#define IP_SERVER "127.0.0.1"
#define PORT_SERVER 21
#define MODE_SERVER "TCP"


int main(int argc , char *argv[])
{
	//create server
	int* sock_description_server = build_server(IP_SERVER, PORT_SERVER);
	// standby and instanciate thread for the new client's connection
	int* sock_client = standby_accept_connection( sock_description_server);
	//send message at this client fixed on the socket
	char* message = "Hello test";
	void send_message( sock_client, message);
	return 0;
}