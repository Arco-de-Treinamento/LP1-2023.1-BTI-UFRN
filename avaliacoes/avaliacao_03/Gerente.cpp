#include <iostream>
#include "Gerente.hpp"

using namespace std;

Gerente::Gerente() {}

Gerente::Gerente(string nome, string cpf, Data data, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, float participacaoLucros) : Pessoa(nome, cpf, data, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(salario, matricula, ingressoEmpresa) {
    this->participacaoLucros = participacaoLucros;
}

float Gerente::getParticipacaoLucros() { return participacaoLucros;}

void Gerente::setParticipacaoLucros(float participacaoLucros) {this->participacaoLucros = participacaoLucros;}

float Gerente::calcularSalario(int diasFaltas) {
    // Considerando um mês com 30 dias
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30.0f) * diasFaltas);

    // Adicional de R$100 por filho
    return salario + getParticipacaoLucros() + (getQtdFilhos() * 100.0f); 
}

float Gerente::calcularRecisao(Data desligamento) {
    Data ing = getIngressoEmpresa();
    // Considerando apenas anos de 365 dias
    float tempoTrabalho = (desligamento.ano - ing.ano) + ((desligamento.mes - ing.mes) / 12.0f) + ((desligamento.dia - ing.dia) / 365.0f);

    return stof(getSalario()) * tempoTrabalho;
}
