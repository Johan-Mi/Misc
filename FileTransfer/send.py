#!/usr/bin/env python3

import socket

filename = input('File name: ')
host = input('IP address of reciever (Blank for localhost): ')
if not host:
    host = '127.0.0.1'
port = input('Port of reciever (Blank for 65432): ')
if not port:
    port = 65432

with open(filename, 'rb') as f:
    content = f.read()
size = len(content)
encodedSize = str(size).encode('utf8')
encodedSize = b''.join([encodedSize, bytes(1024 - len(encodedSize))])

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((host, port))
    s.sendall(encodedSize)
    s.sendall(content)
