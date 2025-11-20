def elemDuplicati(lista):
    cont = 0
    for i in range(len(lista)-1):
        if(lista[i] == lista[i+1]):
            cont+=1
    return cont == 2

lista = [12,45,45,34,78,78,99]

if elemDuplicati(lista):
    print("Ci sono 2 elementi adiacenti")
else:
    print("Non ci sono elementi adiacenti")