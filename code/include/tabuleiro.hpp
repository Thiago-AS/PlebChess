// "Copyright 2018 Mtonin"
/**
* @file quadrado.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef TABULEIRO_HPP_
#define TABULEIRO_HPP_
// includes
#include "quadrado.hpp"
#include "utils.hpp"
using namespace std;
class Tabuleiro {
 private:
  Quadrado *quadrado;
  char tabuleiro[COL_TABULEIRO][LIN_TABULEIRO];
 public:
  Tabuleiro();
  ~Tabuleiro();
  void print_tabuleiro();
  int insere_arqueiro(unsigned int posX, unsigned posY);
  int insere_guerreiro(unsigned int posX, unsigned posY);
  int insere_cavaleiro(unsigned int posX, unsigned posY);
  int insere_lenhadora(unsigned int posX, unsigned posY);
  int insere_mina(unsigned int posX, unsigned posY);
  int insere_fortaleza(unsigned int posX, unsigned posY);
  int eh_possivel_inserir(unsigned int posX, unsigned posY);
  void atualiza_tabuleiro();
  char qual_unidade(unsigned int posX, unsigned posY);
};
#endif
