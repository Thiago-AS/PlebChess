// Copyright [2018] < Grupo Mp >
#include "../include/engine.hpp"

// Metodos da classe Engine
// se quiserem, pode ser mais modularizado e jogador virar outro modulo

Engine::Engine() {
    setTurno();
    setJogador();
	int i = 0, j =0; 
	for ( i = 0; i < LIN_TABULEIRO; i++) {
		for (j = 0; j < COL_TABULEIRO; j++) {
		 tabuleirogame[i][j] = TipoUnidade::t_UnidadeVazio;	
	    }
	}
			
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

TipoUnidade Engine::getUnidadeTAB(unsigned int posX, unsigned int posY) {
 return tabuleirogame[posX][posY];
}
int Engine::setUnidadeTAB(TipoUnidade unit, unsigned int posX, unsigned int posY){
 if( posX > LIN_TABULEIRO || posY  > COL_TABULEIRO) {
	 printf("Posicao invalida\n");
	 return 0;
 } else {
	 tabuleirogame[posX][posY] = unit;
     return 1;	
 }    

}	
// metodos da classe JOGADOR

Jogador::Jogador(int times) {
    time = times;
    inicializaJogador();
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
int Jogador::inicializaJogador() {
    /* eh necessario para os outros metodos ja terem o valor inicial
        desses recursos, para poder fazer as contas */
    arqueiros = 0;
    guerreiros = 0;
    cavaleiros = 0;
    minas = 0;
    madeireiras = 0;
    return 1;
}
int Jogador::setRecursos(int ouro1, int madeira1) {
    ouro = ouro1;
    madeira = madeira1;
}

int Jogador::setTropas(int guerr, int arq, int cav) {
    /* adiciona novas tropas as ja existentes */
    guerreiros = guerr + guerreiros;
    arqueiros = arq + arqueiros;
    cavaleiros = cav + cavaleiros;
	uni_vazias -= (guerr+arq+cav);
}

int Jogador::setConstrucoes(int mina, int madeireira) {
    /* adiciona novas construcoes as ja existentes */
    minas = minas + mina;
    madeireiras = madeireiras + madeireira;
	uni_vazias -= (mina+madeireira);
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
        return 0;  // nao era possivel colocar mais arqueiros
}
Arqueiro Jogador::getVetorArqueiro(int indice) {
    if ( indice >= 0 && indice < 10 )
        return vetorArqueiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Arqueiro();
}
Arqueiro Jogador::getArqueiroBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
	 while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if((vetorArqueiro[i].getPosX() == (posX)) && 
		    (vetorArqueiro[i].getPosY() == (posY))) {
				
                return vetorArqueiro[i];  // bem sucedido
            }  // end if
            i++;
        }  
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
        return 0;  // nao era possivel colocar mais guerreiros
}
Guerreiro Jogador::getVetorGuerreiro(int indice) {
    if ( indice >= 0 && indice < 10 )
        return vetorGuerreiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Guerreiro();
}
Guerreiro Jogador::getGuerreiroBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
     while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if((vetorGuerreiro[i].getPosX() == (posX)) && 
		    (vetorGuerreiro[i].getPosY() == (posY))) {
				
                return vetorGuerreiro[i];  // bem sucedido
            }  // end if
            i++;
        }  
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
        return 0;  // nao era possivel colocar mais cavaleiros
}
Cavaleiro Jogador::getVetorCavaleiro(int indice) {
    if ( indice >= 0 && indice < 10 )
        return vetorCavaleiro[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Cavaleiro();
}
Cavaleiro Jogador::getCavaleiroBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
	 while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if((vetorCavaleiro[i].getPosX() == (posX)) && 
		    (vetorCavaleiro[i].getPosY() == (posY))) {
				
                return vetorCavaleiro[i];  // bem sucedido
            }  // end if
            i++;
        }  
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Cavaleiro();
}

int Jogador::alteraCavaleiro(int indice, unsigned int posX, unsigned int posY) {
    if ( indice >= 0 && indice < 10 ) {
         vetorCavaleiro[indice].setPosY(posY);
         vetorCavaleiro[indice].setPosX(posX);
         return 1;
    } else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
}
int Jogador::alteraArqueiro(int indice, unsigned int posX, unsigned int posY) {
    if ( indice >= 0 && indice < 10 ) {
         vetorArqueiro[indice].setPosY(posY);
         vetorArqueiro[indice].setPosX(posX);
         return 1;
    } else 
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
}
int Jogador::alteraGuerreiro(int indice, unsigned int posX, unsigned int posY) {
    if ( indice >= 0 && indice < 10 ) {
         vetorGuerreiro[indice].setPosY(posY);
         vetorGuerreiro[indice].setPosX(posX);
         return 1;
    } else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
}

int Jogador::setVetorMina(int posicaoX, int posicaoY) {
    int i = 0;
        while ( i < 5 ) {
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                vetorMina[i].setPosX(posicaoX);
                vetorMina[i].setPosY(posicaoY);
            i++;
        }  // end while
        return 1; 
}
int Jogador::setVetorLenhadora(int posicaoX, int posicaoY) {
    int i = 0;
        while ( i < 8 ) {
                 /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                vetorLenhadora[i].setPosX(posicaoX);
                vetorLenhadora[i].setPosY(posicaoY);
            i++;
        }  // end while
        
        return 1;  // bem sucedido
        
}

int Jogador::setFortaleza(int posicaoX, int posicaoY) {
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                un_Fortaleza.setPosX(posicaoX);
                un_Fortaleza.setPosY(posicaoY);
                return 1;  // bem sucedido
     
}

int Jogador::alteraMina(int indice, unsigned int posX, unsigned int posY) {
    if ( indice >= 0 && indice < 5 ) {
         vetorMina[indice].setPosY(posY);
         vetorMina[indice].setPosX(posX);
         return 1;
    } else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
}

int Jogador::alteraLenhadora(int indice, unsigned int posX, unsigned int posY) {
    if ( indice >= 0 && indice < 8 ) {
         vetorLenhadora[indice].setPosY(posY);
         vetorLenhadora[indice].setPosX(posX);
         return 1;
    } else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
}
int Jogador::alteraFortaleza(unsigned int posX, unsigned int posY) {
         un_Fortaleza.setPosY(posY);
         un_Fortaleza.setPosX(posX);
         return 1;
    
}
Mina Jogador::getMinaBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
	 while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if((vetorMina[i].getPosX() == (posX)) && 
		    (vetorMina[i].getPosY() == (posY))) {
				
                return vetorMina[i];  // bem sucedido
            }  // end if
            i++;
        }  
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Mina();
}
Mina Jogador::getVetorMina(int indice) {
    if ( indice >= 0 && indice < 5 )
        return vetorMina[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Mina();
}
Lenhadora Jogador::getLenhadoraBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
	 while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if((vetorLenhadora[i].getPosX() == (posX)) && 
		    (vetorLenhadora[i].getPosY() == (posY))) {
				
                return vetorLenhadora[i];  // bem sucedido
            }  // end if
            i++;
        }  
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Lenhadora();
}
Lenhadora Jogador::getVetorLenhadora(int indice) {
    if ( indice >= 0 && indice < 8 )
        return vetorLenhadora[indice];
    else
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Lenhadora();
}
Fortaleza Jogador::getun_Fortaleza() {
    return un_Fortaleza;
}
   
