/**
* @file main.cpp
* @brief Arquivo com os testes feitos no arquivo contador.cpp e sua respectiva biblioteca. 
*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/personagens.hpp"

TEST_CASE( "Personagens -> metodos get e set", "[personagens.hpp]" ) {
    Personagens p1(zero);
    REQUIRE( p1.setDano(10) == 1 );
    REQUIRE( p1.getDano() == 10 );
    REQUIRE( p1.setVida(150) == 1 );
    REQUIRE( p1.getVida() == 150 );
    REQUIRE( p1.setPosX(1) == 1 );
    REQUIRE( p1.getPosX() == 1 );
    REQUIRE( p1.setPosY(12) == 1 );
    REQUIRE( p1.getPosY() == 12 );
    REQUIRE( p1.setPosX(0) == 1 );
    REQUIRE( p1.getPosX() == 0 );
    REQUIRE( p1.setPosY(0) == 1 );
    REQUIRE( p1.getPosY() == 0);
}

TEST_CASE( "Personagens Construtor - arqueiro", "[personagens.hpp]" ) {
    Personagens p_arq(arqueiro);
    REQUIRE( p_arq.getDano() == 10 );
    REQUIRE( p_arq.getVida() == 150 );
    REQUIRE( p_arq.getPosX() == 0 );
    REQUIRE( p_arq.getPosY() == 0 );
}

TEST_CASE( "Personagens Construtor - guerreiro", "[personagens.hpp]" ) {
    Personagens p_ger(guerreiro);
    REQUIRE( p_ger.getDano() == 10 );
    REQUIRE( p_ger.getVida() == 150 );
    REQUIRE( p_ger.getPosX() == 0 );
    REQUIRE( p_ger.getPosY() == 0 );
}

TEST_CASE( "Personagens Construtor - cavaleiro", "[personagens.hpp]" ) {
    Personagens p_cav(cavaleiro);
    REQUIRE( p_cav.getDano() == 10 );
    REQUIRE( p_cav.getVida() == 150 );
    REQUIRE( p_cav.getPosX() == 0 );
    REQUIRE( p_cav.getPosY() == 0 );
}