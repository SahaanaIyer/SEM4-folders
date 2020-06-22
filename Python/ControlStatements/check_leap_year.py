#Check leap year

print("Enter a year - ")
Y = int(input())
if(Y%4==0 and Y%100!=0 or Y%400==0):
   print("Leap Year")
else:
   print("Not a Leap Year")
