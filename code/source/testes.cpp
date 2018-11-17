/**
* @file main.cpp
* @brief Arquivo com os testes feitos no arquivo contador.cpp e sua respectiva biblioteca. 
*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/arqueiro.hpp"
#include "../include/guerreiro.hpp"
#include "../include/cavaleiro.hpp"
#include "../include/quadrado.hpp"
#include "../include/fortaleza.hpp"
#include "../include/mina.hpp"
#include "../include/lenhadora.hpp"
#include "../include/tabuleiro.hpp"
TEST_CASE( "arqueiro Construtor - arqueiro", "[arqueiro.hpp]" ) {
    Arqueiro p_arq;
    REQUIRE( p_arq.getDano() == 40 );
    REQUIRE( p_arq.getVida() == 100 );
    REQUIRE( p_arq.getPosX() == 0 );
    REQUIRE( p_arq.getPosY() == 0 );
    REQUIRE( p_arq.getQt_turnos() == 2 );
    REQUIRE( p_arq.getQt_casas() == 2 );
    p_arq.get_status_personagem();
}

TEST_CASE( "guerreiro Construtor - guerreiro", "[guerreiro.hpp]" ) {
    Guerreiro p_ger;
    REQUIRE( p_ger.getDano() == 30 );
    REQUIRE( p_ger.getVida() == 150 );
    REQUIRE( p_ger.getPosX() == 0 );
    REQUIRE( p_ger.getPosY() == 0 );
    REQUIRE( p_ger.getQt_turnos() == 1 );
    REQUIRE( p_ger.getQt_casas() == 1 );
    p_ger.get_status_personagem();
}

TEST_CASE( "cavaleiro Construtor - cavaleiro", "[cavaleiro.hpp]" ) {
    Cavaleiro p_cav;
    REQUIRE( p_cav.getDano() == 20 );
    REQUIRE( p_cav.getVida() == 250 );
    REQUIRE( p_cav.getPosX() == 0 );
    REQUIRE( p_cav.getPosY() == 0 );
    REQUIRE( p_cav.getQt_turnos() == 2 );
    REQUIRE( p_cav.getQt_casas() == 3 );
    p_cav.get_status_personagem();
}
TEST_CASE( "Unidade Construtor - fortaleza", "[fortaleza.hpp]" ) {
    Fortaleza u_for;
    REQUIRE( u_for.getLargura() == 2);
    REQUIRE( u_for.getVida() == 500 );
    REQUIRE( u_for.getComprimento() == 4 );
    REQUIRE( u_for.getQt_materia() == 0 );
    REQUIRE( u_for.getRecurso() == nada3 );
    REQUIRE( u_for.getConstrucao() == 999999 );
   u_for.get_status_unidade();
}

TEST_CASE( "Unidade Construtor - lenhadora", "[lenhadora.hpp]" ) {
    Lenhadora u_lenha;
    REQUIRE( u_lenha.getLargura() == 2 );
    REQUIRE( u_lenha.getVida() == 100 );
    REQUIRE( u_lenha.getComprimento() == 2 );
    REQUIRE( u_lenha.getQt_materia() == 5 );
    REQUIRE( u_lenha.getRecurso() == madeira2 );
    REQUIRE( u_lenha.getConstrucao() == 30 );
    u_lenha.get_status_unidade();
}

TEST_CASE( "Unidade Construtor - mina de ouro", "[mina.hpp]" ) {
    Mina u_min;
    REQUIRE( u_min.getLargura() == 2 );
    REQUIRE( u_min.getVida() == 200 );
    REQUIRE( u_min.getComprimento() == 2 );
    REQUIRE( u_min.getQt_materia() == 10 );
    REQUIRE( u_min.getRecurso() == ouro );
    REQUIRE( u_min.getConstrucao() == 50 );
    u_min.get_status_unidade();

}

TEST_CASE( "Utils", "[utils.hpp]" ) {
    REQUIRE( rest_eh_positivo(2) == 1 );
    REQUIRE( rest_eh_positivo(0) == 1 );
    REQUIRE( rest_eh_positivo(-2) == 0 );
    REQUIRE( rest_limiteCol_sup(12) == 1);
    REQUIRE( rest_limiteCol_sup(200) == 0);
    REQUIRE( rest_limiteLin_sup(12) == 1);
    REQUIRE( rest_limiteLin_sup(200) == 0);
    
}

TEST_CASE( " quadrado -> metodos get e set", "[quadrado.hpp]" ) {
    Quadrado q1;
    Tabuleiro t1;
    REQUIRE( q1.setPosX(1) == 1 );
    REQUIRE( q1.getPosX() == 1 );
    REQUIRE( q1.setPosY(12) == 1 );
    REQUIRE( q1.getPosY() == 12 );
    REQUIRE( q1.setPosX(0) == 1 );
    REQUIRE( q1.getPosX() == 0 );
    REQUIRE( q1.setPosY(0) == 1 );
    REQUIRE( q1.getPosY() == 0);
    REQUIRE( q1.setHumano(false) == 1 );
    REQUIRE( q1.setUsado(false) == 1);
    REQUIRE( q1.getHumano() == false );
    REQUIRE( q1.getUsado() == false);
    t1.print_tabuleiro();
    printf("\n\n\n");
    t1.insere_fortaleza(12,0);
    t1.insere_mina(18,12);
    t1.insere_lenhadora(12,22);
    t1.insere_guerreiro(13,13);
    t1.insere_guerreiro(13,11);
    t1.insere_arqueiro(1,13);
    t1.insere_cavaleiro(19,18);
    t1.print_tabuleiro();
}
