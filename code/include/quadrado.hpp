// "Copyright 2018 Grupo MP"
/**
* @file quadrado.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef QUADRADO_HPP_
#define QUADRADO_HPP_
// includes
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
enum class TipoUnidade{
    UnidadeVazio,
    fortaleza,
    lenhadora,
    mina,
    arqueiro,
    cavaleiro,
    guerreiro,
    };

class Quadrado {
 protected:
    TipoUnidade nome = TipoUnidade::UnidadeVazio;
    bool eh_humano = true;
    bool usado = false;
    int posX = -1;
    int posY = -1;
 public:
    Quadrado();
    ~Quadrado();
    int setPosX(unsigned int p_posX);
    int setPosY(unsigned int p_posY);
    int setHumano(bool humano);
    int setUsado(bool uso);
    int setUnidade(TipoUnidade nomeUnidade);
    void unidadeMorta();
    unsigned int getPosX();
    unsigned int getPosY();
    bool getHumano();
    bool getUsado();
    TipoUnidade getUnidade();
};
#endif
