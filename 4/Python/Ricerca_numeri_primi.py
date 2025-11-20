import math
def multipli(numero,n):
    return [numero * i for i in range(2, (n // numero) + 1)]

def numeriPrimi(n):
    lista = [x for x in range(1, n+1)]
    for i in range(2,int(math.sqrt(n)) + 1):
        multipli_i = multipli(i, n)
        lista = [x for x in lista if x not in multipli_i]
    return lista

numero = int(input("Inserisci un numero: "))
primi = numeriPrimi(numero)
print(primi)