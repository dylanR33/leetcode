main: main.o leetcode.o
	gcc main.o leetcode.o -o main
main.o: main.c
	gcc -c main.c
leetcode.o: leetcode.c leetcode.h
	gcc -c leetcode.c

clean:
	rm *.o
	rm main
