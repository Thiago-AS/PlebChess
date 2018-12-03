/**
 * @file gui_manager.h
 * @brief Arquivo que instancia e controla o jogo.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_GUI_MANAGER_H_
#define CODE_INCLUDE_GUI_MANAGER_H_

#include "./gui.h"

/**@brief Classe responsavel por rodar o jogo.
*
*  Instancia a GUI como singleton e realiza o loop principal do jogo.
*/
class GuiManager {
 private:
  /** Instancia unica do singleton. */
  static GuiManager* instance;
  /** Instancia da GUI. */
  Gui* gui;

  GuiManager();
  ~GuiManager();

 public:
  /**
  * @brief Instancia o Singleton.
  * @return Retorna o endereço do objeto unico.
  * Assertiva Entrada:  Não há.
  *
  * Assertiva Saida: Ponteiro para o objeto inicializado.
  */
  static GuiManager* Instance();
  /**
  * @brief Libera memoria do singleton.
  * Assertiva Entrada:  Objeto previamente alocado.
  *
  * Assertiva Saida: Não há.
  */
  static void Release();
  /**
  * @brief Realiza o laço principal do jogo.
  * Assertiva Entrada: Singleton de GUI previamente alocado.
  *
  * Assertiva Saida: Não há.
  */
  void Run();
};

#endif  // CODE_INCLUDE_GUI_MANAGER_H_
