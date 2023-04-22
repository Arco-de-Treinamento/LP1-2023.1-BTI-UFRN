#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

int main (){
    string tempNome;
    vector<double> tempNotas(3);

    cout << "Digite o nome do aluno/a: " << endl;
    // Uso do getline pra nomes com espaço
    getline(cin, tempNome);

    for(int i = 0; i<3; i++){
        cout << "Digite a " << (i + 1) << " nota:" << endl;
        cin >> tempNotas[i];
    }

    map<string, vector<double>> alunos;
//    alunos[tempNome] = tempNotas;

    alunos.insert(make_pair(tempNome, tempNotas));

    double media = accumulate(alunos[tempNome].begin(), alunos[tempNome].end(), 0) / 3;

    cout << tempNome << " - media: " << media << endl;

    return 0;
}

