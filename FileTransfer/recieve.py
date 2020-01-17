#!/usr/bin/env python3

import socket
from requests import get

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
        with open('recieved.txt', 'wb') as f:
            data = conn.recv(1024)
            while data:
                f.write(data)
                data = conn.recv(1024)

print('Recieved file!')
