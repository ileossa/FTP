#include "Builder.h"

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

#include "GlobalValues.h"
#include "File.h"



int main(int argc , char *argv[])
{
	//create server
	int status = build_client(IP_SERVER, PORT_SERVER);
	//read_file("toto", "tata"); 
	// system("ls"); && popen()
	//testCommande();
	//instance_send_file("tt");

	return 0;
}