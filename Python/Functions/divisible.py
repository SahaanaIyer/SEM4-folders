#   Find Numbers Divisible by another Number

lis=[]                # Creating an empty list
n=int(input('Enter number of elements in the list : '))
print('Enter the elements : ')
for i in range(0, n) :
     a = int(input())
     lis.append(a)
print('The entered list is : {}'.format(lis))

num=int(input('Enter the number to divide by – '))

result = list(filter(lambda x: (x%num==0), lis))
print('Numbers divisible by {} are {}'.format(num, result))

