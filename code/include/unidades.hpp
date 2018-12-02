// "Copyright 2018 Grupo MP"
/**
* @file Unidades.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas.
*/
#ifndef CODE_INCLUDE_UNIDADES_HPP_
#define CODE_INCLUDE_UNIDADES_HPP_

// includes
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
/**
 * @brief Enum que indica o tipo de recurso que a unidade produz.
 */
enum tipo_recurso {
    nada = 0,
    madeira = 1,
    ouro = 2
};

class Mina {
 private:
    tipo_recurso recurso;
    bool eh_humano;
    unsigned int vida;
    unsigned int qt_materia;
    unsigned int construcao;
    unsigned int largura;
    unsigned int comprimento;
    // indica a posicao inicial ....
    // crescera de acordo com a largura e o comprimento
    unsigned int posX, posY;

 public:
        // construtor e destrutor
        Mina();
        ~Mina();
        // metodos getter and setters
/**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida da mina para o valor passado.
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
* @fn int setQt_materia(unsigned int materia);
* @brief Metodo que seta o valor de material gerado pela mina.
* @param materia deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se materia for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  materia >= 0
*    Interface explicita: materia
*    Interface implicita:
* Assertiva Saida: Se materia for maior que 0
* entao Qt_materia = materia, caso der certo retorna 1.
*/
        int setQt_materia(unsigned int materia);
/**
* @fn int setLargura(unsigned int p_lar);
* @brief Metodo que seta o valor da largura da mina.
* @param p_lar deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_lar for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_lar >= 0
*    Interface explicita: p_lar
*    Interface implicita:
* Assertiva Saida: Se p_lar for maior que 0
* entao vida = p_lar, caso der certo retorna 1.
*/
        int setLargura(unsigned int p_lar);
/**
* @fn int setComprimento(unsigned int p_com);
* @brief Metodo que seta o valor da comprimento da mina.
* @param p_com deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_com for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_com >= 0
*    Interface explicita: p_com
*    Interface implicita:
* Assertiva Saida: Se p_com for maior que 0
* entao vida = p_com, caso der certo retorna 1.
*/
        int setComprimento(unsigned int p_com);
/**
* @fn int setConstrucao(unsigned int p_const);
* @brief Metodo que seta o valor para construir uma mina.
* @param p_const deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_const for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_const >= 0
*    Interface explicita: p_const
*    Interface implicita:
* Assertiva Saida: Se p_const for maior que 0
* entao Qt_materia = p_const, caso der certo retorna 1.
*/
        int setConstrucao(unsigned int p_const);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do mina para o valor passado.
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
* @brief Metodo que seta o valor da posY do mina para o valor passado.
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
* @fn int setRecurso(tipo_recurso p_recurso);
* @brief Metodo que seta tipo de recurso de mina.
* @param p_recurso deve ser um valor valido para o enum tipo_recurso
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_recurso for um valor possivel seta .
* Requesitos: deve ser de tipo_recurso.
* Assertiva Entrada:  p_recurso >= 0
*    Interface explicita: p_recurso
*    Interface implicita:
* Assertiva Saida: Se p_recurso for maior que 0
* entao recurso = p_recurso, caso der certo retorna 1.
*/
        int setRecurso(tipo_recurso p_recurso);
/**
* @fn int setHumano(bool humano);
* @brief Se a unidade for do jogador seta para true, caso contrario falso.
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
* @brief Retorna o bool referente ao objeto mina.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser mina.
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
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getLargura();
* @brief Retorna o int referente a largura.
* @return Retorna largura
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o valor da largura
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de largura
*/
        unsigned int getLargura();
/**
* @fn unsigned int getComprimento();
* @brief Retorna o int referente a comprimento.
* @return Retorna comprimento
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o valor da comprimento
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de comprimento
*/
        unsigned int getComprimento();
/**
* @fn unsigned int getQt_materia();
* @brief Retorna o int referente a material produzido.
* @return Retorna qt_materia
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o valor produzido
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de produzido por turno
*/
        unsigned int getQt_materia();
/**
* @fn unsigned int getConstrucao();
* @brief Retorna o int referente ao custo para construir mina.
* @return Retorna construcao
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o valor para produzir
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de custo da mina
*/
        unsigned int getConstrucao();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto mina.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser mina.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto mina.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser mina.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a a vida do mina.
*/
        unsigned int getPosY();
/**
* @fn         tipo_recurso getRecurso();
* @brief Retorna o enum do recurso.
* @return Retorna o tipo do recurso
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o tipo do recurso
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor o tipo do recurso
*/
        tipo_recurso getRecurso();
/**
* @fn int get_status_unidade();
* @brief Printa informacoes da unidade.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/
        void get_status_unidade();
};
class Lenhadora {
 private:
    tipo_recurso recurso;
    bool eh_humano;
    unsigned int vida;
    unsigned int qt_materia;
    unsigned int construcao;
    unsigned int largura;
    unsigned int comprimento;
    // indica a posicao inicial ....
    // crescera de acordo com a largura e o comprimento
    unsigned int posX, posY;

 public:
        // construtor e destrutor
        Lenhadora();
        ~Lenhadora();
        // metodos getter and setters
/**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida da lenhadora para o valor passado.
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
* @fn int setQt_materia(unsigned int materia);
* @brief Metodo que seta o valor de material gerado pela lenhadora.
* @param materia deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se materia for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  materia >= 0
*    Interface explicita: materia
*    Interface implicita:
* Assertiva Saida: Se materia for maior que 0
* entao Qt_materia = materia, caso der certo retorna 1.
*/
        int setQt_materia(unsigned int materia);
/**
* @fn int setLargura(unsigned int p_lar);
* @brief Metodo que seta o valor da largura da lenhadora.
* @param p_lar deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_lar for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_lar >= 0
*    Interface explicita: p_lar
*    Interface implicita:
* Assertiva Saida: Se p_lar for maior que 0
* entao vida = p_lar, caso der certo retorna 1.
*/
        int setLargura(unsigned int p_lar);
/**
* @fn int setComprimento(unsigned int p_com);
* @brief Metodo que seta o valor da comprimento da lenhadora.
* @param p_com deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_com for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_com >= 0
*    Interface explicita: p_com
*    Interface implicita:
* Assertiva Saida: Se p_com for maior que 0
* entao vida = p_com, caso der certo retorna 1.
*/
        int setComprimento(unsigned int p_com);
/**
* @fn int setConstrucao(unsigned int p_const);
* @brief Metodo que seta o valor para construir uma lenhadora.
* @param p_const deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_const for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_const >= 0
*    Interface explicita: p_const
*    Interface implicita:
* Assertiva Saida: Se p_const for maior que 0
* entao Qt_materia = p_const, caso der certo retorna 1.
*/
        int setConstrucao(unsigned int p_const);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do lenhadora para o valor passado.
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
* @brief Metodo que seta o valor da posY do lenhadora para o valor passado.
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
* @fn int setRecurso(tipo_recurso p_recurso);
* @brief Metodo que seta tipo de recurso de lenhadora.
* @param p_recurso deve ser um valor valido para o enum tipo_recurso
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_recurso for um valor possivel seta .
* Requesitos: deve ser de tipo_recurso.
* Assertiva Entrada:  p_recurso >= 0
*    Interface explicita: p_recurso
*    Interface implicita:
* Assertiva Saida: Se p_recurso for maior que 0
* entao recurso = p_recurso, caso der certo retorna 1.
*/
        int setRecurso(tipo_recurso p_recurso);
/**
* @fn int setHumano(bool humano);
* @brief Se a unidade for do jogador seta para true, caso contrario falso.
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
* @brief Retorna o bool referente ao objeto lenhadora.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser lenhadora.
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
* Hipoteses: O objeto passado deve ser do tipo lenhadora.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getLargura();
* @brief Retorna o int referente a largura.
* @return Retorna largura
* Hipoteses: O objeto passado deve ser do tipo lenhadora.
* Requesitos: Metodo deve retornar o valor da largura
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de largura
*/
        unsigned int getLargura();
/**
* @fn unsigned int getComprimento();
* @brief Retorna o int referente a comprimento.
* @return Retorna comprimento
* Hipoteses: O objeto passado deve ser do tipo lenhadora.
* Requesitos: Metodo deve retornar o valor da comprimento
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de comprimento
*/
        unsigned int getComprimento();
/**
* @fn unsigned int getQt_materia();
* @brief Retorna o int referente a material produzido.
* @return Retorna qt_materia
* Hipoteses: O objeto passado deve ser do tipo lenhadora.
* Requesitos: Metodo deve retornar o valor produzido
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de produzido por turno
*/
        unsigned int getQt_materia();
/**
* @fn unsigned int getConstrucao();
* @brief Retorna o int referente ao custo para construir lenhadora.
* @return Retorna construcao
* Hipoteses: O objeto passado deve ser do tipo lenhadora.
* Requesitos: Metodo deve retornar o valor para produzir
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de custo da lenhadora
*/
        unsigned int getConstrucao();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto lenhadora.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser lenhadora.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto lenhadora.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser lenhadora.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a a vida do lenhadora.
*/
        unsigned int getPosY();
/**
* @fn         tipo_recurso getRecurso();
* @brief Retorna o enum do recurso.
* @return Retorna o tipo do recurso
* Hipoteses: O objeto passado deve ser do tipo mina.
* Requesitos: Metodo deve retornar o tipo do recurso
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor o tipo do recurso
*/
        tipo_recurso getRecurso();
/**
* @fn int get_status_unidade();
* @brief Printa informacoes da unidade.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/
        void get_status_unidade();
};
class Fortaleza {
 private:
    tipo_recurso recurso;
    bool eh_humano;
    unsigned int vida;
    unsigned int qt_materia;
    unsigned int construcao;
    unsigned int largura;
    unsigned int comprimento;
    // indica a posicao inicial ....
    // crescera de acordo com a largura e o comprimento
    unsigned int posX, posY;

 public:
        // construtor e destrutor
        Fortaleza();
        ~Fortaleza();
        // metodos getter and setters
        /**
* @fn int setVida(unsigned int p_vida);
* @brief Metodo que seta o valor da vida da fortaleza para o valor passado.
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
* @fn int setQt_materia(unsigned int materia);
* @brief Metodo que seta o valor de material gerado pela fprtaleza.
* @param materia deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se materia for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  materia >= 0
*    Interface explicita: materia
*    Interface implicita:
* Assertiva Saida: Se materia for maior que 0
* entao Qt_materia = materia, caso der certo retorna 1.
*/
        int setQt_materia(unsigned int materia);
/**
* @fn int setLargura(unsigned int p_lar);
* @brief Metodo que seta o valor da largura da fortaleza.
* @param p_lar deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_lar for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_lar >= 0
*    Interface explicita: p_lar
*    Interface implicita:
* Assertiva Saida: Se p_lar for maior que 0
* entao vida = p_lar, caso der certo retorna 1.
*/
        int setLargura(unsigned int p_lar);
/**
* @fn int setComprimento(unsigned int p_com);
* @brief Metodo que seta o valor da comprimento da fortaleza.
* @param p_com deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_com for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_com >= 0
*    Interface explicita: p_com
*    Interface implicita:
* Assertiva Saida: Se p_com for maior que 0
* entao vida = p_com, caso der certo retorna 1.
*/
        int setComprimento(unsigned int p_com);
/**
* @fn int setConstrucao(unsigned int p_const);
* @brief Metodo que seta o valor para construir uma fortaleza.
* @param p_const deve ser um valor maior igual a 0
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_const for um valor possivel seta .
* Requesitos: deve ser int.
* Assertiva Entrada:  p_const >= 0
*    Interface explicita: p_const
*    Interface implicita:
* Assertiva Saida: Se p_const for maior que 0
* entao Qt_materia = p_const, caso der certo retorna 1.
*/
        int setConstrucao(unsigned int p_const);
/**
* @fn int setPosX(unsigned int p_posX);
* @brief Metodo que seta o valor da posX do fortaleza para o valor passado.
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
* @brief Metodo que seta o valor da posY do lenhadora para o valor passado.
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
* @fn int setRecurso(tipo_recurso p_recurso);
* @brief Metodo que seta tipo de recurso de fortaleza.
* @param p_recurso deve ser um valor valido para o enum tipo_recurso
* @return 1 caso de certo, 0 c.c.
* Hipoteses: Se p_recurso for um valor possivel seta .
* Requesitos: deve ser de tipo_recurso.
* Assertiva Entrada:  p_recurso >= 0
*    Interface explicita: p_recurso
*    Interface implicita:
* Assertiva Saida: Se p_recurso for maior que 0
* entao recurso = p_recurso, caso der certo retorna 1.
*/
        int setRecurso(tipo_recurso p_recurso);
/**
* @fn int setHumano(bool humano);
* @brief Se a unidade for do jogador seta para true, caso contrario falso.
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
* @brief Retorna o bool referente ao objeto fortaleza.
* @return Retorna eh_humano
* Hipoteses: O objeto passado deve ser fortaleza.
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
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o valor de vida
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de vida
*/
        unsigned int getVida();
/**
* @fn unsigned int getLargura();
* @brief Retorna o int referente a largura.
* @return Retorna largura
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o valor da largura
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de largura
*/
        unsigned int getLargura();
/**
* @fn unsigned int getComprimento();
* @brief Retorna o int referente a comprimento.
* @return Retorna comprimento
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o valor da comprimento
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de comprimento
*/
        unsigned int getComprimento();
/**
* @fn unsigned int getQt_materia();
* @brief Retorna o int referente a material produzido.
* @return Retorna qt_materia
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o valor produzido
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de produzido por turno
*/
        unsigned int getQt_materia();
/**
* @fn unsigned int getConstrucao();
* @brief Retorna o int referente ao custo para construir fortaleza.
* @return Retorna construcao
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o valor para produzir
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor de custo da fortaleza
*/
        unsigned int getConstrucao();
/**
* @fn unsigned int getPosX();
* @brief Retorna a posicao X do objeto fortaleza.
* @return Retorna posX
* Hipoteses: O objeto passado deve ser fortaleza.
* Requesitos: Metodo deve retornar o valor de posX
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve a posicao X do tabuleiro referente ao objeto.
*/
        unsigned int getPosX();
/**
* @fn unsigned int getPosY();
* @brief Retorna a posicao Y do objeto fortaleza.
* @return Retorna posY
* Hipoteses: O objeto passado deve ser fortaleza.
* Requesitos: Metodo deve retornar o valor de posY.
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: devolve a a vida do fortaleza.
*/
        unsigned int getPosY();
/**
* @fn         tipo_recurso getRecurso();
* @brief Retorna o enum do recurso.
* @return Retorna o tipo do recurso
* Hipoteses: O objeto passado deve ser do tipo fortaleza.
* Requesitos: Metodo deve retornar o tipo do recurso
* Assertiva Entrada:  Nao ha
*    Interface explicita: Nao ha
*    Interface implicita: Nao ha
* Assertiva Saida: devolve o valor o tipo do recurso
*/
        tipo_recurso getRecurso();
/**
* @fn int get_status_unidade();
* @brief Printa informacoes da unidade.
* Hipoteses: Nao ha
* Requesitos: Nao ha .
* Assertiva Entrada:  Nao ha.
*    Interface explicita: Nao ha.
*    Interface implicita: Nao ha.
* Assertiva Saida: Printa informacoes e retorna 1.
*/
        void get_status_unidade();
};
#endif
