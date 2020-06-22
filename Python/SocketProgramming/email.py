import socket
import threading
import sys
import os
from queue import Queue
import time

s = socket.socket()
conn = []
add = []
q = Queue()

def bind():
    s.bind('localhost', 9999)
    print("Binding Successful")
    s.listen(3)

def accept():
    for i in conn:
        c.close()
    del conn[:]
    del add[:]
    while True:
        c, a = s.accept()
        s.setblocking(1)
        conn.append(c)
        add.append(a)
        print("Connection established. IP Address", a[0], "Port:", a[1])
        data = s.recv(1024)
        data = data.decode("utf-8")
        chat(data)

def chat(data):
    c = get(data)
    if c is not None:
        transfer(conn, data)

def get(data):
    t = int(data[0])
    c = conn[t]
    return c

def transfer(c, data):
    r = int(data[2])
    if conn[r] is not None:
        conn[r].send(data[5:] + " from " + data[2]).encode(' ')
    else:
        print("Recipent not connected")

def create_threads():
    t = threading.Thread(target=work())
    t.daemon(True)
    t.start()

def work():
    for i in 2:
        x = q.get()
        if x == 1:
            create()
            bind()
            accept()
        if x == 2:
            chat()
    q.task_done()

def create_jobs():
    for x in 2:
        q.put(x)
    q.join()

def main():
    create_threads()
    create_jobs()

if __name__ == "__main__":
    main()
