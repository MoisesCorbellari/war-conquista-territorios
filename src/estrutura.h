#ifndef TERRITORIO_H
#define TERRITORIO_H

// Constante global
#define TAM_STRING 30
#define TAM_COR 10
#define QTD_TERRITORIOS 5

// Usando structs para definir estrutura
typedef struct{
    char nome[TAM_STRING];
    char cor[TAM_COR];
    int tropas;
}Territorio;

#endif