#ifndef CONTA_CORRENTE_HPP
#define CONTA_CORRENTE_HPP

#include <iostream>
#include "conta.hpp"

using namespace std;

class ContaCorrente : public Conta {
    private:
        float taxaSaque;

    public:
        ContaCorrente();
        ContaCorrente(float saldoConta, float taxaSaque);
        void setTaxaSaque(float novaTaxa);
        float getTaxaSaque();
        void depositar(float valor);
        void sacar(float valor);
};

#endif