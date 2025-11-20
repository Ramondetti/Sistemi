def funzione1():
    global x #x viene usata come variabile globale, altrimenti usa x come variabile locale
    x=4

def funzione2():
    x=12 #x come variabile locale
    
x = 4
print(x)