#include <iostream>
#include <queue>

using namespace std;

int main (){
    queue<int> lista;
    int temp;

    for(int i = 0; i<10; i++){
        cout << "Digite o " << i << " numero: " << endl;
        cin >> temp;
        lista.push(temp); 
    }

    for(int j = 0; j<10; j++){
        cout << j << " elemento: " << lista.front() << endl;
        lista.pop(); 
    }

    return 0;
}