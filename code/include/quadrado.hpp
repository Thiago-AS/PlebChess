// "Copyright 2018 Grupo MP"
/**
* @file quadrado.hpp
* @brief Arquivo com as assinaturas da classe Quadrado. 
*/
#ifndef QUADRADO_HPP_
#define QUADRADO_HPP_
// includes
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
/**
 * @brief Enumeracao da Classe tipo de unidades que o jogo pode ter.
 * Descricao: Contem todas as unidades que pode estar presente em um quadrado do mapa.
 */
enum class TipoUnidade{
    UnidadeVazio,
    fortaleza,
    lenhadora,
    mina,
    arqueiro,
    cavaleiro,
    guerreiro,
    };
/**
* @brief Classe que contem as especificacoes do quadrado e como esta sendo usado.
* Descricao: Contem construtor e destrutor além dos metodos getters and setters que
* que sao usados para manipular o objeto quadrado
*/
class Quadrado {
 protected:
    TipoUnidade nome = TipoUnidade::UnidadeVazio;
    bool eh_humano = true;
    bool usado = false;
    int posX = -1;
    int posY = -1;
 public:
    Quadrado();
    ~Quadrado();

/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do quadrado para o valor passado.
* @param p_posX deve ser um valor maior igual a zero e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posX for um valor possivel seta o valor posX para p_posX.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_pox >= 0 && p_posX < LIN_TABULEIRO
*    Interface explicita: p_posX
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que zero e menor que o limite 
* entao posX = p_posX, caso der certo retorna 1.
*/
    int setPosX(unsigned int p_posX);
/**
* @fn int setPosY(unsigned int p_posY);
* @brief Metodo que seta o valor da posY do quadrado para o valor passado.
* @param p_posX deve ser um valor maior igual a zero e menor que o limite
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_posY for um valor possivel seta o valor posY para p_posY.
* Requesitos: A posicao deve pertencer a um valor possivel do tabuleiro
* Assertiva Entrada:  p_posY >= 0 && p_posY < COL_TABULEIRO
*    Interface explicita: p_posY
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se p_posX for maior que zero e menor que o limite 
* entao posY = p_posY, caso der certo retorna 1.
*/	
    int setPosY(unsigned int p_posY);
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
    int setHumano(bool humano);
/**
* @fn int setUsado(bool uso);
* @brief Se o quadrado do tabuleiro tiver algo eh setado para true usado
* @param uso deve ser um booleano, true(1) ou false(0).
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se uso for falso eh_humano sera falso, mesmo caso se for verdadeiro.
* Requesitos: Parametro uso deve ser booleano
* Assertiva Entrada:  typeof(uso) = bool
*    Interface explicita: uso
*    Interface implicita: Nao ha
* Assertiva Saida: usado = uso e retorna 1 se deu certo
*/
    int setUsado(bool uso);
/**
* @fn int setUnidade(TipoUnidade nomeUnidade);
* @brief Esta funcao associa um tipo de unidade a quadrado do tabuleiro
* @param nomeUnidade deve ser fazer parte do TipoUnidade.
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se nomeUnidade for TipoUnidade entao, nome = nomeUnidade
* Requesitos: Parametro deve fazer parte do TipoUnidade, caso contrario havera inconsistencia
* Assertiva Entrada:  typeof(nomeUnidade) = TipoUnidade
*    Interface explicita: nomeUnidade
*    Interface implicita: Nao ha
* Assertiva Saida: nome = TipoUnidade e retorna 1 se deu certo
*/
    int setUnidade(TipoUnidade nomeUnidade);
/**
* @fn void unidadeMorta();
* @brief Esta funcao seta a posicao para uma posicao invalida do tabuleiro e bota nome = UnidadeVazio
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Nao ha hipoteses
* Requesitos: O metodo seta posX e posY para -1 e nome para UnidadeVazio
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: nome = Objeto tem posX = -1 e posY = -1, nome = UnidadeVazio e retorna 1 se deu certo
*/
    void unidadeMorta();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto Quadrado.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser Quadrado.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
    unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto Quadrado.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser Quadrado.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a posicao Y do tabuleiro referente ao objeto.
*/	
    unsigned int getPosY();
/**
* @fn bool getHumano();
* @brief Retorna o bool referente ao objeto Quadrado.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser do tipo Quadrado.
* Requesitos: Metodo deve retornar o valor de eh_humano
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de eh_humano
*/
    bool getHumano();
/**
* @fn bool getUsado();
* @brief Retorna o bool referente a usado ao objeto Quadrado.
* @return Retorna usado
* Hipoteses: O objeto passado deve ser do tipo Quadrado.
* Requesitos: Metodo deve retornar o valor de usado
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de usado
*/
    bool getUsado();
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
    TipoUnidade getUnidade();
};
#endif
