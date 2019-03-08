# import socket

# s = socket.socket()
# print("Socket created")
# dnsTable = {'www.google.com':'92.424.6.1', 'www.apple.com':'123.45.56.78', 'www.abcd.com':'0.0.0.0'}

# port = 8090

# s.bind(('', port))
# print('socket binded to', port)

# s.listen(5)
# print('socket is now listening..')

# while True:
#     c, addr = s.accept()
#     print('got connection from', addr)
#     address = (c.recv(1024).decode('utf-8'))
#     print(address)
#     c.send(dnsTable[address].encode('utf-8'))
#     c.close()

import socket
import os, sys

a = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '127.0.0.1'
PORT = 5000
file = open('hello.txt', 'w')

try:
    a.bind((HOST, PORT))
    a.listen()
    conn, addr = a.accept()
    with conn:
        while True:
            data = conn.recv(1024).decode('utf-8')
            if not data:
                sys.exit()
            else:
                # print("Client: ", data)
                file.write(data)
            # string_to_send = str(input("You: "))
            # conn.send(string_to_send.encode('utf-8'))
except socket.error as err:
    print("Socket Error as", err)
finally:
    # a.close()