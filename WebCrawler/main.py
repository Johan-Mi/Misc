#!/usr/bin/env python3

from bs4 import BeautifulSoup
import urllib.request
import sys

visited = []

banned = ('facebook', 'youtube', 'twitter', '.pdf', '.exe', '.pptx', '.png', '.jpg', '.jpeg', '.docx', '.mp3', '.mp4')

def crawl(site):
	try:
		visited.append(site)
		print(site)
		resp = urllib.request.urlopen(site)
		soup = BeautifulSoup(resp, features='html.parser', from_encoding=resp.info().get_param('charset'))

		for link in soup.find_all('a', href=True):
			url = link['href']
			if url.startswith('http'):
				if url.startswith('https'):
					url = 'http' + url[5:]
				if url[-1] == '/':
					url = url[:-1]
				if not any(n in url for n in banned):
					if url not in visited:
						crawl(url)
	except KeyboardInterrupt as e:
		raise e
	except:
		pass

firstSite = input('First site: ')
try:
	crawl(firstSite)
except:
	pass
