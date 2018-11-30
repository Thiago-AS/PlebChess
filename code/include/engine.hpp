// "Copyright 2018 Grupo MP"
/**
* @file engine.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar a game engine 
*/
#ifndef CODE_INCLUDE_ENGINE_HPP_
#define CODE_INCLUDE_ENGINE_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "../include/tropas.hpp"
#include "../include/unidades.hpp"
using namespace std;
enum Possibilidade {
	p_nada,
	p_construir,
	p_personagem,	
};
/**
 * @brief Enumeracao da Classe tipo de unidades que o jogo pode ter.
 * Descricao: Contem todas as unidades que pode estar presente em um quadrado do mapa.
 */
enum class TipoUnidade{
    t_UnidadeVazio,
    t_fortaleza,
    t_lenhadora,
    t_mina,
    t_arqueiro,
    t_cavaleiro,
    t_guerreiro,
    };

class Engine {
 private:
        unsigned int turnoAtual;
        unsigned int jogadorAtual;

 public:
        // construtor e destrutor
        Engine();
        ~Engine();
        TipoUnidade tabuleirogame[LIN_TABULEIRO][COL_TABULEIRO];
        int tabela_time[LIN_TABULEIRO][COL_TABULEIRO];
        // getters and setters
        int setTurno();  // seta o turno inicial como 1
        int endTurno();  // acaba o turno do jogador, e incrementa o turno atual
        int setJogador();  // por default, o jogador 1 inicia o jogo
        int getJogador();
        int getTurno();
        /**
        * @fn TipoUnidade getUnidade();
        * @brief Retorna TipoUnidade referente ao objeto Quadrado.
        * @return Retorna nome do objeto
        * Hipoteses: O objeto passado deve ser do tipo Quadrado.
        * Requesitos: Metodo deve retornar o valor de nome
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida: devolve o valor de nome
        */
        TipoUnidade getUnidadeTAB( int posX, int posY);
        int setUnidadeTAB(TipoUnidade unit, int posX, int posY);
        int eh_possivel_inserir(unsigned int posX,  unsigned posY);
        int  getTabelaTime( int posX, int posY);
        int setTabelaTime(int value, int posX, int posY);
        void printTAB();
        void printTABverb();
        void printTabelaTime();
};
class Jogador {
 private:
    unsigned int time;  // representa qual time o jog eh
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
    // quantidade de unidades vazias
    unsigned int uni_vazias = LIN_TABULEIRO * COL_TABULEIRO;
    // ganho de recursos por turno
    unsigned int ganhoOuro;
    unsigned int ganhoMadeira;
    // vetores de tropas
    Arqueiro vetorArqueiro[10];
    Guerreiro vetorGuerreiro[10];
    Cavaleiro vetorCavaleiro[10];
    Mina vetorMina[5];
    Lenhadora vetorLenhadora[8];
    Fortaleza un_Fortaleza;


 public:
    // construtor e destrutor
    explicit Jogador(int times);
    ~Jogador();
    // metodos SET
    int setRecursos(int, int);
    int setTropas(int, int, int);
    int setConstrucoes(int, int);
    int setGanhoPorTurno();
    int setVetorArqueiro(int, int, Engine * engine);
    int setVetorGuerreiro(int, int, Engine * engine);
    int setVetorCavaleiro(int, int, Engine * engine);
    int setVetorMina(int, int, Engine * engine);
    int setVetorLenhadora(int, int, Engine * engine);
    int setFortaleza(int, int, Engine * engine);
    int inicializaJogador();
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
    Arqueiro getArqueiroBypos(unsigned int posX, unsigned int posY);
    int alteraArqueiro(int indice, unsigned int posX, unsigned int posY, Engine * engine);
    Guerreiro getVetorGuerreiro(int);
    Guerreiro getGuerreiroBypos(unsigned int posX, unsigned int posY);
    int alteraGuerreiro(int indice, unsigned int posX, unsigned int posY, Engine * engine);
    Cavaleiro getVetorCavaleiro(int);
    Cavaleiro getCavaleiroBypos(unsigned int posX, unsigned int posY);
    int alteraCavaleiro(int indice, unsigned int posX, unsigned int posY, Engine * engine);
    Mina getVetorMina(int);
    Mina getMinaBypos(unsigned int posX, unsigned int posY);
    int alteraMina(int indice, unsigned int posX, unsigned int posY, Engine * engine);
    Lenhadora getVetorLenhadora(int);
    Lenhadora getLenhadoraBypos(unsigned int posX, unsigned int posY);
    int alteraLenhadora(int indice, unsigned int posX, unsigned int posY, Engine * engine);
    Fortaleza getun_Fortaleza();
    int alteraFortaleza(unsigned int posX, unsigned int posY, Engine * engine);
	// metodos de jogo
	Possibilidade verificarPoss(unsigned int posX, unsigned int posY, Engine * engine);
};  // jogador
#endif  // CODE_INCLUDE_ENGINE_HPP_
