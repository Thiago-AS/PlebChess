// "Copyright 2018 Grupo MP"
/**
* @file tropas.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef TROPAS_HPP_
#define TROPAS_HPP_
// includes
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

class Arqueiro {
 private :
    bool eh_humano;
    unsigned int posX;
    unsigned int posY;
    unsigned int vida;
    unsigned int dano;
    unsigned int qt_turnos;
    unsigned int qt_casas;
    unsigned int ativo;

 public :
// construtor e destrutor
        Arqueiro(unsigned int pX, unsigned int pY);
        ~Arqueiro();
        // metodos getter and setters
        int setVida(unsigned int p_vida);
        int setDano(unsigned int p_dano);
        int setPosX(unsigned int p_posX);
        int setPosY(unsigned int p_posY);
        int setQt_turnos(unsigned int turnos);
        int setQt_casas(unsigned int casas);
        int setAtivo(int);
        unsigned int getVida();
        unsigned int getDano();
        unsigned int getPosX();
        unsigned int getPosY();
        unsigned int getQt_turnos();
        unsigned int getQt_casas();
        unsigned int getAtivo();
        int get_status_personagem();
};
class Guerreiro {
 private:
    bool eh_humano;
    unsigned int posX;
    unsigned int posY;
    unsigned int vida;
    unsigned int dano;
    unsigned int qt_turnos;
    unsigned int qt_casas;
    unsigned int ativo;

 public:
        // construtor e destrutor
        Guerreiro(unsigned int pX, unsigned int pY);
        ~Guerreiro();
        // metodos getter and setters
        int setVida(unsigned int p_vida);
        int setDano(unsigned int p_dano);
        int setPosX(unsigned int p_posX);
        int setPosY(unsigned int p_posY);
        int setQt_turnos(unsigned int turnos);
        int setQt_casas(unsigned int casas);
        int setAtivo(int);
        unsigned int getVida();
        unsigned int getDano();
        unsigned int getPosX();
        unsigned int getPosY();
        unsigned int getQt_turnos();
        unsigned int getQt_casas();
        unsigned int getAtivo();
        int get_status_personagem();
};
class Cavaleiro {
 private:
    bool eh_humano;
    unsigned int posX;
    unsigned int posY;
    unsigned int vida;
    unsigned int dano;
    unsigned int qt_turnos;
    unsigned int qt_casas;
    unsigned int ativo;
	
 public:
        // construtor e destrutor
        Cavaleiro(unsigned int pX, unsigned int pY);
        ~Cavaleiro();
        // metodos getter and setters
        int setVida(unsigned int p_vida);
        int setDano(unsigned int p_dano);
        int setPosX(unsigned int p_posX);
        int setPosY(unsigned int p_posY);
        int setQt_turnos(unsigned int turnos);
        int setQt_casas(unsigned int casas);
        int setAtivo(int);
        unsigned int getVida();
        unsigned int getDano();
        unsigned int getPosX();
        unsigned int getPosY();
        unsigned int getQt_turnos();
        unsigned int getQt_casas();
        unsigned int getAtivo();
        int get_status_personagem();
};
class Unidade_vazio {
 private :
    unsigned int posX;
    unsigned int posY;

 public :
// construtor e destrutor
        Unidade_vazio(unsigned int pX, unsigned int pY);
        ~Unidade_vazio();
        // metodos getter and setters
        int setPosX(unsigned int p_posX);
        int setPosY(unsigned int p_posY);
};


#endif
