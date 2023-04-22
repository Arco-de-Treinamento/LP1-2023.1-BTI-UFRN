#include <iostream>

using namespace std;

int soma(int a, int b);

int main (){
    int a, b;

    cout << "Digite o 1 numero da soma: " << endl;
    cin >> a;
    cout << "Digite o 2 numero da soma: " << endl;
    cin >> b;


    cout << "A soma é de todos os numeros é: " << soma(a, b) << endl;
    return 0;
}

int soma(int a, int b){
    if (b == a) return a;
    else return a + soma((a + 1), b);
}
