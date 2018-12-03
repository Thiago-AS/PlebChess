/**
 * @file map.h
 * @brief Arquivo que define o mapa do jogo e suas operações.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_MAP_H_
#define CODE_INCLUDE_MAP_H_

#include "./game_objects.h"

/**@brief Classe de espaço do mapa.
*
*  Define todos como é o espaço do mapa do jogo.
*/
class MapTile {
 public:
  /** Unidade que ocupa o espaço. */
  char unit;
  /** Posição do espaço na tela. */
  SDL_Rect position;
  /** A quem pertence o espaço. */
  int player;
  /** Objeto do espaço. */
  GameObject* object;
};

/**@brief Define o mapa do jogo.
*
*  Classe que define todos os métodos para criar, modificar e renderizar o
*  mapa do jogo.
*/
class Map {
 public:
  /** Foco atual do mouse no mapa. */
  SDL_Point focus;
  /** Matriz do mapa. */
  MapTile map[10][10];

  Map();
  ~Map();

  /**
  * @brief Desenha o mapa na tela.
  * Assertiva Entrada: Mapa previamente inicializado.
  *
  * Assertiva Saida: Não há.
  */
  void DrawMap();
  /**
  * @brief Ajusta o foco atual do mouse.
  * @param row Valor x da tela.
  * @param column Valor y da tela.
  * @param player_turn A que jogador pertence o turno.
  * @return Retorna verdadeiro caso foco seja atualizado com sucesso, falso cc.
  * Assertiva Entrada: Valor de pixels validos e turno previamente definido.
  *
  * Assertiva Saida: Verdadeiro para operação executada com sucesso.
  */
  bool UpdateFocus(int, int, int);
  /**
  * @brief Insere objeto em espaço do mapa.
  * @param object_id Valor que define qual unidade a ser inserida.
  * @param player_turn A que jogador pertence o turno.
  * @param player Jogador atual.
  * @return Retorna verdadeiro caso seja inserido com sucesso, falso cc.
  * Assertiva Entrada: Espaço do mapa deve estar vazio, foco do mouse deve
  * estar dentro do mapa.
  *
  * Assertiva Saida: Verdadeiro para operação executada com sucesso.
  */
  bool InsertObject(int, int, Player*);
  /**
  * @brief Move objeto no mapa.
  * @param object_location Local do objeto a ser movido.
  * @return Retorna verdadeiro caso seja movido com sucesso, falso cc.
  * Assertiva Entrada: Objeto a ser movimentado deve ser uma tropa.
  *
  * Assertiva Saida: Verdadeiro para operação executada com sucesso.
  */
  bool MoveObject(SDL_Point);
  /**
  * @brief Verifica se espaço do mapa esta ocupado.
  * @param player_turn A que jogador pertence o turno.
  * @return Retorna verdadeiro caso esteja ocupado, falso cc.
  * Assertiva Entrada: Espaço não ocupado por objeto do jogador a qual pertence
  * o turno.
  *
  * Assertiva Saida: Verdadeiro para ocupado, falso cc.
  */
  bool Occupied(int);

  bool IsMovePossible(char, SDL_Point);

 private:
  /** Textura de espaço vazio do mapa. */
  SDL_Texture* tile;
};

#endif  // CODE_INCLUDE_MAP_H_
