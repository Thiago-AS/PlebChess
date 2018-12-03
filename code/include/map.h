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
  /** Vida da unidade que ocupa o espaço. */
  int health;
  /** Posição do espaço na tela. */
  SDL_Rect position;
  /** A quem pertence o espaço. */
  Player* player;
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

  Map(Player*, Player*);
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
  /**
  * @brief Verifica se e possivel se movimentar para o espaço.
  * @param unit Unidade a ser verificada.
  * @param object_location Local da unidade.
  * @return Retorna verdadeiro caso seja possivel, falso cc.
  * Assertiva Entrada: Local dentro do mapa de pixel, e unidade existente.
  *
  * Assertiva Saida: Verdadeiro para possivel, falso cc.
  */
  bool IsMovePossible(char, SDL_Point);
  /**
  * @brief Renderiza as casas possiveis para movimento da unidade.
  * @param object_location Local da unidade.
  * Assertiva Entrada: Verificar se unidade se encontra nas extremidades do
  * mapa, e se existe algum objeto no espaço.
  *
  * Assertiva Saida: Não há.
  */
  void DrawPossibleMoves(SDL_Point);
  /**
  * @brief Ataca objeto no mapa.
  * @param object_location Local que ira atacar.
  * @return Retorna verdadeiro caso ataque seja sucesso, falso cc.
  * Assertiva Entrada: Deve existir objeto no foco.
  *
  * Assertiva Saida: Verdadeiro para operação executada com sucesso.
  */
  bool AttackObject(SDL_Point);
  /**
  * @brief Apaga objeto no mapa.
  * Assertiva Entrada: Deve existir objeto no foco.
  *
  * Assertiva Saida: Não há.
  */
  void EraseUnit(SDL_Point);

 private:
  /** Textura de espaço vazio do mapa. */
  SDL_Texture* tile;
  /** Textura de possivel movimentação. */
  SDL_Texture* possible_tile;
  /** Textura de possivel ataque. */
  SDL_Texture* attack_tile;
};

#endif  // CODE_INCLUDE_MAP_H_
