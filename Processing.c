#include "Processing.h"

typedef struct processing_data 
{
	char message[100];
	char* login;
	char* password;
	int jalon;
} processing_data;



processing_data* data_processing(char* msg_receive){
	processing_data* pdata;
	pdata = (struct processing_data*) malloc(sizeof(struct processing_data));
	
	//mettre le switch case tableau
	switch(jalon) {

	   case 0  :
	      if(strcmp(msg_receive, "BONJ") == 0){
	      	processing_data->message = "WHO";
	      	pdata->jalon = 1;
	      }
	      break; 
		
	   case 1  :
	      if( msg_receive != NULL && msg_receive[0] != '\0'){
	      	pdata->login = msg_receive;
	      	pdata->message = "PASSWD";
	      	pdata->jalon = 2;
	      }
	      break; 
	    case 2 : 
	    	if( msg_receive != NULL && msg_receive[0] != '\0'){
	    		pdata->password = msg_receive;
	    		// if(credential_scenario(pdata->login, pdata->password) == 0){
	    		// 	pdata->message = "WELC";
	    		// }
	    		
	    		if(attempt < 0){
	    			pdata->message = "BYE";
	    			pdata->login = "";
	    			pdata->password = "";
	    			pdata->jalon = 0;
	    		}
	    		--attempt;
	    	}
	  
	   
	   	default : 
	   	pdata->res_msg = "Error server, pls retry";
	   	pdata->login = "";
		pdata->password = "";
		pdata->jalon = 0;
	   
	}

	return pdata;
}