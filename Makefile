build:
	gcc movies.c -o movies -std=c99 -Wall
clean:
	rm -rf movies
run1:
	./movies -c1 file.in file.out
run2:
	./movies -c2 file.in file.out
run3:
	./movies -c3 file.in file.out