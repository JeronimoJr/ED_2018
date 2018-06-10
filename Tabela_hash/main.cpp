#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct HashLinear{ //linear probing
    pair<Elem, Marcador> * vet;
    int capacity;
    int size;
    HashLinear(int capacity){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = VAZIO;
        }
    }
/*
    bool insert(Elem elem){
        auto it = find(elem.key);
        if(it == nullptr)
            return false;
        int pos = elem.key % capacity;
        while(pos != VAZIO || pos != DELETADO){
             pos = (pos + 1) % capacity;
            it->pair.first.key
        }

           pos.marc
        pos.elem = elem
        pos.marcador = CHEIO
        size ++;

    }
*/
    // Feito
    bool remove(int key){
        auto it = find(key); //feito
            if(it != nullptr){ // feito
            it->pair.first.key  = DELETADO;
            size--;
            return true; //feito
        }
           return false;
    }

    // Feito
    pair<Elem, Marcador> * find(int key){
        int pos = key % capacity;

        while(true){
            if(vet[pos].first == VAZIO){
                return nullptr;
            }
            if(vet[pos].first == key){
                return &vet[pos];
                pos = (pos + 1) % capacity;
            }
        }
       return nullptr;
    }


    void resize(int capacity){
        auto vet_old = vet;
        vet = new pair<...>[capacity];
        for(auto i = 0; ...)
            vet[i].marcador = VAZIO;
        for(auto& elem : vet_old)
            insert(elem);
        delete vet_old;
    }

}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
