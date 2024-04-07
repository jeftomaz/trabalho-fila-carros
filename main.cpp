#include <iostream>
#include <cstddef>
using namespace std;

const int limite = 100;

struct Node{
    string nome, marca, modelo;
    Node* next;
};

typedef struct{
    Node* first; // aponta para a primeira posição da fila
    Node* last; // aponta para a última posição da fila
    int quantidade; // cria a variável que armazena a quantidade de carros
} Queue;

void init(Queue *carros) {
    carros->first = nullptr; //define a fila vazia na inicialização
    carros->last = nullptr; //define a fila vazia na inicialização
    carros->quantidade = 0; //define que não há carros armazenados ainda
}
/*
bool taCheio(Queue* carros) {
    return carros->quantidade >= carros->limite;
}
*/

// função que adiciona carros
void enqueue(Queue *carros, string nome, string marca, string modelo) {
    
    // verifica se a fila está cheia
    if(carros->quantidade >= limite) {
        cout << "Não é possível adicionar mais carros!\n" << endl;
        return;
    } else {

        // cria um novo node
        Node *novoNode = new Node{nome, marca, modelo, nullptr};

        // verifica se o primeiro carro (first) é nulo (não exite). Se está, define o first e last como novoNode. Se não, define o last e next como novoNode, e o next automaticamente recebe nullptr
        if(carros->first==nullptr) {
            carros->first = novoNode;
            carros->last = novoNode;
        } else {
            carros->last->next = novoNode;
            carros->last = novoNode;
        }
        carros->quantidade++;
    }

}

// função que remove carros

// verifica se o primeiro carro (first) é nulo (não exite).
void dequeue(Queue *carro) {
    if(carro->first==nullptr) {
        cout << "Fila vazia";

        return;
    } else {

        // cria um node temporário que recebe a primeira posição (first)
        Node *temp = carro->first;

        // verifica se há apenas um elemento na fila
        if(carro->first==carro->last) {
            carro->last=nullptr;
        }

        // a primeira posição recebe a posição seguinte (next)
        carro->first = carro->first->next;

        // indica ao usuário o carro sendo removido
        cout << "Removendo o carro: " << temp->nome << "\n";

        delete temp;
        carro->quantidade--;
        return;
    }
}

int main()
{
    Queue carros; // inicializa a fila
    init(&carros);

    // Adicionando carros
    enqueue(&carros,"Roberto", "Vw", "Gol");
    enqueue(&carros,"Fagner", "Fiat", "Uno");
    enqueue(&carros,"Davidson", "Renault", "Kwid");

    // Removendo carros
    dequeue(&carros);
    dequeue(&carros);
    dequeue(&carros);
    dequeue(&carros); // Tenta remover quando a fila está fazia

    return 0;
}