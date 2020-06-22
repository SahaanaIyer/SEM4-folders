#   Make a Simple Calculator

def add(a,b) :
   return a+b

def sub(a,b) :
   return a-b

def mul(a,b) :
   return a*b

def div(a,b) :
   return a/b

print("Enter a choice - \n")
op = int(input("1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n"))

n1 = int(input("Enter your first number: "))
n2 = int(input("Enter your second number: "))

if op==1 :
    n=add(n1,n2)
    print("{} + {} = {}".format(n1, n2, n))

elif op==2 :
    n=sub(n1,n2)
    print("{} - {} = {}".format(n1, n2, n))

elif op==3 :
    n=mul(n1,n2)
    print("{} * {} = {}".format(n1, n2, n))

elif op==4 :
    n=div(n1,n2)
    print("{} / {} = {}".format(n1, n2, n))

else :
    print("Invalid Operator\n")
