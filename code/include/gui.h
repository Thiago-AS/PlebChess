/**
 * @file gui.h
 * @brief Arquivo que instancia todas as telas.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_GUI_H_
#define CODE_INCLUDE_GUI_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

/**@brief Classe que define enum das telas.
*
*  Define uma constante para todas as telas do jogo.
*/
enum class GameScreen: int {
    MAIN_MENU = 0,
    NEW_GAME = 1,
    PAUSE_MENU = 2
};

/**@brief Clase que define e instancia todas as telas do jogo.
*
*  Singleton que gerencia as telas do jogo.
*/
class Gui {
 private:
  /** Instancia unica do singleton. */
  static Gui* instance;
  /** Guarda se objeto iniciado ou não. */
  static bool initialized;
  /** Janela principal do SDL. */
  SDL_Window* mWindow;

  Gui();
  ~Gui();
  /**
  * @brief Inicializa biblioteca SDL.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Verdadeiro para biblioteca inicializada com sucesso
  * falso, cc.
  */
  bool Init();

 public:
  /** Largura da janela. */
  const int SCREEN_WIDTH = 800;
  /** Altura da janela. */
  const int SCREEN_HEIGHT = 640;
  /** Renderer do SDL. */
  static SDL_Renderer* gRenderer;
  /** Fonte utilizada no jogo. */
  static TTF_Font * game_font;
  /** Valor da tela atual. */
  static GameScreen current_screen;
  /** Flag de saida do jogo. */
  static bool quit;

  /**
  * @brief Instancia o Singleton.
  * @return Retorna o endereço do objeto unico.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Ponteiro para o objeto inicializado.
  */
  static Gui* Instance();
  /**
  * @brief Libera memoria do singleton.
  * Assertiva Entrada:  Objeto previamente alocado.
  *
  * Assertiva Saida: Não há.
  */
  static void Release();
  /**
  * @brief Verifica se objeto já foi inicializado.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Verdadeiro para inicializado, falso cc.
  */
  static bool Initialized();
  /**
  * @brief Lida com a pilha de eventos total do jogo.
  * Assertiva Entrada:  Deve existir evento na pilha.
  *
  * Assertiva Saida: Não há.
  */
  void HandleEvents();
  /**
  * @brief Renderiza todas as telas do jogo.
  * Assertiva Entrada: Telas previamente alocadas.
  *
  * Assertiva Saida: Não há.
  */
  void Render();
};

#endif  // CODE_INCLUDE_GUI_H_
