#Exception Handling in Python:
import sys
i=1
while i<=7:
    print ("1.Zero division error (Note: put value of b as 0)")
    print ("2.Value error (Note: put two different data type as values  of a and b )")
    print ("3.Name error")
    print ("4.Type error")
    print ("5.Assertion error")
    print ("6.Keyboard Interrupt error(Note: to check this error enter any key )")
    print ("7.System exit")
    n=int(input("Enter the numbers from 1 to 7 to check the respective exception: \t"))
    if n==1:
        try:
            a=int(input("Enter the value of a "))
            b=int(input("Enter the value of b "))
            c=a/b
        except ZeroDivisionError:
            print("Number divisible by zero exception occurs")
        else:
            print("division is",c)
    elif n==2:
        try:
            a=int(input("Enter the value of a "))
            b=int(input("Enter value of b "))
            c=a/b
        except ValueError:
            print("Value error occurs; division of two dissimilar data types is not allowed ")
        else:
            print("division is ",c)
    elif n==3:
        try:
            a=int(input("Enter value of a "))
            b=int(input("Enter the value of b "))
            c=k/b
        except NameError:
            print("Name error occurs: k is not defined ")
    elif n==4:
        try:
            r='6'+7
        except TypeError:
            print("Type error occurs; provide a valid data type ")
    elif n==5:
        try:
            n=int(input("Enter numbers from 2 to 3 "))
            assert(n>=2 and n<=3)
            print("The entered number is ",n)
        except AssertionError:
            print("Assertion error takes place; enter a valid number")
    elif n==6:
        try:
            print("\n xyz")
        except KeyboardInterruptError:
            print("Keyboard interrupt error takes place; ")
    elif n==7:
        try:
            print("\n Example of system exit ")
            sys.exit()
        except SystemExit:
            print("User has tried to exit the python interpreter")
    else:
        print("Exit program")
        exit()
    i=i+1