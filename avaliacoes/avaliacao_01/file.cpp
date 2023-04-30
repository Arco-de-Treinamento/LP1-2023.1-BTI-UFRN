#include <iostream>
#include <fstream>  
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Realiza a criacao do arquivo
void createFile(string fileName){
  fstream file;

  file.open(fileName + ".csv", ios::out | ios::app);
  file.close();
}

// Verifica se um arquivo existe
bool fileExist(string fileName){
  ifstream file(fileName + ".csv");

  return file.good();
}

// Realiza a leitura do arquivo
vector<vector<string>> readFile(string fileName){
  fstream file;
  
  string tempLine, tempWord;        // Variaveis auxiliares
  vector<string> temRow;            // Linha temporaria da tabela
  vector<vector<string>> table;     // Tabela retirada do .csv

  file.open(fileName + ".csv", ios::in);

  while(getline(file, tempLine)){
    temRow.clear();                 // Limpa a linha temporaria

    stringstream str(tempLine);

    while(getline(str, tempWord, ',')){
      temRow.push_back(tempWord);   // Recupera a celula da tabela
    }
    table.push_back(temRow);        // Recupera a linha da tabela
  }

  file.close();
  return table;
}

// Atualiza o arquivo com a nova tabela
void updateFile(string fileName, vector<vector<string>> table){
  fstream file;

  for(int i = 0; i < table.size(); i++){
    for(int j = 0; j < table[i].size(); j++) cout << setprecision(2) << table[i][j] << " | ";
    cout << "\n";
  }

  file.open(fileName + ".csv", ios::out);

  for(int i = 0; i < table.size(); i++){
    file << table[i][0] << "," << table[i][1] << endl;
  }
}

// Limpa todo o conteudo do arquivo
void cleanFile(string fileName){
  fstream file;

  file.open(fileName + ".csv", ios::out | ios::trunc);
  file.close();
}

// Mostra o conteudo do arquivo na tela
void printTable(string fileName){
  if(fileExist(fileName)){
    vector<vector<string>> table = readFile(fileName);

    for(int i = 0; i < table.size(); i++){
      for(int j = 0; j < table[i].size(); j++) cout << setprecision(2) << table[i][j] << " | ";
      cout << "\n";
    }
  }else{
    cout << "A lista está vazia!" << endl;
  }
}

// Adiciona um novo elemento ao documento informado
void addItem(string fileName, string name, float price){
  fstream file;

  file.open(fileName + ".csv", ios::out | ios::app);
  file << name << "," << to_string(price) << endl; //formato nome, preço

  file.close();
}

// Recupera um item de uma tabela e retorna sua linha
vector<string> getItem(string fileName, string name){
  vector<vector<string>> table = readFile(fileName);
  vector<string> etpString = {"",""};  

  // Edita os valores na tabela
    for(int i = 0; i < table.size(); i++){
      if(table[i][0] == name) return table[i];
    }
  
  // Retorna um vetor limpo caso nada seja encontrado
  return etpString;
}

// Edita um item de uma tabela
void editItem(string fileName, string oldName, string newName, float newPrice){
  if(fileExist(fileName)){
    vector<vector<string>> table = readFile(fileName);

    // Edita os valores na tabela
    for(int i = 0; i < table.size(); i++){
      if(table[i][0] == oldName){
        // Atualiza o nome
        table[i][0] = newName;
        table[i][1] = to_string(newPrice);
      }
    }

    // Reescreve os arquivos
    updateFile(fileName, table);

  }else{
    cout << "Arquivo nao encontrado" << endl;
  }
}

// Remove um item do arquivo
void removeItem(string fileName, string name){
  vector<vector<string>> table = readFile(fileName);
  // Cria uma matriz auxiliar do mesmo tamanho
  vector<vector<string>> auxTable((table.size() - 1), vector<string>(2));

  // Realiza a passagem de elementos para a tabela auxiliar
  for(int i = 0, k = 0; i < table.size(); i++){
    if(table[i][0] != name){
      for(int j = 0; j < table[i].size(); j++) auxTable[k][j] = table[i][j];
      k++;
    }
  }

  // Faz o update do arquivo com a nova tabela
  updateFile(fileName, auxTable);
}
