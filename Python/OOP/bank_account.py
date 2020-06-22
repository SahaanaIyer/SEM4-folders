# Implement simple banking application

import random

class account:
      accno=1000+random.randint(1,999)
      def createAccount(self,name,bal,mob):
          self.name=name
          self.bal=bal
          self.mob=mob
          print("Account created successfully")
      def deposit(self,a):
          self.bal=self.bal + a
          print("Amount deposited successfully")
          print("The balance is",self.bal)
      def withdraw(self,a):
          self.bal=self.bal - a
          print("Amount deposited successfully")
          print("The balance is",self.bal)
      def computeInterest(self,month):
          si = self.bal*0.05*month
          self.bal += si
          return si
      def displayBalance(self):
          return self.bal

while True:
      print("1:Create account")
      print("2:Deposit")
      print("3:Withdraw")
      print("4:Compute interest")
      print("5:Display balance")
      print("6:exit")
      n=int(input("Enter your choice: "))
      if n==1:
           a = account()
           n = input("Enter the name:")
           bal = int(input("Enter the starting amount:"))
           m = int(input("Enter the mobile number:"))
           a.createAccount(n,bal,m)
           print()
      elif n==2:
           d = int(input("Enter the deposit amount:"))
           a.deposit(d)
           print()
      elif n==3:
           d = int(input("Enter the withdraw amount:"))
           a.withdraw(d)
           print()
      elif n==4:
           m = int(input("Enter the month: "))
           print("Interest is",a.computeInterest(m))
           print()
      elif n==5:
           print("BALANCE is",a.displayBalance())
           print()
      elif n==6:
           break