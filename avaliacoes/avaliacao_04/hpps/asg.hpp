/**
 * @file asg.hpp
 * @brief Contém a definição da classe Asg.
 */

#ifndef ASG_HPP
#define ASG_HPP

#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
* @class Asg
* @brief Classe que representa um funcionario ASG
* 
* A classe Asg herda as características da classe Pessoa e da classe Funcionario.
*/
 
class Asg : public Pessoa, public Funcionario {
private:
    /**< Adicional de insalubridade do ASG */
    float adicionalInsalubridade = 0.05; 

public:
    /**
     * @brief Construtor padrão da classe Asg.
     */
    Asg();

    /**
     * @brief Construtor da classe Asg que permite definir o adicional de insalubridade.
     * @param adicionalInsalubridade O valor do adicional de insalubridade a ser definido.
     */
    Asg(float adicionalInsalubridade);

    /**
     * @brief Obtém o valor do adicional de insalubridade.
     * @return O valor do adicional de insalubridade.
     */
    float getAdcionalInsabubridade();

    /**
     * @brief Define o valor do adicional de insalubridade.
     * @param adicionalInsalubridade O valor do adicional de insalubridade a ser definido.
     */
    void setAdcionalInsabubridade(float adicionalInsalubridade);

    /**
     * @brief Calcula o salário do ASG considerando os dias de falta.
     * @param diasFaltas O número de dias de falta do ASG.
     * @return O valor do salário do ASG após o desconto das faltas e adicional de insalubridade.
     */
    float calcularSalario(int diasFaltas);

    /**
     * @brief Calcula o valor da rescisão do ASG com base na data de desligamento.
     * @param desligamento A data de desligamento do ASG.
     * @return O valor da rescisão do ASG.
     */
    float calcularRecisao(Data desligamento);
};

#endif

