#include <iostream>
#include "Empresa.hpp"

using namespace std;

Empresa::Empresa() {}

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, Data hoje) {
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
    this->hoje = hoje;
}

float Empresa::getFaturamentoMensal() {return faturamentoMensal;}
string Empresa::getNomeEmpresa() {return nomeEmpresa;}
string Empresa::getCnpj() {return cnpj;}
Pessoa Empresa::getDono() {return dono;}
vector<ASG> Empresa::getASGs() {return ASGs;}
vector<Vendedor> Empresa::getVendedores() {return vendedores;}
vector<Gerente> Empresa::getGerentes() {return gerentes;}

void Empresa::setFaturamentoMensal(float faturamentoMensal) {this->faturamentoMensal = faturamentoMensal;}
void Empresa::setNomeEmpresa(string nomeEmpresa) {this->nomeEmpresa = nomeEmpresa;}
void Empresa::setCnpj(string cnpj) {this->cnpj = cnpj;}


void Empresa::carregaFuncoes() {
    carregarEmpresa();
    carregarASGs();
    carregarVendedor();
    carregarGerente();
    carregaDono();
    imprimeASGs();

    cout << endl;
    imprimeVendedores();
    cout << endl;
    imprimeGerentes();
    cout << endl;
    imprimeDono();
    cout << endl;

    calculaTodoOsSalarios();
}

void Empresa::carregarEmpresa() {
    ifstream arquivo;
    string cache;

    arquivo.open("data/empresa.txt", ios::in);

    // Ignorar as primeiras 2 linhas
    getline(arquivo, cache);
    getline(arquivo, cache);

    // Ler os dados da empresa  
    getline(arquivo, nomeEmpresa);
    getline(arquivo, cnpj);
    arquivo >> faturamentoMensal;

    arquivo.close();
}

void Empresa::carregarASGs() {
    ifstream arquivo;

    string cache, nomeASG, cpfASG, estadoCivil, matricula, salario, qntFilhos;
    float insalubridade;
    Endereco enderecoPessoal;
    Data dataNascimento, dataIngresso;

    arquivo.open("data/asg.txt", ios::in);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo 'asg.txt'" << endl;
        return;
    }

    getline(arquivo, cache);
    // Loop de leitura
    while (getline(arquivo, cache)){
        // Ignorar a primeira 1 linha

        if(cache.find("ASG Nº:") != string::npos){
            // Dados pessoais
            getline(arquivo, cache);
            getline(arquivo, nomeASG);
            getline(arquivo, cpfASG);
            getline(arquivo, qntFilhos);
            getline(arquivo, estadoCivil);
            // Endereço pessoal
            getline(arquivo, cache);
            getline(arquivo, enderecoPessoal.cidade);
            getline(arquivo, enderecoPessoal.cep);
            getline(arquivo, enderecoPessoal.bairro);
            getline(arquivo, enderecoPessoal.rua);
            arquivo >> enderecoPessoal.numero;
            arquivo.ignore();
            // Data de nascimento
            getline(arquivo, cache);
            arquivo >> dataNascimento.ano >> dataNascimento.mes >> dataNascimento.dia;
            arquivo.ignore();
            // Dados funcionais
            getline(arquivo, cache);
            getline(arquivo, matricula);
            getline(arquivo, salario);
            arquivo >> insalubridade;
            arquivo.ignore();
            // Data de ingresso
            getline(arquivo, cache);
            arquivo >> dataIngresso.ano >> dataIngresso.mes >> dataIngresso.dia;

            cout << endl;

            // Adiciona os dados ao vector de ASGs
            ASGs.push_back(ASG(nomeASG, cpfASG, dataNascimento, enderecoPessoal, estadoCivil, stoi(qntFilhos), salario, matricula, dataIngresso, insalubridade));
       
            // Ignora a proxima linha
            getline(arquivo, cache);
        }
    }
}

void Empresa::carregarVendedor() {
    ifstream arquivo;

    string cache, nomeVendedor, cpfVendedor, estadoCivil, matricula, salario,qntFilhos;
    char categoria;
    Endereco enderecoPessoal;
    Data dataNascimento, dataIngresso;

    arquivo.open("data/vendedor.txt", ios::in);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo 'vendedor.txt'" << endl;
        return;
    }

    getline(arquivo, cache);
    // Loop de leitura
    while (getline(arquivo, cache)){
        // Ignorar a primeira 1 linha

        if(cache.find("VENDEDOR Nº:") != string::npos){
            // Dados pessoais
            getline(arquivo, cache);
            getline(arquivo, nomeVendedor);
            getline(arquivo, cpfVendedor);
            getline(arquivo, qntFilhos);
            getline(arquivo, estadoCivil);
            // Endereço pessoal
            getline(arquivo, cache);
            getline(arquivo, enderecoPessoal.cidade);
            getline(arquivo, enderecoPessoal.cep);
            getline(arquivo, enderecoPessoal.bairro);
            getline(arquivo, enderecoPessoal.rua);
            arquivo >> enderecoPessoal.numero;
            arquivo.ignore();
            // Data de nascimento
            getline(arquivo, cache);
            arquivo >> dataNascimento.ano >> dataNascimento.mes >> dataNascimento.dia;
            arquivo.ignore();
            // Dados funcionais
            getline(arquivo, cache);
            getline(arquivo, matricula);
            getline(arquivo, salario);
            arquivo >> categoria;
            arquivo.ignore();
            // Data de ingresso
            getline(arquivo, cache);
            arquivo >> dataIngresso.ano >> dataIngresso.mes >> dataIngresso.dia;

            // Adiciona os dados ao vector de vendedores
            vendedores.push_back(Vendedor(nomeVendedor, cpfVendedor, dataNascimento, enderecoPessoal, estadoCivil, stoi(qntFilhos), salario, matricula, dataIngresso, categoria));

            // Ignora a proxima linha
            getline(arquivo, cache);
        }
    }
}

void Empresa::carregarGerente() {
    ifstream arquivo;

    string cache, nomeGerente, cpfGerente, estadoCivil, matricula, salario, qntFilhos;
    float partLucros;
    Endereco enderecoPessoal;
    Data dataNascimento, dataIngresso;

    arquivo.open("data/gerente.txt", ios::in);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo 'gerente.txt'" << endl;
        return;
    }

    getline(arquivo, cache);
    // Loop de leitura
    while (getline(arquivo, cache)){
        // Ignorar a primeira 1 linha

        if(cache.find("GERENTE Nº:") != string::npos){
            // Dados pessoais
            getline(arquivo, cache);
            getline(arquivo, nomeGerente);
            getline(arquivo, cpfGerente);
            getline(arquivo, qntFilhos);
            getline(arquivo, estadoCivil);
            // Endereço pessoal
            getline(arquivo, cache);
            getline(arquivo, enderecoPessoal.cidade);
            getline(arquivo, enderecoPessoal.cep);
            getline(arquivo, enderecoPessoal.bairro);
            getline(arquivo, enderecoPessoal.rua);
            arquivo >> enderecoPessoal.numero;
            arquivo.ignore();
            // Data de nascimento
            getline(arquivo, cache);
            arquivo >> dataNascimento.ano >> dataNascimento.mes >> dataNascimento.dia;
            arquivo.ignore();
            // Dados funcionais
            getline(arquivo, cache);
            getline(arquivo, matricula);
            getline(arquivo, salario);
            arquivo >> partLucros;
            arquivo.ignore();
            // Data de ingresso
            getline(arquivo, cache);
            arquivo >> dataIngresso.ano >> dataIngresso.mes >> dataIngresso.dia;

            // Adiciona os dados ao vector de gerentes
            gerentes.push_back(Gerente(nomeGerente, cpfGerente, dataNascimento, enderecoPessoal, estadoCivil, stoi(qntFilhos), salario, matricula, dataIngresso, partLucros));

            // Ignora a proxima linha
            getline(arquivo, cache);
        }
    }
    
    arquivo.close();
}

void Empresa::carregaDono() {
    ifstream arquivo;

    string cache, nomeDono, cpfDono, estadoCivil,qntFilhos;
    Endereco enderecoPessoal;
    Data dataNascimento;

    arquivo.open("data/dono.txt", ios::in);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo 'dono.txt'" << endl;
        return;
    }

    // Ignorar as primeiras 2 linhas
    getline(arquivo, cache);
    getline(arquivo, cache);
    // Ler os dados do dono
    getline(arquivo, nomeDono);
    getline(arquivo, cpfDono);
    getline(arquivo, qntFilhos);
    getline(arquivo, estadoCivil);
    getline(arquivo, enderecoPessoal.cidade);
    getline(arquivo, enderecoPessoal.cep);
    getline(arquivo, enderecoPessoal.bairro);
    getline(arquivo, enderecoPessoal.rua);
    arquivo >> enderecoPessoal.numero;
    arquivo >> dataNascimento.ano;
    arquivo >> dataNascimento.mes;
    arquivo >> dataNascimento.dia;

    dono = Pessoa(nomeDono, cpfDono, dataNascimento, enderecoPessoal, estadoCivil, stoi(qntFilhos));

    arquivo.close();
}

void Empresa::imprimeASGs() {
    cout << "ASGs da empresa " << nomeEmpresa  << endl;
    
    for (ASG& ASG : ASGs) cout << "Mat.: " << ASG.getMatricula() << " | Nome: " << ASG.getNome() << endl;
}

void Empresa::imprimeVendedores() {
    cout << "Vendedores da empresa " << nomeEmpresa  << endl;

    for (Vendedor& vendedor : vendedores) cout << "Mat.: " <<vendedor.getMatricula() << " | Nome: " << vendedor.getNome() << endl;
}

void Empresa::imprimeGerentes() {
    cout << "Gerentes da empresa " << nomeEmpresa  << endl;

    for (Gerente& gerente : gerentes) cout <<"Mat.: " << gerente.getMatricula() << " | Nome: " << gerente.getNome() << endl;  
}

void Empresa::imprimeDono() {
    cout << "Dono da empresa " << nomeEmpresa  << endl;

    cout << "Nome: " << dono.getNome() << " | CPF: " << dono.getCpf() << endl;
}

void Empresa::calculaTodoOsSalarios() {
    float totalSalarios = 0.0f;
    float totalASG = 0.0f;
    float totalVendedor = 0.0f;
    float totalGerente = 0.0f;

    // Setando para 2 casas decimais
    cout << fixed << setprecision(2);

    // Somar todos os salarios considerando 0 faltas
    cout << "Cargo: ASG" << endl; 
    for (ASG& ASG : ASGs) {
        cout << ASG.getMatricula() << " - " << ASG.getNome() << " - R$ " << ASG.calcularSalario(0) << endl;
        totalASG += ASG.calcularSalario(0);
    }
    cout << "Total ASG: R$ " << totalASG << endl;
    cout << endl;

    cout << "Cargo: Vendedor" << endl;
    for (Vendedor& vendedor : vendedores) {
        cout << vendedor.getMatricula() << " - " << vendedor.getNome() << " - R$ "<< vendedor.calcularSalario(0) << endl;
        totalVendedor += vendedor.calcularSalario(0);
    }
    cout << "Total Vendedor: R$ " << totalVendedor << endl;
    cout << endl;

    cout << "Cargo: Gerente" << endl;
    for (Gerente& gerente : gerentes) {
        cout << gerente.getMatricula() << " - " << gerente.getNome() << " - R$ " << gerente.calcularSalario(0) << endl;
        totalGerente += gerente.calcularSalario(0);
    }
    cout << "Total Gerente: R$ " << totalGerente << endl;
    cout << endl;

    totalSalarios = totalASG + totalVendedor + totalGerente;
    cout << "CUSTO TOTAL DE RH: R$ " << totalSalarios << endl;
}

void Empresa::buscaFuncionario(string matricula) {
    for (ASG& ASG : ASGs) {
        if (ASG.getMatricula() == matricula) {
            cout << ASG.getMatricula() << " - " << ASG.getNome() << endl;
            return;
        }
    }

    for (Vendedor& vendedor : vendedores) {
        if (vendedor.getMatricula() == matricula) {
            cout << vendedor.getMatricula() << " - " << vendedor.getNome() << endl;
            return;
        }
    }

    for (Gerente& gerente : gerentes) {
        if (gerente.getMatricula() == matricula) {
            cout << gerente.getMatricula() << " - " << gerente.getNome() << endl;
            return;
        }
    }

    cout << "Funcionário não encontrado no sistma" << endl;
}

void Empresa::calculaSalarioFuncionario(string matricula) {
    // Setando para 2 casas decimais
    cout << fixed << setprecision(2);

    for (ASG& ASG : ASGs) {
        if (ASG.getMatricula() == matricula) {
            cout << ASG.getMatricula() << " - " << ASG.getNome() << " - R$" << ASG.calcularSalario(0) << endl;
            return;
        }
    }

    for (Vendedor& vendedor : vendedores) {
        if (vendedor.getMatricula() == matricula) {
            cout << vendedor.getMatricula() << " - " << vendedor.getNome() << " - R$ "<< vendedor.calcularSalario(0) << endl;
            return;
        }
    }

    for (Gerente& gerente : gerentes) {
        if (gerente.getMatricula() == matricula) {
            cout << gerente.getMatricula() << " - " << gerente.getNome() << " - R$" << gerente.calcularSalario(0) << endl;
            return;
        }
    }

    // Setando para 2 casas decimais
    cout << fixed << setprecision(2);

    cout << "Funcionário não encontrado no sistma" << endl;
}

void Empresa::calcularRecisao(string matricula, Data desligamento) {
    // Setando para 2 casas decimais
    cout << fixed << setprecision(2);

    for (ASG& ASG : ASGs) {
        if (ASG.getMatricula() == matricula) {
            cout << ASG.getMatricula() << " - " << ASG.getNome() << " - R$" << ASG.calcularRecisao(desligamento) << endl;
            return;
        }
    }

    for (Vendedor& vendedor : vendedores) {
        if (vendedor.getMatricula() == matricula) {
            cout << vendedor.getMatricula() << " - " << vendedor.getNome() << " - R$ "<< vendedor.calcularRecisao(desligamento) << endl;
            return;
        }
    }

    for (Gerente& gerente : gerentes) {
        if (gerente.getMatricula() == matricula) {
            cout << gerente.getMatricula() << " - " << gerente.getNome() << " - R$" << gerente.calcularRecisao(desligamento) << endl;
            return;
        }
    }

    cout << "Funcionário não encontrado no sistma" << endl;
}
