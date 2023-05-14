#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>

using namespace std;

string createFile(map<string, double> alunos, string fileName){
  fstream file;
  string name = fileName + ".txt";

  cout << "Iniciando escrita do arquivo..." << endl;
  file.open(name, ios::out | ios::app);

  map<string, double>::iterator it;
  file << "Lista de alunos" << endl;

  for(it = alunos.begin(); it!=alunos.end(); it++){
    file << "Aluno: " << (*it).first << " | Media: " << (*it).second << endl; 
  }

  file.close();
  cout << "Escrita do arquivo concluida!" << endl;

  return name; 
}

void readFile(string name){
  fstream file;
  file.open(name, ios::in);

  string temp;
  list<string> data;

  cout << "Iniciando a leitura do arquivo" << endl;

  while(getline(file, temp)){
    data.push_back(temp);
  }

  cout << "Alunos presentes na lista: " << endl;
  for(auto i : data) cout << i << "\n";

}

