all: server

server: MainServer.c Chiffrement.c Chiffrement.h Commandes.c Commandes.h Credentials.c Credentials.h Server.c Server.h
	gcc MainServer.c Chiffrement.c Commandes.c Credentials.c Server.c -lpthread -o server

clean:
	rm -f *.o server 

