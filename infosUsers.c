/*
*     gcc infosUsers.c -o infosUsers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM ";"
#define BUFF_SIZE 128


typedef struct {
	char * name;
	char * password;
   user_struct * next;
}user_struct;

typedef enum{
	NAME,
	PASSWORD
}user_typedf;

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
   user_struct  *  infos = NULL;
   FILE           *  file  = NULL;
   char           *  token = NULL;
   char              buff [BUFF_SIZE];


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


static void free_user_infos (user_struct ** p)
{
   if (p != NULL && *p != NULL)
   {
      free ((*p)->name);
      free ((*p)->password);

      free (*p);
      *p = NULL;
   }
}



int main (void)
{
   user_struct * infos = get_contact ("users.csv");
   if(infos != NULL){
      printf( "%s : %s\n", infos->name, infos->password);
      free_user_infos (& infos);
   }
   
   return EXIT_SUCCESS;
}