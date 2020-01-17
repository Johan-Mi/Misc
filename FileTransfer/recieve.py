#!/usr/bin/env python3

import socket

port = input('Port to listen on (Blank for 65432): ')
if port:
    port = int(port)
else:
    port = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(('', port))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        size = conn.recv(1024).decode('utf8')
        size = size.rstrip('\0')
        size = int(size)
        content = conn.recv(size)

with open('recieved.txt', 'wb') as f:
    f.write(content)
print('Recieved file!')
