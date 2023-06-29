#include <iostream>
#include "ASG.hpp"

using namespace std;

ASG::ASG() {}

ASG::ASG(string nome, string cpf, Data data, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, float adicionalInsalubridade) : Pessoa(nome, cpf, data, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(salario, matricula, ingressoEmpresa) {
    this->adicionalInsalubridade = adicionalInsalubridade;
}

float ASG::getAdicionalInsalubridade() {return adicionalInsalubridade;}

void ASG::setAdicionalInsalubridade(float adicionalInsalubridade) {this->adicionalInsalubridade = adicionalInsalubridade;}


float ASG::calcularSalario(int diasFaltas) {
    // Considerando um mês com 30 dias
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30.0f) * diasFaltas);
    float insalubridade = salario * getAdicionalInsalubridade();

    // Adicional de R$100 por filho
    return salario + insalubridade + (getQtdFilhos() * 100.0f); 
}


float ASG::calcularRecisao(Data desligamento) {
    Data ing = getIngressoEmpresa();
    // Considerando apenas anos de 365 dias
    float tempoTrabalho = (desligamento.ano - ing.ano) + ((desligamento.mes - ing.mes) / 12.0f) + ((desligamento.dia - ing.dia) / 365.0f);

    return stof(getSalario()) * tempoTrabalho;
}
