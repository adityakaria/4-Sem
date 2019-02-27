import socket

s = socket.socket()
print("Socket created")
dnsTable = {'www.google.com':'92.424.6.1', 'www.apple.com':'123.45.56.78', 'www.abcd.com':'0.0.0.0'}

port = 8090

s.bind(('', port))
print('socket binded to', port)

s.listen(5)
print('socket is now listening..')

while True:
    c, addr = s.accept()
    print('got connection from', addr)
    address = (c.recv(1024).decode('utf-8'))
    print(address)
    c.send(dnsTable[address].encode('utf-8'))
    c.close()