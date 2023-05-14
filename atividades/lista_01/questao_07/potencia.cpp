#include <iostream>

using namespace std;

int potencia(int base, int expoente);

int main (){
    int base, expoente;

    cout << "Digite a base da potencia que sera calculada: " << endl;
    cin >> base;
    cout << "Digite o expoente da potencia que sera calculada: " << endl;
    cin >> expoente;


    cout << "A potencia é: " << potencia(base, expoente) << endl;
    return 0;
}

int potencia(int base, int expoente){
    if (expoente == 0) return 1;
    else return base * potencia(base,(expoente - 1));
}
