#   Display Powers of 2 using Anonymous Function

terms = int(input('Enter the number of terms required – '))
result = list(map(lambda x: 2**x, range(terms)))
print('The total terms are : {}'.format(terms))
for i in range(terms):
   print('2 raised to power {} is {}'.format(i, result[i]))
