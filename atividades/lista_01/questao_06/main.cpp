#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <vector>
#include "ioFile.hpp"

using namespace std;

int main (){
    string tempText;
    string searchText;
    string fileName;
 
    while(true){
        char opt;
        cout << "Inserir uma nova musica no arquivo? [y/n]: ";
        cin >> opt;

        if(opt == 'y' || opt == 'Y'){
            cin.ignore(); 

            cout << "Digite o nome da musica: " << endl;
            getline(cin, tempText);

            fileName = addFile(tempText, "musicas");
            
        }else{
            break;
        }
    }

    cout << "Digite o nome da musica da pesquisa: " << endl;
    cin.ignore(); 
    getline(cin, searchText);

    if(searchFile(fileName, searchText)) cout << "Musica encontrada!" << endl;
    else cout << "Musica nao encontrada ;-;" << endl;

    return 0;
}

