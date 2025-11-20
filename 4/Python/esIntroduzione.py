x = 5
y = 7.4
print(x*y)
#fsafd    python non compila ma esegue riga per riga
print(x+y)

#for i in range(0, 10): #range crea una lista: x = [0,1,2,3,4,5,6,7,8,9]
    #print(i)

#for i in [0,5,9]: #i conterra gli elementi della lista tipo for of
    #print(i)

for i in [0, 5, 6, 9]: #stampa anche i*2 percè è indentato
    if 3 < i < 12:
        print(i, "Il doppio vale:", sep=" ", end=" ") #end: mette un carattere alla fine della riga
        # sep: sepratore tra più variabili
        print(i*2)
st = 'un\' "parolaccia"'
print(st)
#quando indento gli dico che lo scope è finito, c'è la graffa di chiusura

for i in range(0, 8):
    print(i*"*")
print("*")
print("*")

cont = 0
for i in range(1, 17):
    if i <= 7:
        print('*' * i)
    elif i == 8:
        print('*')
        print('*')
    else:
        print('*' * (16 - i))