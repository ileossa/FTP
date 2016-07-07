#include "Server.h"





void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
     
    //exemple send message
    //write(sock , message , strlen(message));
     
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        
        printf("%s\n", client_message );
        //Send the message back to client
        //write(sock , client_message , strlen(client_message));
        if(strcmp("BONJ", client_message) != 0){
            message = "WHO";            
        } else if(strcmp("pass", client_message) != 0){
            
        }

        write(sock , message , strlen(message));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
         
    //Free the socket pointer
    free(socket_desc);
     
    return 0;
}


int* new_client(int new_socket){
	pthread_t sniffer_thread;

	int *new_sock = malloc(4);
    *new_sock = new_socket;

	if( pthread_create( &sniffer_thread , NULL ,  connection_handler , &new_sock) < 0)
	{
	    perror("could not create thread");
	    return 1;
	}
	 
	//Now join the thread , so that we dont terminate before the thread
	//pthread_join( sniffer_thread , NULL);
	puts("Handler assigned");
	return *new_sock;
}




int* instanciate_socket(){
	int socket_open;
	/* Ouverture d'un socket afin de recevoir des demandes de connection */
	int sock_des = (socket_open = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));
	if( sock_des == -1)
	{
		printf("Error instanciate socket\n");
	}
	return *sock_des;
}



void* connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
     
    //exemple send message
    //write(sock , message , strlen(message));
     
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        
        printf("%s\n", client_message );
        //Send the message back to client
        //write(sock , client_message , strlen(client_message));
        if(strcmp("BONJ", client_message) != 0){
            message = "WHO";            
        } else if(strcmp("pass", client_message) != 0){
            
        }

        write(sock , message , strlen(message));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
         
    //Free the socket pointer
    free(socket_desc);
     
    return 0;
}



int* build_server(char* ip, int port){
	
	int socket_desc = instanciate_socket();
	
	/* Indentification du socket */
	server_struct s_server;
	bzero((char *)&s_server,sizeof(s_server));
	s_server.sin_family      = AF_INET;
	s_server.sin_addr.s_addr = inet_addr(ip);
	s_server.sin_port = htons(port);

	int socket_bind = bind(socket_desc,(struct sockaddr *)&s_server , sizeof(s_server));
	if ( socket_bind < 0) 
	{ 
		printf("error bind socket\n");
		exit(1);
	}
	printf("Server up on %s::%d\n", s_server.sin_addr.s_addr, s_server.sin_port);
	return *socket_bind;
}



int* standby_accept_connection(int socket_desc){
	server_struct *client;
	int new_socket;
	listen(socket_desc , 3);
	int c = sizeof(client);
	while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
    	new_client(new_socket);
    }
    if (new_socket<0)
    {
        perror("accept failed");
        return 1;
    }
    return *new_socket;
}


void send_message(int socket, char* message){
	write(socket , message , strlen(message));
}