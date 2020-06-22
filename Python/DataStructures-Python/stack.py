class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None

    def isempty(self):
        if self.head == None:
            return True
        else:
            return False

    def push(self,data):
        if self.head == None:
            self.head=Node(data)
        else:
            newnode = Node(data)
            newnode.next = self.head
            self.head = newnode

    def pop(self):
        if self.isempty():
            return None
        else:
            poppednode = self.head
            self.head = self.head.next
            poppednode.next = None
            return poppednode.data

    def peek(self):
        if self.isempty():
            return None
        else:
            return self.head.data

    def display(self):
        iternode = self.head
        if self.isempty():
            print("Stack Underflow\n")
        else:
            while(iternode != None):
                print(iternode.data,",",end = " ")
                iternode = iternode.next
            return

def main():
    MyStack = Stack()
    while(1):
        n = int(input("1.Push 2.Pop 3.Display 4.Peek 5.isEmpty 6.Exit\n"))
        if(n==1):
            x=int(input("Enter the no to be pushed:\t"))
            MyStack.push(x)
        elif(n==2):
            x=MyStack.pop()
            print("Popped element is ",x)
        elif(n==3):
            MyStack.display()
        elif(n==4):
            x=MyStack.peek()
            print("The topmost element is ",x)
        elif(n==5):
            if(MyStack.isempty()):
                print("Empty")
            else:
                print("Not empty")
        else:
            return

if __name__ == '__main__':
    main()


