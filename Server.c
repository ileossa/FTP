#include "Server.h"




int build_server(char* ip, int port){
    struct sockaddr_in dest; /* socket info about the machine connecting to us */
    struct sockaddr_in serv; /* socket info about our server */
    int mysocket;            /* socket used to listen for incoming connections */
    socklen_t socksize = sizeof(struct sockaddr_in);

    //memset(&serv, 0, sizeof(serv));           /* zero the struct before filling the fields */
    serv.sin_family = AF_INET;                /* set the type of connection to TCP/IP */
    serv.sin_addr.s_addr = inet_addr(ip); /* set our address to any interface */
    serv.sin_port = htons(port);           /* set the server port number */    

    mysocket = socket(AF_INET, SOCK_STREAM, 0);
  
    /* bind serv information to mysocket */
    bind_socket(mysocket, serv);

    /* start listening, allowing a queue of up to 1 pending connection */
    listen(mysocket, 1);
    int consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
  	
  	

    while(consocket)
    {
        // send_to(consocket, "Hello World !\n");
        // infinity_receive(consocket);
        //commandes_local(consocket , "ls");
        //credential_scenario(consocket);

        // copie de la socket, evite que le client suivant écrase la mémoire
        int *s = malloc(4);
        *s = consocket;
        // debut instance du thread
        // nom du thread
        pthread_t th1;
        int statut = pthread_create( &th1 , NULL ,  thread_client , (void*) s);
        if(statut < 0){
            perror("could not create thread");
            exit(2);
        }
       
        // close(consocket);
        consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
    }

    close(mysocket);
    return EXIT_SUCCESS;
}



void* thread_client(void* sock){
    int socket = *(int*)sock;
    char* msg_receive = NULL;
    char* tmp;
    struct Processing_data* res_processing;
    res_processing = init_processing();
    printf("thread client\n");

    while(1){
        //ecoute
        msg_receive = infinity_receive(socket);
        res_processing->message = msg_receive;
        int x=0;
        for(x; msg_receive[x] != '\0'; ++x){
            printf("msg : %c\n",msg_receive[x] );
        }

        if(strcmp(msg_receive, "client_close_connection") == 0){
            printf("client close connection, close socket && exit thread");
            close(socket);
            pthread_exit(0);
        }

        res_processing = data_processing(res_processing);
        printf("process: message: %s  jalon: %3i", res_processing->message, res_processing->jalon);
        if(strcmp(res_processing->message, "BYE") == 0){
            close(socket);
            pthread_exit(0);
        }
        //j envoie le msg
        tmp = res_processing->message;
        send_to(socket, tmp);
    }    
    return NULL;
}



char* infinity_receive(int socket){
	char* receive_msg = malloc(sizeof(len_buffer_receive));
    int n = recv(socket , receive_msg , len_buffer_receive , 0);
    if( n == 0){
        close(socket);
        return "client_close_connection";
    }
    printf("client msg: %s", receive_msg);
    int len = strlen(receive_msg);
    receive_msg[len-2] = '\0';
    return receive_msg;
}


void send_to(int socket, char* msg){	
	//printf("Incoming connection from %s - sending welcome\n", inet_ntoa(dest.sin_addr));
    send(socket, msg, strlen(msg), 0);
}


void bind_socket(int socket, struct sockaddr_in server){
	int r = bind(socket, (struct sockaddr *)&server, sizeof(struct sockaddr));
	if(r != 0){
		printf("Error Bind socket\n");
		exit(1);
	}
	printf("Server Up\n");
}



void* test_thread(void* socket){
    int sock = *(int*)socket;
    printf("debut test thread\n");
    send_to(sock, "thread test");
    
    char * m = infinity_receive(sock);
    write(sock , m , strlen(m));
    
    m = infinity_receive(sock);
    send_to(sock, m);

    close(sock);
    /* the function must return something - NULL will do */
    return NULL;
}


// void *connection_handler(void *socket_desc)
// {
//     //Get the socket descriptor
//     int sock = *(int*)socket_desc;
//     int read_size;
//     char *message , client_message[2000];
     
//     //exemple send message
//     //write(sock , message , strlen(message));
     
//     //Receive a message from client
//     while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
//     {
        
//         printf("%s\n", client_message );
//         //Send the message back to client
//         //write(sock , client_message , strlen(client_message));
//         if(strcmp("BONJ", client_message) != 0){
//             message = "WHO";            
//         } else if(strcmp("pass", client_message) != 0){
            
//         }

//         write(sock , message , strlen(message));
//     }
     
//     if(read_size == 0)
//     {
//         puts("Client disconnected");
//         fflush(stdout);
//     }
//     else if(read_size == -1)
//     {
//         perror("recv failed");
//     }
         
//     //Free the socket pointer
//     free(socket_desc);
     
//     return 0;
// }


// int* new_client(int new_socket){
// 	pthread_t sniffer_thread;

// 	int *new_sock = malloc(4);
//     *new_sock = new_socket;

// 	if( pthread_create( &sniffer_thread , NULL ,  connection_handler , &new_sock) < 0)
// 	{
// 	    perror("could not create thread");
// 	    return 1;
// 	}
	 
// 	//Now join the thread , so that we dont terminate before the thread
// 	//pthread_join( sniffer_thread , NULL);
// 	puts("Handler assigned");
// 	return *new_sock;
// }




// int* instanciate_socket(){
// 	int socket_open;
// 	/* Ouverture d'un socket afin de recevoir des demandes de connection */
// 	int sock_des = (socket_open = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));
// 	if( sock_des == -1)
// 	{
// 		printf("Error instanciate socket\n");
// 	}
// 	return *sock_des;
// }



// void* connection_handler(void *socket_desc)
// {
//     //Get the socket descriptor
//     int sock = *(int*)socket_desc;
//     int read_size;
//     char *message , client_message[2000];
     
//     //exemple send message
//     //write(sock , message , strlen(message));
     
//     //Receive a message from client
//     while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
//     {
        
//         printf("%s\n", client_message );
//         //Send the message back to client
//         //write(sock , client_message , strlen(client_message));
//         if(strcmp("BONJ", client_message) != 0){
//             message = "WHO";            
//         } else if(strcmp("pass", client_message) != 0){
            
//         }

//         write(sock , message , strlen(message));
//     }
     
//     if(read_size == 0)
//     {
//         puts("Client disconnected");
//         fflush(stdout);
//     }
//     else if(read_size == -1)
//     {
//         perror("recv failed");
//     }
         
//     //Free the socket pointer
//     free(socket_desc);
     
//     return 0;
// }







// int* standby_accept_connection(int socket_desc){
// 	server_struct *client;
// 	int new_socket;
// 	listen(socket_desc , 3);
// 	int c = sizeof(client);
// 	while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
//     {
//     	new_client(new_socket);
//     }
//     if (new_socket<0)
//     {
//         perror("accept failed");
//         return 1;
//     }
//     return *new_socket;
// }


// void send_message(int socket, char* message){
// 	write(socket , message , strlen(message));
// }