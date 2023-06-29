#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario {
    private:
        char tipoVendedor;

    public:
        Vendedor();
        Vendedor(std::string nome, std::string cpf, Data data, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor);

        char getTipoVendedor();
        void setTipoVendedor(char tipoVendedor);

        float calcularSalario(int diasFaltas) override;
        float calcularRecisao(Data desligamento) override;
};

#endif
