import socket

s = socket.socket()

dnsTable = {'www.google.com':'92.424.6.1', 'www.apple.com':'123.45.56.78', 'www.abcd.com':'0.0.0.0'}

port = 8090
s.connect(('127.0.0.1', port))

print('available options:\n1. www.google.com\n2. www.apple.com\n3.www.abcd.com\n')

blah=input("Enter the address:").encode('utf-8')
# blah = 'blah'
# print('---1')
s.send(blah)
# print('---2')
print(s.recv(1024).decode('utf-8'))

s.close()