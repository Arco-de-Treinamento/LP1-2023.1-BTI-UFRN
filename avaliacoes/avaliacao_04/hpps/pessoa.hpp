/**
 * @file pessoa.hpp
 * @brief Contém a definição da classe Pessoa.
 */

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include "util.hpp"

/**
* @class Pessoa
* @brief Classe que representa uma Pessoa.
* 
* A classe Pessoa representa uma pessoa física, com atributos como nome, CPF, data de nascimento, endereço pessoal, estado civil e quantidade de filhos.
*/
 
class Pessoa {
private:
  std::string nome; /**< Nome da pessoa. */
  std::string cpf; /**< CPF da pessoa. */
  Data dataNascimento; /**< Data de nascimento da pessoa. */
  Endereco enderecoPessoal; /**< Endereço pessoal da pessoa. */
  std::string estadoCivil; /**< Estado civil da pessoa. */
  int qtdFilhos; /**< Quantidade de filhos da pessoa. */

public:
  /**
   * @brief Construtor padrão da classe Pessoa.
   */
  Pessoa();

  /**
   * @brief Construtor da classe Pessoa.
   * @param nome O nome da pessoa.
   * @param cpf O CPF da pessoa.
   * @param dataNascimento A data de nascimento da pessoa.
   * @param enderecoPessoal O endereço pessoal da pessoa.
   * @param estadoCivil O estado civil da pessoa.
   * @param qtdFilhos A quantidade de filhos da pessoa.
   */
  Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);

  /**
   * @brief Obtém o nome da pessoa.
   * @return O nome da pessoa.
   */
  std::string getNome();

  /**
   * @brief Obtém o CPF da pessoa.
   * @return O CPF da pessoa.
   */
  std::string getCpf();

  /**
   * @brief Obtém a data de nascimento da pessoa.
   * @return A data de nascimento da pessoa.
   */
  Data getDataNascimento();

  /**
   * @brief Obtém o endereço pessoal da pessoa.
   * @return O endereço pessoal da pessoa.
   */
  Endereco getEndereco();

  /**
   * @brief Obtém o estado civil da pessoa.
   * @return O estado civil da pessoa.
   */
  std::string getEstadoCivil();

  /**
   * @brief Obtém a quantidade de filhos da pessoa.
   * @return A quantidade de filhos da pessoa.
   */
  int getQtdFilhos();

  /**
   * @brief Define o nome da pessoa.
   * @param nome O nome a ser definido.
   */
  void setNome(std::string nome);

  /**
   * @brief Define o CPF da pessoa.
   * @param cpf O CPF a ser definido.
   */
  void setCpf(std::string cpf);

  /**
   * @brief Define a data de nascimento da pessoa.
   * @param dataNascimento A data de nascimento a ser definida.
   */
  void setDataNascimento(Data dataNascimento);

  /**
   * @brief Define o endereço pessoal da pessoa.
   * @param enderecoPessoal O endereço pessoal a ser definido.
   */
  void setEndereco(Endereco enderecoPessoal);

  /**
   * @brief Define o estado civil da pessoa.
   * @param estadoCivil O estado civil a ser definido.
   */
  void setEstadoCivil(std::string estadoCivil);

  /**
   * @brief Define a quantidade de filhos da pessoa.
   * @param qtdFilhos A quantidade de filhos a ser definida.
   */
  void setQtdFilhos(int qtdFilhos);
};

#endif

