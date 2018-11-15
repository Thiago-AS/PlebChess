
#include "../include/unidades.hpp"

Unidades::Unidades(tipo_unidades unidade){
    if(unidade == fortaleza) {
          setVida(500);
          setRecurso(nada);
          setQt_materia(0);
          setComprimento(4);
          setLargura(2);
          setConstrucao(999999);
          setUnidade(fortaleza);

    } else if(unidade == lenhadora) {
          setVida(100);
          setRecurso(madeira);
          setQt_materia(5);
          setComprimento(2);
          setLargura(2);
          setConstrucao(30);
          setUnidade(lenhadora);          
    } else if(unidade == mina) {
          setVida(200);
          setRecurso(ouro);
          setQt_materia(10);
          setComprimento(2);
          setLargura(2);
          setConstrucao(50);
          setUnidade(mina);
    }

}
Unidades::~Unidades() {

}
int Unidades::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
	vida = p_vida;
    return 1;

}
int Unidades::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
	qt_materia = materia;
    return 1;

}
int Unidades::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
	largura = p_lar;
    return 1;

}
int Unidades::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
	comprimento = p_com;
    return 1;

}
int Unidades::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
	construcao = p_const;
    return 1;

}
int  Unidades::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
	rest_limiteLin_sup(p_posX + getLargura());
	posX = p_posX;
    return 1;
}
int  Unidades::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
	rest_limiteCol_sup(p_posY + getComprimento());
	posY = p_posY;
    return 1;
}
int Unidades::setUnidade(tipo_unidades p_unidade) {
    unidade = p_unidade;
    return 1;
  
}
int Unidades::setRecurso(tipo_recurso p_recurso) {
    recurso = p_recurso;
    return 1;

}
unsigned int Unidades::getVida() {
    return vida;
}
unsigned int Unidades::getLargura() {
    return largura;
}
unsigned int Unidades::getComprimento() {
    return comprimento;
}
unsigned int Unidades::getQt_materia() {
    return qt_materia;
}
unsigned int Unidades::getConstrucao() {
    return construcao;
}
tipo_unidades Unidades::getUnidade() {
    return unidade;
}
tipo_recurso Unidades::getRecurso() {
    return recurso;  
}
unsigned int  Unidades::getPosX() {
    return posX;
}
unsigned int  Unidades::getPosY() {
    return posY;
}

void Unidades::get_status_unidade() {
    if (getUnidade()==zero_u){
        printf("Unidade :: ZERO \n");    
    } else if (getUnidade()==fortaleza){
    	printf("Unidade :: fortaleza \n"); 

    } else if (getUnidade()== mina){
    	printf("UNidade :: MINA \n");
    	
    } else if (getUnidade()== lenhadora){
    	printf("Personagem :: lenhadora \n");
    	
    }
    printf("A unidade tem \nVida: %d Produz: %d\n",getVida(),getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n",getComprimento(),getLargura());
    printf("Para construir precisa :  %d \n",getConstrucao());


}