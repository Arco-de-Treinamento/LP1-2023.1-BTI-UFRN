FILES = main.cpp area.cpp
OBJECTS = main.o area.o

all: clean compile link 	
	./calcArea

compile: $(FILES)
	g++ -c main.cpp area.cpp

link: $(OBJECTS)
	g++ -o calcArea main.o area.o
		
clean:
	rm -rf calcArea *.o
