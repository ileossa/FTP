#include "File.h"






// int instance_receive_file(char* path_file){
// 	  struct sockaddr_in dest; /* socket info about the machine connecting to us */
//     struct sockaddr_in serv; /* socket info about our server */
//     int mysocket;            /* socket used to listen for incoming connections */
//     socklen_t socksize = sizeof(struct sockaddr_in);

//     serv.sin_family = AF_INET;                /* set the type of connection to TCP/IP */
//     serv.sin_addr.s_addr = inet_addr(IP_SERVER); /* set our address to any interface */
//     serv.sin_port = htons(receive_port);           /* set the server port number */    

//     mysocket = socket(AF_INET, SOCK_STREAM, 0);
  
//     /* bind serv information to mysocket */
//     bind_socket(mysocket, serv);

//     /* start listening, allowing a queue of up to 1 pending connection */
//     listen(mysocket, 1);
    
//     send_size_file(mysocket)
    
    
//     close(mysocket);
//     return 0;
// }


// int instance_send_file(char* path_file){
// 	int mysocket;
//   char* chaine = malloc(sizeof(255));

//   struct sockaddr_in serverAddress;//client will connect on this
//   //create socket
//   mysocket=socket(AF_INET,SOCK_STREAM,0);
//   //initialize the socket addresses
//   memset(&serverAddress,0,sizeof(serverAddress));
//   serverAddress.sin_family=AF_INET;
//   serverAddress.sin_addr.s_addr=inet_addr(IP_SERVER);
//   serverAddress.sin_port=htons(receive_port);

//   //client  connect to server on port
//   connect(mysocket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
//   printf("name file: ");
//   fgets(chaine, 255, stdin);
//   send_name_file(mysocket, chaine);
//   send_file_data(mysocket, chaine);
      
//   close(mysocket);
//   return EXIT_SUCCESS;
// }


// int send_name_file(int peer_socket, char* filename){

//    len = send(peer_socket, filename, strlen(filename), 0);
//     if (len < 0) {
//         printf("failed to send filename: %s\n", filename);
//         return -1;
//     }else{
//        printf("name sent: %s\n", filename);
//     }
//     return 0;
// }


// int send_file_data(int peer_socket, char* filepath){
//   // test open and read file
//   fd = open(filepath, O_RDONLY);
//   if (fd == -1) {
//       printf( "Can't open file \"%s\" error: \"%s\"", filepath);
//       return -1;
//   }

//   if (fstat(fd, &file_stat) < 0) {
//       printf("fstat failed: %s");
//       return -1;
//   }
//   // send file
//   int remain_data = (int)file_stat.st_size;
//   off_t offset = 0;
//   while (((sent_bytes = (int)sendfile(peer_socket, fd, &offset, BUFSIZ)) > 0) && (remain_data > 0)) {
//       remain_data -= sent_bytes;
//   }
//   printf("remain data : %i\n", remain_data);
//   close(fd);
//   return remain_data;
// }

// int send_size_file(int ){
//   len = send(peer_socket, file_size, sizeof(file_size), 0);
//   if (len < 0) {
//       fprintf(stderr, "Failed to send file_size: %s", strerror(errno));
//       return -1;
//   }else{
//       printf("file send: %s : %i\n", filename, file_size );
//   }
// }


