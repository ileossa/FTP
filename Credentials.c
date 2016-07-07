#include "Credentials.h"



char *name;
char *password;


static char * str_dup (const char * str)
{
   char * dup = NULL;
   if (str != NULL)
   {
      size_t size = strlen (str) + 1;
      dup = malloc (size);

      if (dup != NULL)
      {
         memcpy (dup, str, size);
      }
   }
   return dup;
}


static user_struct * get_contact (const char * filename)
{
   user_struct* infos = NULL;
   FILE *  file  = NULL;
   char *  token = NULL;
   char buff [BUFF_SIZE];


   file = fopen (filename, "r");

   if (file != NULL)
   {
      while ((fgets (buff, BUFF_SIZE, file)) != NULL)
      {
         char *   p = buff;
         int      i = 0;


         infos = malloc (sizeof (* infos));

         if (infos != NULL)
         {
            while ((token = strtok (p, DELIM)) != NULL)
            {
               if (i == 0)
                  p = NULL;

               switch (i)
               {
                  case NAME:
                     infos->name = str_dup (token);
                     break;

                  case PASSWORD:
                     infos->password = str_dup (token);
                     break;
               }
               ++i;
            }
         }
      }

      fclose (file);
   }
   return infos;
}


static void free_credentials_infos (user_struct **p)
{
   if (p != NULL && *p != NULL)
   {
      free ((*p)->name);
      free ((*p)->password);

      free (*p);
      *p = NULL;
   }
}



int test_credential(char* id, char* pass){
	name = id;
	password = pass;
	user_struct* infos = get_contact ("users.csv");
   	if(infos != NULL){
   		if(id == infos->name && password == infos->password){
   			return TRUE;
   		}
      	// printf( "%s : %s\n", infos->name, infos->password);
      
   }
   free_credentials_infos (& infos);
   return FALSE;
}


char* file_save_credentials(char* path_file){
   if(path_file != NULL){
      return path_file;
   }
   return PATH_FILE;
}