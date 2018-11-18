// "Copyright 2018 Mtonin"
#include "../include/lenhadora.hpp"
Lenhadora::Lenhadora() {
          setVida(100);
          setRecurso(madeira2);
          setQt_materia(5);
          setComprimento(2);
          setLargura(2);
          setConstrucao(30);
        }
Lenhadora::~Lenhadora() {}
int Lenhadora::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
  }
int Lenhadora::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
  qt_materia = materia;
    return 1;
}
int Lenhadora::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
  largura = p_lar;
    return 1;
}
int Lenhadora::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
  comprimento = p_com;
    return 1;
}
int Lenhadora::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
  construcao = p_const;
    return 1;
}
int  Lenhadora::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX + getLargura());
  posX = p_posX;
    return 1;}
int  Lenhadora::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY + getComprimento());
  posY = p_posY;
    return 1;}
int Lenhadora::setRecurso(tipo_recurso2 p_recurso) {
    recurso = p_recurso;
    return 1;
}
unsigned int Lenhadora::getVida() {
    return vida;}
unsigned int Lenhadora::getLargura() {
    return largura;}
unsigned int Lenhadora::getComprimento() {
    return comprimento;}
unsigned int Lenhadora::getQt_materia() {
    return qt_materia;}
unsigned int Lenhadora::getConstrucao() {
    return construcao;}
tipo_recurso2 Lenhadora::getRecurso() {
    return recurso;  }
unsigned int  Lenhadora::getPosX() {
    return posX;}
unsigned int  Lenhadora::getPosY() {
    return posY;}

void Lenhadora::get_status_unidade() {
    printf("UNidade :: Lenhadora \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
}
