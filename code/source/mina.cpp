// "Copyright 2018 Mtonin"
#include "../include/mina.hpp"
Mina::Mina() {
          setVida(200);
          setRecurso(ouro);
          setQt_materia(10);
          setComprimento(2);
          setLargura(2);
          setConstrucao(50);}
Mina::~Mina() {}
int Mina::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
    vida = p_vida;
    return 1;
}
int Mina::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
    qt_materia = materia;
    return 1;
}
int Mina::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
    largura = p_lar;
    return 1;
}
int Mina::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
    comprimento = p_com;
    return 1;
}
int Mina::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
    construcao = p_const;
    return 1;
}
int  Mina::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
    rest_limiteLin_sup(p_posX + getLargura());
    posX = p_posX;
    return 1;}
int  Mina::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
    rest_limiteCol_sup(p_posY + getComprimento());
    posY = p_posY;
    return 1;}
int Mina::setRecurso(tipo_recurso p_recurso) {
    recurso = p_recurso;
    return 1;
}
unsigned int Mina::getVida() {
    return vida;}
unsigned int Mina::getLargura() {
    return largura;}
unsigned int Mina::getComprimento() {
    return comprimento;}
unsigned int Mina::getQt_materia() {
    return qt_materia;}
unsigned int Mina::getConstrucao() {
    return construcao;}
tipo_recurso Mina::getRecurso() {
    return recurso;  }
unsigned int  Mina::getPosX() {
    return posX;}
unsigned int  Mina::getPosY() {
    return posY;}

void Mina::get_status_unidade() {
       printf("UNidade :: MINA \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
}
