// "Copyright 2018 Grupo MP"
/**
* @file main.cpp
* @brief Arquivo com os testes feitos no arquivo contador.cpp e sua respectiva biblioteca. 
*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/tropas.hpp"
#include "../include/unidades.hpp"
#include "../include/tabuleiro.hpp"
#include "../include/engine.hpp"

TEST_CASE("arqueiro Construtor - arqueiro", "[tropas.hpp]" ) {
    Arqueiro p_arq;
    REQUIRE(p_arq.getDano() == 40);
    REQUIRE(p_arq.getVida() == 100);
    REQUIRE(p_arq.getPosX() == 0);
    REQUIRE(p_arq.getPosY() == 0);
    REQUIRE(p_arq.getQt_turnos() == 2);
    REQUIRE(p_arq.getQt_casas() == 2);
    REQUIRE(p_arq.setHumano(1) == 1);
    REQUIRE(p_arq.getHumano() == 1);
    p_arq.get_status_personagem();
}

TEST_CASE("guerreiro Construtor - guerreiro", "[tropas.hpp]" ) {
    Guerreiro p_ger;
    REQUIRE(p_ger.getDano() == 30);
    REQUIRE(p_ger.getVida() == 150);
    REQUIRE(p_ger.getPosX() == 0);
    REQUIRE(p_ger.getPosY() == 0);
    REQUIRE(p_ger.getQt_turnos() == 1);
    REQUIRE(p_ger.getQt_casas() == 1);
    REQUIRE(p_ger.setHumano(1) == 1);
    REQUIRE(p_ger.getHumano() == 1);
    p_ger.get_status_personagem();
}

TEST_CASE("cavaleiro Construtor - cavaleiro", "[tropas.hpp]" ) {
    Cavaleiro p_cav;
    REQUIRE(p_cav.getDano() == 20);
    REQUIRE(p_cav.getVida() == 250);
    REQUIRE(p_cav.getPosX() == 0);
    REQUIRE(p_cav.getPosY() == 0);
    REQUIRE(p_cav.getQt_turnos() == 2);
    REQUIRE(p_cav.getQt_casas() == 3);
    REQUIRE(p_cav.setHumano(1) == 1);
    REQUIRE(p_cav.getHumano() == 1);
    p_cav.get_status_personagem();
}
TEST_CASE("guerreiro Construtor - Vazio", "[tropas.hpp]" ) {
    Unidade_vazio p_vazio(0, 0);
    REQUIRE(p_vazio.getPosX() == 0);
    REQUIRE(p_vazio.getPosY() == 0);
    Unidade_vazio p_vazio1(10, 12);
    REQUIRE(p_vazio1.getPosX() == 10);
    REQUIRE(p_vazio1.getPosY() == 12);
}
TEST_CASE("Unidade Construtor - fortaleza", "[unidades.hpp]" ) {
    Fortaleza u_for;
    REQUIRE(u_for.getLargura() == 2);
    REQUIRE(u_for.getVida() == 500);
    REQUIRE(u_for.getComprimento() == 4);
    REQUIRE(u_for.getQt_materia() == 0);
    REQUIRE(u_for.getRecurso() == nada);
    REQUIRE(u_for.getConstrucao() == 999999);
    REQUIRE(u_for.setHumano(1) == 1);
    REQUIRE(u_for.getHumano() == 1);
    u_for.get_status_unidade();
}
TEST_CASE("Unidade Construtor - lenhadora", "[unidades.hpp]" ) {
    Lenhadora u_lenha;
    REQUIRE(u_lenha.getLargura() == 2);
    REQUIRE(u_lenha.getVida() == 100);
    REQUIRE(u_lenha.getComprimento() == 2);
    REQUIRE(u_lenha.getQt_materia() == 5);
    REQUIRE(u_lenha.getRecurso() == madeira);
    REQUIRE(u_lenha.getConstrucao() == 30);
    REQUIRE(u_lenha.setHumano(1) == 1);
    REQUIRE(u_lenha.getHumano() == 1);
    u_lenha.get_status_unidade();
}

TEST_CASE("Unidade Construtor - mina de ouro", "[unidades.hpp]" ) {
    Mina u_min;
    REQUIRE(u_min.getLargura() == 2);
    REQUIRE(u_min.getVida() == 200);
    REQUIRE(u_min.getComprimento() == 2);
    REQUIRE(u_min.getQt_materia() == 10);
    REQUIRE(u_min.getRecurso() == ouro);
    REQUIRE(u_min.getConstrucao() == 50);
    REQUIRE(u_min.setHumano(1) == 1);
    REQUIRE(u_min.getHumano() == 1);
    u_min.get_status_unidade();
}
TEST_CASE("Utils", "[utils.hpp]" ) {
    REQUIRE(rest_eh_positivo(2) == 1);
    REQUIRE(rest_eh_positivo(0) == 1);
    REQUIRE(rest_eh_positivo(-2) == 0);
    REQUIRE(rest_limiteCol_sup(12) == 1);
    REQUIRE(rest_limiteCol_sup(200) == 0);
    REQUIRE(rest_limiteLin_sup(12) == 1);
    REQUIRE(rest_limiteLin_sup(200) == 0);
}
TEST_CASE(" quadrado -> metodos get e set", "[quadrado.hpp]" ) {
    Tabuleiro t1;
    t1.print_tabuleiro();
    printf("\n\n\n");
    REQUIRE(t1.insere_fortaleza(12, 0) == 1);
    REQUIRE(t1.qual_unidade(12, 0) == 'F');
    REQUIRE(t1.qual_unidade(12, 1) == 'F');
    REQUIRE(t1.qual_unidade(13, 1) == 'F');
    REQUIRE(t1.qual_unidade(13, 0) == 'F');
    REQUIRE(t1.qual_unidade(14, 1) == 'F');
    REQUIRE(t1.qual_unidade(14, 0) == 'F');
    REQUIRE(t1.qual_unidade(15, 1) == 'F');
    REQUIRE(t1.qual_unidade(15, 0) == 'F');
    REQUIRE(t1.insere_mina(18, 12)  == 1);
    REQUIRE(t1.qual_unidade(18, 12) == 'M');
    REQUIRE(t1.qual_unidade(19, 12) == 'M');
    REQUIRE(t1.qual_unidade(18, 13) == 'M');
    REQUIRE(t1.qual_unidade(19, 13) == 'M');
    REQUIRE(t1.insere_lenhadora(12, 22) == 1);
    REQUIRE(t1.qual_unidade(12, 22) == 'L');
    REQUIRE(t1.qual_unidade(12, 23) == 'L');
    REQUIRE(t1.qual_unidade(13, 22) == 'L');
    REQUIRE(t1.qual_unidade(13, 23) == 'L');
    REQUIRE(t1.insere_guerreiro(13, 13) == 1);
    REQUIRE(t1.qual_unidade(13, 13) == 'G');
    REQUIRE(t1.insere_guerreiro(13, 11) == 1);
    REQUIRE(t1.qual_unidade(13, 11) == 'G');
    REQUIRE(t1.insere_arqueiro(1, 13) == 1);
    REQUIRE(t1.qual_unidade(1, 13) == 'A');
    REQUIRE(t1.insere_cavaleiro(19, 18) == 1);
    REQUIRE(t1.qual_unidade(19, 18) == 'C');
    t1.print_tabuleiro();
}

TEST_CASE("Inicializacao da Engine", "[engine.hpp]" ) {
    Engine En0;  // inicializa uma classe sem parametros
    REQUIRE(En0.getTurno() == 1);
    REQUIRE(En0.getJogador() == 1);
    En0.endTurno();  // encerra um turno para verificar
                    // se serao atualizados os valores
    REQUIRE(En0.getTurno() == 2);
    REQUIRE(En0.getJogador() == 2);
    En0.endTurno();   // verifica se troca o jog nos 2 casos
    REQUIRE(En0.getJogador() == 1);
    REQUIRE(En0.getUnidadeTAB(12, 11) == TipoUnidade::t_UnidadeVazio);
    REQUIRE(En0.setUnidadeTAB(TipoUnidade::t_arqueiro, 13, 13) == 1);
    REQUIRE(En0.getUnidadeTAB(13, 13) == TipoUnidade::t_arqueiro);
}

TEST_CASE("Inicializacao do Jogador", "[engine.hpp]" ) {
    Jogador Jog1(1);  // inicializa no time 1
    int teste;
    teste = Jog1.inicializaJogador();
    REQUIRE(teste == 1);
    REQUIRE(Jog1.getTime() == 1);
    REQUIRE(Jog1.getOuro() == 10);
    REQUIRE(Jog1.getMadeira() == 10);
    REQUIRE(Jog1.getGuerreiros() == 0);
    REQUIRE(Jog1.getArqueiros() == 0);
    REQUIRE(Jog1.getCavaleiros() == 0);
    REQUIRE(Jog1.getMadeireiras() == 0);
    REQUIRE(Jog1.getMinas() == 0);
    REQUIRE(Jog1.getGanhoOuro() == 5);
    REQUIRE(Jog1.getGanhoMadeira() == 5);
}

TEST_CASE("Recursos do Jogador", "[engine.hpp]" ) {
// Caso sejam adicionadas madeireiras e minas
    Jogador Jog1(1);
    Jog1.setConstrucoes(2, 2);
    Jog1.setGanhoPorTurno();  // deve ser chamada para atualizar os valores
    REQUIRE(Jog1.getGanhoOuro() == 25);
    REQUIRE(Jog1.getGanhoMadeira() == 15);
}
TEST_CASE("Vetor de Arqueiros", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Arqueiro P1;
    int i = 0, teste;
    for ( i; i < 10; i++ ) {
        teste = Jog1.setVetorArqueiro(10, 8);
    }
    REQUIRE(teste == 1);  // bem sucedido
    teste = Jog1.setVetorArqueiro(10, 10);
    REQUIRE(teste == 0);
    // ja esta no limite de arqueiros permitidos
    P1 = Jog1.getVetorArqueiro(0);
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    P1 = Jog1.getVetorArqueiro(9);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    REQUIRE(Jog1.alteraArqueiro(3, 17, 16) == 1);
    P1 = Jog1.getVetorArqueiro(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 17);
    REQUIRE(P1.getPosY() == 16);
    P1 = Jog1.getArqueiroBypos(17, 16);
    REQUIRE(P1.getPosX() == 17);
    REQUIRE(P1.getPosY() == 16);
}
TEST_CASE("Vetor de Guerreiros", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Guerreiro P1;
    int i = 0, teste;
    for ( i; i < 10; i++ ) {
        teste = Jog1.setVetorGuerreiro(10, 8);
    }
    REQUIRE(teste == 1);  // bem sucedido
    teste = Jog1.setVetorGuerreiro(10, 10);
    REQUIRE(teste == 0);
    // ja esta no limite de guerreiros permitidos
    P1 = Jog1.getVetorGuerreiro(0);
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    P1 = Jog1.getVetorGuerreiro(9);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    REQUIRE(Jog1.alteraGuerreiro(3, 1, 11) == 1);
    P1 = Jog1.getVetorGuerreiro(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
    P1 = Jog1.getGuerreiroBypos(1, 11);
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
}
TEST_CASE("Vetor de Cavaleiros", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Cavaleiro P1;
    int i = 0, teste;
    for ( i; i < 10; i++ ) {
        teste = Jog1.setVetorCavaleiro(10, 8);
    }
    REQUIRE(teste == 1);  // bem sucedido
    teste = Jog1.setVetorCavaleiro(10, 10);
    REQUIRE(teste == 0);
    // ja esta no limite de cavaleiros permitidos
    P1 = Jog1.getVetorCavaleiro(0);
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    P1 = Jog1.getVetorCavaleiro(9);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(P1.getAtivo() == 1);
    REQUIRE(Jog1.alteraCavaleiro(3, 12, 11) == 1);
    P1 = Jog1.getVetorCavaleiro(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 12);
    REQUIRE(P1.getPosY() == 11);
    P1 = Jog1.getCavaleiroBypos(12, 11);
    REQUIRE(P1.getPosX() == 12);
    REQUIRE(P1.getPosY() == 11);
}
TEST_CASE("Vetor Mina", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Mina P1;
    int i = 0, teste;
    for ( i; i < 5; i++ ) {
        teste = Jog1.setVetorMina(10, 8);
    }
    REQUIRE(teste == 1);  // bem sucedido
    // ja esta no limite de guerreiros permitidos
    P1 = Jog1.getVetorMina(0);
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    P1 = Jog1.getVetorMina(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(Jog1.alteraMina(3, 1, 11) == 1);
    P1 = Jog1.getVetorMina(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
    P1 = Jog1.getMinaBypos(1, 11);
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
}
TEST_CASE("Vetor de Lenha", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Lenhadora P1;
    int i = 0, teste;
    for ( i; i < 8; i++ ) {
        teste = Jog1.setVetorLenhadora(10, 8);
    }
    REQUIRE(teste == 1);  // bem sucedido
    // ja esta no limite de guerreiros permitidos
    P1 = Jog1.getVetorLenhadora(0);
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    P1 = Jog1.getVetorLenhadora(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 10);
    REQUIRE(P1.getPosY() == 8);
    REQUIRE(Jog1.alteraLenhadora(3, 1, 11) == 1);
    P1 = Jog1.getVetorLenhadora(3);
    // testes para o ultimo elemento do vetor
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
    P1 = Jog1.getLenhadoraBypos(1, 11);
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 11);
}
TEST_CASE("Vetor de Fortaleza", "[engine.hpp]" ) {
    Jogador Jog1(1);
    Fortaleza P1, P2;
    // ja esta no limite de guerreiros permitidos
    Jog1.setFortaleza(1, 1);
    P1 = Jog1.getun_Fortaleza();
    // testes para o primeiro elemento do vetor
    REQUIRE(P1.getPosX() == 1);
    REQUIRE(P1.getPosY() == 1);
    P1 = Jog1.getun_Fortaleza();
    REQUIRE(Jog1.alteraFortaleza(3, 1) == 1);
    P2 = Jog1.getun_Fortaleza();
    // testes para o ultimo elemento do vetor
    REQUIRE(P2.getPosX() == 3);
    REQUIRE(P2.getPosY() == 1);
}
