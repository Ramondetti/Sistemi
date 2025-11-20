import socket

#in C# Studente pippo = new Studente(param);
#richiama il costruttore

#in python: pippo = Studente(param);
#istanzia un socket UDP
my_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

my_socket.connect(("127.0.0.1",5006))
#bytes converte in bytes il messaggio
my_socket.sendto(bytes("Ciao bellissimo".encode("utf-8")),("127.0.0.1",5006))

