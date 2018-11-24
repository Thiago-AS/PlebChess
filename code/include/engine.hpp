/**
* @file engine.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar a game engine 
*/
#ifndef ENGINE_HPP_
#define ENGINE_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "../include/tropas.hpp"
using namespace std;


class Engine {

    private:
    unsigned int turnoAtual;
    unsigned int jogadorAtual;
    
    
    public:
        // construtor e destrutor
        Engine();
        ~Engine();

        // getters and setters
        int setTurno(); // seta o turno inicial como 1
        int endTurno(); // acaba o turno do jogador, e incrementa o turno atual
        int setJogador(); // por default, o jogador 1 inicia o jogo
        int getJogador();
        int getTurno();

};


class Jogador {

    private:
    unsigned int time; // representa qual time o jog eh
    // quantidade de recursos atuais
    unsigned int ouro;
    unsigned int madeira;

    // quantidade de tropas atuais
    unsigned int guerreiros;
    unsigned int arqueiros;
    unsigned int cavaleiros;

    // quantidade de construcoes atuais
    unsigned int minas;
    unsigned int madeireiras;

    // ganho de recursos por turno
    unsigned int ganhoOuro;
    unsigned int ganhoMadeira;
    
    // vetores de tropas
    Arqueiro vetorArqueiro[10];
    Guerreiro vetorGuerreiro[10];
    Cavaleiro vetorCavaleiro[10];          

    public:
    // construtor e destrutor
    Jogador( int times );
    ~Jogador();
    // metodos SET
    int setRecursos(int, int);
    int setTropas(int, int, int);
    int setConstrucoes(int, int);
    int setGanhoPorTurno();
    int setVetorArqueiro(int, int);
    int setVetorGuerreiro(int, int);
    int setVetorCavaleiro(int, int);
    // metodos GET
    int getTime();
    int getOuro();
    int getMadeira();
    int getGuerreiros();
    int getArqueiros();
    int getCavaleiros();
    int getMinas();
    int getMadeireiras();
    int getGanhoOuro();
    int getGanhoMadeira();
    Arqueiro getVetorArqueiro(int);
    Guerreiro getVetorGuerreiro(int);
    Cavaleiro getVetorCavaleiro(int);

}; // jogador
#endif
