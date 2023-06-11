#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Gerente : public Pessoa, public Funcionario {
    private:
        float participacaoLucros;

    public:
        Gerente();
        Gerente(std::string nome, std::string cpf, Data data, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data ingressoEmpresa, float participacaoLucros);

        float getParticipacaoLucros();
        void setParticipacaoLucros(float participacaoLucros);

        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
};

#endif
