#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"

using namespace std;

class Cliente{
    private:
        std::string nome;
        std::string cpf;
        ContaPoupanca* poupanca;
        ContaCorrente* corrente;

    public:
        Cliente();
        Cliente(std::string nome, std::string cpf, float saldoPoupanca, float saldoConta);
        std::string getNome();
        void setNome(std::string novoNome);
        std::string getCPF();
        void setCPF(std::string novoCPF);
        ContaPoupanca* getPoupanca();
        ContaCorrente* getCorrente();
};

#endif