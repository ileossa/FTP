#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "Credentials.h"
#include "Commandes.h"
#include "GlobalValues.h"



struct Processing_data
{
	char* message;
	char* login;
	char* password;
	int jalon;
	int attempt;
};
typedef struct Processing_data Processing_data;


struct Processing_data* data_processing(Processing_data* p);
struct Processing_data* init_processing();
