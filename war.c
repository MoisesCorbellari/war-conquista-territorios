// ================================================================
// Desafio: Nível Novato - parte 1
// 
// Objetivo: 
//  -> Implementar a funcionalidade de ataque entre territórios.
//  -> Permitir que um jogador selecione um território como atacante, e outro como defensor. 
//  -> O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.
//
// ================================================================

#include <stdio.h> // entrada e saída de dados
#include <stdlib.h> // inclui funções como malloc, free e etc.
#include <string.h> //função para manipular string
#include <time.h> // função relacionado ao tempo 
#include "src/limpar.h" //aplicando modularização para função limparBuffer
#include "src/territorio.h" //modularizando funções de cadastro, exibição e ataque
#include "src/estrutura.h"

int main(){
    srand(time(NULL)); // inicializa gerador de números aleatórios

    int qtdTerritorio=QTD_TERRITORIOS;
    int atacante = -1, defensor;

    //alocação dinâmica de memória
    Territorio *territorios = (Territorio *)calloc(qtdTerritorio, sizeof(Territorio));
    if (territorios == NULL){
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    //Cadastro de territórios
    printf("----------------------------------------------\n");
    printf("        WAR: Conquista de Territórios        \n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < qtdTerritorio; i++){
        printf("\n--- Cadastrando Território %d ---\n", i+1);
        cadastrarTerritorio(&territorios[i], i);
    }

    //exibir territórios
    printf("\n===================================\n");
    printf("             Tropas atuais             ");
    printf("\n===================================\n");
    exibirTerritorio(territorios, qtdTerritorio);

    //ataque territórios
    while(1){
        printf("\n===================================\n");
        printf("               ATACAR                  ");
        printf("\n===================================\n");
        printf("Escolha o território atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &atacante);
        limparBuffer();

    if(atacante == 0){
        printf("Saindo do jogo ...\n");
        break; //sai do jogo
    } else{
        printf("Escolha o território defensor (1 a 5): ");
        scanf("%d", &defensor);
        limparBuffer();
    }if (defensor < 1 || defensor > qtdTerritorio || defensor == atacante){
        printf("Opção inválida!\n");
        continue; //volta ao loop
    }

    int idxAtacante = atacante - 1;
    int idxDefensor = defensor - 1;

    //faz o ataque
    ataqueTerritorio(&territorios[idxAtacante], &territorios[idxDefensor]);

    //territorios atualizados
    exibirTerritorio(territorios, qtdTerritorio);
}
    
    //libera memória alocada
    free(territorios);
    printf("\nMemória liberada\n");

    return 0;
}