''' Write a menu driven program in python which reads a number and implements the following methods: factorial(), reverse(), testArmstrong(), testPalindrome(), testPrime(), fibonacciSeries()'''

def factorial(num):
    if num == 0:
        return 1;
    else:
        return num * factorial(num - 1)

def reverse(num):
    n = num
    s = 0
    while n > 0:
        s = s * 10 + n % 10
        n = n // 10
    return s

def testArmstrong(num):
    s = 0
    n = num
    while n > 0:
        s = s + (n % 10) ** 3
        n = n // 10
    if s == num:
        print('{} is an Armstrong number'.format(num))
    else:
        print('{} is not an Armstrong number'.format(num))

def testPalindrome(num):
    if (reverse(num) == num):
        print('{} is a Palindrome'.format(num))
    else:
        print('{} is not a Palindrome'.format(num))

def testPrime(num):
    for i in range(2, num):
        if num % i == 0:
            print('{} is not a prime number'.format(num))
            return
    print('{} is a prime number'.format(num))

def fibonacciSeries(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    else:
        return fibonacciSeries(num - 1) + fibonacciSeries(num - 2)

while True:
    print('Enter the choice - ')
    choice = int(input('1:Factorial\t2:Reverse\t3:Armstrong\t4:Palindrome\t5:Prime\t6:Fibonacci\t7:Exit\n'))
    N = int(input('Enter the number - \n'))

    if choice == 1:
        print('Factorial of {} is {}'.format(N, factorial(N)))
    elif choice == 2:
        print('Reverse of {} is {}'.format(N, reverse(N)))
    elif choice == 3:
        testArmstrong(N)
    elif choice == 4:
        testPalindrome(N)
    elif choice == 5:
        testPrime(N)
    elif choice == 6:
        print("The {} terms are: ".format(N))
        for i in range(N):
            print(fibonacciSeries(i))
    else:
        print('Invalid Choice\n')
        break
