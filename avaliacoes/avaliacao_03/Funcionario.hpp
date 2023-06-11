#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "util.hpp"

class Funcionario {
    private:
        std::string salario;
        std::string matricula;
        Data ingressoEmpresa;

    public:
        Funcionario();
        Funcionario(std::string salario, std::string matricula, Data ingressoEmpresa);

        std::string getSalario();
        std::string getMatricula();
        Data getIngressoEmpresa();

        void setMatricula(std::string matricula);
        void setSalario(std::string salario);
        void setIngressoEmpresa(Data ingressoEmpresa);

        virtual float calcularSalario(int diasFaltas) {return 0;}
        virtual float calcularRecisao(Data desligamento){return 0;}
};

#endif
