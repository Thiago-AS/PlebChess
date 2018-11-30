// Copyright [2018] < Grupo Mp >
#include "../include/engine.hpp"

// Metodos da classe Engine
// se quiserem, pode ser mais modularizado e jogador virar outro modulo

Engine::Engine() {
    setTurno();
    setJogador();
    int i = 0, j = 0;
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
         tabuleirogame[i][j] = TipoUnidade::t_UnidadeVazio;
        }
    }
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
         tabela_time[i][j] = 5;
        }
    }
   for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
         tabela_personagem[i][j] = impossivel;
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

TipoUnidade Engine::getUnidadeTAB(int posX, int posY) {
    if(posX == -1 || posY == -1 ) {
        return TipoUnidade::    t_UnidadeVazio;
    }

  return tabuleirogame[posX][posY];
}
int Engine::setUnidadeTAB(TipoUnidade unit, int posX,
     int posY) {
  if (posX == -1 || posY == -1) {
    return 1;
  }  
  if (posX > LIN_TABULEIRO || posY  > COL_TABULEIRO) {
     printf("%d e %d Posicao invalida\n", posX, posY);
     return 0;
  } else {
     tabuleirogame[posX][posY] = unit;
     return 1;
  }
}

int  Engine::getTabelaTime( int posX, int posY) {
    if(posX == -1 || posY == -1 ) {
        return 5;
    }

  return tabela_time[posX][posY];

}
int Engine::setTabelaTime(int value, int posX, int posY) {
  if (posX == -1 || posY == -1) {
    return 1;
  }  
  if (posX > LIN_TABULEIRO || posY  > COL_TABULEIRO) {
     printf("%d e %d Posicao invalida\n", posX, posY);
     return 0;
  } else {
     tabela_time[posX][posY] = value;
     return 1;
  }

}

int Engine::eh_possivel_inserir(unsigned int posX,  unsigned int posY) {
    if(posX == -1 || posY == -1) {
        return 1;
    }
    if (tabuleirogame[posX][posY] == TipoUnidade::t_UnidadeVazio) {
        return 1;
    } else {
        return 0;
    }
}

void Engine::printTAB() {
    int i, j;
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
         if(tabuleirogame[i][j] == TipoUnidade::t_UnidadeVazio) {
                 printf("-");
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_arqueiro) {
            if(getTabelaTime(i,j) == 1) {
                 printf("A");
            } else {
                printf("a");
            }
                 
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_guerreiro) {
                 if(getTabelaTime(i,j) == 1) {
                 printf("G");
            } else {
                printf("g");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_cavaleiro) {
             if(getTabelaTime(i,j) == 1) {
                 printf("C");
            } else {
                printf("c");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_mina) {
            if(getTabelaTime(i,j) == 1) {
                 printf("M");
            } else {
                printf("m");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_fortaleza) {
                if(getTabelaTime(i,j) == 1) {
                 printf("F");
            } else {
                printf("f");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_lenhadora) {
              if(getTabelaTime(i,j) == 1) {
                 printf("L");
            } else {
                printf("l");
            }
         }
         printf(" ");
        }
        printf("\n");
    }    
}
void Engine::printTABpersonagem() {
    int i, j;
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
          if(tabela_personagem[i][j] == impossivel) {
                printf("X ");
            
         }
         if(tabela_personagem[i][j] == atacar) {
                printf("A ");
            
         }
         if(tabela_personagem[i][j] == movimentar) {
                printf("M ");
            
         }

        }
        printf("\n");
    }
    printf("\n\n\n");    
}
void Engine::printTABverb() {
    int i, j;
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
         if(tabuleirogame[i][j] == TipoUnidade::t_UnidadeVazio) {
                 printf("-");
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_arqueiro) {
            if(getTabelaTime(i,j) == 1) {
                 printf("A");
            } else {
                printf("a");
            }
                 
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_guerreiro) {
                 if(getTabelaTime(i,j) == 1) {
                 printf("G");
            } else {
                printf("g");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_cavaleiro) {
             if(getTabelaTime(i,j) == 1) {
                 printf("C");
            } else {
                printf("c");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_mina) {
            if(getTabelaTime(i,j) == 1) {
                 printf("M");
            } else {
                printf("m");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_fortaleza) {
                if(getTabelaTime(i,j) == 1) {
                 printf("F");
            } else {
                printf("f");
            }
         }
         if(tabuleirogame[i][j] == TipoUnidade::t_lenhadora) {
              if(getTabelaTime(i,j) == 1) {
                 printf("L");
            } else {
                printf("l");
            }
         }
         printf("(%d)[%d,%d] /", tabela_time[i][j],i, j);
         if ((i+j) % 5 == 0) {
            printf("\n");
         }
        }
        printf("\n");
    }    
}
void Engine::printTabelaTime() {
    int i, j;
    for (i = 0; i < LIN_TABULEIRO; i++) {
        for (j = 0; j < COL_TABULEIRO; j++) {
            printf("%d ",tabela_time[i][j] );
        }
        printf("\n");
    }    
}
// metodos da classe JOGADOR

Jogador::Jogador(int times) {
    time = times;
    Engine en;
    inicializaJogador();
    setRecursos(10, 10);
    setTropas(0, 0, 0);
    setConstrucoes(0, 0);
    setGanhoPorTurno();
    setVetorArqueiro(-1,-1, &en);
    setVetorCavaleiro(-1,-1, &en);
    setVetorGuerreiro(-1,-1, &en);
    setVetorMina(-1,-1, &en);
    setVetorLenhadora(-1,-1, &en);
    setFortaleza(-1,-1, &en);
    
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

    ganhoOuro = (minas * 10) + 5;  // quantidade vezes quanto cada da por turno
    ganhoMadeira = (madeireiras * 5) + 5;
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
int Jogador::setVetorArqueiro(int posicaoX, int posicaoY, Engine * engine) {
    int i = 0;
        while ( i < 10 ) {
                vetorArqueiro[i].setAtivo(1);  // ativa o arqueiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o arqueiro */
                if(!engine->eh_possivel_inserir(posicaoX,posicaoY)) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                }
                vetorArqueiro[i].setHumano(1);
                engine->setTabelaTime(vetorArqueiro[i].getHumano(),posicaoX,posicaoY);
                vetorArqueiro[i].setPosX(posicaoX);
                vetorArqueiro[i].setPosY(posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_arqueiro,posicaoX,posicaoY);
            i++;
        }  // end while
        return 1;  // bem sucedido
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
        if ((vetorArqueiro[i].getPosX() == (posX)) &&
            (vetorArqueiro[i].getPosY() == (posY))) {
                return vetorArqueiro[i];  // bem sucedido
            }  // end if
            i++;
        }
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Arqueiro();
}
int Jogador::setVetorGuerreiro(int posicaoX, int posicaoY, Engine * engine) {
    int i = 0;
        while ( i < 10 ) {
                vetorGuerreiro[i].setAtivo(1);  // ativa o guerreiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o guerreiro */
               if(!engine->eh_possivel_inserir(posicaoX,posicaoY)) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                }
                vetorGuerreiro[i].setHumano(1);
                engine->setTabelaTime(vetorGuerreiro[i].getHumano(),posicaoX,posicaoY);
                vetorGuerreiro[i].setPosX(posicaoX);
                vetorGuerreiro[i].setPosY(posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_guerreiro,posicaoX,posicaoY);
            i++;
        }  // end while
        return 1;  // bem sucedido
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
        if ((vetorGuerreiro[i].getPosX() == (posX)) &&
            (vetorGuerreiro[i].getPosY() == (posY))) {
                return vetorGuerreiro[i];  // bem sucedido
            }  // end if
            i++;
        }
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Guerreiro();
}
int Jogador::setVetorCavaleiro(int posicaoX, int posicaoY, Engine * engine) {
    int i = 0;
        while ( i < 10 ) {
                vetorCavaleiro[i].setAtivo(1);  // ativa o cavaleiro
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                if(!engine->eh_possivel_inserir(posicaoX,posicaoY)) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                }
                vetorCavaleiro[i].setHumano(1);
                engine->setTabelaTime(vetorCavaleiro[i].getHumano(),posicaoX,posicaoY);
                vetorCavaleiro[i].setPosX(posicaoX);
                vetorCavaleiro[i].setPosY(posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_cavaleiro,posicaoX,posicaoY);

            i++;
        }  // end while

        return 1;  
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
        if ((vetorCavaleiro[i].getPosX() == (posX)) &&
            (vetorCavaleiro[i].getPosY() == (posY))) {
                return vetorCavaleiro[i];  // bem sucedido
            }  // end if
            i++;
        }
            /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return Cavaleiro();
}

int Jogador::alteraCavaleiro(int indice, unsigned int posX, unsigned int posY, Engine * engine) {
    if ( indice >= 0 && indice < 10 ) {
        if(!engine->eh_possivel_inserir(posX,posY)) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
         }
         engine->setTabelaTime(vetorCavaleiro[indice].getHumano(),posX,posY);
         vetorCavaleiro[indice].setPosY(posY);
         vetorCavaleiro[indice].setPosX(posX);
        engine->setUnidadeTAB(TipoUnidade::t_cavaleiro,posX,posY);
         return 1;
    } else {
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
        }
}
int Jogador::alteraArqueiro(int indice, unsigned int posX, unsigned int posY, Engine * engine) {
    if ( indice >= 0 && indice < 10 ) {
        if(!engine->eh_possivel_inserir(posX,posY)) {
              printf("Eh impossivel inserir - ha elemento\n");
              return 0;
       }
        engine->setTabelaTime(vetorArqueiro[indice].getHumano(), posX, posY);
         vetorArqueiro[indice].setPosY(posY);
         vetorArqueiro[indice].setPosX(posX);
         engine->setUnidadeTAB(TipoUnidade::t_arqueiro,posX,posY);

         return 1;
    } else {
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
        }
}
int Jogador::alteraGuerreiro(int indice, unsigned int posX, unsigned int posY, Engine * engine) {
    if ( indice >= 0 && indice < 10 ) {
            if(!engine->eh_possivel_inserir(posX, posY)) {
                printf("Eh impossivel inserir - ha elemento\n");
                return 0;
           }
        engine->setTabelaTime(vetorGuerreiro[indice].getHumano(),posX,posY);
        vetorGuerreiro[indice].setPosY(posY);
        vetorGuerreiro[indice].setPosX(posX);
        engine->setUnidadeTAB(TipoUnidade::t_guerreiro,posX,posY);

         return 1;
    } else {
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
        }
}

int Jogador::setVetorMina(int posicaoX, int posicaoY, Engine * engine) {
    int i = 0;
        while ( i < 5 ) {
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                if (posicaoX != -1 && posicaoY != -1) {
                if(!((engine->eh_possivel_inserir(posicaoX,posicaoY))
                    &&  (engine->eh_possivel_inserir(posicaoX, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX, posicaoY+1))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY+1)))) {
                    printf("%d  %d\n",posicaoY, posicaoX );
                    return 0;
                } if (!((rest_limiteCol_sup(posicaoY+1)) ||   (rest_limiteLin_sup(posicaoX+1))) ) {
                    return 0; 
                }
                }
                vetorArqueiro[i].setHumano(1);
                if (posicaoX != -1 && posicaoY != -1) {
                engine->setTabelaTime(1,posicaoX,posicaoY);
                engine->setTabelaTime(1,posicaoX+1,posicaoY);
                engine->setTabelaTime(1,posicaoX,posicaoY+1);
                engine->setTabelaTime(1,posicaoX+1,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_mina,posicaoX,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_mina,posicaoX+1,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_mina,posicaoX,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_mina,posicaoX+1,posicaoY+1);
               }
                vetorMina[i].setPosX(posicaoX);
                vetorMina[i].setPosY(posicaoY);
            i++;
        }  // end while
        return 1;
}
int Jogador::setVetorLenhadora(int posicaoX, int posicaoY, Engine * engine) {
    int i = 0;
        while ( i < 8 ) {
                 /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
                if (posicaoX != -1 && posicaoY != -1) {
                if(!((engine->eh_possivel_inserir(posicaoX,posicaoY))
                    &&  (engine->eh_possivel_inserir(posicaoX, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX, posicaoY+1))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY+1)))) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                } if (!((rest_limiteCol_sup(posicaoY+1)) ||   (rest_limiteLin_sup(posicaoX+1))) ) {
                    return 0; 
                }
                }
                vetorLenhadora[i].setHumano(1);
                vetorLenhadora[i].setPosX(posicaoX);
                vetorLenhadora[i].setPosY(posicaoY);
                if( posicaoX != -1 && posicaoY != -1 ) {
                engine->setTabelaTime(1,posicaoX,posicaoY);
                engine->setTabelaTime(1,posicaoX+1,posicaoY);
                engine->setTabelaTime(1,posicaoX,posicaoY+1);
                engine->setTabelaTime(1,posicaoX+1,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+1,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+1,posicaoY+1);
                }

            i++;
        }  // end while
        return 1;  // bem sucedido
}

int Jogador::setFortaleza(int posicaoX, int posicaoY, Engine * engine) {
                /* As posicoes devem ser recebidas da posicao do quartel
                    que construiu o cavaleiro */
            if ( posicaoX != -1 && posicaoY != -1 ) { 
                if(!((engine->eh_possivel_inserir(posicaoX,posicaoY))
                    &&  (engine->eh_possivel_inserir(posicaoX, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX, posicaoY+1))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX+1, posicaoY+1))
                    && (engine->eh_possivel_inserir(posicaoX+2, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX+2, posicaoY+1))
                    && (engine->eh_possivel_inserir(posicaoX+3, posicaoY))
                    && (engine->eh_possivel_inserir(posicaoX+3, posicaoY+1)))) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                } if (  !((rest_limiteCol_sup(posicaoY+3)) ||   (rest_limiteLin_sup(posicaoX+1))) ) {
                    return 0; 
                }
                }
                un_Fortaleza.setPosX(posicaoX);
                un_Fortaleza.setPosY(posicaoY);
                if ( posicaoX != -1 && posicaoY != -1) {                
                engine->setTabelaTime(1,posicaoX,posicaoY);
                engine->setTabelaTime(1,posicaoX+1,posicaoY);
                engine->setTabelaTime(1,posicaoX,posicaoY+1);
                engine->setTabelaTime(1,posicaoX+1,posicaoY+1);
                engine->setTabelaTime(1,posicaoX+2,posicaoY);
                engine->setTabelaTime(1,posicaoX+3,posicaoY);
                engine->setTabelaTime(1,posicaoX+2,posicaoY+1);
                engine->setTabelaTime(1,posicaoX+3,posicaoY+1);   
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+1,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+2,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+3,posicaoY);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+1,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+2,posicaoY+1);
                engine->setUnidadeTAB(TipoUnidade::t_lenhadora,posicaoX+3,posicaoY+1);
                }
                
                return 1;  // bem sucedido
}

int Jogador::alteraMina(int indice, unsigned int posX, unsigned int posY, Engine * engine) {
    if ( indice >= 0 && indice < 5 ) {
        if ( posX != -1 && posY != -1 ) { 
                if(!((engine->eh_possivel_inserir(posX,posY))
                    &&  (engine->eh_possivel_inserir(posX, posY))
                    && (engine->eh_possivel_inserir(posX, posY+1))
                    && (engine->eh_possivel_inserir(posX+1, posY))
                    && (engine->eh_possivel_inserir(posX+1, posY+1)))) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                } if (  !(rest_limiteCol_sup(posY+1)) ||   !(rest_limiteLin_sup(posX+1)) ) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0; 
                }
                }
                vetorMina[indice].setPosY(posY);
                vetorMina[indice].setPosX(posX);
                if( posX != -1 && posY != -1 ) {
                engine->setTabelaTime(1,posX,posY);
                engine->setTabelaTime(1,posX+1,posY);
                engine->setTabelaTime(1,posX,posY+1);
                engine->setTabelaTime(1,posX+1,posY+1);
                engine->setUnidadeTAB(TipoUnidade::t_mina, posX, posY);
                engine->setUnidadeTAB(TipoUnidade::t_mina, posX+1, posY);
                engine->setUnidadeTAB(TipoUnidade::t_mina, posX, posY+1);
                engine->setUnidadeTAB(TipoUnidade::t_mina, posX+1, posY+1);
               }


         return 1;
    } else {
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
    }
}

int Jogador::alteraLenhadora(int indice, unsigned int posX, unsigned int posY, Engine * engine) {
    if ( indice >= 0 && indice < 8 ) {
        if ( posX == -1 || posY == -1 ) { 
          if(!((engine->eh_possivel_inserir(posX,posY))
                    &&  (engine->eh_possivel_inserir(posX, posY))
                    && (engine->eh_possivel_inserir(posX, posY+1))
                    && (engine->eh_possivel_inserir(posX+1, posY))
                    && (engine->eh_possivel_inserir(posX+1, posY+1)))) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                } if (  !(rest_limiteCol_sup(posY+1))  ||  ! (rest_limiteLin_sup(posX+1)) ) {
                    return 0; 
                }
             }
                vetorLenhadora[indice].setPosY(posY);
                vetorLenhadora[indice].setPosX(posX);
                if (posX != -1 && posY != -1 ) {
                engine->setTabelaTime(1,posX,posY);
                engine->setTabelaTime(1,posX+1,posY);
                engine->setTabelaTime(1,posX,posY+1);
                engine->setTabelaTime(1,posX+1,posY+1);
         engine->setUnidadeTAB(TipoUnidade::t_lenhadora, posX, posY);
         engine->setUnidadeTAB(TipoUnidade::t_lenhadora, posX+1, posY);
         engine->setUnidadeTAB(TipoUnidade::t_lenhadora, posX, posY+1);
         engine->setUnidadeTAB(TipoUnidade::t_lenhadora, posX+1, posY+1);
         }
         return 1;
    } else {
    /* Caso o indice seja passado errado, retorna um personagem
     * do tipo zero_p, mas eh quando o metodo eh usado errado */
        return 0;
    }
}
int Jogador::alteraFortaleza(unsigned int posX, unsigned int posY, Engine * engine) {
    if ( posX != -1 && posY != -1 ) { 
               
        if(!((engine->eh_possivel_inserir(posX,posY))
                    &&  (engine->eh_possivel_inserir(posX, posY))
                    && (engine->eh_possivel_inserir(posX, posY+1))
                    && (engine->eh_possivel_inserir(posX+1, posY))
                    && (engine->eh_possivel_inserir(posX+1, posY+1))
                    && (engine->eh_possivel_inserir(posX+2, posY))
                    && (engine->eh_possivel_inserir(posX+2, posY+1))
                    && (engine->eh_possivel_inserir(posX+3, posY))
                    && (engine->eh_possivel_inserir(posX+3, posY+1)))) {
                    printf("Eh impossivel inserir - ha elemento\n");
                    return 0;
                } if (  !(rest_limiteCol_sup(posY+3)) ||  !(rest_limiteLin_sup(posX+1)) ) {
                    return 0; 
        }
       }
        un_Fortaleza.setPosY(posY);
        un_Fortaleza.setPosX(posX);
        if ( posX != -1 && posY != -1 ) { 
        engine->setTabelaTime(1,posX,posY);
        engine->setTabelaTime(1,posX+1,posY);
        engine->setTabelaTime(1,posX,posY+1);
        engine->setTabelaTime(1,posX+1,posY+1);
        engine->setTabelaTime(1,posX+2,posY);
        engine->setTabelaTime(1,posX+3,posY);
        engine->setTabelaTime(1,posX+2,posY+1);
        engine->setTabelaTime(1,posX+3,posY+1);   
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX,posY);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+1,posY);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+2,posY);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+3,posY);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX,posY+1);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+1,posY+1);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+2,posY+1);
        engine->setUnidadeTAB(TipoUnidade::t_fortaleza,posX+3,posY+1);
        }        
         return 1;
}
Mina Jogador::getMinaBypos(unsigned int posX, unsigned int posY) {
     int i = 0;
     while ( i < 10 ) {
        /* As posicoes devem ser recebidas da posicao do quartel
         que construiu o arqueiro */
        if ((vetorMina[i].getPosX() == (posX)) &&
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
        if ((vetorLenhadora[i].getPosX() == (posX)) &&
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
Possibilidade Jogador::verificarPoss(unsigned int posX, unsigned int posY, Engine * engine) {
    if (engine->getUnidadeTAB(posX,posY) == TipoUnidade::t_UnidadeVazio) {
		return p_construir;
	} 
    if (engine->getUnidadeTAB(posX,posY) == TipoUnidade::t_fortaleza 
	|| engine->getUnidadeTAB(posX,posY) == TipoUnidade::t_mina
	|| engine->getUnidadeTAB(posX,posY) == TipoUnidade::t_lenhadora) {
		return p_nada;
	} else {
		return p_personagem;
	}
}

int Jogador::acaoPersonagem(unsigned int posX, unsigned int posY, Engine * engine) {
   
int i, lim_i, j, lim_j;   
if (engine->getUnidadeTAB(posX, posY) == TipoUnidade::t_cavaleiro) {
           if (posX - 3 < 0 ) {
               i = 0;
           } else {
            i = posX - 3;
           } 
           if (posX + 3 >= COL_TABULEIRO) {
            lim_i = COL_TABULEIRO;
           } else {
            lim_i = posX + 3;
           }
           if (posY - 3 < 0 ) {
               j = 0;
           } else {
            j = posY - 3;
           } 
           if (posY + 3 >= LIN_TABULEIRO) {
            lim_j = LIN_TABULEIRO;
           } else {
            lim_j = posY + 3;
           }


for ( i ; i <= lim_i; i++) {
    for (j ; j <= lim_j; j++ ) {
    if (i != posX && j != posY) {
    if (engine->getUnidadeTAB(i,j) == TipoUnidade::t_UnidadeVazio) {
        engine->tabela_personagem[i][j] = movimentar;
    } 
    if ((engine->getUnidadeTAB(i,j) == TipoUnidade::t_fortaleza 
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_mina
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_lenhadora
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_arqueiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_guerreiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade:: t_cavaleiro) && engine->getTabelaTime(i,j) == 0) {
        engine->tabela_personagem[i][j] = atacar;
    } else {
        engine->tabela_personagem[i][j] = impossivel;
    }
    }
    }
 }   
}
if (engine->getUnidadeTAB(posX, posY) == TipoUnidade::t_arqueiro) {
           if (posX - 2 < 0 ) {
               i = 0;
           } else {
            i = posX - 2;
           } 
           if (posX + 2 >= COL_TABULEIRO) {
            lim_i = COL_TABULEIRO;
           } else {
            lim_i = posX + 2;
           }
           if (posY - 2 < 0 ) {
               j = 0;
           } else {
            j = posY - 2;
           } 
           if (posY + 2 >= LIN_TABULEIRO) {
            lim_j = LIN_TABULEIRO;
           } else {
            lim_j = posY + 2;
           }


for ( i ; i <= lim_i; i++) {
    for (j ; j <= lim_j; j++ ) {
    if (i != posX && j != posY) {
    if (engine->getUnidadeTAB(i,j) == TipoUnidade::t_UnidadeVazio) {
        engine->tabela_personagem[i][j] = movimentar;
    } 
    if ((engine->getUnidadeTAB(i,j) == TipoUnidade::t_fortaleza 
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_mina
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_lenhadora
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_arqueiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_guerreiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade:: t_cavaleiro) && engine->getTabelaTime(i,j) == 0) {
        engine->tabela_personagem[i][j] = atacar;
    } else {
        engine->tabela_personagem[i][j] = impossivel;
    }
    }
    }
 }   
}
if (engine->getUnidadeTAB(posX, posY) == TipoUnidade::t_arqueiro) {
           if (posX - 1 < 0 ) {
               i = 0;
           } else {
            i = posX - 1;
           } 
           if (posX + 1 >= COL_TABULEIRO) {
            lim_i = COL_TABULEIRO;
           } else {
            lim_i = posX + 1;
           }
           if (posY - 1 < 0 ) {
               j = 0;
           } else {
            j = posY - 1;
           } 
           if (posY + 1 >= LIN_TABULEIRO) {
            lim_j = LIN_TABULEIRO;
           } else {
            lim_j = posY + 1;
           }


for ( i ; i <= lim_i; i++) {
    for (j ; j <= lim_j; j++ ) {
    if (i != posX && j != posY) {
    if (engine->getUnidadeTAB(i,j) == TipoUnidade::t_UnidadeVazio) {
        engine->tabela_personagem[i][j] = movimentar;
    } 
    if ((engine->getUnidadeTAB(i,j) == TipoUnidade::t_fortaleza 
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_mina
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_lenhadora
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_arqueiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade::t_guerreiro
    || engine->getUnidadeTAB(i,j) == TipoUnidade:: t_cavaleiro) && engine->getTabelaTime(i,j) == 0) {
        engine->tabela_personagem[i][j] = atacar;
    } else {
        engine->tabela_personagem[i][j] = impossivel;
    }
    }
    }
 }


}

return 1;

}