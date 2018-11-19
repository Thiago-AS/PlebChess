#include "../include/quadrado.hpp"
    Quadrado::Quadrado() {

    }
   Quadrado::~Quadrado() {

    }		
int  Quadrado::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX);
  posX = p_posX;
    return 1;
}
int  Quadrado::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY);
  posY = p_posY;
    return 1;
}

int Quadrado::setHumano(bool humano) {
  eh_humano = humano;
  return 1;
}
int Quadrado::setUsado(bool uso) {
  usado = uso;
  return 1;
}

unsigned int  Quadrado::getPosX() {
    return posX;
}
unsigned int  Quadrado::getPosY() {
    return posY;
}    

bool Quadrado::getHumano() {
     return eh_humano;
}
bool Quadrado::getUsado() {
    return usado;
}    
void Quadrado::unidadeMorta() {
    setUsado(false);
    setPosY(-1);
    setPosX(-1);

}