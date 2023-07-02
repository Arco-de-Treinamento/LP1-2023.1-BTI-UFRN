/**
* @file empresa.hpp
* @brief Contém a definição da classe empresa.
*/
 
#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

/**
* @class Empresa
* @brief Classe que representa uma Empresa.
* 
* A classe Empresa é responsável por gerir todos os tipos de funcionarios, seja ASG, Vendedor ou Gerente.
* Além disso, ela também é responsável por gerir os arquivos e gerar os relatórios.
*/

class Empresa {
private:
  float faturamentoMensal; /**< Faturamento mensal da empresa. */
  std::string nomeEmpresa; /**< Nome da empresa. */
  std::string cnpj; /**< CNPJ da empresa. */
  Pessoa *Dono = new Pessoa(); /**< Dono da empresa. */
  std::vector<Asg> asgs; /**< Lista de asgs da empresa. */
  std::vector<Vendedor> vendedores; /**< Lista de vendedores da empresa. */
  std::vector<Gerente> gerentes; /**< Lista de gerentes da empresa. */

public:
  /**
   * @brief Construtor padrão da classe Empresa.
   */
  Empresa();

  /**
   * @brief Construtor da classe Empresa.
   * @param nomeEmpresa Nome da empresa.
   * @param faturamentoMensal Faturamento mensal da empresa.
   * @param cnpj CNPJ da empresa.
   */
  Empresa(std::string nomeEmpresa, float faturamentoMensal, std::string cnpj);

  /**
   * @brief Obtém o faturamento mensal da empresa.
   * @return Faturamento mensal da empresa.
   */
  float getFaturamentoMensal();

  /**
   * @brief Obtém o nome da empresa.
   * @return Nome da empresa.
   */
  std::string getNomeEmpresa();

  /**
   * @brief Obtém o CNPJ da empresa.
   * @return CNPJ da empresa.
   */
  std::string getCnpj();

  /**
   * @brief Obtém o dono da empresa.
   * @return Ponteiro para o dono da empresa.
   */
  Pessoa *getDono();

  /**
   * @brief Obtém a lista de vendedores da empresa.
   * @return Lista de vendedores da empresa.
   */
  std::vector<Vendedor> getVendedores();

  /**
   * @brief Obtém a lista de asgs da empresa.
   * @return Lista de asgs da empresa.
   */
  std::vector<Asg> getAsg();

  /**
   * @brief Obtém a lista de gerentes da empresa.
   * @return Lista de gerentes da empresa.
   */
  std::vector<Gerente> getGerente();

  /**
   * @brief Define o faturamento mensal da empresa.
   * @param faturamentoMensal Faturamento mensal da empresa.
   */
  void setFaturamentoMensal(float faturamentoMensal);

  /**
   * @brief Define o nome da empresa.
   * @param nomeEmpresa Nome da empresa.
   */
  void setNomeEmpresa(std::string nomeEmpresa);

  /**
   * @brief Define o CNPJ da empresa.
   * @param cnpj CNPJ da empresa.
   */
  void setCnpj(std::string cnpj);

  /**
   * @brief Carrega as funções da empresa.
   */
  void carregaFuncoes();

  /**
   * @brief Contrata um novo funcionário para a empresa.
   */
  void contratarFuncionario();

  /**
   * @brief Demite um funcionário da empresa.
   * @param matricula Matrícula do funcionário a ser demitido.
   * @param desligamento Data de desligamento do funcionário.
   */
  void demitirFuncionario(std::string matricula, Data desligamento);

  /**
   * @brief Carrega os dados da empresa.
   */
  void carregarEmpresa();

  /**
   * @brief Carrega os dados dos ASGs da empresa.
   */
  void carregarAsg();

  /**
   * @brief Carrega os dados dos vendedores da empresa.
   */
  void carregarVendedor();

  /**
   * @brief Carrega os dados dos gerentes da empresa.
   */
  void carregarGerente();

  /**
   * @brief Carrega os dados do dono da empresa.
   */
  void carregaDono();

  /**
   * @brief Imprime os dados dos ASGs da empresa.
   */
  void imprimeAsgs();

  /**
   * @brief Imprime os dados dos vendedores da empresa.
   */
  void imprimeVendedores();

  /**
   * @brief Imprime os dados dos gerentes da empresa.
   */
  void imprimeGerentes();

  /**
   * @brief Imprime os dados do dono da empresa.
   */
  void imprimeDono();

  /**
   * @brief Busca um funcionário pelo número de matrícula.
   * @param matricula Matrícula do funcionário a ser buscado.
   */
  void buscaFuncionario(std::string matricula);

  /**
   * @brief Calcula o salário de um funcionário pelo número de matrícula.
   * @param matricula Matrícula do funcionário.
   */
  void calculaSalarioFuncionario(std::string matricula);

  /**
   * @brief Calcula o salário de todos os funcionários da empresa.
   */
  void calculaTodoOsSalarios();

  /**
   * @brief Calcula a rescisão de um funcionário pelo número de matrícula e data de desligamento.
   * @param matricula Matrícula do funcionário.
   * @param desligamento Data de desligamento do funcionário.
   */
  void calcularRescisao(std::string matricula, Data desligamento);
};

#endif

