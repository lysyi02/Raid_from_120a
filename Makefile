targets = main.bin
CC = clang
C_OPTS = -std=gnu11 -pedantic -g -Wall -I./src src/lib.c -lm
 
all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

