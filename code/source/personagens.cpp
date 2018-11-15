
#include "../include/personagens.hpp"


Personagens::Personagens(void){


}
Personagens::~Personagens(void){

}
	   // metodos getter and setters
int  Personagens::setVida(unsigned int p_vida){
    vida = p_vida;
    return 1;
}
int  Personagens::setDano(unsigned int p_dano){
    dano = p_dano;
    return 1;
}
int  Personagens::setPosX(unsigned int p_posX){
    posX = p_posX;
    return 1;
}
int  Personagens::setPosY(unsigned int p_posY){
    posY = p_posY;
    return 1;
}
unsigned int  Personagens::getVida(){
    return vida;
}
unsigned int  Personagens::getDano(){
    return dano;
}
unsigned int  Personagens::getPosX(){
    return posX;
}
unsigned int  Personagens::getPosY(){
    return posY;
}
tipo_personagens  Personagens::getPersonagem(){
    return personagem;
}
		

