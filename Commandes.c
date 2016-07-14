#include "Commandes.h"



char* commandes_local(char* commande){
	printf("commande start with %s", commande);
	int len = strlen(commande);
    commande[len-2] = '\0';
	int x = 0;
	for(x; commande[x] != '\0'; ++x){
            printf("msg : %c\n",commande[x] );
        }

	FILE* in;
	extern FILE* popen();
	char* buff = malloc(sizeof("2048"));
	char* s = malloc(sizeof("caca"));
	s="";


	// pipe sur l'invite de commande avec popen et execution de la commande passé en parametre
	if(!(in = popen(commande, "r"))){
		exit(1);
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){
		printf("MY : : : :    %s", buff);
		//send_to(socket, buff);
		s = concat(s, buff);
	}
	pclose(in);
	printf("end commande buff: %s\n", buff);
	printf("SSO: %s\n",s );
	commande = s;
	return commande;
}




char* list_commandes_local(char* m){
	printf("caca : %s\n", m);

	char* res = malloc(sizeof("caca"));
	res = "toto";
	
	int i = strcmp(m, "ls") == 0;
	int ip = (strcmp(m, "pwd") == 0);
	printf("caca i: %i\n", i);
	printf("caca ip: %i\n", ip);
	if(  i == 0 || ip == 0){
		m=  commandes_local(m);
		return toto(m);
		
		// printf("res : %s\n", res);
		// return res;
	}

	char** sm = str_split(m,' ');
 
	if(strcmp(sm[0], "cd")){
		
	}
	if(strcmp(sm[0], "rm")){
		
	}
	printf("caca res: %s\n", res);
	return m;
}

char* toto(char* c){
	printf("toto c: %s\n", c);
	return c;
}



char* list_commandes_to(char* m){
	char* res;

	if(strcmp(m, "rls") == 0 || (strcmp(m, "rpwd") == 0)){
		//res = commandes_local(m);
		return res;
	}

	char** sm = str_split(m,' ');

	return res;
}


char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}



char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
