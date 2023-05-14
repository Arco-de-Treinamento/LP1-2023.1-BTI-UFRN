#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <vector>
#include "ioFile.hpp"

using namespace std;

int main (){
    string tempNome;
    vector<double> tempNotas(3);

    map<string, double> alunos;

    while(true){
        char opt;
        cout << "Inserir um aluno no arquivo? [y/n]: ";
        cin >> opt;

        if(opt == 'y' || opt == 'Y'){
            cin.ignore(); 

            cout << "Digite o nome do aluno/a: " << endl;
            getline(cin, tempNome);

            for(int i = 0; i<3; i++){
                cout << "Digite a " << (i + 1) << " nota:" << endl;
                cin >> tempNotas[i];
            }

            double media = accumulate(tempNotas.begin(), tempNotas.end(), 0) / 3;

            alunos. insert(make_pair(tempNome, media));
            
        }else{
            break;
        }
    }

    //Criando arquivos com os alunos
    string fileName = createFile(alunos, "notas");

    //Lendo arquivos;
    readFile(fileName);

    return 0;
}

