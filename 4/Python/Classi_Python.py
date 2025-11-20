class Dado:
    colore = "giallo"
    def lancia(self): #self: this
        print("sono, ",self.colore)

#in C#: Dado My_dado = new Dado()

#in Python:
my_dado = Dado()
my_dado.colore = "Verde"

print(my_dado.lancia())

