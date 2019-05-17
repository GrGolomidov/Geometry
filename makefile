all: bin/geometry

	bin/geometry: build/src/main.o build/src/calculation.o
	g++ -Wall -Werror build/src/main.o build/src/calculation.o -o bin/geometry

	build/src/main.o: src/main.c
	g++ -Wall -Werror -c src/main.c -o build/src/main.o

	build/src/calculation.o: src/calculation.c
	g++ -Wall -Werror -c src/calculation.c -o build/src/calculation.o

.PHONY : clean

bin:
	mkdir bin
build:
	mkdir build
clean:
	rm -rf build
	rm -rf bin
