/**
 * @file main.cpp
 * @brief Função main do projeto de gestão.
 * 
 * Esse projeto consiste na criação de um sistema para gerenciamento de funcionários da empresa Atacadão dos Calçados. Sua função é gerir toda a parte financeira da empresa com base nos dados enviados através de arquivos.
 *
 * @author José Manoel Freitas da Silva
 * @date 01 de julho de 2023
 */

#include <iostream>
#include <vector>
#include "./hpps/empresa.hpp"

/**
 * @brief Função principal do aplicativo.
 * @return Inicialização do programa.
 */
int main(){
  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
  return 0;
}

