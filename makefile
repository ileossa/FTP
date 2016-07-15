all: server client

server: MainServer.c Chiffrement.c Chiffrement.h Commandes.c Commandes.h Credentials.c Credentials.h Builder.c Builder.h Generic.h Generic.c Processing.h Processing.c File.c File.h
	gcc MainServer.c Chiffrement.c Commandes.c Credentials.c Generic.c Processing.c File.c Builder.c -lpthread -o server

client: MainClient.c Commandes.c Commandes.h Builder.c Builder.h Processing.h Processing.c Credentials.c Credentials.h File.c File.h
	gcc MainClient.c Commandes.c  Builder.c Credentials.c File.c Processing.c -lpthread -o client

clean:
	rm -f *.o p->message client