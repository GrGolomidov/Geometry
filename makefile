all: bin/main

bin/main: build/main.o build/calculation.o bin
	g++ -Wall -Werror build/main.o build/calculation.o -o bin/main

build/main.o: src/main.cpp build
	g++ -Wall -Werror -c src/main.cpp -o build/main.o

build/calculation.o: src/calculation.cpp
	g++ -Wall -Werror -c src/calculation.cpp -o build/calculation.o

.PHONY : clean

bin:
	mkdir bin
build:
	mkdir build
clean:
	rm -rf build
	rm -rf bin
