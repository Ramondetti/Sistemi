def alternaListe(lista1,lista2):
    nuovaLista = []
    for i in range(len(lista1)):
        nuovaLista.append(lista1[i])
        nuovaLista.append(lista2[i])
    return nuovaLista

lista1 =  [1,3,5]
lista2 = [2,4,6]

print(alternaListe(lista1,lista2))