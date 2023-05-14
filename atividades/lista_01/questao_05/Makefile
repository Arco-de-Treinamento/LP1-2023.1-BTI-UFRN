FILES = main.cpp ioFile.cpp
OBJECTS = main.o ioFile.o

all: clean compile link 	
	./listaAlunos

compile: $(FILES)
	g++ -c main.cpp ioFile.cpp

link: $(OBJECTS)
	g++ -o listaAlunos main.o ioFile.o
		
clean:
	rm -rf listaAlunos *.o
