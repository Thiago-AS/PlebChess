/**
* @file unidades.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef UNIDADES_HPP_
#define UNIDADES_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
enum tipo_unidades {
	zero =0,
    fortaleza = 1,
    lenhadora = 2,
    mina = 3
};
enum tipo_recurso {
	nada = 0,
	madeira = 1,
	ouro = 2
};

class unidades {
    private:
    tipo_unidades unidade;
	tipo_recurso recurso;
    bool eh_humano;
    unsigned int vida;
    unsigned int qt_materia;
	unsigned int largura;
	unsigned int comprimento;
    public:
        //construtor e destrutor	
        Unidades(tipo_recurso recurso_atual);
        ~Unidades();
        // metodos getter and setters
        int setVida(unsigned int p_vida);
        int setQt_materia(unsigned int materia);
        int setLargura(unsigned int p_lar);
        int setComprimento(unsigned int p_com);
        int setUnidade(tipo_unidades unidade);
		int setRecurso(tipo_recurso recurso);
        unsigned int getVida();
        unsigned int getLargura();
        unsigned int getComprimento();
        unsigned int getQt_materia();
		tipo_unidades getUnidade();
        tipo_recurso getRecurso();
        
};
#endif  
