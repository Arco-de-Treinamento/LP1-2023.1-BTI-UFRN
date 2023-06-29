#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Pessoa.hpp"
#include "ASG.hpp"
#include "Vendedor.hpp"
#include "Gerente.hpp"
#include "util.hpp"

class Empresa {
    private:
        float faturamentoMensal;
        std::string nomeEmpresa;
        std::string cnpj;
        Pessoa dono;
        std::vector<ASG> ASGs;
        std::vector<Vendedor> vendedores;
        std::vector<Gerente> gerentes;
        Data hoje;

    public:
        Empresa();
        Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal, Data hoje);

        float getFaturamentoMensal();
        std::string getNomeEmpresa();
        std::string getCnpj();
        Pessoa getDono();
        std::vector<ASG> getASGs();
        std::vector<Vendedor> getVendedores();
        std::vector<Gerente> getGerentes();

        void setFaturamentoMensal(float faturamentoMensal);
        void setNomeEmpresa(std::string nomeEmpresa);
        void setCnpj(std::string cnpj);

        void carregaFuncoes();
        void carregarEmpresa();
        void carregarASGs();
        void carregarVendedor();
        void carregarGerente();
        void carregaDono();
        void imprimeASGs();
        void imprimeVendedores();
        void imprimeGerentes();
        void imprimeDono();
        void calculaTodoOsSalarios();
        void buscaFuncionario(std::string matricula);
        void calculaSalarioFuncionario(std::string matricula);
        void calcularRecisao(std::string matricula, Data desligamento);
};

#endif
