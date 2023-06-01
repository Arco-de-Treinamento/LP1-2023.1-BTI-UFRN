#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>

using namespace std;

class Conta{
    protected:
        float saldoConta;

    public:
        float getSaldo();
        void setSaldo(float novoSaldo);
        virtual void depositar(float valor) = 0;
        virtual void sacar(float valor) = 0;
};

#endif