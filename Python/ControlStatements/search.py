b=input("Enter the elements -\n")
a=b.split()
key=int(input("Enter the element to be searched - \n"))
l=0
h=len(a)-1
flag=0
while l<h:
	m=(l+h)//2
	if key==int(a[m]):
		print(key,"is found at",m)
		flag=1
		break
	else:
		if key<int(a[m]):
			h=m-1
		else:
			l=m+1
if flag==0:
	print(key,"not found\n")
