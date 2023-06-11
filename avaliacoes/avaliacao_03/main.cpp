#include <iostream>
#include "Empresa.hpp"

int main() {
    Data dataHoje;
    std::cout << "Digite a data de hoje (dia, mês, ano): ";
    std::cin >> dataHoje.dia >> dataHoje.mes >> dataHoje.ano;

    Empresa *atacadoDosCalcados = new Empresa("Atacado dos Calcados", "40.101.588/0001-98", 156289.56, dataHoje);
    atacadoDosCalcados->carregaFuncoes();

    // Deleta a empresa para liberar a memoria
    delete atacadoDosCalcados;
    return 0;
}
