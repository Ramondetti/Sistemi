import socket

#in C# Studente pippo = new Studente(param);
#richiama il costruttore

#in python: pippo = Studente(param);
#istanzia un socket UDP
my_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

#aggancia il socket a un ip e una porta
my_socket.bind(("127.0.0.1",5006))
print("Server in ascolto")

(messaggio,addr)=my_socket.recvfrom(1024)# buffer size

print(messaggio)


