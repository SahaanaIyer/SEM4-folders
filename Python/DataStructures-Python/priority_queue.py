class Node:
    def __init__(self, info, priority):
        self.info = info
        self.priority = priority

class PriorityQueue:
    def __init__(self):
        self.queue = list()

    def insert(self, node):
        if self.size() == 0:
            self.queue.append(node)
        else:
            for x in range(0, self.size()):
                if node.priority >= self.queue[x].priority:
                    if x == (self.size() - 1):
                        self.queue.insert(x + 1, node)
                    else:
                        continue
                else:
                    self.queue.insert(x, node)
                    return True

    def delete(self):
        if self.size() == 0:
            print("Empty")
        else:
             return self.queue.pop(0)

    def show(self):
        if self.size() == 0:
            print("Empty")
        else:
            for x in self.queue:
                 print(str(x.info) + " - " + str(x.priority))

    def size(self):
        return len(self.queue)

def main():
    Mypqueue= PriorityQueue()
    while(1):
        n = int(input("1.Insert 2.Delete 3.Display 4.Size 5.Exit\n"))
        if(n==1):
            print("Enter the name and priority to be inserted:\t")
            name = str(input())
            priority = int(input())
            node = Node(name, priority)
            Mypqueue.insert(node)
        elif(n==2):
            Mypqueue.delete()

        elif(n==3):
            Mypqueue.show()
        elif(n==4):
            x=Mypqueue.size()
            print("The size is ",x)
        else:
            return

if __name__ == '__main__':
    main()
