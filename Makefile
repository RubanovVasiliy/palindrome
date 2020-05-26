FLAGS = -Wall -Werror

all: bin build bin/p

bin/p: build/src/main.o 
	gcc $(flags) build/src/main.o -o bin/p

build/src/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/src/main.o

bin:
	mkdir -p bin

build:
	mkdir -p build/src

run: all
	./bin/p

.PHONY: clean

clean:
	rm -rf build bin