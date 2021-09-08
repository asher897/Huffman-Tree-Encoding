#SHRAAR001 Makefile for Assignment Three CSC3022F

CC = g++ -c -o
linker = g++ -o
rm = rm -f

huffencode: driver.o node.o huffman.o
		$(linker) huffencode driver.o node.o huffman.o -std=c++11

tests: unit_tests.o
		$(linker) tests unit_tests.o node.o huffman.o -std=c++11

driver.o: driver.cpp
		$(CC) driver.o driver.cpp -std=c++11

node.o: node.cpp
		$(CC) node.o node.cpp -std=c++11

huffman.o: huffman.cpp
		$(CC) huffman.o huffman.cpp -std=c++11

unit_tests.o: unit_tests.cpp
		$(CC) unit_tests.o unit_tests.cpp -std=c++11

run: huffencode
		./huffencode

default: huffencode

clean:
		$(rm) driver.o huffman.o node.o huffencode
