#include "Credentials.h"


char* getfield(char* line, int num)
{
   char* tok;
   for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
   {
      if (!--num)
         return tok;
   }
   return NULL;
}


int read_file(char* name, char* password)
{
   FILE* fp;
   char* line = NULL;
   char* line_tmp = NULL;
   char* cred_concat = NULL;
   size_t len = 0;
   ssize_t read;

   // test_space(name);
   // test_space(password);

   

   fp = fopen("users.csv", "r");
   if (fp == NULL){
      printf("exit can't open file\n");
     exit(EXIT_FAILURE);
   }
   char* t = NULL;
   while ((read = getline(&line, &len, fp)) != -1) {
      //printf("Retrieved line of length %zu :\n", read);
      printf("%s\n", line);
      
      
      
      
      if(
      (test_credential_password(extract_password(line), password) == 0) &&      
      (test_credential_name(extract_name(line), name)) == 0)
      {
         //good login and password
         //printf("good %s : %s\n", name, password );
         fclose(fp);
         if (line)
            free(line);
         free(cred_concat); 
         return 0;
      }     
   }
   fclose(fp);
   if (line)
      free(line);
   free(cred_concat); 
   return 1; 
}


int test_credential_name(char* name_file, char* name_receive){
   if(strcmp(name_file, name_receive) == 0){
      return 0;
   }
   return 1;
}


int test_credential_password(char* password_file, char* password_receive){
   if(strcmp(password_file, password_receive) == 0){
      return 0;
   }
   return 1;
}


char* extract_name(char* line){
   char* t = getfield(line, 1);
   return t;
}


char* extract_password(char* line){
   char* t = getfield(line, 2);
   return t;
}



char* get_login(){
   char* login = malloc(sizeof("azertyuiop"));
   printf("login: ");
   scanf("%s", login);
   return login;
}



char* get_password(){
   char* password = malloc(sizeof("azertyuiop"));
   printf("password: ");
   scanf("%s", password);
   return password;
}


