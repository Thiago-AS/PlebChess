/**
* @file main.cpp
* @brief Arquivo com os testes feitos no arquivo contador.cpp e sua respectiva biblioteca. 
*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/personagens.hpp"

TEST_CASE( "Personagens -> metodos get e set", "[personagens.hpp]" ) {
    Personagens p1;
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



