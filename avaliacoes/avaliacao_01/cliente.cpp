#include <iostream>
#include <fstream>  
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

#include "file.hpp"

using namespace std;

// Cadastrar um novo produto no carrinho
void adcionarCarrinho(string fileName, vector<string> produtosList){
  string name;
  vector<string> novoCarrinho;

  cout << "Informe o nome do produto" << endl;
  cin.ignore();
  getline(cin, name);

  //procura o produto nas listas de produtos disponiveis
  for(auto i : produtosList){
    novoCarrinho = getItem(i, name);

    //para o loop caso encontre o produto em uma das listas
    if(novoCarrinho[0] != "") break;
  }

  if(novoCarrinho[0] != ""){
    addItem(fileName, novoCarrinho[0], stof(novoCarrinho[1]));
    cout << "Produto cadastrado!" << endl;
  }else{
    cout << "Produto não encontrado" << endl;
  }
}

// Calcula o total do carrinho
void totalCarrinho(string fileName){
  if(fileExist(fileName)){
    // Armazena o carrinho na tabela
    vector<vector<string>> carrinho = readFile("carrinho");
    float total = 0.0;

    //Soma todos os valores do carrinho
    for(int i = 0; i < carrinho.size(); i++){
      cout << stof(carrinho[i][1]) << endl;
      total += stof(carrinho[i][1]);
    }

    cout << "Total do carrinho: " << setprecision(4) << total << endl;
  }else{
    cout << "O carrinho está vazio!" << endl;
  }
}


// Remove um produto do carrinho
void removerCarrinho(string fileName){
  string name;

  cout << "Informe o nome do produto que deseja remover" << endl;
  cin.ignore();
  getline(cin, name);

  removeItem(fileName, name);
  cout << name << " removido!" << endl;
}

void menuCliente(){
  while(true){
    cout << "--------------------------------\n";
    cout << "~~~~~ Lanchonete Genérica! ~~~~~\n";
    cout << "--------------------------------\n";
    cout << endl;
    cout << "1 - Listar todos os sanduiches\n";
    cout << "2 - Listar todos os sucos\n";
    cout << "3 - Escolher lanche\n";
    cout << "4 - Calcular total\n";
    cout << "5 - Carrinho\n"; 
    cout << "6 - Excluir item do carrinho\n";
    cout << "7 - Sair\n";

    int opt;
    cin >> opt;

    switch (opt){
      case 1:
        printTable("sanduiche");
        break;
      
      case 2:
        printTable("suco");
        break;   
      
      case 3:
        adcionarCarrinho("carrinho", {"sanduiche", "suco"});
        break;
      
      case 4:
        totalCarrinho("carrinho");
        break;
      case 5:
        printTable("carrinho");
        break;
      
      case 6:
        removerCarrinho("carrinho");
        break;

      default:
        exit(0);
        break;
    }
  }
}
