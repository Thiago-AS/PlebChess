// "Copyright 2018 Grupo MP"
/**
* @file utils.hpp
* @brief Arquivo com as funcoes para verficar restricoes. 
*/
#ifndef UTILS_HPP_
#define UTILS_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;
#define LIN_TABULEIRO 30
#define COL_TABULEIRO 30

/**
* @fn int rest_eh_positivo(int ind);
* @brief Funcao que verifica se o int e positivo
* @param ind eh o inteiro a ser verificado
* @return 1 caso de certo, 0 c.c.
* Hipoteses: A funcao deve devolver 1 se for maior ou igual a zero.
* Requesitos: Ind deve ser um inteiro.
* Assertiva Entrada:  Ind >= 0
*    Interface explicita: Ind
*    Interface implicita: Nao ha
* Assertiva Saida: Se ind >= 0 entao retorna 1, c.c 0.
*/
int rest_eh_positivo(int ind);
/**
* @fn int rest_limiteCol_sup(int ind);
* @brief Funcao que verifica se o int eh menor que COL_TABULEIRO
* @param ind eh o inteiro a ser verificado
* @return 1 caso de certo, 0 c.c.
* Hipoteses: A funcao deve devolver 1 se for menor que o limite.
* Requesitos: Ind deve ser um inteiro.
* Assertiva Entrada:  Ind < COL_TABULEIRO.
*    Interface explicita: Ind
*    Interface implicita: COL_TABULEIRO
* Assertiva Saida: Se ind < COL_TABULEIRO entao retorna 1, c.c 0.
*/
int rest_limiteCol_sup(int ind);
/**
* @fn int rest_limiteLin_sup(int ind);
* @brief Funcao que verifica se o int eh menor que LIN_TABULEIRO
* @param ind eh o inteiro a ser verificado
* @return 1 caso de certo, 0 c.c.
* Hipoteses: A funcao deve devolver 1 se for menor que o limite.
* Requesitos: Ind deve ser um inteiro.
* Assertiva Entrada:  Ind < LIN_TABULEIRO.
*    Interface explicita: Ind
*    Interface implicita: LIN_TABULEIRO
* Assertiva Saida: Se ind < LIN_TABULEIRO entao retorna 1, c.c 0.
*/
int rest_limiteLin_sup(int ind);

#endif
