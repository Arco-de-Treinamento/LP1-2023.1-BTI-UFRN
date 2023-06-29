#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

struct Endereco {
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
};

struct Data {
    int ano;
    int mes;
    int dia;
};

#endif 
