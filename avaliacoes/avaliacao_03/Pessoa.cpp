#include <iostream>
#include "Pessoa.hpp"

using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome,  string cpf,  Data data, Endereco enderecoPessoal,  string estadoCivil, int qtdFilhos) {
    this->nome = nome;
    this->cpf = cpf;
    this->data = data;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
}

string Pessoa::getNome(){return nome;}
string Pessoa::getCpf(){return cpf;}
Data Pessoa::getData(){return data;}
Endereco Pessoa::getEnderecoPessoal(){return enderecoPessoal;}
string Pessoa::getEstadoCivil(){return estadoCivil;}
int Pessoa::getQtdFilhos(){return qtdFilhos;}

void Pessoa::setNome(string nome){this->nome = nome;}
void Pessoa::setCpf(string cpf){this->cpf = cpf;}
void Pessoa::setData(Data data){this->data = data;}
void Pessoa::setEnderecoPessoal(Endereco endereco){this->enderecoPessoal = endereco;}
void Pessoa::setEstadoCivil(string estadoCivil){this->estadoCivil = estadoCivil;}
void Pessoa::setQtdFilhos(int qtdFilhos){this->qtdFilhos = qtdFilhos;}
