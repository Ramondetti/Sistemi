import threading
import time
from random import randint

def thread_1_Prova(concorrente,punteggi_1_prova):
    print(f"Concorrente {concorrente} attende di iniziare la prima prova")
    with semaforo_prima_prova:
        print(f"Concorrente {concorrente} inizia la prima prova")
        t = randint(1,3)
        time.sleep(t)
        with lock:
            print(f"Concorrente {concorrente} termina la prima prova con il punteggio di {10-len(punteggi_1_prova)}")
            punteggi_1_prova[concorrente] = 10-len(punteggi_1_prova)

def thread_2_Prova(concorrente,punteggi_2_prova):
    print(f"Concorrente {concorrente} attende di iniziare la seconda prova")
    with semaforo_seconda_prova:
        print(f"Concorrente {concorrente} inizia la seconda prova")
        current_thread = threading.current_thread()
        current_thread.name = f"{concorrente}"
        t = randint(2,4)
        time.sleep(t)
        with lock:
            punteggio = randint(1,10)
            print(f"Concorrente {concorrente} termina la seconda prova con il punteggio di {punteggio}")
            punteggi_2_prova[concorrente] = punteggio

def thread_premiazione(concorrente):
    with semaforo_premiazione:
        print(f"Concorrente {concorrente} termina la gara con totale {punteggi_1_prova[concorrente] + punteggi_2_prova[concorrente]} punti")

threads = []
concorrenti = [f"C{i}" for i in range(10)]
punteggi_1_prova = {}
lock = threading.Lock()
semaforo_prima_prova = threading.Semaphore(7)

for c in concorrenti:
    th = threading.Thread(target=thread_1_Prova, args=(c,punteggi_1_prova))
    th.start()
    threads.append(th)

for th in threads:
    th.join()

punteggi_2_prova = {}
threads = []
semaforo_seconda_prova = threading.Semaphore(3)

for c in concorrenti:
    th = threading.Thread(target=thread_2_Prova, args=(c,punteggi_2_prova))
    th.start()
    threads.append(th)

for th in threads:
    th.join()

semaforo_premiazione = threading.Semaphore(1)
for c in concorrenti:
    th = threading.Thread(target=thread_premiazione, args=(c,))
    th.start()