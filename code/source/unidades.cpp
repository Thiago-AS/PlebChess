// "Copyright 2018 Grupo MP"
#include "../include/unidades.hpp"
Mina::Mina() {
          setVida(200);
          setRecurso(ouro);
          setQt_materia(10);
          setComprimento(2);
          setLargura(2);
          setConstrucao(50);
		  setPosX(0);
		  setPosY(0);
		  }
Mina::~Mina() {}
int Mina::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
    vida = p_vida;
    return 1;
}
int Mina::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
    qt_materia = materia;
    return 1;
}
int Mina::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
    largura = p_lar;
    return 1;
}
int Mina::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
    comprimento = p_com;
    return 1;
}
int Mina::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
    construcao = p_const;
    return 1;
}
int  Mina::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
    rest_limiteLin_sup(p_posX + getLargura());
    posX = p_posX;
    return 1;}
int  Mina::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
    rest_limiteCol_sup(p_posY + getComprimento());
    posY = p_posY;
    return 1;}
int Mina::setRecurso(tipo_recurso p_recurso) {
    recurso = p_recurso;
    return 1;
}
unsigned int Mina::getVida() {
    return vida;
    }
unsigned int Mina::getLargura() {
    return largura;
    }
unsigned int Mina::getComprimento() {
    return comprimento;
    }
unsigned int Mina::getQt_materia() {
    return qt_materia;
    }
unsigned int Mina::getConstrucao() {
    return construcao;
    }
tipo_recurso Mina::getRecurso() {
    return recurso;
    }
unsigned int  Mina::getPosX() {
    return posX;
    }
unsigned int  Mina::getPosY() {
    return posY;
    }

void Mina::get_status_unidade() {
       printf("UNidade :: MINA \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
}
Lenhadora::Lenhadora() {
          setVida(100);
          setRecurso(madeira);
          setQt_materia(5);
          setComprimento(2);
          setLargura(2);
          setConstrucao(30);
		  setPosX(0);
		  setPosY(0);
        }
Lenhadora::~Lenhadora() {}
int Lenhadora::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
  }
int Lenhadora::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
  qt_materia = materia;
    return 1;
}
int Lenhadora::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
  largura = p_lar;
    return 1;
}
int Lenhadora::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
  comprimento = p_com;
    return 1;
}
int Lenhadora::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
  construcao = p_const;
    return 1;
}
int  Lenhadora::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX + getLargura());
  posX = p_posX;
    return 1;}
int  Lenhadora::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY + getComprimento());
  posY = p_posY;
    return 1;}
int Lenhadora::setRecurso(tipo_recurso p_recurso) {
    recurso = p_recurso;
    return 1;
}
unsigned int Lenhadora::getVida() {
    return vida;
  }
unsigned int Lenhadora::getLargura() {
    return largura;
  }
unsigned int Lenhadora::getComprimento() {
    return comprimento;
  }
unsigned int Lenhadora::getQt_materia() {
    return qt_materia;
  }
unsigned int Lenhadora::getConstrucao() {
    return construcao;
  }
tipo_recurso Lenhadora::getRecurso() {
    return recurso;
  }
unsigned int  Lenhadora::getPosX() {
    return posX;
  }
unsigned int  Lenhadora::getPosY() {
    return posY;
  }

void Lenhadora::get_status_unidade() {
    printf("UNidade :: Lenhadora \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
}
Fortaleza::Fortaleza() {
         setVida(500);
          setRecurso(nada);
          setQt_materia(0);
          setComprimento(4);
          setLargura(2);
          setConstrucao(999999);
	  setPosX(0);
	  setPosY(0);
}
Fortaleza::~Fortaleza() {}
int Fortaleza::setVida(unsigned int p_vida) {
    rest_eh_positivo(p_vida);
  vida = p_vida;
    return 1;
}
int Fortaleza::setQt_materia(unsigned int materia) {
    rest_eh_positivo(materia);
  qt_materia = materia;
    return 1;
}
int Fortaleza::setLargura(unsigned int p_lar) {
    rest_eh_positivo(p_lar);
  largura = p_lar;
    return 1;
}
int Fortaleza::setComprimento(unsigned int p_com) {
    rest_eh_positivo(p_com);
  comprimento = p_com;
    return 1;
}
int Fortaleza::setConstrucao(unsigned int p_const) {
    rest_eh_positivo(p_const);
  construcao = p_const;
    return 1;}
int  Fortaleza::setPosX(unsigned int p_posX) {
    rest_eh_positivo(p_posX);
  rest_limiteLin_sup(p_posX + getLargura());
  posX = p_posX;
    return 1;}
int  Fortaleza::setPosY(unsigned int p_posY) {
    rest_eh_positivo(p_posY);
  rest_limiteCol_sup(p_posY + getComprimento());
  posY = p_posY;
    return 1;}
int Fortaleza::setRecurso(tipo_recurso p_recurso) {
    recurso = p_recurso;
    return 1;
    }
unsigned int Fortaleza::getVida() {
    return vida;
    }
unsigned int Fortaleza::getLargura() {
    return largura;
    }
unsigned int Fortaleza::getComprimento() {
    return comprimento;
    }
unsigned int Fortaleza::getQt_materia() {
    return qt_materia;
    }
unsigned int Fortaleza::getConstrucao() {
    return construcao;
    }
tipo_recurso Fortaleza::getRecurso() {
    return recurso;
    }
unsigned int  Fortaleza::getPosX() {
    return posX;
    }
unsigned int  Fortaleza::getPosY() {
    return posY;
    }

void Fortaleza::get_status_unidade() {
    printf("UNidade :: Fortaleza \n");
    printf("A unidade tem \nVida: %d Produz: %d\n", getVida(), getQt_materia());
    printf("Tem: Comprimento:%d Largura:%d\n", getComprimento(), getLargura());
    printf("Para construir precisa :  %d \n", getConstrucao());
  }
