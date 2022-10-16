a=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
,"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
def cipher(message, shift,command):
    end_text=""
    if command=='decode':
        shift *= -1
    for char in message:
        if char in a:
           position=a.index(char)
           new_position=position+shift
           end_text+=a[new_position]
        else:
            end_text+=char
    print(end_text)
from art import logo
print(logo)
is_encrypting=True
while is_encrypting:
    command=input("Type 'encode' to encrypt and 'decode' to decrypt: \n").lower()
    if command=='encode' or command=='decode':
        message=input("Type ypur message: \n").lower()
        shift=int(input("Enter the shift value: \n"))
        shift=shift%25
        cipher(message,shift,command)
    else:
        print("wrong input")
    result=input("type 'yes' for encoding more and 'no' for closing the programme\n")
    if result=="no":
        is_encrypting=False
        print("Thanks for using this software")
