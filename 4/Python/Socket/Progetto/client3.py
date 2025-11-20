import socket
import threading
import json
import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext
from tkinter import font as tkFont
import datetime


class ChatClient:
    def __init__(self):
        self.socket = None
        self.username = None
        self.connected = False
        self.running = False
        self.current_chat_view = "broadcast"  # "broadcast" o "private"

        # Configurazione GUI
        self.setup_gui()

    def setup_gui(self):
        """Configura l'interfaccia grafica"""
        self.root = tk.Tk()
        self.root.title("Chat Client Pro")
        self.root.geometry("1000x700")
        self.root.configure(bg='#1a1a2e')

        # Font personalizzati
        self.title_font = tkFont.Font(family="Segoe UI", size=18, weight="bold")
        self.subtitle_font = tkFont.Font(family="Segoe UI", size=12, weight="bold")
        self.normal_font = tkFont.Font(family="Segoe UI", size=10)
        self.button_font = tkFont.Font(family="Segoe UI", size=10, weight="bold")

        self.create_connection_frame()
        self.create_chat_frame()

        # Gestione chiusura finestra
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

    def create_connection_frame(self):
        """Crea il frame per la connessione"""
        self.connection_frame = tk.Frame(self.root, bg='#1a1a2e')
        self.connection_frame.pack(fill='both', expand=True, padx=30, pady=30)

        # Container principale
        main_container = tk.Frame(self.connection_frame, bg='#16213e', relief='raised', bd=2)
        main_container.pack(expand=True, padx=50, pady=50)

        # Titolo
        title_label = tk.Label(
            main_container,
            text="💬 Chat Application Pro",
            font=self.title_font,
            bg='#16213e',
            fg='#00d4ff'
        )
        title_label.pack(pady=(30, 40))

        # Frame per i campi di input
        input_frame = tk.Frame(main_container, bg='#16213e')
        input_frame.pack(pady=20, padx=40)

        # Server Host
        tk.Label(
            input_frame,
            text="🌐 Server Host:",
            font=self.subtitle_font,
            bg='#16213e',
            fg='#ffffff'
        ).grid(row=0, column=0, padx=15, pady=15, sticky='e')

        self.host_entry = tk.Entry(
            input_frame,
            font=self.normal_font,
            width=25,
            bg='#0f3460',
            fg='#ffffff',
            insertbackground='#00d4ff',
            relief='flat',
            bd=5
        )
        self.host_entry.insert(0, "localhost")
        self.host_entry.grid(row=0, column=1, padx=15, pady=15)

        # Server Port
        tk.Label(
            input_frame,
            text="🔌 Server Port:",
            font=self.subtitle_font,
            bg='#16213e',
            fg='#ffffff'
        ).grid(row=1, column=0, padx=15, pady=15, sticky='e')

        self.port_entry = tk.Entry(
            input_frame,
            font=self.normal_font,
            width=25,
            bg='#0f3460',
            fg='#ffffff',
            insertbackground='#00d4ff',
            relief='flat',
            bd=5
        )
        self.port_entry.insert(0, "12345")
        self.port_entry.grid(row=1, column=1, padx=15, pady=15)

        # Username
        tk.Label(
            input_frame,
            text="👤 Username:",
            font=self.subtitle_font,
            bg='#16213e',
            fg='#ffffff'
        ).grid(row=2, column=0, padx=15, pady=15, sticky='e')

        self.username_entry = tk.Entry(
            input_frame,
            font=self.normal_font,
            width=25,
            bg='#0f3460',
            fg='#ffffff',
            insertbackground='#00d4ff',
            relief='flat',
            bd=5
        )
        self.username_entry.grid(row=2, column=1, padx=15, pady=15)
        self.username_entry.bind('<Return>', lambda e: self.connect_to_server())

        # Pulsante connessione
        self.connect_button = tk.Button(
            main_container,
            text="🚀 Connetti al Server",
            command=self.connect_to_server,
            font=self.button_font,
            bg='#00d4ff',
            fg='#1a1a2e',
            activebackground='#33ddff',
            relief='flat',
            padx=30,
            pady=15,
            cursor='hand2'
        )
        self.connect_button.pack(pady=(30, 40))

    def create_chat_frame(self):
        """Crea il frame per la chat"""
        self.chat_frame = tk.Frame(self.root, bg='#1a1a2e')

        # Header con titolo e controlli
        header_frame = tk.Frame(self.chat_frame, bg='#16213e', height=60)
        header_frame.pack(fill='x', padx=10, pady=(10, 0))
        header_frame.pack_propagate(False)

        # Titolo chat
        chat_title = tk.Label(
            header_frame,
            text="💬 Chat Application Pro",
            font=self.title_font,
            bg='#16213e',
            fg='#00d4ff'
        )
        chat_title.pack(side='left', padx=20, pady=15)

        # Pulsanti per cambiare vista
        view_frame = tk.Frame(header_frame, bg='#16213e')
        view_frame.pack(side='right', padx=20, pady=10)

        self.broadcast_btn = tk.Button(
            view_frame,
            text="📢 Chat Pubblica",
            command=lambda: self.switch_chat_view("broadcast"),
            font=self.button_font,
            bg='#00d4ff',
            fg='#1a1a2e',
            activebackground='#33ddff',
            relief='flat',
            padx=15,
            pady=8,
            cursor='hand2'
        )
        self.broadcast_btn.pack(side='left', padx=(0, 10))

        self.private_btn = tk.Button(
            view_frame,
            text="🔒 Chat Privata",
            command=lambda: self.switch_chat_view("private"),
            font=self.button_font,
            bg='#e74c3c',
            fg='white',
            activebackground='#ec7063',
            relief='flat',
            padx=15,
            pady=8,
            cursor='hand2'
        )
        self.private_btn.pack(side='left')

        # Frame principale diviso in due colonne
        main_frame = tk.Frame(self.chat_frame, bg='#1a1a2e')
        main_frame.pack(fill='both', expand=True, padx=10, pady=10)

        # Colonna sinistra - Area chat
        left_frame = tk.Frame(main_frame, bg='#1a1a2e')
        left_frame.pack(side='left', fill='both', expand=True, padx=(0, 10))

        # Container per le aree di chat
        chat_container = tk.Frame(left_frame, bg='#16213e', relief='raised', bd=2)
        chat_container.pack(fill='both', expand=True, pady=(0, 10))

        # Header dell'area messaggi
        self.chat_header = tk.Label(
            chat_container,
            text="📢 Chat Pubblica",
            font=self.subtitle_font,
            bg='#0f3460',
            fg='#00d4ff',
            pady=10
        )
        self.chat_header.pack(fill='x')

        # Area messaggi broadcast
        self.broadcast_display = scrolledtext.ScrolledText(
            chat_container,
            height=20,
            width=60,
            font=self.normal_font,
            bg='#0f3460',
            fg='#ffffff',
            insertbackground='#00d4ff',
            state='disabled',
            relief='flat',
            bd=0
        )
        self.broadcast_display.pack(fill='both', expand=True, padx=10, pady=(0, 10))

        # Area messaggi privati (inizialmente nascosta)
        self.private_display = scrolledtext.ScrolledText(
            chat_container,
            height=20,
            width=60,
            font=self.normal_font,
            bg='#2d1b2d',
            fg='#ffb3ff',
            insertbackground='#e74c3c',
            state='disabled',
            relief='flat',
            bd=0
        )

        # Frame per input messaggi
        message_frame = tk.Frame(left_frame, bg='#16213e', relief='raised', bd=2)
        message_frame.pack(fill='x', pady=(0, 10))

        # Header del frame messaggi
        input_header = tk.Label(
            message_frame,
            text="✍️ Scrivi un messaggio",
            font=self.subtitle_font,
            bg='#0f3460',
            fg='#00d4ff',
            pady=8
        )
        input_header.pack(fill='x')

        # Controlli per il messaggio
        controls_frame = tk.Frame(message_frame, bg='#16213e')
        controls_frame.pack(fill='x', padx=10, pady=10)

        # Dropdown per tipo messaggio
        tk.Label(
            controls_frame,
            text="Tipo:",
            font=self.normal_font,
            bg='#16213e',
            fg='#ffffff'
        ).pack(side='left', padx=(0, 5))

        self.message_type = tk.StringVar(value="Broadcast")
        type_combo = ttk.Combobox(
            controls_frame,
            textvariable=self.message_type,
            values=["Broadcast", "Privato"],
            state="readonly",
            width=12,
            font=self.normal_font
        )
        type_combo.pack(side='left', padx=(0, 10))
        type_combo.bind('<<ComboboxSelected>>', self.on_message_type_change)

        # Entry per destinatario (inizialmente nascosto)
        self.recipient_label = tk.Label(
            controls_frame,
            text="A:",
            font=self.normal_font,
            bg='#16213e',
            fg='#e74c3c'
        )

        self.recipient_entry = tk.Entry(
            controls_frame,
            font=self.normal_font,
            width=15,
            bg='#2d1b2d',
            fg='#ffb3ff',
            insertbackground='#e74c3c',
            relief='flat',
            bd=3
        )

        # Entry per messaggio
        msg_input_frame = tk.Frame(message_frame, bg='#16213e')
        msg_input_frame.pack(fill='x', padx=10, pady=(0, 10))

        self.message_entry = tk.Entry(
            msg_input_frame,
            font=self.normal_font,
            bg='#0f3460',
            fg='#ffffff',
            insertbackground='#00d4ff',
            relief='flat',
            bd=5
        )
        self.message_entry.pack(side='left', fill='x', expand=True, padx=(0, 10))
        self.message_entry.bind('<Return>', lambda e: self.send_message())

        # Pulsante invio
        send_button = tk.Button(
            msg_input_frame,
            text="📤 Invia",
            command=self.send_message,
            font=self.button_font,
            bg='#27ae60',
            fg='white',
            activebackground='#2ecc71',
            relief='flat',
            padx=20,
            pady=8,
            cursor='hand2'
        )
        send_button.pack(side='right')

        # Colonna destra - Utenti online
        right_frame = tk.Frame(main_frame, bg='#16213e', relief='raised', bd=2)
        right_frame.pack(side='right', fill='y', padx=(10, 0))

        # Header utenti
        users_header = tk.Label(
            right_frame,
            text="👥 Utenti Online",
            font=self.subtitle_font,
            bg='#0f3460',
            fg='#00d4ff',
            pady=10
        )
        users_header.pack(fill='x')

        # Lista utenti
        self.users_listbox = tk.Listbox(
            right_frame,
            height=20,
            width=25,
            font=self.normal_font,
            bg='#0f3460',
            fg='#ffffff',
            selectbackground='#00d4ff',
            selectforeground='#1a1a2e',
            relief='flat',
            bd=0
        )
        self.users_listbox.pack(fill='both', expand=True, padx=10, pady=(0, 10))
        self.users_listbox.bind('<Double-Button-1>', self.on_user_double_click)

        # Pulsante disconnessione
        self.disconnect_button = tk.Button(
            self.chat_frame,
            text="🔌 Disconnetti",
            command=self.disconnect_from_server,
            font=self.button_font,
            bg='#e74c3c',
            fg='white',
            activebackground='#ec7063',
            relief='flat',
            padx=30,
            pady=12,
            cursor='hand2'
        )
        self.disconnect_button.pack(pady=10)

    def switch_chat_view(self, view_type):
        """Cambia la vista tra chat pubblica e privata"""
        self.current_chat_view = view_type

        if view_type == "broadcast":
            # Mostra chat pubblica
            self.private_display.pack_forget()
            self.broadcast_display.pack(fill='both', expand=True, padx=10, pady=(0, 10))
            self.chat_header.config(text="📢 Chat Pubblica", fg='#00d4ff', bg='#0f3460')

            # Aggiorna stile pulsanti
            self.broadcast_btn.config(bg='#00d4ff', fg='#1a1a2e')
            self.private_btn.config(bg='#34495e', fg='#ffffff')

        else:
            # Mostra chat privata
            self.broadcast_display.pack_forget()
            self.private_display.pack(fill='both', expand=True, padx=10, pady=(0, 10))
            self.chat_header.config(text="🔒 Chat Privata", fg='#e74c3c', bg='#2d1b2d')

            # Aggiorna stile pulsanti
            self.private_btn.config(bg='#e74c3c', fg='white')
            self.broadcast_btn.config(bg='#34495e', fg='#ffffff')

    def on_message_type_change(self, event=None):
        """Gestisce il cambio del tipo di messaggio"""
        if self.message_type.get() == "Privato":
            self.recipient_label.pack(side='left', padx=(10, 5))
            self.recipient_entry.pack(side='left', padx=(0, 10))
            self.recipient_entry.delete(0, tk.END)
            # Cambia automaticamente alla vista privata
            self.switch_chat_view("private")
        else:
            self.recipient_label.pack_forget()
            self.recipient_entry.pack_forget()
            # Cambia automaticamente alla vista pubblica
            self.switch_chat_view("broadcast")

    def on_user_double_click(self, event=None):
        """Gestisce il double click su un utente per messaggio privato"""
        selection = self.users_listbox.curselection()
        if selection:
            username = self.users_listbox.get(selection[0])

            # Rimuovi l'icona e il testo "(tu)" per ottenere solo il nome utente
            username = username.replace("👤 ", "")  # Rimuovi l'icona
            username = username.replace(" (tu)", "")  # Rimuovi "(tu)"
            username = username.strip()  # Rimuovi spazi extra

        if username != self.username:
            self.message_type.set("Privato")
            self.on_message_type_change()
            self.recipient_entry.delete(0, tk.END)
            self.recipient_entry.insert(0, username)
            self.message_entry.focus()

    def update_user_list(self, users):
        """Aggiorna la lista degli utenti"""
        self.users_listbox.delete(0, tk.END)
        for user in users:
            if user == self.username:
                self.users_listbox.insert(tk.END, f"👤 {user} (tu)")
            else:
                self.users_listbox.insert(tk.END, f"👤 {user}")

    def connect_to_server(self):
        """Connette al server"""
        host = self.host_entry.get().strip()
        port = self.port_entry.get().strip()
        username = self.username_entry.get().strip()

        if not host or not port or not username:
            messagebox.showerror("Errore", "Compila tutti i campi!")
            return

        try:
            port = int(port)
        except ValueError:
            messagebox.showerror("Errore", "La porta deve essere un numero!")
            return

        if len(username) < 3 or len(username) > 20:
            messagebox.showerror("Errore", "L'username deve essere tra 3 e 20 caratteri!")
            return

        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((host, port))

            # Invia richiesta di join
            join_message = {
                'type': 'join',
                'username': username
            }
            self.send_to_server(join_message)

            self.username = username
            self.running = True

            # Avvia thread per ricevere messaggi
            self.receive_thread = threading.Thread(target=self.receive_messages)
            self.receive_thread.daemon = True
            self.receive_thread.start()

        except Exception as e:
            messagebox.showerror("Errore di Connessione", f"Impossibile connettersi al server:\n{e}")

    def receive_messages(self):
        """Riceve messaggi dal server"""
        while self.running:
            try:
                data = self.socket.recv(1024).decode('utf-8')
                if not data:
                    break

                message = json.loads(data)
                self.handle_server_message(message)

            except ConnectionResetError:
                self.display_message("❌ Connessione al server persa!", "system", "broadcast")
                break
            except json.JSONDecodeError:
                continue
            except Exception as e:
                self.display_message(f"❌ Errore: {e}", "system", "broadcast")
                break

        self.running = False
        self.connected = False

    def handle_server_message(self, message):
        """Gestisce i messaggi ricevuti dal server"""
        msg_type = message.get('type')

        if msg_type == 'join_success':
            self.connected = True
            self.show_chat_interface()
            self.display_message("✅ " + message.get('message', ''), "system", "broadcast")

        elif msg_type == 'join_error':
            messagebox.showerror("Errore", message.get('message', ''))
            self.disconnect_from_server()

        elif msg_type == 'broadcast_message':
            sender = message.get('sender', '')
            content = message.get('message', '')
            timestamp = message.get('timestamp', '')
            # I messaggi broadcast vanno SOLO nella chat pubblica
            self.display_message(f"[{timestamp}] {sender}: {content}", "broadcast", "broadcast")

        elif msg_type == 'private_message':
            sender = message.get('sender', '')
            content = message.get('message', '')
            timestamp = message.get('timestamp', '')
            # I messaggi privati vanno SOLO nella chat privata
            self.display_message(f"[{timestamp}] 💬 {sender}: {content}", "private", "private")

        elif msg_type == 'private_confirmation':
            recipient = message.get('recipient', '')
            content = message.get('message', '')
            timestamp = message.get('timestamp', '')
            # I messaggi inviati vanno SOLO nella chat privata
            self.display_message(f"[{timestamp}] ➤ A {recipient}: {content}", "sent", "private")

        elif msg_type == 'user_joined':
            username = message.get('username', '')
            timestamp = message.get('timestamp', '')
            self.display_message(f"[{timestamp}] ➕ {username} si è unito alla chat", "system", "broadcast")

        elif msg_type == 'user_left':
            username = message.get('username', '')
            timestamp = message.get('timestamp', '')
            self.display_message(f"[{timestamp}] ➖ {username} ha lasciato la chat", "system", "broadcast")

        elif msg_type == 'user_list':
            users = message.get('users', [])
            self.update_user_list(users)

        elif msg_type == 'error':
            self.display_message(f"❌ {message.get('message', '')}", "error", "broadcast")

    def display_message(self, message, msg_type="normal", chat_area="broadcast"):
        """Visualizza un messaggio nella chat appropriata"""
        # Seleziona l'area di chat corretta
        if chat_area == "private":
            display_widget = self.private_display
        else:
            display_widget = self.broadcast_display

        display_widget.config(state='normal')

        # Colori per diversi tipi di messaggio
        if chat_area == "private":
            colors = {
                "system": "#ff9999",
                "broadcast": "#ffb3ff",  # Non dovrebbe mai essere usato
                "private": "#ffb3ff",
                "sent": "#99ff99",
                "error": "#ff6666"
            }
        else:
            colors = {
                "system": "#ffcc66",
                "broadcast": "#ffffff",
                "private": "#ffffff",  # Non dovrebbe mai essere usato
                "sent": "#99ff99",
                "error": "#ff6666"
            }

        color = colors.get(msg_type, "#ffffff")

        # Inserisci il messaggio
        display_widget.insert(tk.END, message + "\n")

        # Scorri automaticamente in basso
        display_widget.see(tk.END)
        display_widget.config(state='disabled')

    def update_user_list(self, users):
        """Aggiorna la lista degli utenti"""
        self.users_listbox.delete(0, tk.END)
        for user in users:
            if user == self.username:
                self.users_listbox.insert(tk.END, f"👤 {user} (tu)")
            else:
                self.users_listbox.insert(tk.END, f"👤 {user}")

    def send_message(self):
        """Invia un messaggio"""
        if not self.connected:
            return

        content = self.message_entry.get().strip()
        if not content:
            return

        if self.message_type.get() == "Broadcast":
            message = {
                'type': 'message',
                'message': content
            }
        else:
            recipient = self.recipient_entry.get().strip()
            if not recipient:
                messagebox.showerror("Errore", "Specifica il destinatario!")
                return

            message = {
                'type': 'private_message',
                'recipient': recipient,
                'message': content
            }

        self.send_to_server(message)
        self.message_entry.delete(0, tk.END)

    def send_to_server(self, message):
        """Invia un messaggio al server"""
        try:
            message_json = json.dumps(message)
            self.socket.send(message_json.encode('utf-8'))
        except Exception as e:
            self.display_message(f"❌ Errore nell'invio: {e}", "error", "broadcast")

    def show_chat_interface(self):
        """Mostra l'interfaccia di chat"""
        self.connection_frame.pack_forget()
        self.chat_frame.pack(fill='both', expand=True)
        self.message_entry.focus()

    def show_connection_interface(self):
        """Mostra l'interfaccia di connessione"""
        self.chat_frame.pack_forget()
        self.connection_frame.pack(fill='both', expand=True, padx=30, pady=30)

    def disconnect_from_server(self):
        """Disconnette dal server"""
        self.running = False
        self.connected = False

        if self.socket:
            try:
                self.socket.close()
            except:
                pass
            self.socket = None

        self.show_connection_interface()

        # Pulisci entrambe le aree di chat
        self.broadcast_display.config(state='normal')
        self.broadcast_display.delete(1.0, tk.END)
        self.broadcast_display.config(state='disabled')

        self.private_display.config(state='normal')
        self.private_display.delete(1.0, tk.END)
        self.private_display.config(state='disabled')

        self.users_listbox.delete(0, tk.END)

    def on_closing(self):
        """Gestisce la chiusura dell'applicazione"""
        if self.connected:
            self.disconnect_from_server()
        self.root.destroy()

    def run(self):
        """Avvia l'applicazione"""
        self.root.mainloop()


if __name__ == "__main__":
    client = ChatClient()
    client.run()