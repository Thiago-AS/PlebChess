// "Copyright 2018 Mtonin"
/**
* @file utils.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
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
#define COL_TABULEIRO 20


int rest_eh_positivo(int ind);
int rest_limiteCol_sup(int ind);
int rest_limiteLin_sup(int ind);

#endif
