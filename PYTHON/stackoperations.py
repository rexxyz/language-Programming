#Stack operations in python

arr = []
ch = 0
while ch != 5:
    ch = int(input("1. Peek\n2. Push\n3. Pop\n4. Display\n5. Exit\n"))
    if ch == 1:
        if arr == []:
            print("No array elements")
        else:
            print(arr[-1])
    elif ch == 2:
        elem = int(input("Enter the number to be pushed: "))
        arr.append(elem)
    elif ch == 3:
        if arr == []:
            print("No elements in the array")
        else:
            elem = arr[-1]
            print(elem,"is popped")
    elif ch == 4:
        if arr == []:
            print("No elements in the array")
        else:
            print(arr)