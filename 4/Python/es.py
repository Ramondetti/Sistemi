def divisione(a,b):
    while b != 0:
        a,b = b,a%b
    return a
print(divisione(12,6))