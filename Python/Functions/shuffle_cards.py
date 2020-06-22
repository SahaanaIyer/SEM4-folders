#   Shuffle deck of cards

import itertools, random

l1=['Heart', 'Club', 'Spade', 'Diamond']
l2=[1,2,3,4,5,6,7,8,9,10,11,12,13]

deck = (list(itertools.product(l1, l2)))
random.shuffle(deck)

n=int(input("Enter the number of products required – "))
for i in range(0,n):
   j=0
   print(deck[i][j],deck[i][j+1])

