// ================================================================
// Desafio: Nível Novato - parte 1
// 
// Objetivo: 
//  -> Construir uma base de dados de territórios utilizando uma estrutura de dados composta.
//  -> Criar uma struct chamada Territorio que armazenará informações como nome, cor do exército e quantidade de tropas. 
//  -> O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.
//
// ================================================================

#include <string.h> //função para manipular string
#include "src/limpar.h" //aplicando modularização para função limparBuffer

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

int main(){
    Territorio territorios[QTD_TERRITORIOS];
    int batalhao = 0;
    int opcao;
    
    do{
        printf("----------------------------------------------\n");
        printf("    WAR: Conquista de Territórios - parte 1\n");
        printf("----------------------------------------------\n");
        printf("1 - Cadastrar território\n");
        printf("2 - Listar territórios\n");
        printf("0 - Sair\n");
        printf("----------------------------------------------\n");
        printf("Digite a opção: ");

        // Lê a opção escolhida
        scanf("%d", &opcao);
        limparBuffer();

        // Processamento da opção
        switch(opcao){
            case 1:
                if (batalhao >= QTD_TERRITORIOS){
                    printf("\nTodas as tropas já foram registradas");
                }else{
                    for (int i = batalhao; i < QTD_TERRITORIOS; i++){
                        printf("\n--- Cadastrando Território %d ---\n", i+1);

                        printf("Nome do território: ");
                        fgets(territorios[batalhao].nome, TAM_STRING, stdin);

                        printf("Cor do Exército (ex: Azul, Verde): ");
                        fgets(territorios[batalhao].cor, TAM_COR, stdin);

                        territorios[batalhao].nome[strcspn(territorios[batalhao].nome, "\n")] = '\0';
                        territorios[batalhao].cor[strcspn(territorios[batalhao].cor, "\n")] = '\0';

                        printf("Número de tropas: ");
                        scanf("\n%d", &territorios[batalhao].tropas);
                        limparBuffer();

                        batalhao++;
                    }

                    printf("\n      Tropas cadastradas com sucesso!      \n");
                }
                break;

            case 2:
                printf("\n        Lista dos Territórios    \n");
                if (batalhao == 0){
                    printf("Nenhuma tropa cadastrada!\n");
                } else{
                    for (int i = 0; i < batalhao; i++){
                        printf("Território %d\n"
                                    "- Nome: %s | Dominado pelo exército: %s | Tropas: %d\n\n", 
                            i+1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
                    }
                }
                break;

            case 0:
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                printf("\nPara continuar, pressione ENTER!");
                getchar();
                break;
        };
    } while (opcao!=0);
    
    return 0;
}