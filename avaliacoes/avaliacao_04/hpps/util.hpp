/**
 * @file util.hpp
 * @brief Contém a definição dos structs Data e Endereço
*/


#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>

/**
 * @brief Estrutura que representa uma data.
 */
typedef struct {
  int dia; /**< Dia da data. */
  int mes; /**< Mês da data. */
  int ano; /**< Ano da data. */
} Data;

/**
 * @brief Estrutura que representa um endereço.
 */
typedef struct {
  std::string rua; /**< Rua do endereço. */
  std::string bairro; /**< Bairro do endereço. */
  std::string cidade; /**< Cidade do endereço. */
  std::string cep; /**< CEP do endereço. */
  int numero; /**< Número do endereço. */
} Endereco;

#endif

