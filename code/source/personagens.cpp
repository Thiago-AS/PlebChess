
#include "../include/personagens.hpp"


Personagens::Personagens(tipo_personagens personagem_atual) {
    if(personagem_atual == arqueiro) {
          setVida(100);
          setDano(40);
          setPosY(0);
          setPosX(0);
          setQt_turnos(2);
          setQt_casas(2);
          setPersonagem(arqueiro);
    } else if(personagem_atual == guerreiro) {
          setVida(150);
          setDano(30);
          setPosY(0);
          setPosX(0);
          setQt_turnos(1);
          setQt_casas(1);
          setPersonagem(guerreiro);
    } else if(personagem_atual == cavaleiro) {
          setVida(250);
          setDano(20);
          setPosY(0);
          setPosX(0);
          setQt_turnos(2);
          setQt_casas(3);
          setPersonagem(cavaleiro);
    }

}
Personagens::~Personagens(void) {

}
	   // metodos getter and setters
int  Personagens::setVida(unsigned int p_vida) {
    vida = p_vida;
    return 1;
}
int  Personagens::setDano(unsigned int p_dano) {
    dano = p_dano;
    return 1;
}
int  Personagens::setPosX(unsigned int p_posX) {
    posX = p_posX;
    return 1;
}
int  Personagens::setPosY(unsigned int p_posY) {
    posY = p_posY;
    return 1;
}
int Personagens::setQt_turnos(unsigned int turnos){
    qt_turnos = turnos;
    return 1;
}
int Personagens::setQt_casas(unsigned int casas){
    qt_casas =  casas;
    return 1;
}
int  Personagens::setPersonagem(tipo_personagens tipo) {
    personagem = tipo;
    return 1;
}
unsigned int  Personagens::getVida() {
    return vida;
}
unsigned int  Personagens::getDano() {
    return dano;
}
unsigned int  Personagens::getPosX() {
    return posX;
}
unsigned int  Personagens::getPosY() {
    return posY;
}
unsigned int  Personagens::getQt_turnos() {
    return qt_turnos;
}
unsigned int  Personagens::getQt_casas() {
    return qt_casas;
}
tipo_personagens  Personagens::getPersonagem() {
    return personagem;
}
int Personagens::get_status_personagem(){
    if (getPersonagem()==zero_p){
        printf("Personagem :: ZERO \n");    
    } else if (getPersonagem()==arqueiro){
    	printf("Personagem :: ARQUEIRO \n"); 

    } else if (getPersonagem()==guerreiro){
    	printf("Personagem :: guerreiro \n");
    	
    } else if (getPersonagem()==cavaleiro){
    	printf("Personagem :: CAVALEIRO \n");
    	
    }
    printf("O personagem tem \nVida: %d Dano: %d\n",getVida(),getDano());
    printf("Esta na posicao: X:%d Y:%d\n",getPosX(),getPosY());
    printf("Limitacoes: Quantidade de turnos para ser produzido %d \n",getQt_turnos());
    printf("\tQuantidade de casas que podem ser andadas %d \n",getQt_casas());

}		

