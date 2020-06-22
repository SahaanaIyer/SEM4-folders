#   Convert Decimal to Binary, Octal and Hexadecimal

def binary(n) :
   lis=[]
   while n>0 :
      lis.append(n%2)
      n=n/2
   print('{} in binary'.format(lis[::-1]))

def octal(n) :
   lis=[]
   while n>0 :
      lis.append(n%8)
      n=n/8
   print('{} in octal'.format(lis[::-1]))

def hexadec(n) :
   lis=[]
   while n>0 :
      lis.append(n%16)
      n=n/16
   print('{} in hexadecimal'.format(lis[::-1]))

dec=int(input('Enter a decimal number – '))
print('The decimal value {} is – '.format(dec))
binary(dec)
octal(dec)
hexadec(dec)
