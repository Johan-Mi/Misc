#!/usr/bin/env python3
"""Crawls websites."""

import urllib.request
from bs4 import BeautifulSoup

visited = []

banned = ("facebook", "youtube", "twitter", ".pdf", ".exe", ".pptx", ".png",
          ".jpg", ".jpeg", ".docx", ".mp3", ".mp4")


def crawl(site):
    """Recursively crawls links on `site`."""
    try:
        visited.append(site)
        print(site)
        resp = urllib.request.urlopen(site)
        soup = BeautifulSoup(resp,
                             features="html.parser",
                             from_encoding=resp.info().get_param("charset"))

        for link in soup.find_all("a", href=True):
            url = link["href"]
            if url.startswith("http"):
                if url.startswith("https"):
                    url = "http" + url[5:]
                if url[-1] == "/":
                    url = url[:-1]
                if not any(n in url for n in banned):
                    if url not in visited:
                        crawl(url)
    except KeyboardInterrupt:
        raise
    except:
        pass


def main():
    """Asks the user for the first site to crawl, and then crawls said site."""
    first_site = input("First site: ")
    try:
        crawl(first_site)
    except:
        pass


if __name__ == "__main__":
    main()
