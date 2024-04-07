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

        cout << "\nCarro Adicionado!\n";
        carros->quantidade++;
    }

}

// função que remove carros

// verifica se o primeiro carro (first) é nulo (não exite).
void dequeue(Queue *carro) {
    if(carro->first==nullptr) {
        cout << "Fila vazia!";

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
        cout << "Veículo Removido: " << temp->nome << "\n";

        delete temp;
        carro->quantidade--;
        return;
    }
}

// lista todos os carros
void list(Queue *carro) {
    Node *atual = carro->first; // ponteiro temporário para percorrer a lista

    int count = 1;

    while(atual != nullptr) {
        cout << "Carro " << count << ":\n";
        cout << "Condutor: " << atual->nome << "\n";
        cout << "Marca: " << atual->marca << "\n";
        cout << "Modelo: " << atual->modelo << "\n\n";

        atual = atual->next; // aponta para o próximo da lista
        count++;
    }
}

void menu(){

    // inicializa a fila
    Queue carros;
    init(&carros);


    int opt;
    string nome, marca, modelo;

    do {

        cout << "\nEscolha uma opção\n\n";
        cout << "1 - Adicionar novo carro\n";
        cout << "2 - Remover carro\n";
        cout << "3 - Listar todos os carro\n";
        cout << "4 - Sair\n";
        cout << "Opção: ";
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "Adicionando Novo Carro\n";

            cout <<"Qual o nome do condutor? Nome: ";
            cin >> nome;

            cout << "Qual a marca do veículo? Marca: ";
            cin >> marca;

            cout <<"Qual o modelo do veiculo? Modelo: ";
            cin >> modelo;

            enqueue(&carros, nome, marca, modelo);

            break;
        
        case 2:
            cout << "Removendo Veículo\n";
            dequeue(&carros);
            break;

        case 3:
            cout << "\nLista de Carros\n\n";
            list(&carros);
            break;

        case 4:
            cout << "Finalizando o sistema... \n";

        default:
            cout << "Opção Inválida!\n";
        }
    } while (opt != 4);
}

int main()
{
    menu();
}