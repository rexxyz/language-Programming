print("Type '+', '-', '*', '/' for the operation to be used")
operation = input("What kind of operation you want to solve? ")


firstNumber = int(input("Enter your first number: "))
secondNumber = int(input("Enter your second number: "))

def calculator():
    if (operation == "+"):
        add(firstNumber, secondNumber)
    elif (operation == "-"):
        subtract(firstNumber, secondNumber)
    elif (operation == "*"):
        multiply(firstNumber, secondNumber)
    elif (operation == "/"):
        divide(firstNumber, secondNumber)
    else:
        print("Please enter correct operation to be used")


def add(a, b):
    addition = a + b
    print(addition)

def subtract(a, b):
    minus = a - b
    print(minus)

def multiply(a, b):
    multiplication = a * b
    print(multiplication)

def divide(a, b):
    division = a / b
    print(division)

calculator()

