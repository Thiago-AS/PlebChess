/**
 * @file game_objects.h
 * @brief Arquivo que define os objetos basicos da engine grafica.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_GAME_OBJECTS_H_
#define CODE_INCLUDE_GAME_OBJECTS_H_

#include <string>
#include <vector>
#include "./gui.h"
#include "../include/texture_manager.h"

using namespace std;

/**@brief Classe que define os objetos graficos do jogo.
*
*  Define todos os métodos para criar, modificar e renderizar um objeto no
*  jogo.
*/
class GameObject {
 public:
  GameObject(SDL_Texture*, int, int, int, int);
  ~GameObject();
  /**
  * @brief Lida com os eventos de clique do objeto.
  * @param button_event Evento de mouse do respectivo objeto.
  * @return Retorna caso evento pertenca ao objeto, falso c.c.
  * Assertiva Entrada:  Deve exisitir um evento de mouse.
  *
  * Assertiva Saida: Verdadeiro para evento do respectivo objeto, falso c.c.
  */
  bool HandleMouse(SDL_MouseButtonEvent&);
  /**
  * @brief Atualiza a posição do objeto.
  * @param x Nova posição x.
  * @param y Nova posição y.
  * Assertiva Entrada: Parametros devem ser inteiros.
  *
  * Assertiva Saida: Não há.
  */
  void Update(int, int);
  /**
  * @brief Renderiza objeto na tela.
  * Assertiva Entrada: Deve existir textura a ser renderizada.
  *
  * Assertiva Saida: Não há.
  */
  void Render();
  /**
  * @brief Limpa toda memoria do objeto.
  * Assertiva Entrada: Objeto previamente alocado.
  *
  * Assertiva Saida: Textura desalocado e apontado para null.
  */
  void Clean();

 private:
  /** Textura do objeto. */
  SDL_Texture* obj_texture;
  /** Posição do retangulo na tela onde objeto sera renderizado. */
  SDL_Rect dst_rect;
};

/**@brief Classe que define um vetor que carrega objetos de jogo.
*
*  Define todos os métodos para criar, modificar e renderizar multiplos objetos.
*/
class VectorObjects {
 public:
  /**
  * @brief Adiciona objeto ao vetor.
  * @param object Objeto a ser adicionado
  * Assertiva Entrada: Objeto previamente alocado.
  *
  * Assertiva Saida: Não há.
  */
  void AddObject(GameObject*);
  /**
  * @brief Retorna objeto do vetor.
  * @param position Posição do objeto no vetor.
  * Assertiva Entrada: Posição existente.
  *
  * Assertiva Saida: Objeto da posição fornecida.
  */
  GameObject* GetObject(int);
  /**
  * @brief Lida com os eventos de mouse dos objetos no vetor.
  * @param button_event Eventos de mouse da pilha.
  * Assertiva Entrada: Deve existir evento de mouse na pilha.
  *
  * Assertiva Saida: Posição do objeto que corresponde ao evento ocorrido.
  */
  int HandleMouse(SDL_MouseButtonEvent&);
  /**
  * @brief Renderiza todos os objetos do vetor.
  * Assertiva Entrada: Vetor não deve estar vazio.
  *
  * Assertiva Saida: Não há.
  */
  void Draw();
  /**
  * @brief Limpa a memoria de todos objetos no vetor.
  * Assertiva Entrada: Vetor não deve estar vazio.
  *
  * Assertiva Saida: Textura desalocadas e objetos apontados para null.
  */
  void Clean();

 private:
  /** Vetor de objetos. */
  vector<GameObject*> objects_vector;
};

/**@brief Classe que define os jogadores.
*
*  Define todos os métodos que definem um jogador.
*/
class Player {
 public:
  Player(int);
  ~Player();
  /**
  * @brief Atualiza quantidade de madeira do jogador.
  * @param value valor a ser modificado.
  * Assertiva Entrada: Inteiro sem sinal.
  *
  * Assertiva Saida: Não há.
  */
  void UpdateWood(int);
  /**
  * @brief Atualiza quantidade de ouro do jogador.
  * @param value valor a ser modificado.
  * Assertiva Entrada: Inteiro sem sinal.
  *
  * Assertiva Saida: Não há.
  */
  void UpdateGold(int);
  /**
  * @brief Finaliza turno do jogador.
  * Assertiva Entrada: Não há.
  *
  * Assertiva Saida: Não há.
  */
  void FinishTurn();

  /** Valor total de madeira do jogador. */
  int total_wood;
  /** Valor total de ouro do jogador. */
  int total_gold;
  /** Quantidade de lenhadoras. */
  int amount_w;
  /** Quantidade de minas. */
  int amount_m;
  /** Player id. */
  int id;

  /** Texto do valor total de ouro. */
  GameObject* gold_text;
  /** Texto do valor total de madeira. */
  GameObject* wood_text;

 private:
  /** Fonte utilizada. */
  SDL_Texture* fontSup;
  /** Altura e largura da textura. */
  int lw, lh;
};

#endif  // CODE_INCLUDE_GAME_OBJECTS_H_
