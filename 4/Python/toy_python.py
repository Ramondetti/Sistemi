def toy_1(lista1,lista2):
    nuovaLista = lista1[:]
    for elemLista2 in lista2:
        for elemLista1 in nuovaLista:
            if elemLista1 == elemLista2:
                lista1.remove(elemLista1)
    print(lista1)
    print(lista2)

def toy_2(x):
    x = str(x)
    x = int("".join(sorted(x,reverse=True)))
    return  x

def toy_3(a,b):
    somma = 0
    if a<b:
        for i in range(a,b+1):
            somma+=i
    elif a>b:
        for i in range(b,a+1):
            somma+=i
    else:
        somma = a
    return somma

def toy_4(lista1):
    listaNumeriPari = [x for x in lista1 if x%2 == 0]
    listaNumeriPari = sorted(listaNumeriPari,reverse=False)
    cont = 0
    for i in range(len(lista1)):
        if lista1[i] % 2 == 0:
            lista1[i] = listaNumeriPari[cont]
            cont+=1
    print(lista1)

def toy_5(testo):
    nuovaStringa = ""
    for char in testo:
        if 'a' <= char <= 'z':
            nuovaStringa += chr((ord(char) - ord('a') + 13) % 26 + ord('a'))
        elif 'A' <= char <= 'Z':
            nuovaStringa += chr((ord(char) - ord('A') + 13) % 26 + ord('A'))
        else:
            nuovaStringa += char
    print(nuovaStringa)

def toy_6(ip):
    bytes = ip.split(".")
    if len(bytes) != 4:
        return False
    else:
        for byte in bytes:
            if not byte.startswith("0"):
                if int(byte) > 0 and int(byte) <= 255:
                    continue
                else:
                    return False
            else:
                return False
        return True

def toy_9(a,b):
    return ",".join([str(i) for i in range(a,b) if i % 7 == 0 and i % 5 != 0 ])


def toy_10(a,b):
    diz = {}
    for i in range(a,b+1):
        diz[i] = i**2
    n = int(input("Inserisci un numero da cercare nel dizionario: "))
    vet = list(diz.values())
    dizKeys = list(diz.keys())
    print(dizKeys[vet.index(n)])

def toy_11(lista):
    tupla = [lista[i] for i in range(len(lista)-1) if lista[i] == lista[i+1]]
    return tuple(tupla)

a = [1, 2, 2, 2, 3]
b = [2]
#toy_1(a,b)

#print(toy_2(421459))

#print(toy_3(5,-1))

#toy_4([9, 8, 7, 6, 5 ,4 , 4, 3, 1])

#toy_5("cia#o!")

print(toy_9(100,200))

#toy_10(2,10)

lista = [1,12,12,3,43,13,3,13,45,45]
#print(toy_11(lista))

#if toy_6("255.200.180.12"):
    #print("L'ip è corretto") 
#else:
    #print("L'ip non è corretto")