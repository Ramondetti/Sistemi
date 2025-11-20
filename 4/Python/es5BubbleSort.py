def swap(j):
	temp = lista[j]
	lista[j] = lista[j+1]
	lista[j+1] = temp
	
    
lista = [6, 2, 4, 7, 5, 1, 9, 3, 15, 22]


for i in range(len(lista)-1):
	for j in range(len(lista)-i-1):
		if lista[j] > lista[j+1]:
			swap(j)
				
print(lista)