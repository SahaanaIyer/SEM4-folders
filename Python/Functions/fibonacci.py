#   Display Fibonacci Sequence using Recursion

def fib(num) :
    if num==0 :
       return 0
    elif num==1 :
       return 1
    else :
       return fib(num-1)+fib(num-2)

n=int(input("Enter the number of terms – "))
print("The fibonacci sequence is : ")
for i in range(n) :
    print(fib(i))
