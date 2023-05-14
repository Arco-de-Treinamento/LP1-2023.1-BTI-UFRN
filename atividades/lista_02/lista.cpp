#include <iostream>

using namespace std;

class Lista {
    private:
    int *data;  // ponteiro para o array que armazena os valores
    int size;   // tamanho atual da lista

    public:
    // construtor que recebe a capacidade inicial da lista
    Lista(int tam) {
        this->size = 0;
        this->data = new int[tam];
    }

    // retorna o elemento na posição passada como parâmetro
    int get(int index) { return data[index]; }

    // insere um valor na frente da lista
    void push_front(int valor) {
        for (int i = size; i > 0; i--) data[i] = data[i - 1];

        data[0] = valor;
        size++;
    }

    // insere um valor no fim da lista
    void push_back(int valor) {
        data[size] = valor;
        size++;
    }

    // insere um valor em uma determinada posição da lista
    void insert(int index, int valor) {
        for (int i = size; i > index; i--) data[i] = data[i - 1];

        data[index] = valor;
        size++;
    }

    // remove um valor da frente da lista
    void pop_front() {
        for (int i = 0; i < size - 1; i++) data[i] = data[i + 1];
        size--;
    }

    // remove o último elemento da lista
    void pop_back() { size--; }

    // remove o elemento localizado na posição passada como parâmetro
    void removeAt(int index) {
        for (int i = index; i < size - 1; i++) data[i] = data[i + 1];
        size--;
    }

    // retorna o tamanho da lista
    int sizeOf() { return size; }

    // procura um valor na lista
    int find(int valor) {
        for (int i = 0; i < size; i++) if (data[i] == valor) return i;
        return -1;
    }

    // remove todos os elementos da lista
    void deleteList() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    // ordena a lista de forma crescente com um inserction sort
    void sort() {
        int i, j, key;

        for (i = 1; i < size; i++) {
            key = data[i];
            j = i - 1;

            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    // ordena a lista de forma decrescente com um inserction sort
    void reverse() {
        int i, j, key;

        for (i = 1; i < size; i++) {
            key = data[i];
            j = i - 1;

            while (j >= 0 && data[j] < key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
};

int main() {
    Lista lista(5); // cria uma lista com capacidade inicial de 5 elementos

    lista.push_front(1);
    lista.push_front(2);
    lista.push_front(3);
    lista.push_back(4);
    lista.push_back(5);

    cout << "Lista inicial: ";
    for (int i = 0; i < lista.sizeOf(); i++) {
        cout << lista.get(i) << " ";
    }
    cout << endl;

    lista.insert(2, 6);

    cout << "Lista apos insercoes: ";
    for (int i = 0; i < lista.sizeOf(); i++) {
        cout << lista.get(i) << " ";
    }
    cout << endl;

    lista.pop_front();
    lista.pop_back();
    lista.removeAt(2);

    cout << "Lista apos remocoes: ";
    for (int i = 0; i < lista.sizeOf(); i++) {
        cout << lista.get(i) << " ";
    }
    cout << endl;

    int posicao = lista.find(4);
    cout << "Posicao do numero 4: " << posicao << endl;

    lista.sort();

    cout << "Lista ordenada crescentemente: ";
    for (int i = 0; i < lista.sizeOf(); i++) {
        cout << lista.get(i) << " ";
    }
    cout << endl;

    lista.reverse();

    cout << "Lista ordenada decrescentemente: ";
    for (int i = 0; i < lista.sizeOf(); i++) {
        cout << lista.get(i) << " ";
    }
    cout << endl;

    lista.deleteList(); 
    return 0;
}