#Count number of vowels and consonants from the given strings

print("Enter a string - ")
str = input().lower()
vcount=0
ccount=0
for i in str:
     if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u'):
           vcount=vcount+1
     else:
          ccount=ccount+1
print("Vowel count : ",vcount)
print("Consonant count : ",ccount)
