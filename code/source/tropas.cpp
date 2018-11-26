// "Copyright 2018 Grupo MP"
#include "../include/tropas.hpp"
Arqueiro::Arqueiro() {
          setVida(100);
          setDano(40);
          setPosY(0);
          setPosX(0);
          setQt_turnos(2);
          setQt_casas(2);
          setAtivo(0);
}
Arqueiro::~Arqueiro(void) {
}
     // metodos getter and setters
int  Arqueiro::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
}
int  Arqueiro::setDano(unsigned int p_dano) {
    rest_eh_positivo(p_dano);
  dano = p_dano;
    return 1;
}
int  Arqueiro::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX);
  posX = p_posX;
    return 1;
}
int  Arqueiro::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY);
  posY = p_posY;
    return 1;
}
int Arqueiro::setQt_turnos(unsigned int turnos) {
    rest_eh_positivo(turnos);
  qt_turnos = turnos;
    return 1;
}
int Arqueiro::setQt_casas(unsigned int casas) {
    rest_eh_positivo(casas);
  qt_casas =  casas;
    return 1;
}
int Arqueiro::setAtivo(int valor) {
    // deve ser inicializado com 0, e quando inserido no tabuleiro
    // e estiver vivo, setado em 1
    ativo = valor;
    return 1;
}
unsigned int  Arqueiro::getVida() {
    return vida;
}
unsigned int  Arqueiro::getDano() {
    return dano;
}
unsigned int  Arqueiro::getPosX() {
    return posX;
}
unsigned int  Arqueiro::getPosY() {
    return posY;
}
unsigned int  Arqueiro::getQt_turnos() {
    return qt_turnos;
}
unsigned int  Arqueiro::getQt_casas() {
    return qt_casas;
}
unsigned int Arqueiro::getAtivo() {
    return ativo;
}
int Arqueiro::get_status_personagem() {
    printf("Personagem :: Arqueiro \n");
    printf("O personagem tem \nVida: %d Dano: %d\n", getVida(), getDano());
    printf("Esta na posicao: X:%d Y:%d\n", getPosX(), getPosY());
    printf("Limitacoes: Quantidade de turnos para ser produzido");
    printf("%d\n", getQt_turnos());
    printf("\tQuantidade de casas que podem ser andadas %d \n", getQt_casas());
}
Cavaleiro::Cavaleiro() {
          setVida(250);
          setDano(20);
          setPosY(0);
          setPosX(0);
          setQt_turnos(2);
          setQt_casas(3);
          setAtivo(0);
}
Cavaleiro::~Cavaleiro(void) {
}
     // metodos getter and setters
int  Cavaleiro::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
}
int  Cavaleiro::setDano(unsigned int p_dano) {
    rest_eh_positivo(p_dano);
  dano = p_dano;
    return 1;
}
int  Cavaleiro::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX);
  posX = p_posX;
    return 1;
}
int  Cavaleiro::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY);
  posY = p_posY;
    return 1;
}
int Cavaleiro::setQt_turnos(unsigned int turnos) {
    rest_eh_positivo(turnos);
  qt_turnos = turnos;
    return 1;
}
int Cavaleiro::setQt_casas(unsigned int casas) {
    rest_eh_positivo(casas);
  qt_casas =  casas;
    return 1;
}
int Cavaleiro::setAtivo(int valor) {
    // deve ser inicializado com 0, e quando inserido no tabuleiro
    // e estiver vivo, setado em 1
    ativo = valor;
    return 1;
}
unsigned int  Cavaleiro::getVida() {
    return vida;
}
unsigned int  Cavaleiro::getDano() {
    return dano;
}
unsigned int  Cavaleiro::getPosX() {
    return posX;
}
unsigned int  Cavaleiro::getPosY() {
    return posY;
}
unsigned int  Cavaleiro::getQt_turnos() {
    return qt_turnos;
}
unsigned int  Cavaleiro::getQt_casas() {
    return qt_casas;
}
unsigned int Cavaleiro::getAtivo() {
    return ativo;
}
int Cavaleiro::get_status_personagem() {
    printf("Personagem :: Cavaleiro \n");
    printf("O personagem tem \nVida: %d Dano: %d\n", getVida(), getDano());
    printf("Esta na posicao: X:%d Y:%d\n", getPosX(), getPosY());
    printf("Limitacoes: Quantidade de turnos para ser produzido");
    printf(" %d \n", getQt_turnos());
    printf("\tQuantidade de casas que podem ser andadas %d \n", getQt_casas());
}

Guerreiro::Guerreiro() {
          setVida(150);
          setDano(30);
          setPosY(0);
          setPosX(0);
          setQt_turnos(1);
          setQt_casas(1);
          setAtivo(0);
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
int Guerreiro::setQt_turnos(unsigned int turnos) {
    rest_eh_positivo(turnos);
    qt_turnos = turnos;
    return 1;
}
int Guerreiro::setQt_casas(unsigned int casas) {
    rest_eh_positivo(casas);
    qt_casas =  casas;
    return 1;
}
int Guerreiro::setAtivo(int valor) {
    // deve ser inicializado com 0, e quando inserido no tabuleiro
    // e estiver vivo, setado em 1
    ativo = valor;
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
unsigned int Guerreiro::getAtivo() {
    return ativo;
}
int Guerreiro::get_status_personagem() {
       printf("Personagem :: guerreiro \n");
    printf("O personagem tem \nVida: %d Dano: %d\n", getVida(), getDano());
    printf("Esta na posicao: X:%d Y:%d\n", getPosX(), getPosY());
    printf("Limitacoes: Quantidade de turnos para ser produzido");
    printf(" %d \n", getQt_turnos());
    printf("\tQuantidade de casas que podem ser andadas %d \n", getQt_casas());
}
