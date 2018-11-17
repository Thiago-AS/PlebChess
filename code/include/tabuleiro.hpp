/**
* @file quadrado.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef TABULEIRO_HPP_
#define TABULEIRO_HPP_
// includes
#include "quadrado.hpp"
using namespace std;

class Tabuleiro
{
private:

  Quadrado  **tabuleiro_jogo;

public:
  Tabuleiro();
  ~Tabuleiro();
};

#endif
