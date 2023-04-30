#include <iostream>
#include "cliente.hpp" 
#include "gerente.hpp" 

using namespace std;

int main(int argc, char *argv[]){

  cout << "--------------------------------\n";
  cout << "~~~~~ Lanchonete Genérica! ~~~~~\n";
  cout << "--------------------------------\n";

  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Cliente\n";
  cout << "2 - Gerente\n";
  cout << "-> :";

  int perfil; 
  cin >> perfil;
  
  switch (perfil){
    case 1: // Cliente
      menuCliente();
      break;
    
    case 2: // Gerente
      menuGerente();
      break;
           
    default:
      cout << "Perfil não localizado\n"<< endl;
      break;
  }
  
  return 0; 
}