// "Copyright 2018 Grupo MP"
/**
* @file tabuleiro.hpp
* @brief Arquivo com as assinaturas da classe tabuleiro. 
*/
#ifndef TABULEIRO_HPP_
#define TABULEIRO_HPP_
// includes
#include "utils.hpp"
#include "engine.hpp"
using namespace std;

/**
* @brief Classe que contem as especificacoes do tabuleiro e como esta sendo usado.
* Descricao: Contem construtor e destrutor além dos metodos getters and setters que
* que sao usados para manipular o objeto Tabuleiro
*/
class Tabuleiro {
 private:
  char tabuleiro[COL_TABULEIRO][LIN_TABULEIRO];

 public:
  Tabuleiro();
  ~Tabuleiro();
  /**
* @fn void print_tabuleiro();
* @brief Este metodo imprime o tabuleiro
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Nao ha hipoteses
* Requesitos: Nao ha requisitos
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: Sera impresso em tela o tabuleiro.
*/
  void print_tabuleiro();
/**
* @fn   int insere_arqueiro(unsigned int posX, unsigned posY);
* @brief Insere o char 'A' representando o objeto arqueiro
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/  
  int insere_arqueiro(unsigned int posX, unsigned posY);
/**
* @fn   int insere_guerreiro(unsigned int posX, unsigned posY);
* @brief Insere o char 'G' representando o objeto guerreiro
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/ 
  int insere_guerreiro(unsigned int posX, unsigned posY);
/**
* @fn   int insere_cavaleiro(unsigned int posX, unsigned posY);
* @brief Insere o char 'C' representando o objeto cavaleiro
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/
  int insere_cavaleiro(unsigned int posX, unsigned posY);
/**
* @fn   int insere_lenhadora(unsigned int posX, unsigned posY);
* @brief Insere o char 'L' representando o objeto lenhadora
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/  
  int insere_lenhadora(unsigned int posX, unsigned posY);
/**
* @fn   int insere_mina(unsigned int posX, unsigned posY);
* @brief Insere o char 'M' representando o objeto Mina
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/  
  int insere_mina(unsigned int posX, unsigned posY);
/**
* @fn   int insere_fortaleza(unsigned int posX, unsigned posY);
* @brief Insere o char 'F' representando o objeto fortaleza
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se possivel insere o char.
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: tabuleiro com o char inserido no local
*/
  int insere_fortaleza(unsigned int posX, unsigned posY);
/**
* @fn   int eh_possivel_inserir(unsigned int posX, unsigned posY);
* @brief Verifica se eh possivel inserir naquele local
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return 1 caso seja possivel inserir, 0 c.c.
* Hipoteses: Verifica-se tem algum char que representa um objeto no local
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: Int com 1 se for possivel inserir, 0 c.c.
*/
  int eh_possivel_inserir(unsigned int posX, unsigned posY);
  void atualiza_tabuleiro();
/**
* @fn char qual_unidade(unsigned int posX, unsigned posY);
* @brief Verifica qual char esta em tabuleiro[posX][posY]
* @param posX refere-se a posicao X do tabuleiro.
* @param posY refere-se a posicao Y do tabuleiro.
* @return Retorna o char referente a posicao tabuleiro[posX][posY] 
* Hipoteses: Verifica-se o char na posicao
* Requesitos: PosX e posY devem ser uma valor possivel para o tabuleiro
* Assertiva Entrada:   0 =< posX < COL_TABULEIRO && 0 =< posY < LIN_TABULEIRO 
*    Interface explicita: posX e posY
*    Interface implicita: tabuleiro
* Assertiva Saida: Sera retornado o char da posicao do tabuleiro, caso nao de erro
*/
  char qual_unidade(unsigned int posX, unsigned posY);
};
#endif
