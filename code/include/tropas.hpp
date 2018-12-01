// "Copyright 2018 Grupo MP"
/**
* @file tropas.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que implementam objetos da tropa. 
*/
#ifndef CODE_INCLUDE_TROPAS_HPP_
#define CODE_INCLUDE_TROPAS_HPP_
// includes
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
/**
* @brief Classe que contem as especificacoes do arqueiro e como esta sendo usado.
* Descricao: Contem construtor e destrutor além dos metodos getters and setters que
* que sao usados para manipular o objeto arqueiro
*/
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
        Arqueiro();
        ~Arqueiro();
        // metodos getter and setters
/**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida do arqueiro para o valor passado.
* @param p_vida deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_vida for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_vida >= 0
*    Interface explicita: p_vida
*    Interface implicita:
* Assertiva Saida: Se p_vida for maior que 0 
* entao vida = p_vida, caso der certo retorna 1.
*/
        int setVida(unsigned int p_vida);
/**
* @fn int setDano(unsigned int p_dano);
* @brief Metodo que seta o valor do dano do arqueiro para o valor passado.
* @param p_dano deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_dano for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  p_dano >= 0
*    Interface explicita: p_vida
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao dano = p_dano, caso der certo retorna 1.
*/
        int setDano(unsigned int p_dano);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do arqueiro para o valor passado.
* @param p_posX deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posX for um valor possivel seta o valor posX para p_posX.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_pox >= 0 && p_posX < LIN_TABULEIRO
*    Interface explicita: p_posX
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que -1 e menor que o limite 
* entao posX = p_posX, caso der certo retorna 1.
*/
        int setPosX(unsigned int p_posX);
/**
* @fn int setPosY(unsigned int p_posY);
* @brief Metodo que seta o valor da posY do arqueiro para o valor passado.
* @param p_posY deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posY for um valor possivel seta o valor posY para p_posY.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_posY >= -1 && p_posY < COL_TABULEIRO
*    Interface explicita: p_posY
*    Interface implicita: COL_TABULEIRO
* Assertiva Saida: Se p_posY for maior que -1 e menor que o limite 
* entao posY = p_posY, caso der certo retorna 1.
*/
        int setPosY(unsigned int p_posY);
/**
* @fn     int setQt_turnos(unsigned int turnos);
* @brief Metodo que seta o valor do turnos para produzir um arqueiro.
* @param turnos deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se turnos for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  turnos > 0
*    Interface explicita: turnos
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_turnos = turnos, caso der certo retorna 1.
*/
        int setQt_turnos(unsigned int turnos);
/**
* @fn     int setQt_casas(unsigned int casas);
* @brief Metodo que seta o valor de casas andaveis pelo arqueiro.
* @param casas deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se casas for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  casas > 0
*    Interface explicita: casas
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_casas = casas, caso der certo retorna 1.
*/
        int setQt_casas(unsigned int casas);
/**
* @fn int setAtivo(int p_ativo);
* @brief Seta ativo = 1 se estiver ativo c.c. = 0.
* @param p_ativo deve ser um int, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_ativo for falso ativo sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro p_ativo deve ser int
* Assertiva Entrada:  typeof(p_ativo) = bool
*    Interface explicita: p_ativo
*    Interface implicita: Nao ha
* Assertiva Saida: usado = uso e retorna 1 se deu certo
*/
        int setAtivo(int);
/**
* @fn int setHumano(bool humano);
* @brief Se a peca for do jogador seta para true, caso contrario falso.
* @param humano deve ser um booleano, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se humano for falso eh_humano sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro humano deve ser booleano
* Assertiva Entrada:  typeof(humano) = bool
*    Interface explicita: humano
*    Interface implicita: Nao ha
* Assertiva Saida: eh_humano = humano e retorna 1 se deu certo
*/
        int setHumano(bool);
/**
* @fn bool getHumano();
* @brief Retorna o bool referente ao objeto arqueiro.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de eh_humano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de eh_humano
*/
        bool getHumano();
/**
* @fn unsigned int getVida();
* @brief Retorna o int referente a vida.
* @return Retorna vida
* Hipoteses: O objeto passado deve ser do tipo arqueiro.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getDano();
* @brief Retorna o int referente a dano.
* @return Retorna dano
* Hipoteses: O objeto passado deve ser do tipo arqueiro.
* Requesitos: Metodo deve retornar o valor de dano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de dano
*/
        unsigned int getDano();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto arqueiro.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto arqueiro.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a a vida do arqueiro.
*/    
        unsigned int getPosY();
/**
* @fn unsigned int getQt_turnos();
* @brief Retorna a  turnos do objeto arqueiro.
* @return Retorna qt_turnos
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de qt_turnos.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a turnos para construir arqueiro.
*/
        unsigned int getQt_turnos();
/**
* @fn unsigned int getQt_casas();
* @brief Retorna as quantidade de casas andaveis do objeto arqueiro.
* @return Retorna qt_casas
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de qt_casas.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a casas andaveis pelo arqueiro.
*/    
        unsigned int getQt_casas();
/**
* @fn unsigned int getAtivo();
* @brief Retorna se eh ativo ou nao do objeto arqueiro.
* @return Retorna ativo
* Hipoteses: O objeto passado deve ser arqueiro.
* Requesitos: Metodo deve retornar o valor de ativo.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve ativo se estiver em jogo, 0 c.c.
*/    
        unsigned int getAtivo();
/**
* @fn int get_status_personagem();
* @brief Printa informacoes da tropa.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/    
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
        Guerreiro();
        ~Guerreiro();
        // metodos getter and setters
/**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida do guerreiro para o valor passado.
* @param p_vida deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_vida for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  p_vida >= 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_vida for maior que 0 
* entao vida = p_vida, caso der certo retorna 1.
*/
        int setVida(unsigned int p_vida);
/**
* @fn int setDano(unsigned int p_dano);
* @brief Metodo que seta o valor do dano do guerreiro para o valor passado.
* @param p_dano deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_dano for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  p_dano >= 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao dano = p_dano, caso der certo retorna 1.
*/
        int setDano(unsigned int p_dano);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do guerreiro para o valor passado.
* @param p_posX deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posX for um valor possivel seta o valor posX para p_posX.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_pox >= -1 && p_posX < LIN_TABULEIRO
*    Interface explicita: p_posX
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que -1 e menor que o limite 
* entao posX = p_posX, caso der certo retorna 1.
*/
        int setPosX(unsigned int p_posX);
/**
* @fn int setPosY(unsigned int p_posY);
* @brief Metodo que seta o valor da posY do guerreiro para o valor passado.
* @param p_posY deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posY for um valor possivel seta o valor posY para p_posY.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_posY >= -1 && p_posY < COL_TABULEIRO
*    Interface explicita: p_posY
*    Interface implicita: COL_TABULEIRO
* Assertiva Saida: Se p_posY for maior que -1 e menor que o limite 
* entao posY = p_posY, caso der certo retorna 1.
*/
        int setPosY(unsigned int p_posY);
/**
* @fn     int setQt_turnos(unsigned int turnos);
* @brief Metodo que seta o valor do turnos para produzir um guerreiro.
* @param turnos deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se turnos for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  turnos > 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_turnos = turnos, caso der certo retorna 1.
*/
        int setQt_turnos(unsigned int turnos);
/**
* @fn     int setQt_casas(unsigned int casas);
* @brief Metodo que seta o valor de casas andaveis pelo guerreiro.
* @param casas deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se casas for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  casas > 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_casas = casas, caso der certo retorna 1.
*/
        int setQt_casas(unsigned int casas);
/**
* @fn int setAtivo(int p_ativo);
* @brief Seta ativo = 1 se estiver ativo c.c. = 0.
* @param p_ativo deve ser um int, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_ativo for falso ativo sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro p_ativo deve ser int
* Assertiva Entrada:  typeof(p_ativo) = bool
*    Interface explicita: p_ativo
*    Interface implicita: Nao ha
* Assertiva Saida: usado = uso e retorna 1 se deu certo
*/
        int setAtivo(int);
/**
* @fn int setHumano(bool humano);
* @brief Se a peca for do jogador seta para true, caso contrario falso.
* @param humano deve ser um booleano, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se humano for falso eh_humano sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro humano deve ser booleano
* Assertiva Entrada:  typeof(humano) = bool
*    Interface explicita: humano
*    Interface implicita: Nao ha
* Assertiva Saida: eh_humano = humano e retorna 1 se deu certo
*/
        int setHumano(bool);
/**
* @fn bool getHumano();
* @brief Retorna o bool referente ao objeto guerreiro.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de eh_humano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de eh_humano
*/
        bool getHumano();
/**
* @fn unsigned int getVida();
* @brief Retorna o int referente a vida.
* @return Retorna vida
* Hipoteses: O objeto passado deve ser do tipo guerreiro.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getDano();
* @brief Retorna o int referente a dano.
* @return Retorna dano
* Hipoteses: O objeto passado deve ser do tipo guerreiro.
* Requesitos: Metodo deve retornar o valor de dano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de dano
*/
        unsigned int getDano();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto guerreiro.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto guerreiro.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de posY
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao Y do tabuleiro referente ao objeto.
*/
        unsigned int getPosY();
/**
* @fn unsigned int getQt_turnos();
* @brief Retorna a  turnos do objeto guerreiro.
* @return Retorna qt_turnos
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de qt_turnos.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a turnos para construir guerreiro.
*/
        unsigned int getQt_turnos();
/**
* @fn unsigned int getQt_casas();
* @brief Retorna as quantidade de casas andaveis do objeto guerreiro.
* @return Retorna qt_casas
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de qt_casas.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a casas andaveis pelo guerreiro.
*/
        unsigned int getQt_casas();
/**
* @fn unsigned int getAtivo();
* @brief Retorna se eh ativo ou nao do objeto guerreiro.
* @return Retorna ativo
* Hipoteses: O objeto passado deve ser guerreiro.
* Requesitos: Metodo deve retornar o valor de ativo.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve ativo se estiver em jogo, 0 c.c.
*/    
        unsigned int getAtivo();
/**
* @fn int get_status_personagem();
* @brief Printa informacoes da tropa.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/    
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
        Cavaleiro();
        ~Cavaleiro();
        // metodos getter and setters
/**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida do cavaleiro para o valor passado.
* @param p_vida deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_vida  for um valor possivel seta o valor vida para p_vida.
* Requesitos: Deve ser int.
* Assertiva Entrada:  p_vida >= 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_vida for maior que 0 
* entao vida = p_vida, caso der certo retorna 1.
*/
        int setVida(unsigned int p_vida);
/**
* @fn int setDano(unsigned int p_dano);
* @brief Metodo que seta o valor do dano do cavaleiro para o valor passado.
* @param p_dano deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_dano for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  p_dano >= 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao dano = p_dano, caso der certo retorna 1.
*/
        int setDano(unsigned int p_dano);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do cavaleiro para o valor passado.
* @param p_posX deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posX for um valor possivel seta o valor posX para p_posX.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_pox >= -1 && p_posX < LIN_TABULEIRO
*    Interface explicita: p_posX
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que -1 e menor que o limite 
* entao posX = p_posX, caso der certo retorna 1.
*/
        int setPosX(unsigned int p_posX);
/**
* @fn int setPosY(unsigned int p_posY);
* @brief Metodo que seta o valor da posY do cavaleiro para o valor passado.
* @param p_posY deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posY for um valor possivel seta o valor posY para p_posY.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_posY >= -1 && p_posY < COL_TABULEIRO
*    Interface explicita: p_posY
*    Interface implicita: COL_TABULEIRO
* Assertiva Saida: Se p_posY for maior que -1 e menor que o limite 
* entao posY = p_posY, caso der certo retorna 1.
*/
        int setPosY(unsigned int p_posY);
/**
* @fn     int setQt_turnos(unsigned int turnos);
* @brief Metodo que seta o valor do turnos para produzir um cavaleiro.
* @param turnos deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se turnos for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  turnos > 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_turnos = turnos, caso der certo retorna 1.
*/
        int setQt_turnos(unsigned int turnos);
/**
* @fn     int setQt_casas(unsigned int casas);
* @brief Metodo que seta o valor do casas andaveis pelo cavaleiro.
* @param casas deve ser um valor maior a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se casas for um valor possivel seta o valor.
* Requesitos: deve ser int.
* Assertiva Entrada:  casas > 0
*    Interface explicita:
*    Interface implicita:
* Assertiva Saida: Se p_dano for maior que 0 
* entao qt_casas = casas, caso der certo retorna 1.
*/
        int setQt_casas(unsigned int casas);
/**
* @fn int setAtivo(int p_ativo);
* @brief Seta ativo = 1 se estiver ativo c.c. = 0.
* @param p_ativo deve ser um int, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_ativo for falso ativo sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro p_ativo deve ser int
* Assertiva Entrada:  typeof(p_ativo) = bool
*    Interface explicita: p_ativo
*    Interface implicita: Nao ha
* Assertiva Saida: usado = uso e retorna 1 se deu certo
*/
        int setAtivo(int);
/**
* @fn int setHumano(bool humano);
* @brief Se a peca for do jogador seta para true, caso contrario falso.
* @param humano deve ser um booleano, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se humano for falso eh_humano sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro humano deve ser booleano
* Assertiva Entrada:  typeof(humano) = bool
*    Interface explicita: humano
*    Interface implicita: Nao ha
* Assertiva Saida: eh_humano = humano e retorna 1 se deu certo
*/
        int setHumano(bool);
/**
* @fn bool getHumano();
* @brief Retorna o bool referente ao objeto cavaleiro.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de eh_humano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de eh_humano
*/
        bool getHumano();
/**
* @fn unsigned int getVida();
* @brief Retorna o int referente a vida.
* @return Retorna vida
* Hipoteses: O objeto passado deve ser do tipo cavaleiro.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getDano();
* @brief Retorna o int referente a dano.
* @return Retorna dano
* Hipoteses: O objeto passado deve ser do tipo cavaleiro.
* Requesitos: Metodo deve retornar o valor de dano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de dano
*/
        unsigned int getDano();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto cavaleiro.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto cavaleiro.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de posY
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao Y do tabuleiro referente ao objeto.
*/
        unsigned int getPosY();
/**
* @fn unsigned int getQt_turnos();
* @brief Retorna a  turnos do objeto cavaleiro.
* @return Retorna qt_turnos
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de qt_turnos.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a turnos para construir cavaleiro.
*/
        unsigned int getQt_turnos();
/**
* @fn unsigned int getQt_casas();
* @brief Retorna as quantidade de casas andaveis do objeto cavaleiro.
* @return Retorna qt_casas
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de qt_casas.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a casas andaveis pelo cavaleiro.
*/
        unsigned int getQt_casas();
/**
* @fn unsigned int getAtivo();
* @brief Retorna se eh ativo ou nao do objeto cavaleiro.
* @return Retorna ativo
* Hipoteses: O objeto passado deve ser cavaleiro.
* Requesitos: Metodo deve retornar o valor de ativo.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve ativo se estiver em jogo, 0 c.c.
*/    
        unsigned int getAtivo();
/**
* @fn int get_status_personagem();
* @brief Printa informacoes da tropa.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/    
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
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do quadrado vazio para o valor passado.
* @param p_posX deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posX for um valor possivel seta o valor posX para p_posX.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_pox >= -1 && p_posX < LIN_TABULEIRO
*    Interface explicita: p_posX
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que -1 e menor que o limite 
* entao posX = p_posX, caso der certo retorna 1.
*/
        int setPosX(unsigned int p_posX);
/**
* @fn int setPosY(unsigned int p_posY);
* @brief Metodo que seta o valor da posY do quadrado vazio para o valor passado.
* @param p_posY deve ser um valor maior igual a -1 e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posY for um valor possivel seta o valor posY para p_posY.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_posY >= -1 && p_posY < COL_TABULEIRO
*    Interface explicita: p_posY
*    Interface implicita: COL_TABULEIRO
* Assertiva Saida: Se p_posY for maior que -1 e menor que o limite 
* entao posY = p_posY, caso der certo retorna 1.
*/
        int setPosY(unsigned int p_posY);
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto Quadrado vazio.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser Quadrado vazio.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto Quadrado Vazio.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser Quadrado Vazio.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a posicao Y do tabuleiro referente ao objeto.
*/
        unsigned int getPosY();
};


#endif
