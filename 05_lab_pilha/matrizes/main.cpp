#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';


void showMat(matchar &mat, vector<Par> pilha, Par inicio, Par fim){
    mat_draw(mat);

    for(Par par : pilha)
        mat_focus(par, 'c');

    if(pilha.size() > 0)
    mat_focus(pilha.back(),'k');

    mat_focus(inicio, 'g');
    mat_focus(fim,'r');
}

vector <Par> getNeib(Par par){
    vector<Par> vizinhos;

    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;

       return cont;
}

vector<Par> shuffle(vector<Par> vet){
       std:: random_shuffle(vet.begin(), vet.end());
    return vet;
}

void criar_lab(matchar &mat, vector<Par> &pilha){
    mat.get(Par(1,1)) = ABERTO;
    pilha.push_back(Par(1,1));

    while (pilha.size() != 0) {
        Par topo;
        topo = pilha.back();

        vector<Par> vizinhos_fechados;
        for(Par par : getNeib(topo)){
            if(mat.get(par) == PAREDE){
                if(countOpen(mat, par) <= 1)
                vizinhos_fechados.push_back(par);              
            }
        }

        // Selecione aleatoriamente um desses vizinhos ,fure e empilhe
        if(vizinhos_fechados.size() > 0){
            Par escolhido = vizinhos_fechados[rand() % vizinhos_fechados.size()];
            mat.get(escolhido) = ABERTO;
            pilha.push_back(escolhido);
        }
        // Se não existe  desempilhe o topo
        else if(vizinhos_fechados.size() == 0)
            pilha.pop_back();
    }

}

bool findPath(matchar &mat, Par inicio,Par final){
   vector<Par> pilha;

    pilha.push_back(inicio);
    mat.get(inicio) = EMBUSCA;

    while(pilha.size() > 0){
        Par topo = pilha.back();

        if(topo == final){
            showMat(mat,pilha,inicio, final);
            ed_show();
            return true;
        }

        vector<Par> vizinhos_abertos;
        // showMat(mat,pilha, inicio , final);
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO){
                vizinhos_abertos.push_back(par);
                mat_focus(par,'r');
            }
        }
        //ed_show();
        if(vizinhos_abertos.size() == 0){
           pilha.pop_back();
        }


        else{
            Par escolhido = vizinhos_abertos[rand()% vizinhos_abertos.size()];
            mat.get(escolhido) = EMBUSCA;
            pilha.push_back(escolhido);
        }

    }

   return false;

}

int main(){

    vector<Par> pilha;
    srand(time(NULL));
    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matchar mat(15, 20,PAREDE);


   criar_lab(mat,pilha);
    mat_draw(mat);
    ed_show();

    Par inicio = mat_get_click(mat, "Digite o local do inicio");

    Par final = mat_get_click(mat, "Digite o local final");

    mat_draw(mat);
    ed_show();

    findPath(mat, inicio, final);


    ed_lock();//impede que termine abruptamente

    return 0;
}


