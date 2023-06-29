#include <iostream>
#include "contaCorrente.hpp"

using namespace std;


ContaCorrente::ContaCorrente() {taxaSaque = 0.05;};

ContaCorrente::ContaCorrente(float saldoConta, float taxaSaque) {
    this->saldoConta = saldoConta;
    this->taxaSaque = taxaSaque;
    taxaSaque = 0.05;
};

void ContaCorrente::setTaxaSaque(float taxa) {
    this->taxaSaque = taxa;
};

float ContaCorrente::getTaxaSaque() {
    return this->taxaSaque;
};

void ContaCorrente::depositar(float valor) {
    this->saldoConta += valor;
};

void ContaCorrente::sacar(float valor) {
    float saldoDisponivel = this->saldoConta - (this->saldoConta * this->taxaSaque);

    if (valor <= saldoDisponivel) {
        this->saldoConta -= valor;

        cout << "Saque realizado!" << endl;

    } else {
        cout << "Saldo insuficiente" << endl;
    }
};