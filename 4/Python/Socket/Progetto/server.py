import socket
import threading
import json
import datetime
from typing import Dict, List

<<<<<<< HEAD
clients = {}  # nickname: socket

def handle_client(sock):
    nickname = None
    nickname = sock.recv(1024).decode()
    clients[nickname] = sock
    print(f"[+] {nickname} connesso.")
    update_user_list()

    try:
        while True:
            data = sock.recv(1024).decode()
            if "::" in data:
                dest, msg = data.split("::", 1)
                if dest in clients:
                    clients[dest].send(f"{nickname}: {msg}".encode())
    except:
        print(f"[-] {nickname} disconnesso.")
        del clients[nickname]
        update_user_list()
        sock.close()

def update_user_list():
    user_list = ",".join(clients.keys())
    for client in clients.values():
        try:
            client.send(f"[USERS]::{user_list}".encode())
        except:
            pass

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', 5555))
    server.listen()
    print("[SERVER] In ascolto...")

    while True:
        client_socket, _ = server.accept()
        threading.Thread(target=handle_client, args=(client_socket,), daemon=True).start()

start_server()
=======

class ChatServer:
    def __init__(self, host='localhost', port=12345):
        self.host = host
        self.port = port
        self.clients: Dict[socket.socket, str] = {}  # socket -> username
        self.usernames: Dict[str, socket.socket] = {}  # username -> socket
        self.running = False

    def start_server(self):
        """Avvia il server di chat"""
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        try:
            self.server_socket.bind((self.host, self.port))
            self.server_socket.listen(5)
            self.running = True

            print(f"[SERVER] Server avviato su {self.host}:{self.port}")
            print(f"[SERVER] In attesa di connessioni...")

            while self.running:
                try:
                    client_socket, client_address = self.server_socket.accept()
                    print(f"[SERVER] Nuova connessione da {client_address}")

                    # Avvia thread per gestire il client
                    client_thread = threading.Thread(
                        target=self.handle_client,
                        args=(client_socket, client_address)
                    )
                    client_thread.daemon = True
                    client_thread.start()

                except socket.error:
                    if self.running:
                        print("[SERVER] Errore nell'accettare connessioni")

        except Exception as e:
            print(f"[SERVER] Errore nell'avvio del server: {e}")
        finally:
            self.shutdown_server()

    def handle_client(self, client_socket, client_address):
        """Gestisce la comunicazione con un singolo client"""
        username = None

        try:
            while self.running:
                # Ricevi messaggio dal client
                data = client_socket.recv(1024).decode('utf-8')
                if not data:
                    break

                try:
                    message = json.loads(data)
                    message_type = message.get('type')

                    if message_type == 'join':
                        username = message.get('username')
                        if self.handle_user_join(client_socket, username):
                            self.send_message(client_socket, {
                                'type': 'join_success',
                                'message': f'Benvenuto nella chat, {username}!'
                            })
                            self.broadcast_user_list()
                        else:
                            self.send_message(client_socket, {
                                'type': 'join_error',
                                'message': 'Username già in uso!'
                            })

                    elif message_type == 'message':
                        if username:
                            self.handle_message(username, message)

                    elif message_type == 'private_message':
                        if username:
                            self.handle_private_message(username, message)

                except json.JSONDecodeError:
                    print(f"[SERVER] Messaggio non valido da {client_address}")

        except ConnectionResetError:
            print(f"[SERVER] Connessione chiusa improvvisamente da {client_address}")
        except Exception as e:
            print(f"[SERVER] Errore con client {client_address}: {e}")
        finally:
            self.handle_user_disconnect(client_socket, username)

    def handle_user_join(self, client_socket, username):
        """Gestisce l'ingresso di un nuovo utente"""
        if username in self.usernames:
            return False

        self.clients[client_socket] = username
        self.usernames[username] = client_socket

        # Notifica agli altri utenti
        join_message = {
            'type': 'user_joined',
            'username': username,
            'message': f'{username} si è unito alla chat',
            'timestamp': datetime.datetime.now().strftime('%H:%M:%S')
        }
        self.broadcast_message(join_message, exclude_socket=client_socket)

        print(f"[SERVER] {username} si è unito alla chat")
        return True

    def handle_user_disconnect(self, client_socket, username):
        """Gestisce la disconnessione di un utente"""
        if client_socket in self.clients:
            del self.clients[client_socket]

        if username and username in self.usernames:
            del self.usernames[username]

            # Notifica agli altri utenti
            leave_message = {
                'type': 'user_left',
                'username': username,
                'message': f'{username} ha lasciato la chat',
                'timestamp': datetime.datetime.now().strftime('%H:%M:%S')
            }
            self.broadcast_message(leave_message)
            self.broadcast_user_list()

            print(f"[SERVER] {username} ha lasciato la chat")

        try:
            client_socket.close()
        except:
            pass

    def handle_message(self, sender, message):
        """Gestisce i messaggi broadcast"""
        broadcast_message = {
            'type': 'broadcast_message',
            'sender': sender,
            'message': message.get('message', ''),
            'timestamp': datetime.datetime.now().strftime('%H:%M:%S')
        }
        self.broadcast_message(broadcast_message)
        print(f"[BROADCAST] {sender}: {message.get('message', '')}")

    def handle_private_message(self, sender, message):
        """Gestisce i messaggi privati"""
        recipient = message.get('recipient')
        content = message.get('message', '')

        if recipient in self.usernames:
            private_message = {
                'type': 'private_message',
                'sender': sender,
                'message': content,
                'timestamp': datetime.datetime.now().strftime('%H:%M:%S')
            }

            # Invia al destinatario
            recipient_socket = self.usernames[recipient]
            self.send_message(recipient_socket, private_message)

            # Conferma al mittente
            confirmation = {
                'type': 'private_confirmation',
                'recipient': recipient,
                'message': content,
                'timestamp': datetime.datetime.now().strftime('%H:%M:%S')
            }
            sender_socket = self.usernames[sender]
            self.send_message(sender_socket, confirmation)

            print(f"[PRIVATE] {sender} -> {recipient}: {content}")
        else:
            # Utente non trovato
            error_message = {
                'type': 'error',
                'message': f'Utente {recipient} non trovato'
            }
            sender_socket = self.usernames[sender]
            self.send_message(sender_socket, error_message)

    def broadcast_message(self, message, exclude_socket=None):
        """Invia un messaggio a tutti i client connessi"""
        disconnected_clients = []

        for client_socket in self.clients.keys():
            if client_socket != exclude_socket:
                try:
                    self.send_message(client_socket, message)
                except:
                    disconnected_clients.append(client_socket)

        # Rimuovi client disconnessi
        for client_socket in disconnected_clients:
            username = self.clients.get(client_socket)
            self.handle_user_disconnect(client_socket, username)

    def broadcast_user_list(self):
        """Invia la lista degli utenti connessi a tutti i client"""
        user_list = {
            'type': 'user_list',
            'users': list(self.usernames.keys())
        }
        self.broadcast_message(user_list)

    def send_message(self, client_socket, message):
        """Invia un messaggio a un client specifico"""
        try:
            message_json = json.dumps(message)
            client_socket.send(message_json.encode('utf-8'))
        except Exception as e:
            print(f"[SERVER] Errore nell'invio messaggio: {e}")

    def shutdown_server(self):
        """Chiude il server"""
        self.running = False

        # Chiudi tutte le connessioni client
        for client_socket in list(self.clients.keys()):
            try:
                client_socket.close()
            except:
                pass

        # Chiudi socket del server
        try:
            self.server_socket.close()
        except:
            pass

        print("[SERVER] Server chiuso")


if __name__ == "__main__":
    server = ChatServer()
    try:
        server.start_server()
    except KeyboardInterrupt:
        print("\n[SERVER] Interruzione da tastiera")
        server.shutdown_server()
>>>>>>> 8ca59d7af7a2a7551393870c5cb260056c0b0618
