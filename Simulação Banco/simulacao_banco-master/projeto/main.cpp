#include <random>
#include "Libs/pintor.h"

#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>//funcao time
#include <stdlib.h> //funcao srand

using namespace std;

const int TURNOS_DIA = 360;

const int MAX_CAIXAS = 10;

const int CUSTO_CAIXA_DIA = 100;

const int N_EXEC_TESTE = 100;

int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}

int simulacao(int min_clientes, int max_clientes, int dias){

    int min_pac = 1, max_pac = 10;
    int min_doc = 1, max_doc = 5;

    int qtd_banco = 0;

    int tempo = TURNOS_DIA;
    int numCaixas = 5;

    std::vector<Cliente*> caixa(numCaixas);
    std::list<Cliente*> fila_atendimento;
    std:: list<Cliente*> fila_entrar_banco; // galera que quer entrar no banco
    std:: list<Cliente*> fila_saida; // fila para sair do banco
    std:: list<Cliente*>::iterator it;

    int lucro[10]; //lista de lucro
    int lucro_total[10] = {0,0,0,0,0,0,0,0,0,0};
    int saldo = 0;


/*--------------------laço para verificar a médias em tantos *dias-------------*/
for(int d = 0; d < dias; d++){
   for(numCaixas = 1; numCaixas <= MAX_CAIXAS; numCaixas++) {
/*----------------laço que varia o numero de caixas-----------------*/

       qtd_banco = 0;
       saldo = 0;

         /*----------laço que movimenta o banco-------------------*/
       for ( int i = 0; i < tempo; i++){

        /*----------Gerando clientes aleatoriamente-------------------*/
        int qtd_clientes = rand_mm(min_clientes,max_clientes);
        for(int j = 0; j < qtd_clientes; j++){
            fila_entrar_banco.push_back(new Cliente(rand_mm(min_pac, max_pac), rand_mm(min_doc,max_doc))); //crio meus clientes
        }
        /*----------Fim do laço----------------------------------------*/

  /*----------Colocando clientes no banco-------------------*/
        int pessoas_banco = 0;
            while(!fila_entrar_banco.empty()){
                if(pessoas_banco <= max_clientes ){
                    fila_atendimento.push_back(fila_entrar_banco.front()); // pego o cliente da frente e coloco na fila de espera do banco
                    fila_entrar_banco.pop_front();
                    pessoas_banco++;
                }
                else
                    fila_entrar_banco.pop_front();

            }
  /*----------Fim do laço-------------------*/

  /*----------Tirando as pessoas sem paciência-------------------*/
for(auto it = fila_atendimento.begin(); it != fila_atendimento.end(); it++){
    Cliente *aux = *it;

    if(aux->paciencia < min_pac){
        it = fila_atendimento.erase(it);
        it--;
        delete aux;
    }
    else
        aux->paciencia--;

}
  /*----------Fim do laço-------------------*/




  /*----------caixas atendendo e despachando clientes-------------------*/

for(int t = 0; t < numCaixas; t++){
    if(caixa[t] != nullptr){
        if(caixa[t]->documentos >= 1){
            caixa[t]->documentos--;
            saldo++;
        }
        else{
            fila_saida.push_back(caixa[t]);
            //delete caixa[t];
            caixa[t] = nullptr;
        }
    }
    else if(!fila_atendimento.empty()){
            caixa[t] = fila_atendimento.front();
            fila_atendimento.pop_front();
        }
    }
/*----------Fim do laço-------------------*/




/*----------Tirando os clientes do caixa-------------------*/
while(!fila_saida.empty()){
    fila_saida.pop_front();
    pessoas_banco--;
}



} // FIM DO LAÇO QUE MOVIMENTA O BANCO //

        lucro[numCaixas-1] = saldo - (numCaixas * 100);

}/*----------------Fim laço que varia o numero de caixas-----------------*/

for(int i = 0; i < 10; i++)
  lucro_total[i] += lucro[i];

}// Fim do laço que conta os dias


for(int i = 0; i < 10; i++)
    cout << "o lucro medio para " << i + 1 << " caixas em " << dias <<" dias é: " << lucro_total[i] / dias << endl;

   int maior = lucro_total[0];
   int res = 0;
   for(int s = 1;s < 10; s++){
       if(lucro_total[s] > maior){
           maior = lucro_total[s];
           res = s;
       }
   }
   cout << "A quantidade de caixa ideal é: " << res + 1 << " O lucro médio foi de " << lucro_total[res] / dias << endl;

   return lucro_total[res]/dias;
}// Fim do laço da função


int main (){
    int min_clientes, max_clientes;

    cout << "Digite a quantidade minima de clientes: "<< endl;
       cin >> min_clientes;
    cout<<"Digite a quantidade maxima de clientes: "<<endl;
       cin >> max_clientes;

      int recebe =  simulacao(min_clientes,max_clientes,100);

      cout<<"\n"<<recebe<<endl;
    return 0;
}
