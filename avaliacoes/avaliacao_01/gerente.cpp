#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "file.hpp"

using namespace std;

// Cadastrar um novo produto 
void cadastrarProduto(string fileName){
  string name;
  float price;

  cout << "Informe o nome do " << fileName << endl;
  cin.ignore();
  getline(cin, name);
  cout << "Informe o preço do " << fileName << endl;
  cin >> price;


  addItem(fileName, name, price);
  cout << "Produto cadastrado!" << endl;
}

// Editar um item
void editarProduto(string fileName){
  string name, newName;
  float newPrice;

  cout << "Informe o nome do " << fileName << " que deseja editar" << endl;
  cin.ignore();
  getline(cin, name);
  cout << "Informe o novo nome do " << fileName << endl;
  cin.ignore();
  getline(cin, name);
  cout << "Informe o novo valor do " << fileName << endl;
  cin >> newPrice;

  editItem(fileName, name, newName, newPrice);
  cout << fileName << " alterado!" << endl;
}

// Remove um produto
void removerProduto(string fileName){
  string name;

  cout << "Informe o nome do " << fileName << " que deseja remover" << endl;
  cin.ignore();
  getline(cin, name);

  removeItem(fileName, name);
  cout << name << " removido!" << endl;
}

void menuGerente(){
  string password;

  while (true){
    cout << "--------------------------------\n";
    cout << "~~~~~      Admin mode      ~~~~~\n";
    cout << "--------------------------------\n";
    cout << "1 - Entrar\n";
    cout << "2 - Sair\n";

    int login;
    cin >> login;

    switch (login){
      case 1:
        cout << "Senha de acesso: " << endl;
        cin.ignore();
        cin >> password;

        if(password == "admin"){
          while(true){
            cout << "--------------------------------\n";
            cout << "~~~~~ Lanchonete Genérica! ~~~~~\n";
            cout << "--------------------------------\n";
            cout << endl;
            cout << "Admin mode:\n";
            cout << endl;
            cout << "1 - Listar todos os sanduiches\n";
            cout << "2 - Listar todos os sucos\n";
            cout << "3 - Adicionar um novo sanduíche\n";
            cout << "4 - Adicionar um novo suco\n";
            cout << "5 - Editar um sanduíche\n";
            cout << "6 - Editar um suco\n";
            cout << "7 - Excluir um sanduíche\n";
            cout << "8 - Excluir um suco\n";
            cout << "9 - Sair\n";

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
                cadastrarProduto("sanduiche");
                break;
              
              case 4:
                cadastrarProduto("suco");
                break;
              
              case 5:
                editarProduto("sanduiche");
                break;
              
              case 6:
                editarProduto("suco");
                break;
              
              case 7:
                removerProduto("sanduiche");
                break;
              
              case 8:
                removerProduto("suco");
                break;

              default:
                exit(0);
                break;
            }
          }
        } else cout << "Senha incorreta!" << endl;
        break;
      
      default:
        exit(0);
        break;
    }
  }
}
