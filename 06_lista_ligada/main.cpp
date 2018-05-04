#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node* next;

    //Construtores
    Node(int value = 0, Node* next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{
    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        head = deletarTudo(head);
    }

    Node* deletarTudo(Node* node){
        if(node == nullptr)
            return nullptr;

        deletarTudo(node->next);

        delete node;
        return nullptr;
    }


    Node * arrancaRabo(Node * node, int value){
            if(node == nullptr)
                return nullptr;
    node->next = arrancaRabo(node->next, value);
    if(node->next == nullptr){
        if(node->value != value){
            delete node;
            return nullptr;
        }else{
            return node;
        }
    }
    return node;
   }

    // Feito
    Node* cortarRabo(Node* node, int value){
        // A lista chegou no final
        if(node == nullptr)
            return nullptr;
        // Atualizo o meu node
        node->next = cortarRabo(node->next,value);
       // Quando achar o node que estou procurando, deleto ele e corto os demais nós da lista
        if(node->value == value){
            delete node;
            return nullptr;
        }
        //Retorno o no atualizado
        return node;
    }

    void push_front(int value){
        Node* node = new Node(value); //Cria um novo nó
        node->next = head; // o next apontar para valor de head, então head aponta para o node
        this->head = node;
    }


    void pop_front(int value){
        if(head == nullptr)
            return;
        Node* aux;
        aux = head; // Guardo a referência
        this->head = head->next; // Aponto para o próximo nó
        delete aux; // Deleto o valor
    }
    //Consertado
    void push_back(int value){
         Node* node = head;
         Node* anterior = nullptr;
        if(head ==  nullptr){
            head = new Node(value);
            return;
        }

        while (node != nullptr) {
            anterior = node;
            node = node->next;
        }
        anterior->next = new Node(value);
    }

    // feito
    Node * r_push_back(Node * node, int value){
            if(node == nullptr){
                node = new Node(value,nullptr);
                //return nullptr;
            }
            else
                node->next = r_push_back(node->next,value);
            return node;
    }
    // Feito
    void rpush_back(int value){
        this->head = r_push_back(head,value);
    }


    Node* _rpop_back(Node* node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }

       node->next = _rpop_back(node->next);
    }

    void rpop_back(){
           this->head = _rpop_back(head);
       }


    void pop_back(int value){
        if(head == nullptr)
            return;

        if(head->next == nullptr){
           delete head;
            head = nullptr;
            return;
        }

        auto node = head;

        while(node->next->next != nullptr)
            node = node->next;

        delete node->next;
        node->next = nullptr;

    }
    void show(){
        Node* node = head;
        while(node != nullptr){
            cout<<node->value<<" ";
            node = node->next;
        }
         cout<<"\n";
    }

    void _rshow(Node* node){
        if(node == nullptr)
            return;

        cout<<node->value<<" ";
        _rshow(node->next);
    }
    void rshow(){
        _rshow(head);
        cout << endl;
    }


    Node* _remove(Node* node, int value){
       if(node == nullptr)
           return nullptr;

        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }

       node->next = _remove(node->next,value);
    }

    void remove(int value){
        head = _remove(head,value);
    }

    // Feito
    void iremove(int value){
        Node* node = head;
        Node* anterior = nullptr;

        while(node != nullptr && node->value != value){
            anterior = node;
            node = node->next;
        }
        // lista vazia
        if(node == nullptr)
            return;
        // Removendo elemento do inicio da lista, faço a cabeça apontar para o próximo valor da lista
        if(anterior == nullptr)
            head = node->next;
        else
            anterior->next = node->next; // Removendo elemento do meio da lista, utilizo as ligaçõe sintermediáras

    }

        //Feito
    int rsomar(Node * node){
           if(node == nullptr)
               return 0;
         return node->value + rsomar(node->next);
    }

    // Feito
    Node * _rinserir_ordenado(Node * node, int value){
           if(node ==  nullptr || node->value > value){
               node = new Node(value,node);
            return node;
           }
           else
               node->next = _rinserir_ordenado(node->next,value);
       }

        // Feito
    void rinserir_ordenado(int value){
            this->head = _rinserir_ordenado(head,value);
        }

    int size(Node *node){
    int cont = 0;

    while(node != nullptr){
        cont++;
        node = node->next;
    }
        return cont;
   }

    int _rsize(Node* node){
    int cont = 0;

        if(node == nullptr)
            return 0;

       cont+= _rsize(node->next);
        return cont + 1;
    }

    //void rsize(){
      //  this->head = _rsize(head);
    //}
};


int main(){
    SList lista;

    lista.push_back(10);
    lista.push_back(12);
    lista.push_back(13);

    lista._rshow(lista.head);

    int aux = 0;
    aux = lista.rsomar(lista.head);
            cout << "\nSoma: " <<aux << endl;
            lista.iremove(12);
            lista.iremove(13);
     lista._rshow(lista.head);
     lista.rpush_back(14);
     lista.rpush_back(17);
     lista.rpush_back(45);
     lista._rshow(lista.head);
     cout<<"\nInserindo valores ordenadamente\n";

     SList listen;
     listen.rinserir_ordenado(34);
     listen.rinserir_ordenado(12);
     listen.rinserir_ordenado(2);
     listen.rinserir_ordenado(44);
     listen.rinserir_ordenado(28);
     listen._rshow(listen.head);
    cout<<"\n";

    cout<<"Tamanho da lista 'listen' eh "<<listen.size(listen.head)<<endl;
    cout<<"Tamanho da lista 'listen' eh "<<listen._rsize(listen.head)<<endl;
    listen.show();
    //listen.deletarTudo(listen.head);
    //cout<< "Tamanho da lista 'listen' eh "<<listen.size(listen.head)<<endl;
    listen.arrancaRabo(listen.head,12);
    // 2 12 28 34 44
    listen.show();
cout<<"----------------------------------------\n";
    SList teste;
    teste.rinserir_ordenado(10);
    teste.rinserir_ordenado(7);
    teste.rinserir_ordenado(31);
    teste.rinserir_ordenado(26);
    teste.rinserir_ordenado(18);

    teste.show();
    teste.cortarRabo(teste.head, 18);
    teste.show();
cout<<"Testando remover elemento\n";
    SList li;
    li.rpush_back(12);
    li.rpush_back(7);
    li.rshow();
    cout<<"Tamanho da lista: "<<li.size(li.head)<<endl;
    li.iremove(7);
    li.rshow();
    cout<<"Tamanho da lista: "<<li.size(li.head)<<endl;



        return 0;
}

