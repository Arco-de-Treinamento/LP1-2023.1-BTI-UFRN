#include <iostream>
using namespace std;

// Classe No
class No {
public:
    int data;
    No* prox;

    No(int valor){
        data = valor;
        prox = NULL;
    }
};

class ListaEncadeada {
private:
    No* head;
    int size;

public:
    ListaEncadeada() {
        head = NULL;
        size = 0;
    }

    // Insere um valor na frente da lista
    void push_front(int valor) {
        No* novoNo = new No(valor);
        novoNo->prox = head;
        head = novoNo;
        size++;
    }


    // Insere um valor no fim da lista
    void push_back(int valor) {
        No* novoNo = new No(valor);

        if (head == NULL) {
            head = novoNo;
        } else {
            No* temp = head;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novoNo;
        }
        size++;
    }

    // Remove o primeiro elemento da lista
    void pop_front() {
        No* temp = head;
        head = head->prox;
        delete temp;
        size--;
    }

    // Remove o último elemento da lista
    void pop_back() {
        No* temp = head;
        while (temp->prox->prox != NULL) {
            temp = temp->prox;
        }
        delete temp->prox;
        temp->prox = NULL;
        
        size--;
    }

    // Imprime a lista completa
    void print() {
        No* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ,";
            temp = temp->prox;
        }
        cout << endl;
    }

    // Remove um elemento da lista
    void remove(int elemento) {
        // Verifica se a lista ta vazia
        if (head == NULL) {
            cout << "Lista vazia" << endl;
            return;
        }

        // Verifica se o elemento é o primeiro da lista e remove com pop_front
        if (head->data == elemento) {
            pop_front();
            return;
        }

        No* temp = head;

        // Procura o elemento na lista
        while (temp->prox != NULL && temp->prox->data != elemento) {
            temp = temp->prox;
        }
        if (temp->prox != NULL) {
            No* temp2 = temp->prox;
            temp->prox = temp2->prox;
            delete temp2;
            size--;
        } else {
            cout << "Elemento não encontrado" << endl;
        }
    }

    // Retorna o tamanho da lista
    int sizeOf() { return size;}

    // Busca um elemento na lista
    bool find(int valor) {
        No* temp = head;
        while (temp != NULL) {
            if (temp->data == valor) {
                return true;
            }
            temp = temp->prox;
        }
        return false;
    }

    // Remove todos os elementos da lista
    void clear() {
        while (head != NULL) {
            No* temp = head;
            head = head->prox;
            delete temp;
        }
        size = 0;
    }
};

int main() {
    ListaEncadeada lista;

    lista.push_front(5);
    lista.push_front(10);
    lista.push_back(15);
    lista.push_back(20);
    lista.print(); 

    lista.pop_front();
    lista.pop_back();
    lista.print(); 

    lista.remove(15);
    lista.print();

    cout << "Tamanho da lista: " << lista.sizeOf() << endl;
    cout << "Busca elemento 5: " << lista.find(5) << endl; 

    // Limpa a lista
    lista.clear();
    lista.print(); 

    return 0;
}

// Para criar essa lista partindo do codigo criado em sala listas sequencial com a diferenca de que optei por utilizar classes