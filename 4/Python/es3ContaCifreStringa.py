def contaCifreStringa(str):
    cont = 0
    for i in str:
        if i.isdigit():
            cont+=1
    return cont


stringa = "1ciao1"

print("Numero di cifre: ",contaCifreStringa(stringa))