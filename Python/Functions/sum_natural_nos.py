#   Find Sum of Natural Numbers using Recursion

def sum(num) :
    if num==0 :
       return num
    else :
       return num+sum(num-1)

n=int(input("Enter the nth number – "))
print("The sum of first {} natural numbers is {}".format(n,sum(n)))
