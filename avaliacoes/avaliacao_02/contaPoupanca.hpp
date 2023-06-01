#ifndef CONTA_POUPANCA_HPP
#define CONTA_POUPANCA_HPP

#include <iostream>
#include "conta.hpp"

using namespace std;

class ContaPoupanca : public Conta {
    private:
        float taxaRendimento;

    public:
        ContaPoupanca();
        ContaPoupanca(float saldoConta, float taxaRendimento);
        void setTaxaRendimento(float novaTaxa);
        float getTaxaRendimento();
        void depositar(float valor);
        void sacar(float valor) override;
};

#endif
