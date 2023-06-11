#include <iostream>
#include "Funcionario.hpp"

using namespace std;

Funcionario::Funcionario() {}

Funcionario::Funcionario(string salario, string matricula, Data ingressoEmpresa) {
    this->salario = salario;
    this->matricula = matricula;
    this->ingressoEmpresa = ingressoEmpresa;
}

string Funcionario::getSalario() { return salario;}
string Funcionario::getMatricula() {return matricula;}
Data Funcionario::getIngressoEmpresa() {return ingressoEmpresa;}

void Funcionario::setSalario(string salario) { this->salario = salario;}
void Funcionario::setMatricula(string matricula) {this->matricula = matricula;}
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa) {this->ingressoEmpresa = ingressoEmpresa;}
