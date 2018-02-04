main: main.c
	gcc -o run main.c

run: main
	./run

clean:
	rm -rf *.o
	rm -rf *.*~
	rm -rf *.ppm
	rm -rf *.jpg
	rm run