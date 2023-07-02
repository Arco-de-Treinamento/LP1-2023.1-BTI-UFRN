/**
 * @file funcionario.hpp
 * @brief Contém a definição da classe Funcionario.
 */

#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include "util.hpp"

/**
 * @class Funcionario
 * @brief Classe abstrata que representa um Funcionário.
 * 
 * A classe Funcionario  representa um funcionário e possui alguns métodos virtuais que devem ser implementados.
 */
class Funcionario {
private:
    float salario; /**< Salário do Funcionário. */
    int diasFaltas; /**< Dias de faltas do Funcionário. */
    std::string matricula; /**< Matrícula do Funcionário. */
    Data ingressoEmpresa; /**< Data de ingresso do Funcionário na empresa. */

public:
    /**
     * @brief Calcula o salário do Funcionário considerando os dias de falta.
     * @param diasFaltas O número de dias de falta do Funcionário.
     * @return O valor do salário do Funcionário após o desconto das faltas.
     */
    virtual float calcularSalario(int diasFaltas) = 0;

    /**
     * @brief Calcula o valor da rescisão do Funcionário com base na data de desligamento.
     * @param desligamento A data de desligamento do Funcionário.
     * @return O valor da rescisão do Funcionário.
     */
    virtual float calcularRecisao(Data desligamento) = 0;

    /**
     * @brief Obtém o valor do salário do Funcionário.
     * @return O valor do salário do Funcionário.
     */
    float getSalario();

    /**
     * @brief Obtém a matrícula do Funcionário.
     * @return A matrícula do Funcionário.
     */
    std::string getMatricula();

    /**
     * @brief Obtém a data de ingresso do Funcionário na empresa.
     * @return A data de ingresso do Funcionário na empresa.
     */
    Data getDataingresso();

    /**
     * @brief Define o valor do salário do Funcionário.
     * @param salario O valor do salário a ser definido.
     */
    void setSalario(float salario);

    /**
     * @brief Define a matrícula do Funcionário.
     * @param matricula A matrícula a ser definida.
     */
    void setMatricula(std::string matricula);

    /**
     * @brief Define a data de ingresso do Funcionário na empresa.
     * @param ingressoEmpresa A data de ingresso a ser definida.
     */
    void setDataingresso(Data ingressoEmpresa);

    /**
     * @brief Obtém o número de dias de faltas do Funcionário.
     * @return O número de dias de faltas do Funcionário.
     */
    int getDiasFaltas();

    /**
     * @brief Define o número de dias de faltas do Funcionário.
     * @param diasFaltas O número de dias de faltas a ser definido.
     */
    void setDiasFaltas(int diasFaltas);
};

#endif

