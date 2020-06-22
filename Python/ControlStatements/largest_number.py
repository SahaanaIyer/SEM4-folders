#Find the largest among three numbers

print("Enter three nos. a,b,c -")
a = int(input())
b = int(input())
c = int(input())
if(a>b):
    if(a>c):
        print("a is largest")
    else:
        print("c is largest")
else:
    if(b>c):
        print("b is largest")
    else:
        print("c is largest")
