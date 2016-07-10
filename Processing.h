#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "Credentials.h"

#define attempt 3

processing_data* data_processing(char* msg_receive);