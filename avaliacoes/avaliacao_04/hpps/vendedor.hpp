/**
 * @file vendedor.hpp
 * @brief Contém a definição da classe Vendedor
 */

#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
* @class Vendedor
* @brief Classe que representa um vendedor.
* 
* A classe Vendedor herda as características da classe Pessoa e da classe Funcionario.
*/

class Vendedor : public Pessoa, public Funcionario {

private:
    std::string tipoVendedor; /**< Classificação do vendedor (A, B, C). */

public:
    /**
     * @brief Construtor padrão da classe Vendedor.
     */
    Vendedor();

    /**
     * @brief Construtor da classe Vendedor.
     * @param tipoVendedor A classificação do vendedor (A - 25%, B - 10%, C - 5%) para gratificação.
     */
    Vendedor(char tipoVendedor);

    /**
     * @brief Obtém a classificação do vendedor.
     * @return A classificação do vendedor.
     */
    std::string getTipoVendedor();

    /**
     * @brief Define a classificação do vendedor.
     * @param tipoVendedor A classificação do vendedor.
     */
    void setTipoVendedor(std::string tipoVendedor);

    /**
     * @brief Calcula o salário do vendedor considerando os dias de falta e a gratificação.
     * @param diasFaltas O número de dias de falta do vendedor.
     * @return O salário do vendedor no mês.
     */
    float calcularSalario(int diasFaltas);

    /**
     * @brief Calcula o valor da rescisão do vendedor.
     * @param desligamento A data de desligamento do vendedor.
     * @return O valor da rescisão do vendedor.
     */
    float calcularRecisao(Data desligamento);
};

#endif

