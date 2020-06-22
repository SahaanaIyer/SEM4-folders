#Solve quadratic equation

import math
print("Enter three numbers a,b,c")
a = int(input())
b = int(input())
c = int(input())
d = b*b - 4*a*c

if(d<0):
   print("Imaginary roots\n")
   x=-b/(2*a)
   y=math.sqrt(abs(d))/2*a
elif(d==0):
   print("Roots are real and equal\n")
   x=-b/(2*a)
   y=0
else:
   print("Roots are real and unequal\n")
   x=-b/2*a
   y=math.sqrt(d)/(2*a)
print("Roots are ",x,"+",y,"i and ",x,"-",y,"i")
