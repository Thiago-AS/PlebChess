// "Copyright 2018 Grupo MP"
#include "../include/fortaleza.hpp"
Fortaleza::Fortaleza() {
         setVida(500);
          setRecurso(nada3);
          setQt_materia(0);
          setComprimento(4);
          setLargura(2);
          setConstrucao(999999);}
Fortaleza::~Fortaleza() {}
int Fortaleza::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
}
int Fortaleza::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
  qt_materia = materia;
    return 1;
}
int Fortaleza::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
  largura = p_lar;
    return 1;
}
int Fortaleza::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
  comprimento = p_com;
    return 1;
}
int Fortaleza::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
  construcao = p_const;
    return 1;}
int  Fortaleza::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX + getLargura());
  posX = p_posX;
    return 1;}
int  Fortaleza::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY + getComprimento());
  posY = p_posY;
    return 1;}
int Fortaleza::setRecurso(tipo_recurso3 p_recurso) {
    recurso = p_recurso;
    return 1;}
unsigned int Fortaleza::getVida() {
    return vida;}
unsigned int Fortaleza::getLargura() {
    return largura;}
unsigned int Fortaleza::getComprimento() {
    return comprimento;}
unsigned int Fortaleza::getQt_materia() {
    return qt_materia;}
unsigned int Fortaleza::getConstrucao() {
    return construcao;}
tipo_recurso3 Fortaleza::getRecurso() {
    return recurso;  }
unsigned int  Fortaleza::getPosX() {
    return posX;}
unsigned int  Fortaleza::getPosY() {
    return posY;}

void Fortaleza::get_status_unidade() {
    printf("UNidade :: Fortaleza \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
  }
