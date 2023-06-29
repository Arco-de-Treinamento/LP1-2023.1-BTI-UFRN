#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "util.hpp" 

class Pessoa {
    private:
        std::string nome;
        std::string cpf;
        Data data;
        Endereco enderecoPessoal;
        std::string estadoCivil;
        int qtdFilhos;

    public:
        Pessoa(); 
        Pessoa(std::string nome,  std::string cpf,  Data data,  Endereco enderecoPessoal,  std::string estadoCivil, int qtdFilhos);

        std::string getNome();
        std::string getCpf();
        Data getData();
        Endereco getEnderecoPessoal();
        std::string getEstadoCivil();
        int getQtdFilhos();

        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setData(Data data);
        void setEnderecoPessoal(Endereco endereco);
        void setEstadoCivil(std::string estadoCivil);
        void setQtdFilhos(int qtdFilhos);
};

#endif
