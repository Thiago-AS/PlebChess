/**
 * @file texture_manager.h
 * @brief Arquivo que define a biblioteca de texturas.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_TEXTURE_MANAGER_H_
#define CODE_INCLUDE_TEXTURE_MANAGER_H_

#include <string>
#include "./gui.h"

using namespace std;

/**@brief Classe que define as texturas.
*
*  Define todos os métodos para criar, modificar e renderizar uma textura.
*/
class TextureManager {
 public:
  /**
  * @brief Carrega uma textura baseada em imagem.
  * @param  file_name Nome do arquivo png a ser carregado.
  * @return Retorna textura criada.
  * Assertiva Entrada: Deve existir arquivo png com nome inserido.
  *
  * Assertiva Saida: Textura alocada com sucesso.
  */
  static SDL_Texture* LoadTexture(string);
  /**
  * @brief Carrega uma textura baseada em fonte.
  * @param  font Arquivo de fonte TTF.
  * @param  text Texto da textura a ser gerada.
  * @return Retorna textura criada.
  * Assertiva Entrada: Deve existir arquivo ttf com fonte inserida.
  *
  * Assertiva Saida: Textura alocada com sucesso.
  */
  static SDL_Texture* LoadTTF(TTF_Font*, string);
  /**
  * @brief Desenha um objeto diretamente na tela.
  * @param  texture Textura a ser desenhada.
  * @param  src Retangulo da textura de origem.
  * @param  dst Retangulo da tela onde textura sera inserido.
  * Assertiva Entrada: Textura previamente alocada, retangulos de definição com
  * pixel existente.
  *
  * Assertiva Saida: Não há.
  */
  static void Draw(SDL_Texture*, SDL_Rect, SDL_Rect);
};

#endif  // CODE_INCLUDE_TEXTURE_MANAGER_H_
