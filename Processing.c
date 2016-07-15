#include "Processing.h"



struct Processing_data* init_processing(){
	struct Processing_data* p;
	p = (struct Processing_data*) malloc(sizeof(struct Processing_data));
	p->attempt = fix_attempt;
	p->message = "";
	p->login = "";
	p->password = "";
	p->jalon = 0;
	return p;
}


struct Processing_data* data_processing(struct Processing_data* p){
	printf("d1: %s\n", p->message );
	printf("j1: %i\n", p->jalon );

	char* cmd;

	//mettre le switch case tableau
	switch(p->jalon) {

	   case 0  :
	   		// server
			if(strcmp(p->message, "BONJ") == 0){
				printf("01\n");
				p->message = "WHO";
				p->jalon = 1;
			}
			// client
			else if(strcmp(p->message, "WHO") == 0){
				printf("02\n");
				p->message = get_login();
				p->jalon = 1;
			}
			break; 
		
	   case 1  :
	   		// server
			if( p->message != NULL && p->message[0] != '\0' && strcmp(p->message, "PASSWD") != 0 ){
				printf("11\n");
					p->login = p->message;
					p->message = "PASSWD";
					p->jalon = 2;
			}
			// client
			else if(strcmp(p->message, "PASSWD") == 0){
				printf("12\n");
				p->message = get_password();
				p->jalon = 21;
			} 
			break; 
	    case 2 : 
	    	// server
	    	if( p->message != NULL && p->message[0] != '\0' && strcmp(p->message, "WELC") != 0 ){
	    		printf("21\n");
	    		p->password = p->message;
	    		if(read_file(p->login, p->password) == 0){
	    			p->message = "WELC";
	    			p->jalon = 3;
	    		}else{
	    			p->message = "Mauvais login / password";
	      			p->jalon = -1;
	    		}
	    		
	    		if(p->attempt < 0){
	    			p->message = "BYE";
	    			p->login = "";
	    			p->password = "";
	    			p->jalon = 0;
	    		}
	    		p->attempt = p->attempt - 1;
	    	}
	      	break; 

	    case 21 : 
	    	if( strcmp(p->message, "WELC") == 0){
	    		p->jalon = 31;
	    	}else if(strcmp(p->message, "WHO") == 0) {
	    		p->message = get_login();
				p->jalon = 1;
	    	}else{
	    		p->message = "Error parms client";
	    		p->jalon = 0;
	    	}
	    case 32 :
	    case 31 :
	    	// client
	    	if( p->message != NULL && p->message[0] != '\0'){
		    	if( strcmp(p->message, "WELC") == 0 || p->jalon == 32){
			    	printf("appel list commande case 31\n");
			    	// printf("p->message[0]: %c\n", p->message[0]);
			    	// int val;
			    	
			    	cmd = get_commande();
			    	cmd[strlen(cmd)-1] = '\0';
			    	printf("cmd 31 : %s\n",cmd );

			    	if(cmd[0] == 'r'){
				    	p->message = cmd;
			    	}else{
			    		list_commandes_local(cmd);
			    		p->message = "nop";

			    	}	
			    	p->jalon = 32;
			    }
			}
	    	break;
	    case 3 :
	    	// server
	    	if( p->message != NULL && p->message[0] != '\0'){
				if(p->message[0] == 'r'){
			    	printf("appel list commande case 3\n");
			    	printf("p->message: %s\n", p->message );
			    	// printf("p->message[0]: %c\n", p->message[0]);
			    	// int val;
			    	
			    	// char* c;
			    	// c = p->message;
			    	cmd =  list_commandes_to(p->message);			    		    	
			    	p->message = cmd;
			    }
		    }
	    	break;
	    	

	  	case -1 :
	  		p->message = "WHO";
	  		p->jalon = 1;
	  		break;
	   
	   	default : 
	   	p->message = "Error server, pls retry";
	   	p->login = "";
		p->password = "";
		p->jalon = 0;
	   
	}

	return p;
}