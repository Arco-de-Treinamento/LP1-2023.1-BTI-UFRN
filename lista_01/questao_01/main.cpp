#include <iostream>
#include "area.hpp"
using namespace std;

int main (){
    int op = 0;
    cout << "Escolha a operação: " << endl;
    cout << "1 - Area do retangulo/quadrado" << endl;
    cout << "2 - Area do triangulo" << endl;
    cout << "3 - Area do circulo" << endl;

    cin >> op;
    float a, b, result;

    switch(op){
        case 1:
            cout << "Digite o valor da altura: " << endl;
            cin >> a;
            cout << "Digite o valor da base: " << endl;
            cin >> b;
            cout << "Area: " << areaRetagulo(a, b) << endl;
        case 2:
            cout << "Digite o valor da altura: " << endl;
            cin >> a;
            cout << "Digite o valor da base: " << endl;
            cin >> b;
            cout << "Area: " << areaTriangulo(a, b) << endl;
        case 3:
            cout << "Digite o valor do raio: " << endl;
            cin >> a;
            cout << "Area: " << areaCirculo(a) << endl;
            break;
        default:
            cout << "Operação inválida!";
    } 
    
    return 0;
}