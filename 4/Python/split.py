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


def split(lista,stringa):
    global val
    global cont
    global primaMetaLista
    global secondaMetaLista
    cont+=1
    n = int(len(lista) / 2)
    lista1 = lista[0:n]
    lista2 = lista[n:]
    if cont == 1:
        secondaMetaLista = lista2
    print("l1: ",lista1)
    print("l2: " ,lista2)
    if len(lista1) != 1:
        print("ok")
        split(lista1,"ok")
        print("diooooooooooo")
    elif len(lista2) != 1:
        val = lista1
    elif len(lista2) == 1:
        listaUnita = UnioneListeOrdinate(lista1,lista2)
        print("lista unita: " , listaUnita)
        listaUnita = UnioneListeOrdinate(listaUnita, val)
        print("lista unita: ", listaUnita)
        if(stringa == "ok"):
            primaMetaLista = listaUnita
        else:
            secondaMetaLista = listaUnita
        print("primaMetaLista: ",primaMetaLista)
        print("Lista finale: ", UnioneListeOrdinate(primaMetaLista,secondaMetaLista))
        return
        split(secondaMetaLista)

        return
    if len(lista2) !=1 :
        split(lista2,"ok")
    elif len(lista1) == 1:

        print(lista1)
        print(lista2)
        UnioneListeOrdinate(lista1,lista2)
primaMetaLista = []
secondaMetaLista = []
cont = 0
lista = [6, 5, 12, 10, 9, 1]
split(lista,"True")
