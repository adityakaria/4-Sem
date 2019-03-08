# import socket

# s = socket.socket()

# dnsTable = {'www.google.com':'92.424.6.1', 'www.apple.com':'123.45.56.78', 'www.abcd.com':'0.0.0.0'}

# port = 8090
# s.connect(('127.0.0.1', port))

# print('available options:\n1. www.google.com\n2. www.apple.com\n3.www.abcd.com\n')

# blah=input("Enter the address:").encode('utf-8')
# # blah = 'blah'
# # print('---1')
# s.send(blah)
# # print('---2')
# print(s.recv(1024).decode('utf-8'))

# s.close()

import socket
import os, sys

HOST = '127.0.0.1'
PORT = 5000

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect((HOST, PORT))
    while True:
        string_to_send = str(input("You: "))
        s.sendall(string_to_send.encode('utf-8'))
        # data = s.recv(1024).decode('utf-8')
        # if not data:
            # sys.exit()
        # print("Server: ", data)
except socket.error as err:
    print("Socket Error as", err)
finally:
    a.close()

