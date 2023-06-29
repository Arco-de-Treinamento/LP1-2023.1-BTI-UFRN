#include <iostream>
#include <vector>
#include <string>

using namespace std;

// A solução anterior (que esta comentada) apresentava um bug de estouro de memoria.
// Como o problema não foi solucionado, optei por adptar uma solução utlizando STL, 
// com o vector.

class Aluno {
    private:
    string nomeCompleto;
    string cpf;
    string idade;
    long int matricula;
    string serie;

    public:
    Aluno() {} // construtor vazio

    // contrutor parametrizado
    Aluno(string nome, string cpf, string idade, long int matricula, string serie) {
        this->nomeCompleto = nome;
        this->cpf = cpf;
        this->idade = idade;
        this->matricula = matricula;
        this->serie = serie;
    }

    // métodos get
    string getNomeCompleto() { return nomeCompleto; }
    string getCpf() { return cpf; }
    string getIdade() { return idade; }
    long int getMatricula() { return matricula; }
    string getSerie() { return serie; }

    // métodos set
    void setNomeCompleto(string nome) { nomeCompleto = nome; }
    void setCpf(string cpf) { this->cpf = cpf; }
    void setIdade(string idade) { this->idade = idade; }
    void setMatricula(long int matricula) { this->matricula = matricula; }
    void setSerie(string serie) { this->serie = serie; }
};

class Funcionario {
    private:
    string nomeCompleto;
    string cpf;
    string idade;
    long int matricula;
    string cargo;
    float salario;

    public:
    Funcionario() {} // construtor vazio

    // construtor parametrizado
    Funcionario(string nome, string cpf, string idade, long int matricula, string cargo, float salario) {
        this->nomeCompleto = nome;
        this->cpf = cpf;
        this->idade = idade;
        this->matricula = matricula;
        this->cargo = cargo;
        this->salario = salario;
    }

    // métodos get
    string getNomeCompleto() { return nomeCompleto; }
    string getCpf() { return cpf; }
    string getIdade() { return idade; }
    long int getMatricula() { return matricula; }
    string getCargo() { return cargo; }
    float getSalario() { return salario; }

    // métodos set
    void setNomeCompleto(string nome) { nomeCompleto = nome; }
    void setCpf(string cpf) { this->cpf = cpf; }
    void setIdade(string idade) { this->idade = idade; }
    void setMatricula(long int matricula) { this->matricula = matricula; }
    void setCargo(string cargo) { this->cargo = cargo; }
    void setSalario(float salario) { this->salario = salario; }
};

class Escola {
    private:
    string nomeEscola;
    string cnpj;
    vector<Funcionario> funcionarios;
    vector<Aluno> alunos;
    //Funcionario* funcionarios;
    //Aluno* alunos;

    public:
    // construtor
    Escola(string nome, string cnpj) {
        this->nomeEscola = nome;
        this->cnpj = cnpj;
        this->funcionarios = vector<Funcionario>(5);
        this->alunos = vector<Aluno>(10);
        //this->funcionarios = new Funcionario[6]();
        //this->alunos = new Aluno[11]();
    }

    // métodos get
    string getNomeEscola() { return nomeEscola; }
    string getCnpj() { return cnpj; }
    //Funcionario* getFuncionarios() { return funcionarios; }
    //Aluno* getAlunos() { return alunos; }
    vector<Funcionario> getFuncionarios() { return funcionarios; }
    vector<Aluno> getAlunos() { return alunos; }

    // métodos set
    void setNomeEscola(string nome) { nomeEscola = nome; }
    void setCnpj(string cnpj) { this->cnpj = cnpj; }
    //void setFuncionarios(Funcionario* funcionarios) { this->funcionarios = funcionarios; }
    //void setAlunos(Aluno* alunos) { this->alunos = alunos; }
    void setFuncionarios(vector<Funcionario> funcionarios) { 
        this->funcionarios.assign(funcionarios.begin(), funcionarios.end()); 
    }
    void setAlunos(vector<Aluno> alunos) {
        this->alunos.assign(alunos.begin(), alunos.end());
    }

    // lista os alunos da escola
    void listarAlunos() {
        cout << "Lista de Alunos:\n";
        for (int i = 0; i < 10; i++) {
            cout << i+1 << "- Nome: " << alunos[i].getNomeCompleto() << " Matricula: " << alunos[i].getMatricula() << endl;
        }
    }

    // lista os funcionarios da escola
    void listarFuncionarios() {
        cout << "Lista de Funcionarios:\n";
        for (int i = 0; i < 5; i++) {
            cout << i+1 << "Nome: " << funcionarios[i].getNomeCompleto() << " Matricula: " << funcionarios[i].getMatricula() << endl;
        }
    }

    // soma os salarios dos funcionarios
    void somarSalarios() {
        float total = 0;
        for (int i = 0; i < 5; i++) total += funcionarios[i].getSalario();
        
        cout << "A soma dos salarios: R$ " << total << endl;
    }

    // adiciono um aluno
    void adicionarAluno(Aluno aluno) {
        for (int i = 0; i < 10; i++) {
            // verifica se a posição no vetor está livre
            if (alunos[i].getNomeCompleto() == "") {
                alunos[i] = aluno;
                cout << "Aluno adicionado com sucesso!\n";
                return;
            }
        }
        cout << "Nao foi possivel adicionar o aluno\n";
    }
};

int main() {
    // criar objeto escola e setar 5 funcionarios e 5 alunos
    Escola imd = Escola("IMD", "100.054/21");

    //Funcionario funcionarios[5] = {
    vector<Funcionario> funcionarios = {
        Funcionario("Joao Silva", "123.456.789-00", "32", 1001, "Professor", 5000.00),
        Funcionario("Maria Santos", "987.654.321-00", "27", 1002, "Professor", 4000.00),
        Funcionario("Pedro Oliveira", "456.789.123-00", "45", 1003, "Professor", 8000.00),
        Funcionario("Juliana Souza", "321.654.987-00", "29", 1004, "Professor", 4500.00),
        Funcionario("Lucas Martins", "654.321.987-00", "38", 1005, "Professor", 5500.00)
    };

    //Aluno alunos[5] = {
    vector<Aluno> alunos = {
        Aluno("Joao Silva", "123.456.789-00", "18", 2021001, "3"),
        Aluno("Maria Santos", "987.654.321-00", "17", 2021002, "2"),
        Aluno("Pedro Oliveira", "111.222.333-44", "16", 2021003, "1"),
        Aluno("Ana Pereira", "555.666.777-88", "19", 2021004, "3"),
        Aluno("Lucas Souza", "999.888.777-66", "15", 2021005, "1")
    };

    imd.setFuncionarios(funcionarios);
    imd.setAlunos(alunos);

    // adicionar um aluno
    imd.adicionarAluno(Aluno("João Silva", "123.456.789-10", "17", 2022002, "3"));

    // somar salarios e exibir resultado
    imd.somarSalarios();

    // listar alunos e funcionarios
    cout << "Alunos:" << endl;
    imd.listarAlunos();
    cout << endl;

    cout << "Funcionarios:" << endl;
    imd.listarFuncionarios();
    cout << endl;

    return 0;
}