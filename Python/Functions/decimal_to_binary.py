#   Convert Decimal to Binary using Recursion

def binary(n) :
    if n==0 :
        return 0
    else :
        return (n%2)+(10*binary(n/2))

dec=int(input("Enter a decimal number – "))
print("The binary equivalent of {} is {}".format(dec,binary(dec)))

