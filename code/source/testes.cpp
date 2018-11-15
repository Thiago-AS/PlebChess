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
    REQUIRE( p1.setVida(1500) == 1 );
    REQUIRE( p1.getVida() == 1500 );
    REQUIRE( p1.setPosX(1) == 1 );
    REQUIRE( p1.getPosX() == 1 );
    REQUIRE( p1.setPosY(12) == 1 );
    REQUIRE( p1.getPosY() == 12 );
    REQUIRE( p1.setPosX(0) == 1 );
    REQUIRE( p1.getPosX() == 0 );
    REQUIRE( p1.setPosY(0) == 1 );
    REQUIRE( p1.getPosY() == 0);
    REQUIRE( p1.setQt_turnos(10) == 1 );
    REQUIRE( p1.getQt_turnos() == 10 );
    REQUIRE( p1.setQt_casas(5) == 1 );
    REQUIRE( p1.getQt_casas() == 5 );
    REQUIRE(p1.setPersonagem(zero) == 1);
    REQUIRE( p1.getPersonagem() == 0);
    p1.get_status_personagem();
}

TEST_CASE( "Personagens Construtor - arqueiro", "[personagens.hpp]" ) {
    Personagens p_arq(arqueiro);
    REQUIRE( p_arq.getDano() == 40 );
    REQUIRE( p_arq.getVida() == 100 );
    REQUIRE( p_arq.getPosX() == 0 );
    REQUIRE( p_arq.getPosY() == 0 );
    REQUIRE( p_arq.getQt_turnos() == 2 );
    REQUIRE( p_arq.getQt_casas() == 2 );
    REQUIRE( p_arq.getPersonagem() == 1);
    p_arq.get_status_personagem();
}

TEST_CASE( "Personagens Construtor - guerreiro", "[personagens.hpp]" ) {
    Personagens p_ger(guerreiro);
    REQUIRE( p_ger.getDano() == 30 );
    REQUIRE( p_ger.getVida() == 150 );
    REQUIRE( p_ger.getPosX() == 0 );
    REQUIRE( p_ger.getPosY() == 0 );
    REQUIRE( p_ger.getQt_turnos() == 1 );
    REQUIRE( p_ger.getQt_casas() == 1 );
    REQUIRE( p_ger.getPersonagem() == 2);
    p_ger.get_status_personagem();
}

TEST_CASE( "Personagens Construtor - cavaleiro", "[personagens.hpp]" ) {
    Personagens p_cav(cavaleiro);
    REQUIRE( p_cav.getDano() == 20 );
    REQUIRE( p_cav.getVida() == 250 );
    REQUIRE( p_cav.getPosX() == 0 );
    REQUIRE( p_cav.getPosY() == 0 );
    REQUIRE( p_cav.getQt_turnos() == 2 );
    REQUIRE( p_cav.getQt_casas() == 3 );
    REQUIRE( p_cav.getPersonagem() == 3);
    p_cav.get_status_personagem();
}

TEST_CASE( "unidades -> metodos get e set", "[personagens.hpp]" ) {
    unidades u1(zero);
    REQUIRE( u1.setQt_materia(3) == 1 );
    REQUIRE( u1.getQt_materia() == 3 );
    REQUIRE( u1.setVida(3100) == 1 );
    REQUIRE( u1.getVida() == 3100 );
    REQUIRE( u1.setLargura(20) == 1 );
    REQUIRE( u1.getLargura() == 20 );
    REQUIRE( u1.setComprimento(12) == 1 );
    REQUIRE( u1.getComprimento() == 12 );
    REQUIRE( u1.setUnidade(zero) == 1 );
    REQUIRE( u1.getUnidade() == zero );
    REQUIRE( u1.setRecurso(nada) == 1 );
    REQUIRE( u1.getQt_Recurso() == nada);
   
}

TEST_CASE( "Unidade Construtor - fortaleza", "[unidades.hpp]" ) {
    unidades u_for(fortaleza);
    REQUIRE( u_for.getLargura() == 40 );
    REQUIRE( u_for.getVida() == 100 );
    REQUIRE( u_for.getComprimento() == 0 );
    REQUIRE( u_for.getQt_materia() == 0 );
    REQUIRE( u_for.getQt_Unidade() == 2 );
    REQUIRE( u_for.getQt_Recurso() == 2 );
   
}

TEST_CASE( "Unidade Construtor - lenhadora", "[unidades.hpp]" ) {
    unidades u_lenha(fortaleza);
    REQUIRE( u_lenha.getLargura() == 40 );
    REQUIRE( u_lenha.getVida() == 100 );
    REQUIRE( u_lenha.getComprimento() == 0 );
    REQUIRE( u_lenha.getQt_materia() == 0 );
    REQUIRE( u_lenha.getQt_Unidade() == 2 );
    REQUIRE( u_lenha.getQt_Recurso() == 2 );
}

TEST_CASE( "Unidade Construtor - mina de ouro", "[unidades.hpp]" ) {
    unidades u_min(fortaleza);
    REQUIRE( u_min.getLargura() == 40 );
    REQUIRE( u_min.getVida() == 100 );
    REQUIRE( u_min.getComprimento() == 0 );
    REQUIRE( u_min.getQt_materia() == 0 );
    REQUIRE( u_min.getQt_Unidade() == 2 );
    REQUIRE( u_min.getQt_Recurso() == 2 );

}