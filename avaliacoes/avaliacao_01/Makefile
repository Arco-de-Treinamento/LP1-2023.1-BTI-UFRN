FILES = main.cpp file.cpp gerente.cpp cliente.cpp
OBJECTS = main.o file.o gerente.o cliente.o

all: clean compile link 	
	./lanchonete

compile: $(FILES)
	g++ -c main.cpp file.cpp gerente.cpp cliente.cpp

link: $(OBJECTS)
	g++ -o lanchonete main.o file.o gerente.o cliente.o
		
clean:
	rm -rf lanchonete *.o
