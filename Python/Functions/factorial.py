#   Find Factorial of Number using Recursion

def fact(num) :
    if num==0 :
       return 1
    else :
       return num*fact(num-1)

n=int(input("Enter a number whose factorial is to be found – "))
print("The factorial {} is {}".format(n,fact(n)))
