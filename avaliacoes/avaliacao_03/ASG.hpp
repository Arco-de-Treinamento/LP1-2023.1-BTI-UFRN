#ifndef ASG_HPP
#define ASG_HPP

#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

class ASG : public Pessoa, public Funcionario {
    private:
        float adicionalInsalubridade;

    public:
        ASG();
        ASG(std::string nome, std::string cpf, Data data, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data ingressoEmpresa, float adicionalInsalubridade);

        float getAdicionalInsalubridade();
        void setAdicionalInsalubridade(float adicionalInsalubridade);

        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
    };

#endif
