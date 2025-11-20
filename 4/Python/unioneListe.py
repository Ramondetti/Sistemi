def UnioneListeOrdinate(lista1, lista2):
    listaUnita = []
    i, j = 0, 0 

    while i < len(lista1) and j < len(lista2):
        if lista1[i] < lista2[j]:
            listaUnita.append(lista1[i])
            i += 1
        else:
            listaUnita.append(lista2[j])
            j += 1

    while i < len(lista1):
        listaUnita.append(lista1[i])
        i += 1

    while j < len(lista2):
        listaUnita.append(lista2[j])
        j += 1

    return listaUnita

lista1 = [2, 3, 5, 6, 7, 9]
lista2 = [1, 4, 5, 8, 10, 15, 22]

print(f"Unione liste: {UnioneListeOrdinate(lista1, lista2)}")