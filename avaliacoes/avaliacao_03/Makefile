FILES = main.cpp ASG.cpp Empresa.cpp Funcionario.cpp Gerente.cpp Pessoa.cpp Vendedor.cpp
OBJECTS = $(FILES:.cpp=.o)

# Nome do executável
EXECUTABLE = empresa

FLAGS = -std=c++11 -Wall -g

all: clean compile link
	./$(EXECUTABLE)

compile: $(FILES)
	g++ $(FLAGS) -c $(FILES)

link: $(OBJECTS)
	g++ $(FLAGS) -o $(EXECUTABLE) $(OBJECTS)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)