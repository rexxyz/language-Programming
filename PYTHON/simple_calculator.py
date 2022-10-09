# program for calculator
n = "y"
while (n == "y"):
    oper = input("Enter operation: \n1. +\n2. -\n3. *\n4. /\n ")
    number_1 = int(input("Enter your First number : "))
    number_2 = int(input("Enter your Second number : "))
    if oper == "+":
        output = number_1+number_2
        print(number_1, "+", number_2, "=", output)
    elif oper == "-":
        output = number_1-number_2
        print(number_1, "-", number_2, "=", output)
    elif oper == "*":
        output = number_1*number_2
        print(number_1, "*", number_2, "=", output)
    elif oper == "%":
        output = number_1 % number_2
        print(number_1, "%", number_2, "=", output)
    elif oper == "/":
        if number_2 == 0:
            print("Math Error")
        else:
            output = number_1/number_2
            print(number_1, "/", number_2, "=", output)
    n = input("\n1.Do you want to continue: press y \n2.Stop: press n\n ")
