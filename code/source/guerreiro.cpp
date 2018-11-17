
#include "../include/guerreiro.hpp"

Guerreiro::Guerreiro() {
          setVida(150);
          setDano(30);
          setPosY(0);
          setPosX(0);
          setQt_turnos(1);
          setQt_casas(1);
}
Guerreiro::~Guerreiro(void) {

}
	   // metodos getter and setters
int  Guerreiro::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
	vida = p_vida;
    return 1;
}
int  Guerreiro::setDano(unsigned int p_dano) {
    rest_eh_positivo(p_dano);
	dano = p_dano;
    return 1;
}
int  Guerreiro::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
	rest_limiteLin_sup(p_posX);
	posX = p_posX;
    return 1;
}
int  Guerreiro::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
	rest_limiteCol_sup(p_posY);
	posY = p_posY;
    return 1;
}
int Guerreiro::setQt_turnos(unsigned int turnos){
    rest_eh_positivo(turnos);
	qt_turnos = turnos;
    return 1;
}
int Guerreiro::setQt_casas(unsigned int casas){
    rest_eh_positivo(casas);
	qt_casas =  casas;
    return 1;
}
unsigned int  Guerreiro::getVida() {
    return vida;
}
unsigned int  Guerreiro::getDano() {
    return dano;
}
unsigned int  Guerreiro::getPosX() {
    return posX;
}
unsigned int  Guerreiro::getPosY() {
    return posY;
}
unsigned int  Guerreiro::getQt_turnos() {
    return qt_turnos;
}
unsigned int  Guerreiro::getQt_casas() {
    return qt_casas;
}
int Guerreiro::get_status_personagem(){
   	printf("Personagem :: guerreiro \n");
    printf("O personagem tem \nVida: %d Dano: %d\n",getVida(),getDano());
    printf("Esta na posicao: X:%d Y:%d\n",getPosX(),getPosY());
    printf("Limitacoes: Quantidade de turnos para ser produzido %d \n",getQt_turnos());
    printf("\tQuantidade de casas que podem ser andadas %d \n",getQt_casas());

}		

