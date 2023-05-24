
#include <iostream>
#include "contaPoupanca.hpp"

using namespace std;


ContaPoupanca::ContaPoupanca() {
    taxaRendimento = 0.05;
};

ContaPoupanca::ContaPoupanca(float saldoConta, float taxaRendimento) {
    this->saldoConta = saldoConta;
    this->taxaRendimento = taxaRendimento;
    taxaRendimento = 0.05;
}

void ContaPoupanca::setTaxaRendimento(float taxa) {
    this->taxaRendimento = taxa;
};

float ContaPoupanca::getTaxaRendimento() {
    return this->taxaRendimento;
};

void ContaPoupanca::depositar(float valor) {
    float bonificacao = valor + (valor * this->taxaRendimento);
    this->saldoConta += bonificacao;

    cout << "Deposito realizado!"<< endl;
};

void ContaPoupanca::sacar(float valor) {
    float saldoDisp = this->saldoConta;

    if (valor <= saldoDisp) {
        this->saldoConta -= valor;
        cout << "Saque realizado!" << endl;

    } else {
        cout << "Saldo insuficiente." << endl;
    }
};
