test.exe:test.o
	gcc -o test.exe test.o
test.o:test.c
	gcc -c test.c
.PHONY:rebuild clean
rebuild:clean test.exe
clean:
	rm -rf test.exe test.o
