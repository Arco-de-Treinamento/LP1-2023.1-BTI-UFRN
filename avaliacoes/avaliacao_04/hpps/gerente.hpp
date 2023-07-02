/**
* @file gerente.hpp
* @brief Contém a definição da classe Gerente
*/
 
#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @brief Classe que representa um gerente.
 */
 
/**
* @class Gerente
* @brief Classe que representa um gerente.
* 
* A classe Gerente herda as características da classe Pessoa e da classe Funcionario.
*/

class Gerente : public Pessoa, public Funcionario {

private:
    float participacaoLucros; /**< Participação nos lucros do gerente. */

public:
    /**
     * @brief Construtor padrão da classe Gerente.
     */
    Gerente();

    /**
     * @brief Construtor da classe Gerente.
     * @param participacaoLucros A participação nos lucros do gerente.
     */
    Gerente(float participacaoLucros);

    /**
     * @brief Obtém a participação nos lucros do gerente.
     * @return A participação nos lucros.
     */
    float getParticipacaoLucros();

    /**
     * @brief Define a participação nos lucros do gerente.
     * @param participacaoLucros A participação nos lucros.
     */
    void setParticipacaoLucros(float participacaoLucros);

    /**
     * @brief Calcula o salário do gerente considerando os dias de falta.
     * @param diasFaltas O número de dias de falta do gerente.
     * @return O salário do gerente no mês.
     */
    float calcularSalario(int diasFaltas);

    /**
     * @brief Calcula o valor da rescisão do gerente.
     * @param desligamento A data de desligamento do gerente.
     * @return O valor da rescisão do gerente.
     */
    float calcularRecisao(Data desligamento);
};

#endif

