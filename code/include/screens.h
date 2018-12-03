/**
 * @file screens.h
 * @brief Arquivo que define as telas utilizadas no jogo.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_SCREENS_H_
#define  CODE_INCLUDE_SCREENS_H_

#include <vector>
#include "./game_objects.h"
#include "./map.h"

/**@brief Classe do menu principal.
*
*  Define todos os métodos necessarios para executar o menu incial do jogo.
*/
class MainMenu {
 public:
  MainMenu();
  ~MainMenu();

  /**
  * @brief Lida com os eventos do menu inicial.
  * @param events Pilha de eventos a ser tratada.
  * Assertiva Entrada:  Deve existir evento na pilha.
  *
  * Assertiva Saida: Não há.
  */
  void EventHandler(SDL_Event&);
  /**
  * @brief Carrega os elementos a serem impressos.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Não há.
  */
  void LoadScreen();
  /**
  * @brief Imprime os elementos previamente carregados.
  * Assertiva Entrada:  Elementos devem estar carregados.
  *
  * Assertiva Saida: Não há.
  */
  void Render();

 private:
  /** Vetor de objetos que serão carregados na tela. */
  VectorObjects screen_objects;
};

/**@brief Classe do menu de pausa.
*
*  Define todos os métodos necessarios para executar o menu de pausa.
*/
class PauseMenu {
 public:
  PauseMenu();
  ~PauseMenu();

  /**
  * @brief Lida com os eventos do menu de pausa.
  * @param events Pilha de eventos a ser tratada.
  * Hipoteses: Nao há.
  * Assertiva Entrada:  Deve existir evento na pilha.
  *
  * Assertiva Saida: Não há.
  */
  void EventHandler(SDL_Event&);
  /**
  * @brief Carrega os elementos a serem impressos.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Não há.
  */
  void LoadScreen();
  /**
  * @brief Imprime os elementos previamente carregados.
  * Assertiva Entrada:  Elementos devem estar carregados.
  *
  * Assertiva Saida: Não há.
  */
  void Render();

 private:
  /** Vetor de objetos que serão carregados na tela. */
  VectorObjects screen_objects;
};

/**@brief Classe da tela de jogo.
*
*  Define todos os métodos necessarios para executar a tela de jogo.
*/
class GameScene {
 public:
  GameScene();
  ~GameScene();

  /**
  * @brief Lida com os eventos da tela de jogo.
  * @param events Pilha de eventos a ser tratada.
  * Hipoteses: Nao há.
  * Assertiva Entrada:  Deve existir evento na pilha.
  *
  * Assertiva Saida: Não há.
  */
  void EventHandler(SDL_Event&);
  /**
  * @brief Carrega os elementos a serem impressos.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Não há.
  */
  void LoadScreen();
  /**
  * @brief Imprime os elementos previamente carregados.
  * Assertiva Entrada:  Elementos devem estar carregados.
  *
  * Assertiva Saida: Não há.
  */
  void Render();

 private:
  /** Jogador 0. */
  Player* player0;
  /** Jogador 1. */
  Player* player1;
  /** Guarda a quem pertence o turno. */
  int player_turn;
  /** Vetor de botões que serão carregados na tela. */
  VectorObjects button_objects;
  /** Vetor de textos que serão carregados na tela. */
  VectorObjects texts;
  /** Mapa do jogo. */
  Map* map;
  /** Flag para identificar inserção. */
  int insertion_flag;
  /** Flag para identificar movimentação. */
  int move_flag;
  /** Pontos do objeto a ser movido. */
  SDL_Point to_be_moved;
};

#endif  // CODE_INCLUDE_SCREENS_H_
