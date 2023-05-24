#include <iostream>
#include "cliente.hpp"

using namespace std;

Cliente::Cliente() {};

Cliente::Cliente(std::string nome, std::string cpf, float saldoPoupanca, float saldoConta) {
    this->nome = nome;
    this->cpf = cpf;
    this->poupanca = new ContaPoupanca();
    this->corrente = new ContaCorrente();
    poupanca->setSaldo(saldoPoupanca);
    corrente->setSaldo(saldoConta);
}

string Cliente::getNome() {
    return this->nome;
}

void Cliente::setNome(string nome) {
    this->nome = nome;
}

string Cliente::getCPF() {
    return this->cpf;
}

void Cliente::setCPF(string cpf) {
    cpf = cpf;
}

ContaPoupanca* Cliente::getPoupanca() {
    return poupanca;
}

ContaCorrente* Cliente::getCorrente() {
    return corrente;
}