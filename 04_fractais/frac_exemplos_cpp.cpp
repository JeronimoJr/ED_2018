#include <lib/pen.h>

 //Trigo
/*void trigo(Pen& p, int lado){
    float angulo = 45;

    if(lado <= 0)
        return;
    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.left(angulo);
        trigo(p, lado * 0.30);
        p.right(angulo*2);
        p.setColor(rand() % 255,rand() % 255,rand() % 255 );
        trigo(p, lado * 0.30);
        p.left(angulo);
    }
    for(int i = 0; i < 4; i++){
        p.walk(-lado);
    }
}*/

/* Floco de Neve
void gelo(Pen& p,int aux, int lado){
    float angulo = 72;
    if(aux == 0 || lado < 3)
    return;

    p.walk(lado);
    gelo(p,5, lado *0.36);
    p.walk(-lado);
    p.right(angulo); // 360*0.2
    p.setColor(rand() % 255,rand() % 255,rand() % 255);
    aux--;
    gelo(p,aux, lado);
}*/

//Circulo
/*void circulos(Pen& p, double lado){
    double angulo = 60;
    if(lado < 1)
        return;

    p.circle(lado);

    for(int i = 0; i < 6; i++){
        p.setColor(rand() % 255,rand() % 255,rand() % 255);
        p.left(angulo);
        p.up();
        p.walk(lado);
        p.down();
        circulos(p,lado*0.33);
        p.up();
        p.walk(-lado);
        p.down();
    }
}*/

void arvore(Pen& p, int lado){
    float angulo = 35;
    float dec = 17;
    if(lado < 10)
        return;
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(angulo);
    arvore(p, lado - dec);
    p.left(angulo);
    arvore(p, lado-dec);
    p.left(angulo);
    arvore(p,lado - dec);
    p.right(angulo);
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(-lado);
}

void fractal(){
    Pen p(800, 600);
   //Circulo p.setXY(400,300);
    p.setXY(400,300);
   //Circulo p.setThickness(2);
    p.setThickness(2);
    //Trigo p.setXY(400, 500);
    //gelo p.setXY(400,300)
    //Circulo p.setHeading(0);
    p.setHeading(90);
   //trigo p.setHeading(90);
    //gelo p.setHeading(60);

    p.setSpeed(0);

    int lado = 100;
    arvore(p,lado);
    //circulos(p,200);
    // trigo(p,80);
    //gelo(p,5,200);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
