#include <stdio.h>
#include <iostream>
#include <list>

void rodar(std::list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();
}

void mostrar(std::list<int> &lista){
    for(int x : lista)
        std::cout << x << " ";
    std::cout << "\n";
}

int main(){
    std::cout << "Digite qtd e primeiro" << std::endl;
    int qtd = 0;
    scanf("%i", &qtd);

    int primeiro = 0;
    std::cin >> primeiro;
    std:: cout<< "Digite o numero de saltos: "<<std::endl;
    int saltos = 0;
    std:: cin >> saltos;

    std::list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);


    while(lista.front() != primeiro)
        rodar(lista);

    mostrar(lista);
    while(lista.size() > 1){
        // Vai rodar o numeros de vezes do valor de salto
        for(int j = 0; j < saltos; j++)
        rodar(lista);

        lista.pop_front();
        mostrar(lista);
    }
    return 0;
}
