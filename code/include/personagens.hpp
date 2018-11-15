/**
* @file personagens.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef PERSONAGENS_HPP_
#define PERSONAGENS_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

enum tipo_personagens{
	arqueiro, guerreiro, cavaleiro
};


class Personagens {
	private:
		tipo_personagens personagem;
		bool eh_humano;
		unsigned int posX;
		unsigned int posY;
		unsigned int vida;
		unsigned int dano;
	public:
	   //construtor e destrutor	
	   Personagens();
	   ~Personagens();
	   // metodos getter and setters
	   int  setVida(unsigned int vida);
	   int  setDano(unsigned int dano);
	   int  setPosX(unsigned int posX);
	   int  setPosY(unsigned int posY);
	   unsigned int  getVida();
	   unsigned int  getDano();
	   unsigned int  getPosX();
	   unsigned int  getPosY();
	   tipo_personagens  getPersonagem();
		
};

#endif  
