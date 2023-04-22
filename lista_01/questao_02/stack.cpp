#include <iostream>
#include <stack>

using namespace std;

int main (){
    stack<int> stack;
    int temp;

    for(int i = 0; i<10; i++){
        cout << "Digite o " << i << " numero: " << endl;
        cin >> temp;
        stack.push(temp); 
    }


    for(int x = 0, j = 10; x<10; x++, j--){
        cout << j << " elemento: " << stack.top() << endl;
        stack.pop();     
    }

    return 0;
}