#include "contaCorrente.hpp"
#include "contaPoupanca.hpp"
#include "cliente.hpp"
#include <iostream>

using namespace std;

int main() {
    Cliente cliente("João", "123456789", 1000.0, 2000.0);
 
    ContaPoupanca* contaPoupanca = cliente.getPoupanca();
    ContaCorrente* contaCorrente = cliente.getCorrente();

    cout << "Saldo Poupanca: " << contaPoupanca->getSaldo() << endl;
    cout << "Saldo Conta Corrente: " << contaCorrente->getSaldo() << endl;

    contaPoupanca->depositar(500.0);
    contaCorrente->depositar(1000.0);
    cout << "Saldo Poupanca: " << contaPoupanca->getSaldo() << endl;
    cout << "Saldo Conta Corrente: " << contaCorrente->getSaldo() << endl;


    contaPoupanca->sacar(200.0);
    contaCorrente->sacar(500.0);
    cout << "Saldo Poupanca: " << contaPoupanca->getSaldo() << endl;
    cout << "Saldo Conta Corrente: " << contaCorrente->getSaldo() << endl;

    return 0;
}

// Quanto ao uso da poupanca e da contaCorrete e contaPoupaca, infelizmente não entendi ao certo
// como poderia criar os objetos na heap. Cheguei a esse método de utilização apos 
// pesquisa em foruns e paginas.