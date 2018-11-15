#include "../include/utils.hpp"
int rest_eh_positivo(int ind) {
    if(ind >= 0) {
    	return 1;
    } else {
    	return 0;
		printf("Valor invalido\n\n");
		exit(0);
    }
}
int rest_limiteCol_sup(int ind) {
    if(ind < COL_TABULEIRO) {
		return 1;
	} else {
		return 0;
		printf("Valor invalido\n\n");
		exit(0);
	}	 
}
int rest_limiteLin_sup(int ind) {
    if(ind < LIN_TABULEIRO) {
		return 1;
	} else {
		return 0;
		printf("Valor invalido\n\n");
		exit(0);
	}	 
}