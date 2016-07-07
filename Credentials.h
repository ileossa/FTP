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

#include "Generic.h"

#define DELIM ";"
#define BUFF_SIZE 128
#define PATH_FILE "users.csv"

typedef struct User user_struct;
struct User{
   char * name;
   char * password;
   user_struct * next;
};

typedef enum UserE user_typedf;
enum UserE{
   NAME,
   PASSWORD
};

int test_credential(char* id, char* password);
char* file_save_credentials(char* path_file);