#include <iostream>
#include "Vendedor.hpp"

using namespace std;

Vendedor::Vendedor() {}

Vendedor::Vendedor(string nome, string cpf, Data data, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos, string salario, string matricula, Data ingressoEmpresa, char tipoVendedor) : Pessoa(nome, cpf, data, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(salario, matricula, ingressoEmpresa) {
    this->tipoVendedor = tipoVendedor;
}

char Vendedor::getTipoVendedor() { return tipoVendedor;}

void Vendedor::setTipoVendedor(char tipoVendedor) { this->tipoVendedor = tipoVendedor;}


float Vendedor::calcularSalario(int diasFaltas) {
    // Considerando um mês com 30 dias
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30.0f) * diasFaltas);
    float gratificacao;
    
    // Calculando a gratificação
    switch (getTipoVendedor()) {
        case 'A':
            gratificacao = stof(getSalario()) * 0.25f;
            break;
        case 'B':
            gratificacao = stof(getSalario()) * 0.10f;
            break;
        case 'C':
            gratificacao = stof(getSalario()) * 0.05f;
            break;
        default:
            gratificacao = 0.0f;
            break;
    }

    // Adicional de R$100 por filho
    return salario + gratificacao + (getQtdFilhos() * 100.0f); 
}

float Vendedor::calcularRecisao(Data desligamento) {
    Data ing = getIngressoEmpresa();
    // Considerando apenas anos de 365 dias
    float tempoTrabalho = (desligamento.ano - ing.ano) + ((desligamento.mes - ing.mes) / 12.0f) + ((desligamento.dia - ing.dia) / 365.0f);

    return stof(getSalario()) * tempoTrabalho;
}
