#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#include <unistd.h>
#include <libgen.h>

#include "GlobalValues.h"

#define send_port 6666
#define receive_port 5555

int instance_send_file(char* path_file);
int instance_receive_file(char* path_file);