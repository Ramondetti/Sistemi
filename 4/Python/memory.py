#import random
from random import shuffle,randint #importo solo la funzione shuffle e randint

def aggiornaVettorePosizioni():
    for i in range(0, len(memory)):
        posNum.append(i)

memory = [1,1,2,2,3,3,4,4,5,5,6, 6, 7, 7, 8, 8, 9, 9]
posNum = []
aggiornaVettorePosizioni()



random.shuffle(memory)

vinto = False

while vinto == False:
    if len(memory) == 0:
        print("Hai vinto")
        vinto = True
    else:
        print("Posizioni: ", posNum)
        pos1 = input("Inserisci la prima posizione: ")
        while not pos1.isdigit() or int(pos1) >= len(memory):
            pos1 = input("Inserisci la prima posizione: ")
        pos1 = int(pos1)
        print("Numero nella posizione inserita: ", memory[pos1])
        pos2 = input("Inserisci la seconda posizione: ")
        while not pos2.isdigit() or int(pos2) >= len(memory):
            pos2 = input("Inserisci la seconda posizione: ")
        pos2 = int(pos2)
        print("Numero nella posizione inserita: ", memory[pos2])
        print()
        if memory[pos1] == memory[pos2] and pos1 != pos2:
            print("Hai trovato una coppia")
            numero = memory[pos1]
            memory.pop(pos1)
            memory.remove(numero)
            aggiornaVettorePosizioni()
