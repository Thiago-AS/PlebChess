// "Copyright 2018 Grupo MP"
#include "../include/utils.hpp"
int rest_eh_positivo(int ind) {
    //  o valor -1 sera usado como local dos objetos nao usados.
    if (ind >= -1) {
        return 1;
    } else {
        printf("Valor invalido\n\n");
        return 0;
    }
}
int rest_limiteCol_sup(int ind) {
    if (ind < COL_TABULEIRO) {
        return 1;
    } else {
        printf("Valor invalido\n\n");
        return 0;
    }
}
int rest_limiteLin_sup(int ind) {
    if (ind < LIN_TABULEIRO) {
        return 1;
    } else {
        printf("Valor invalido\n\n");
        return 0;
    }
}
