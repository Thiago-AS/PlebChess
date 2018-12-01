// "Copyright 2018 Grupo MP"
/**
* @file engine.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar a game engine 
*/
#ifndef CODE_INCLUDE_ENGINE_HPP_
#define CODE_INCLUDE_ENGINE_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "../include/tropas.hpp"
#include "../include/unidades.hpp"
using namespace std;
/**
 * @brief Enum que indica as possibilidades de cada quadrado do mapa. 
 */
enum Possibilidade {
    p_nada,
    p_construir,
    p_personagem
};
/**
 * @brief Enum que indica acoes do personagem. 
 */
enum Acao {
    movimentar,
    atacar,
    impossivel
};
/**
 * @brief Enumeracao da Classe tipo de unidades que o jogo pode ter.
 * Descricao: Contem todas as unidades que pode estar presente em um quadrado do mapa.
 */
enum class TipoUnidade{
    t_UnidadeVazio,
    t_fortaleza,
    t_lenhadora,
    t_mina,
    t_arqueiro,
    t_cavaleiro,
    t_guerreiro,
    };

class Engine {
 private:
        unsigned int turnoAtual;
        unsigned int jogadorAtual;

 public:
        // construtor e destrutor
        Engine();
        ~Engine();
        TipoUnidade tabuleirogame[LIN_TABULEIRO][COL_TABULEIRO];
        int tabela_time[LIN_TABULEIRO][COL_TABULEIRO];
        Acao tabela_personagem[LIN_TABULEIRO][COL_TABULEIRO];
        // getters and setters
        /**
        * @fn TipoUnidade setTurno();
        * @brief Seta o turno inicial como 1.
        * @return Retorna 1 
        * Hipoteses: Nao há
        * Requesitos: Metodo deve retornar 1
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida: Retornar 1 indicando sucesso
        */
        int setTurno();  // seta o turno inicial como 1
        /**
        * @fn TipoUnidade endTurno();
        * @brief acaba o turno do jogador, e incrementa o turno atual.
        * @return Retorna 1 
        * Hipoteses: Nao há
        * Requesitos: Metodo deve retornar 1
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida: Retornar 1 indicando sucesso
        */
        int endTurno();  // acaba o turno do jogador, e incrementa o turno atual
        /**
        * @fn TipoUnidade setJogador();
        * @brief O jogador 1 (humano) inicia.
        * @return Retorna 1 
        * Hipoteses: Nao há
        * Requesitos: Metodo deve retornar 1
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida: Retornar 1 indicando sucesso
        */
        int setJogador();  // por default, o jogador 1 inicia o jogo
         /**
        * @fn TipoUnidade getJogador();
        * @brief Retornar o jogador que esta jogando.
        * @return Retorna 1 - humano, 0 - PC 
        * Hipoteses: Nao há
        * Requesitos: Metodo deve retornar 1 ou 0
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida:  Retorna 1 - humano, 0 - PC 
        */
        int getJogador();
         /**
        * @fn TipoUnidade getTurno();
        * @brief Retornar o turno atual.
        * @return Retorna turno atual 
        * Hipoteses: Nao há
        * Requesitos: Metodo deve retornar o turno
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Nao ha
        * Assertiva Saida:  Retorna um int 
        */
        int getTurno();
        /**
        * @fn TipoUnidade getUnidadeTAB(int posX, int posY);
        * @brief Retorna TipoUnidade referente ao objeto Quadrado.
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna nome do objeto
        * Hipoteses: Deve ser passado valores de posX e posY valido ou -1.
        * Requesitos: posX e posY valores do tabuleiro
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabuleirogame
        * Assertiva Saida: devolve o valor de nome do objeto
        */
        TipoUnidade getUnidadeTAB(int posX, int posY);
        /**
        * @fn int setUnidadeTAB(TipoUnidade, int, int );
        * @brief Dado uma posicao X e Y insere tipoUnidade.
        * @param unit tipo de unidade a ser inserida
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna nome do objeto
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro
        * Assertiva Entrada:  0 < posX < COL_LIM && 0 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabuleirogame
        * Assertiva Saida: devolve o valor de nome do objeto
        */
        int setUnidadeTAB(TipoUnidade unit, int posX, int posY);
        /**
        * @fn int eh_possivel_inserir(unsigned int posX,  unsigned posY);
        * @brief Retorna 1 se for possivel inserir e insere 'VAZIO' em 
        * posX e posY.
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna 1 se for possivel inserir na tabela
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro
        * Assertiva Entrada:  0 < posX < COL_LIM && 0 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabuleirogame
        * Assertiva Saida: 1 se possivel inserir
        */
        int eh_possivel_inserir(unsigned int posX,  unsigned posY);
        /**
        * @fn int getTabelaTime(int posX, int posY);
        * @brief Retorna 1 (humano), 0(PC) e 5(vazio) 
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna 1 se for possivel inserir na tabela
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro ou -1
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabela_time
        * Assertiva Saida: Int indicando a situacao
        */
        int  getTabelaTime(int posX, int posY);
        /**
        * @fn Acao getTabelaP(int posX,int posY);
        * @brief dado a posicao de um personagem verifica se eh possivel
        * atacar, movimentar ou fazer nada 
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna 1 se for possivel inserir na tabela
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro ou -1
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabela_personagem
        * Assertiva Saida: Enum indicando acoes do personagem
        */
        Acao getTabelaP(int posX, int posY);
        /**
        * @fn int setTabelaP(Acao, int posX, int posY);
        * @brief  Seta uma acao em uma determinada posicao
        * @param value eh uma acao do personagem
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna 1 se for possivel inserir na tabela
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro ou -1
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabela_personagem
        * Assertiva Saida: 1 se deu certo, tabela tem novo valor inserido
        */        
        int setTabelaP(Acao, int posX, int posY);
        /**
        * @fn int setTabelaTime(int value, int posX, int posY);
        * @brief  Seta um int em uma determinada posicao
        * @param value -> 5 - vazio, 1 humano e 0 pc
        * @param posX equivale a posicao X
        * @param posY equivale a posicao Y
        * @return Retorna 1 se for possivel inserir na tabela
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro ou -1
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabela_personagem
        * Assertiva Saida: 1 se deu certo e tabela inserida
        */ 
        int setTabelaTime(int value, int posX, int posY);
        /**
        * @fn int zeraTABpersonagem();
        * @brief  Seta um int em uma determinada posicao
        * Hipoteses: Deve ser passado valores de posX e posY valido.
        * Requesitos: posX e posY valores do tabuleiro ou -1
        * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
        *    Interface explicita: Nao ha
        *    Interface implicita: tabela_time
        * Assertiva Saida: tabela zerada
        */ 
        void zeraTABpersonagem();
        /**
        * @fn int printTAB();
        * @brief  printa tabuleirogame
        */
        void printTAB();
        /**
        * @fn int printTABpersonagem();
        * @brief  printa tabela tabela_personagem
        */
        void printTABpersonagem();
        /**
        * @fn int printTAB();
        * @brief  printa tabuleirogame + info de time
        */
        void printTABverb();
        /**
        * @fn int printTabelaTime();
        * @brief  printa tabela_time
        */
        void printTabelaTime();
};
class Jogador {
 private:
    unsigned int time;  // representa qual time o jog eh
    // quantidade de recursos atuais
    unsigned int ouro;
    unsigned int madeira;
    // quantidade de tropas atuais
    unsigned int guerreiros;
    unsigned int arqueiros;
    unsigned int cavaleiros;
    // quantidade de construcoes atuais
    unsigned int minas;
    unsigned int madeireiras;
    // quantidade de unidades vazias
    unsigned int uni_vazias = LIN_TABULEIRO * COL_TABULEIRO;
    // ganho de recursos por turno
    unsigned int ganhoOuro;
    unsigned int ganhoMadeira;
    // vetores de tropas
    Arqueiro vetorArqueiro[10];
    Guerreiro vetorGuerreiro[10];
    Cavaleiro vetorCavaleiro[10];
    Mina vetorMina[5];
    Lenhadora vetorLenhadora[8];
    Fortaleza un_Fortaleza;


 public:
    // construtor e destrutor
    explicit Jogador(int times);
    ~Jogador();
    // metodos SET
    /**
        * @fn int setRecursos(int , int );
        * @brief  Seta os recursos madeira e ouro
        * @param ouro1 -> quantidade de ouro
        * @param madeira1 -> quantidade de madeira
        * @return Retorna 1 se OK
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ouro, madeira
        * Assertiva Saida: 1 se deu certo
        */ 
    int setRecursos(int, int);
    /**
        * @fn int setTropas(int , int , int);
        * @brief  Seta as tropas
        * @param guerr -> quantidade de guerreiro
        * @param arq -> quantidade de arqueiro
        * @param cav -> quantidade de cavaleiros
        * @return Retorna 1 se OK
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: guerreiro, arqueiros, cavaleiros
        * Assertiva Saida: 1 se deu certo
        */
    int setTropas(int, int, int);
    /**
        * @fn int setConstrucoes(int , int );
        * @brief  Seta de unidades mina e lenhadora
        * @param mina -> quantidade de mina
        * @param madereira -> quantidade de madereiras
        * @return Retorna 1 se OK
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ouro, madeira
        * Assertiva Saida: 1 se deu certo
        */ 
     int setConstrucoes(int, int);
    /**
        * @fn int setGanhoPorTurno();
        * @brief  Seta quantidade de recurso madeira e ouro ganho por turno
        * @return Retorna 1 se OK
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ganhoOuro, ganhoMadeira
        * Assertiva Saida: 1 se deu certo
        */      
    int setGanhoPorTurno();
    /**
    * @fn int setVetorArqueiro(int, int, Engine * engine, bool);
    * @brief  Cria um vetor de arqueiros nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorArqueiro
    * Assertiva Saida: 1 se deu certo e vetor inserido
    */
    int setVetorArqueiro(int, int, Engine * engine, bool);
    /**
    * @fn int setVetorGuerreiro(int, int, Engine * engine, bool);
    * @brief  Cria um vetor de guerreiros nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorGuerreiro
    * Assertiva Saida: 1 se deu certo e vetor inserido
    */
    int setVetorGuerreiro(int, int, Engine * engine, bool);
    /**
    * @fn int setVetorCavaleiro(int, int, Engine * engine, bool);
    * @brief  Cria um vetor de cavaleiros nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorCavaleiro
    * Assertiva Saida: 1 se deu certo e vetor inserido
    */
    int setVetorCavaleiro(int, int, Engine * engine, bool);
    /**
    * @fn int setVetorMina(int, int, Engine * engine, bool);
    * @brief  Cria um vetor de minas nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorMina
    * Assertiva Saida: 1 se deu certo e vetor inserido
    */
    int setVetorMina(int, int, Engine * engine, bool);
    /**
    * @fn int setVetorLenhadora(int, int, Engine * engine, bool);
    * @brief  Cria um vetor de lenhadora nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorLenhadora
    * Assertiva Saida: 1 se deu certo e vetor inserido
    */
    int setVetorLenhadora(int, int, Engine * engine, bool);
        /**
    * @fn int setFortaleza(int, int, Engine * engine, bool);
    * @brief  Cria um objeto fortaleza nas posicoes indicada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @param times indica o time em getHumano(times)
    * @return Retorna 1 se for possivel inserir na tabela
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: un_Fortaleza
    * Assertiva Saida: 1 se deu certo e objeto preenchido
    */
    int setFortaleza(int, int, Engine * engine, bool);
    /**
        * @fn int inicializaJogador();
        * @brief  Seta quantidades de tudo para jogador
        * @return Retorna 1 se OK
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: arqueiros, guerreiros, cavaleiros,
        * minas, madeireiras
        * Assertiva Saida: 1 se deu certo
        */
    int inicializaJogador();
    // metodos GET
        /**
        * @fn int getTime();
        * @brief  Retornar o time do jogador humano ou PC
        * @return Retorna o time
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: time
        * Assertiva Saida: 1 se humano, 0 pc
        */
    int getTime();
            /**
        * @fn int getTime();
        * @brief  Retornar o ouro do jogador humano
        * @return Retorna o ouro
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ouro
        * Assertiva Saida: Quantidade de ouro
        */
    int getOuro();
        /**
        * @fn int getMadeira();
        * @brief  Retornar a madeira do jogador
        * @return Retorna a madeira
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: madeira
        * Assertiva Saida: Quantidade de madeira
        */
    int getMadeira();
        /**
        * @fn int getGuerreiros();
        * @brief  Retornar quantidade de guerreiros do jogador
        * @return Retorna o guerreiros
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: guerreiros
        * Assertiva Saida: Quantidade de guerreiros
        */
    int getGuerreiros();
        /**
        * @fn int getArqueiros();
        * @brief  Retornar quantidade de arqueiros do jogador
        * @return Retorna o arqueiros
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: arqueiros
        * Assertiva Saida: Quantidade de arqueiros
        */
    int getArqueiros();
        /**
        * @fn int getCavaleiros();
        * @brief  Retornar quantidade de Cavaleiros do jogador
        * @return Retorna o Cavaleiros
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Cavaleiros
        * Assertiva Saida: Quantidade de Cavaleiros
        */
    int getCavaleiros();
       /**
        * @fn int getMinas();
        * @brief  Retornar quantidade de Minas do jogador
        * @return Retorna o Minas
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Minas
        * Assertiva Saida: Quantidade de Minas
        */    
    int getMinas();
       /**
        * @fn int getMadereira();
        * @brief  Retornar quantidade de Madereira do jogador
        * @return Retorna o Madereira
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: Madereiras
        * Assertiva Saida: Quantidade de Madereira
        */
    int getMadeireiras();
     /**
        * @fn int getganhoOuro();
        * @brief  Retornar quantidade de ganhoOuro
        * @return Retorna o ganhoOuro
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ganhoOuro
        * Assertiva Saida: Quantidade de ganhoOuro
        */
    int getGanhoOuro();
    /**
        * @fn int getganhoMadeira();
        * @brief  Retornar quantidade de ganhoMadeira
        * @return Retorna o ganhoMadeira
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: ganhoMadeira
        * Assertiva Saida: Quantidade de ganhoMadeira
        */
    int getGanhoMadeira();
        /**
    * @fn    Arqueiro getVetorArqueiro(int indice);
    * @brief  Dados um indice  recuperar objeto do indice.
    * @param Indice deve ser um int valido para tal vetor
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valor valido para o vetor.
    * Requesitos: deve ser um int valido para tal vetor
    * Assertiva Entrada:   0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorArqueiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Arqueiro getVetorArqueiro(int);
    /**
    * @fn    Arqueiro getArqueiroBypos(unsigned int posX, unsigned int posY);
    * @brief  Dados as posicoes procura arqueiro o indice no vetor de arqueiro
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorArqueiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Arqueiro getArqueiroBypos(unsigned int posX, unsigned int posY);
    /**
    * @fn    int alteraArqueiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta o arqueiro do indice nas posicoes passada
    * @param Indice deve ser um int valido para tal vetor
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    && 0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorArqueiro
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraArqueiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    /**
    * @fn    Guerreiro getVetorGuerreiro(int indice);
    * @brief  Dados um indice  recuperar objeto do indice.
    * @param Indice deve ser um int valido para tal vetor
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valor valido para o vetor.
    * Requesitos: deve ser um int valido para tal vetor
    * Assertiva Entrada:   0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorGuerreiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Guerreiro getVetorGuerreiro(int);
    /**
    * @fn    Guerreiro getGuerreiroBypos(unsigned int posX, unsigned int posY);
    * @brief  Dados as posicoes procura Guerreiro o indice no vetor de arqueiro
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorGuerreiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Guerreiro getGuerreiroBypos(unsigned int posX, unsigned int posY);
      /**
    * @fn    int alteraGuerreiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta o guerreiro do indice nas posicoes passada
    * @param Indice deve ser um int valido para tal vetor
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    && 0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorGuerreiro
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraGuerreiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    /**
    * @fn    Cavaleiro getVetorCavaleiro(int indice);
    * @brief  Dados um indice  recuperar objeto do indice.
    * @param Indice deve ser um int valido para tal vetor
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valor valido para o vetor.
    * Requesitos: deve ser um int valido para tal vetor
    * Assertiva Entrada:   0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorCavaleiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Cavaleiro getVetorCavaleiro(int);
    /**
    * @fn    Cavaleiro getCavaleiroBypos(unsigned int posX, unsigned int posY);
    * @brief  Dados as posicoes procura Cavaleiro o indice no vetor de arqueiro
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorCavaleiro
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Cavaleiro getCavaleiroBypos(unsigned int posX, unsigned int posY);
    /**
    * @fn    int alteraCavaleiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta o cavaleiro do indice nas posicoes passada
    * @param Indice deve ser um int valido para tal vetor
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    && 0 < indice < 10
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorCavaleiro
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraCavaleiro(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    /**
    * @fn    Mina getVetorMina(int indice);
    * @brief  Dados um indice  recuperar objeto do indice.
    * @param Indice deve ser um int valido para tal vetor
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valor valido para o vetor.
    * Requesitos: deve ser um int valido para tal vetor
    * Assertiva Entrada:   0 < indice < 5
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorMina
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Mina getVetorMina(int);
    /**
    * @fn    Mina getMinaBypos(unsigned int posX, unsigned int posY);
    * @brief  Dados as posicoes procura Mina o indice no vetor de arqueiro
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorMina
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Mina getMinaBypos(unsigned int posX, unsigned int posY);
        /**
    * @fn    int alteraMina(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta a mina do indice nas posicoes passada
    * @param Indice deve ser um int valido para tal vetor
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    && 0 < indice < 5
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorMina
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraMina(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    /**
    * @fn    Lenhadora getVetorLenhadora(int indice);
    * @brief  Dados um indice  recuperar objeto do indice.
    * @param Indice deve ser um int valido para tal vetor
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valor valido para o vetor.
    * Requesitos: deve ser um int valido para tal vetor
    * Assertiva Entrada:   0 < indice < 8
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorLenhadora
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Lenhadora getVetorLenhadora(int);
    /**
    * @fn    Lenhadora getLenhadoraBypos(unsigned int posX, unsigned int posY);
    * @brief  Dados as posicoes procura Lenhadora o indice no vetor de arqueiro
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna objeto correto ou um personagem zero_p
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorLenhadora
    * Assertiva Saida: Objeto correto ou zero_p
    */
    Lenhadora getLenhadoraBypos(unsigned int posX, unsigned int posY);
   /**
    * @fn    int alteraLenhadora(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta a lenhadora do indice nas posicoes passada
    * @param Indice deve ser um int valido para tal vetor
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    && 0 < indice < 8
    *    Interface explicita: Nao ha
    *    Interface implicita: vetorLenhadora
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraLenhadora(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
        /**
        * @fn int Fortaleza getun_Fortaleza();
        * @brief  Retorna a fortaleza
        * @return Retorna o objeto fortaleza
        * Hipoteses: Nao ha.
        * Requesitos: Nao ha
        * Assertiva Entrada:  Nao ha
        *    Interface explicita: Nao ha
        *    Interface implicita: un_Fortaleza
        * Assertiva Saida: Objeto correto ou zero_p
        */
    Fortaleza getun_Fortaleza();
        /**
    * @fn    int alteraFortaleza(int indice, unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief Seta a fortaleza nas posicoes passada
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @return Retorna 1 sucesso
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: un_Fortaleza
    * Assertiva Saida: Retorna 1 sucesso
    */
    int alteraFortaleza(unsigned int posX, unsigned int posY, Engine * engine);
    // metodos de jogo
/**
    * @fn     Possibilidade verificarPoss(unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief  Dada uma posicao verifica suas possibilidades de acoes
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @return Enum Possibilidade - personagem, construir, vazio
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: Nao ha
    * Assertiva Saida: retornar valor do enum possibilidade
    */
    Possibilidade verificarPoss(unsigned int posX, unsigned int posY,
        Engine * engine);
   /**
    * @fn     Acao acaoPersonagem(unsigned int posX, unsigned int posY,
        Engine * engine);
    * @brief  Dada uma posicao verifica suas possibilidades
    de acoes do personagem
    * @param posX equivale a posicao X
    * @param posY equivale a posicao Y
    * @param engine para linkar com o objeto engine
    * @return Enum Acao - movimentar, atacar, impossivel
    * Hipoteses: Deve ser passado valores de posX e posY valido.
    * Requesitos: posX e posY valores do tabuleiro ou -1
    * Assertiva Entrada:  -1 < posX < COL_LIM && -1 <posY < LIN_LIM
    *    Interface explicita: Nao ha
    *    Interface implicita: Nao ha
    * Assertiva Saida: retornar valor do enum possibilidade
    */
    Acao acaoPersonagem(unsigned int posX, unsigned int posY, Engine * engine);
    int EscolherAcaoPos(unsigned int posX, unsigned int posY, Engine * engine);
};  // jogador
#endif  // CODE_INCLUDE_ENGINE_HPP_
