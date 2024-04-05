#include <iostream>
#include <cstddef>
using namespace std;

const int limite = 100;

typedef struct Node {
    string nome, marca, modelo;
    Node *next;
} Node;

typedef struct{
    Node* first; // aponta para a primeira posição da fila
    Node* last; // aponta para a última posição da fila
    int quantidade; // cria a variável que armazena a quantidade de carros
} Queue;

void init(Queue* carros) {
    carros->first = nullptr; //define a fila vazia na inicialização
    carros->last = nullptr; //define a fila vazia na inicialização
    carros->quantidade = 0; //define que não há carros armazenados ainda
}
/*
bool taCheio(Queue* carros) {
    return carros->quantidade >= carros->limite;
}
*/
void enqueue(Queue* carros, string nome, string marca, string modelo) {
    
    // verifica se a fila é maior ou igual ao limite de carros
    if(carros->quantidade >= limite)
    {
        cout << "Não é possível adicionar mais carros!\n" << endl;
        return;
    }

    Node* novoNode = new Node{nome, marca, modelo, nullptr};

    // verifica se a fila está vazia

    if(carros->first==nullptr) {
        carros->first = novoNode;
        carros->last = novoNode;
    } else {
        carros->last->next = novoNode;
        carros->last = novoNode;
    }

    carros->quantidade++;

}

int main()
{
    Queue carros;

    return 0;
}