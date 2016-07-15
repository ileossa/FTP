#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define essai 3

#include "Generic.h"


void test_credential();
char* getfield(char* line, int num);
int test_credential_name( char* name_file, char* name_receive);
int test_credential_password( char* password_file, char* password_receive);
char* extract_name( char* line);
char* extract_password( char* line);

// client method
char* get_login();
char* get_password();
