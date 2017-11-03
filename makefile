all: dirinfo.c
	gcc dirinfo.c

clean:
	rm -f a.out

run: all
	./a.out
