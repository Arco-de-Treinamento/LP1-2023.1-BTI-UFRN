#ifndef CLIENTE
#define CLIENTE

#include <vector>

void menuCliente();
void adcionarCarrinho(std::string fileName, std::vector<std::string> produtosList);
void totalCarrinho(std::string fileName);
void removerCarrinho(std::string fileName);

#endif