#!/usr/bin/env python3

import socket

filename = input('File name: ')
host = input('IP address of reciever (Blank for localhost): ')
if not host:
    host = '127.0.0.1'
port = input('Port of reciever (Blank for 65432): ')
if port:
    port = int(port)
else:
    port = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((host, port))
    with open(filename, 'rb') as f:
        data = f.read(1024)
        while data:
            s.send(data)
            data = f.read(1024)
