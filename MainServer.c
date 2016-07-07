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
#define PORT_SERVER 2300
#define MODE_SERVER "TCP"


int main(int argc , char *argv[])
{
	//create server
	int status = build_server(IP_SERVER, PORT_SERVER);
	
	return status;
}