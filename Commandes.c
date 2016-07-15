#include "Commandes.h"



char* commandes_local(char* commande){ 
	FILE* in;
	extern FILE* popen();
	char* buff = malloc(sizeof("just do it"));
	char* s = malloc(sizeof("just do it"));
	s="";


	// pipe sur l'invite de commande avec popen et execution de la commande passé en parametre
	if(!(in = popen(commande, "r"))){
		exit(1);
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){	
		s = concat(s, buff);
	}
	pclose(in);	
	commande = s;
	return commande;
}




void list_commandes_local(char* m){
    char* res = m;

    int pwd = strcmp(m, "pwd");
    int ls = strcmp(m, "ls");

	if( ls == 0 || pwd == 0  ){
		printf("%s\n",  commandes_local(m));
	}else if (m[0] == 'r' && m[1] == 'm'){
        printf("%s\n",  commandes_local(m));
    }else{
        printf("null commande for list commandes local");
    }
}


char* list_commandes_to(char* m){
	char* res = m;

    int rpwd = strcmp(m, "rpwd");
    int rls = strcmp(m, "rls");

    printf("list_commandes_to\n" );
    printf("m: %s\n", m );
    printf("rpwd: %i\n", rpwd);
    printf("rls: %i\n", rls);

	if(strcmp(m, "rls") == 0 ){
        return commandes_local("ls");
    }else if (strcmp(m, "rpwd") == 0){
		return commandes_local("pwd");
	}

	return "null commande for list commandes distant";
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


char* get_commande(){
   char* chaine = malloc(sizeof(50));
 
    printf("Entrez une chaine:\n");
    fgets(chaine, sizeof(chaine), stdin);    
    printf("Chaine: %s\n", chaine);
    return chaine;
}
 
 
char* clean(char *c, int i){
    int len = strlen(c);
    c[len-i] = '\0'; 
    return "c";
}



void  parse(char *line, char **argv)
{
    while (*line != '\0') {       /* if not the end of line ....... */ 
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';     /* replace white spaces with 0    */
        *argv++ = line;          /* save the argument position     */
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
           line++;             /* skip the argument until ...    */
    }
    *argv = '\0';                 /* mark the end of argument list  */
}

