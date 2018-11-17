#include "../include/tabuleiro.hpp"

Tabuleiro::Tabuleiro()
{
    tabuleiro_jogo = new Quadrado *[LIN_TABULEIRO];

    for (int i = 0; i < LIN_TABULEIRO; i++) {
        tabuleiro_jogo[i] = new Quadrado[COL_TABULEIRO];
    }


}

Tabuleiro::~Tabuleiro()
{

}
