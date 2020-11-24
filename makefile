CFLAGS=-Os
PREFIX=/usr/local
dircount: dircount.c

clean:; rm -fv dircount

install: dircount
	@echo :: installing 'dircount' at $(PREFIX)/bin/dircount
	sudo install -m 755 dircount $(PREFIX)/bin/dircount

.PHONY: clean
.PHONY: install
