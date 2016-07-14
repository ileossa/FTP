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
	//mettre le switch case tableau
	switch(p->jalon) {

	   case 0  :
	      if(strcmp(p->message, "BONJ") == 0){
	      	p->message = "WHO";
	      	p->jalon = 1;
	      }
	      break; 
		
	   case 1  :
	      if( p->message != NULL && p->message[0] != '\0'){
	      	p->login = p->message;
	      	p->message = "PASSWD";
	      	p->jalon = 2;
	      }
	      break; 
	    case 2 : 
	    	if( p->message != NULL && p->message[0] != '\0'){
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

	    case 3 :
	    	printf("appel list commande\n");
	    	printf("p->message[0]: %c\n", p->message[0]);
	    	int val;
	    	char* c;
	    	c = p->message;
	    	if(p->message[0] == 'r'){
	    		// tmp, list_commandes_to(p->message));
	    	}else{
	    		c = list_commandes_local(c);
	    	}
	    	printf("process comande tmp: %s\n", c);
	    	p->message = c;
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