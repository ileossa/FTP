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
#include <assert.h>


char* commandes_local(char* commande);
void list_commandes_local(char* m);
char* list_commandes_to(char* m);

char** str_split(char* a_str, const char a_delim);
char* concat(char *s1, char *s2);

char* get_commande();
char* clean(char *c, int i);