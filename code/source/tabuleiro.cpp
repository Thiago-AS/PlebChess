// "Copyright 2018 Mtonin"
#include "../include/tabuleiro.hpp"
Tabuleiro::Tabuleiro() {
for (int i = 0; i < COL_TABULEIRO; i++) {
for (int j = 0; j  < LIN_TABULEIRO; j++) {
    tabuleiro[i][j] = '-';
}
}
}
Tabuleiro::~Tabuleiro() {
}
void Tabuleiro::print_tabuleiro() {
    for (int i = 0; i < COL_TABULEIRO; i++) {
        for (int j = 0; j < LIN_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
int Tabuleiro::insere_arqueiro(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX);
  eh_possivel_inserir(posX, posY);
  tabuleiro[posX][posY] = 'A';
  return 1;
}
int Tabuleiro::insere_guerreiro(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX);
  eh_possivel_inserir(posX, posY);
  tabuleiro[posX][posY] = 'G';
  return 1;
}
int Tabuleiro::insere_cavaleiro(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX);
  eh_possivel_inserir(posX, posY);
  tabuleiro[posX][posY] = 'C';
  return 1;
}
int Tabuleiro::insere_lenhadora(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY+1);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX+1);
  eh_possivel_inserir(posX, posY);
  eh_possivel_inserir(posX, posY+1);
  eh_possivel_inserir(posX+1, posY);
  eh_possivel_inserir(posX+1, posY+1);
  tabuleiro[posX][posY] = 'L';
  tabuleiro[posX][posY+1] = 'L';
  tabuleiro[posX+1][posY] = 'L';
  tabuleiro[posX+1][posY+1] = 'L';
  return 1;
}
int Tabuleiro::insere_mina(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY+1);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX+1);
  eh_possivel_inserir(posX, posY);
  eh_possivel_inserir(posX, posY+1);
  eh_possivel_inserir(posX+1, posY);
  eh_possivel_inserir(posX+1, posY+1);
  tabuleiro[posX][posY] = 'M';
  tabuleiro[posX][posY+1] = 'M';
  tabuleiro[posX+1][posY] = 'M';
  tabuleiro[posX+1][posY+1] = 'M';
  return 1;
}
int Tabuleiro::insere_fortaleza(unsigned int posX,  unsigned posY) {
  rest_eh_positivo(posX);
  rest_limiteLin_sup(posY+3);
  rest_eh_positivo(posY);
  rest_limiteCol_sup(posX+1);
  eh_possivel_inserir(posX, posY);
  eh_possivel_inserir(posX, posY+1);
  eh_possivel_inserir(posX+1, posY);
  eh_possivel_inserir(posX+1, posY+1);
  eh_possivel_inserir(posX+2, posY);
  eh_possivel_inserir(posX+2, posY+1);
  eh_possivel_inserir(posX+3, posY);
  eh_possivel_inserir(posX+3, posY+1);
  tabuleiro[posX][posY] = 'F';
  tabuleiro[posX][posY+1] = 'F';
  tabuleiro[posX+1][posY] = 'F';
  tabuleiro[posX+1][posY+1] = 'F';
  tabuleiro[posX+2][posY] = 'F';
  tabuleiro[posX+2][posY+1] = 'F';
  tabuleiro[posX+3][posY] = 'F';
  tabuleiro[posX+3][posY+1] = 'F';
  return 1;
}
int Tabuleiro::eh_possivel_inserir(unsigned int posX,  unsigned posY) {
    if (tabuleiro[posX][posY] == '-') {
        return 1;
    } else {
        exit(0);
    }
}
char Tabuleiro::qual_unidade(unsigned int posX,  unsigned posY) {
    return tabuleiro[posX][posY];
}
