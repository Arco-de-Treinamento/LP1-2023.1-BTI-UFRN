#include <iostream>
#include "conta.hpp"

using namespace std;

float Conta::getSaldo() {
    return this->saldoConta;
}

void Conta::setSaldo(float novoSaldo) {
    this->saldoConta = novoSaldo;
}