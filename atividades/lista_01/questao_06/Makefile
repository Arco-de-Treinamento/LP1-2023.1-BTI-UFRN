FILES = main.cpp ioFile.cpp
OBJECTS = main.o ioFile.o

all: clean compile link 	
	./listaMusicas

compile: $(FILES)
	g++ -c main.cpp ioFile.cpp

link: $(OBJECTS)
	g++ -o listaMusicas main.o ioFile.o
		
clean:
	rm -rf listaMusicas *.o
