l1=[]
print("Enter the number of items:\t")
n = int(input())
for i in range(0,n):
    x = int(input())
    l1.append(x)
print(l1)
for i in range(0,n):
    for j in range(0,n-1):
        if l1[j+1] < l1[j] :
            l1[j], l1[j+1] = l1[j+1], l1[j]
print(l1)
