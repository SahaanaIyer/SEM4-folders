import socket

s = socket.socket()
s.connect('localhost', 9999)
while True:
    str = input("Enter message transfer in format: from to message. Enter -1 for no sending of message\n")
    if str != -1:
        s.send(str)
    data = s.recv(1024):
    if data is not None:
        print(data.decode("utf-8"))
s.close()
