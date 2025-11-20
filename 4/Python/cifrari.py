def cifrario_vigenere(text,chiave):
    new_str = ""
    cont = 0

    for i in text:
        if i >= "a" and i <= "z" or i >="A" and i <= "Z":
            diff = ord(chiave[cont].lower()) - ord("a")
            if i.islower():
                new_str+= chr((ord(i) - ord("a") + diff) % 26 + ord("a"))
            else:
                new_str+= chr((ord(i) - ord("A") + diff) % 26 + ord("A"))
            cont = (cont + 1) % len(chiave)
        elif i.isdigit():
            new_str+= chr(ord("a") + int(i))
        else:
            new_str+=i
    return new_str

def decifraio_vigenere(str_cifr, chiave):
    strDecifrata = ""
    cont = 0
    for i in str_cifr:
        if i >= "a" and i <= "z" or i >= "A" and i <= "Z":
            diff = ord(chiave[cont].lower()) - ord("a")
            if i.islower():
                strDecifrata += chr((ord(i) - ord('a') - diff + 26) % 26 + ord('a'))
            else:
                strDecifrata += chr((ord(i) - ord('A') - diff + 26) % 26 + ord('A'))
            cont = (cont + 1) % len(chiave)
        else:
            strDecifrata += i
    return strDecifrata



text = "hello world0"
chiave = "key"
print(cifrario_vigenere(text,chiave))
print(decifraio_vigenere(cifrario_vigenere(text,chiave),chiave))