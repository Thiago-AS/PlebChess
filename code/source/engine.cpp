// Copyright [2018] < Grupo Mp >
#include "../include/tropas.hpp"
#include "../include/unidades.hpp"
#include "../include/engine.hpp"

// Metodos da classe Engine
// se quiserem, pode ser mais modularizado e jogador virar outro modulo

Engine::Engine() {
    setTurno();
    setJogador();
}
Engine::~Engine() {
}

int Engine::setTurno() {
    turnoAtual = 1;
    return 1;
}

int Engine::endTurno() {
    turnoAtual++;
    if ( jogadorAtual == 1 )
        jogadorAtual = 2;
    else
        jogadorAtual = 1;
    return 1;
}

int Engine::setJogador() {
    jogadorAtual = 1;  // pode ser 1 ou 2
    return 1;
}

int Engine::getJogador() {
    return jogadorAtual;
}

int Engine::getTurno() {
    return turnoAtual;
}

// metodos da classe JOGADOR

Jogador::Jogador(int times) {
    time = times;
    setRecursos(10, 10);
    setTropas(0, 0, 0);
    setConstrucoes(0, 0);
    setGanhoPorTurno();
}

Jogador::~Jogador() {
}

/* Todos os valores dados inicialmente sao arbitrarios, e podem
 * ser alterados para balancear o ritmo do jogo
 */

int Jogador::setRecursos(int ouro1, int madeira1) {
    ouro = ouro1;
    madeira = madeira1;
}

int Jogador::setTropas(int guerr, int arq, int cav) {
    guerreiros = guerr;
    arqueiros = arq;
    cavaleiros = cav;
}

int Jogador::setConstrucoes(int mina, int madeireira) {
    minas = mina;
    madeireiras = madeireira;
}

int Jogador::setGanhoPorTurno() {
    /* Deve ser arrumado para receber a quantidade proveniente
     * do arquivo unidades.cpp, para mudar em apenas um lugar do
     * codigo. A implementacao atual eh soh um modelo
     */

    ganhoOuro = (minas*10) + 5;  // quantidade vezes quanto cada da por turno
    ganhoMadeira = (madeireiras*5) + 5;
}

int Jogador::getTime() {
    return time;
}

int Jogador::getOuro() {
    return ouro;
}

int Jogador::getMadeira() {
    return madeira;
}

int Jogador::getGuerreiros() {
    return guerreiros;
}

int Jogador::getArqueiros() {
    return arqueiros;
}

int Jogador::getCavaleiros() {
    return cavaleiros;
}

int Jogador::getMinas() {
    return minas;
}

int Jogador::getMadeireiras() {
    return madeireiras;
}

int Jogador::getGanhoOuro() {
    return ganhoOuro;
}

int Jogador::getGanhoMadeira() {
    return ganhoMadeira;
}
int Jogador::setVetorArqueiro(int posicaoX, int posicaoY) {
    int i = 0;
        while ( i < 10 ) {
            if ( vetorArqueiro[i].getAtivo() == 0 ) {
                vetorArqueiro[i].setAtivo(1);  // ativa o arqueiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o arqueiro */
                vetorArqueiro[i].setPosX(posicaoX);
                vetorArqueiro[i].setPosY(posicaoY);
                return 1;  // bem sucedido
            }  // end if
            i++;
        }  // end while
        return 0; // nao era possivel colocar mais arqueiros
}
Arqueiro Jogador::getVetorArqueiro(int indice) {
    if( indice >= 0 && indice < 10 )
        return vetorArqueiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Arqueiro();
}
int Jogador::setVetorGuerreiro(int posicaoX, int posicaoY) {
    int i = 0;
        while ( i < 10 ) {
            if ( vetorGuerreiro[i].getAtivo() == 0 ) {
                vetorGuerreiro[i].setAtivo(1);  // ativa o guerreiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o guerreiro */
                vetorGuerreiro[i].setPosX(posicaoX);
                vetorGuerreiro[i].setPosY(posicaoY);
                return 1;  // bem sucedido
            }  // end if
            i++;
        }  // end while
        return 0; // nao era possivel colocar mais guerreiros 
}
Guerreiro Jogador::getVetorGuerreiro(int indice) {
    if( indice >= 0 && indice < 10 )
        return vetorGuerreiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Guerreiro();
}
int Jogador::setVetorCavaleiro(int posicaoX, int posicaoY) {
    int i = 0;
        while ( i < 10 ) {
            if ( vetorCavaleiro[i].getAtivo() == 0 ) {
                vetorCavaleiro[i].setAtivo(1);  // ativa o cavaleiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                vetorCavaleiro[i].setPosX(posicaoX);
                vetorCavaleiro[i].setPosY(posicaoY);
                return 1;  // bem sucedido
            }  // end if
            i++;
        }  // end while
        return 0; // nao era possivel colocar mais cavaleiros 
}
Cavaleiro Jogador::getVetorCavaleiro(int indice) {
    if( indice >= 0 && indice < 10 )
        return vetorCavaleiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Cavaleiro();
}
