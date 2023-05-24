FILES = main.cpp conta.cpp contaPoupanca.cpp contaCorrente.cpp cliente.cpp
OBJECTS = main.o conta.o contaPoupanca.o contaCorrente.o cliente.o

all: clean compile link 	
	./banco

compile: $(FILES)
	g++ -c $(FILES)

link: $(OBJECTS)
	g++ -o banco $(OBJECTS)
		
clean:
	rm -rf banco *.o
