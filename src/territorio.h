#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrutura.h"


//função para cadastro
void cadastrarTerritorio(Territorio *t, int i){
    printf("Nome do território: ");
    fgets(t->nome, TAM_STRING, stdin);

    printf("Cor do Exército (ex: Azul, Verde): ");
    fgets(t->cor, TAM_COR, stdin);

    t->nome[strcspn(t->nome, "\n")] = '\0';
    t->cor[strcspn(t->cor, "\n")] = '\0';

    printf("Número de tropas: ");
    scanf("\n%d", &t->tropas);
    getchar();
}

//função para exibir os territórios
void exibirTerritorio(Territorio *mapa, int n){
    for (int batalhao = 0; batalhao < n; batalhao++){
        printf("%d. Nome: %s (Exército: %s, Tropas: %d)\n",
            batalhao+1, mapa[batalhao].nome, mapa[batalhao].cor, mapa[batalhao].tropas);
    }

}

// função de ataque
void ataqueTerritorio(Territorio *atacante, Territorio *defensor){
    int maxMover = atacante->tropas - 1; // deve deixar pelo menos 1 tropa
    // verifica se o atacante tem tropas suficientes
    if (atacante->tropas <= 0){
        printf("\n%s não tem tropas para o ataque!\n", atacante->nome);
        return;
    }
    
    // simulação dos dados
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;
    
    printf("\nRolando os dados: %s (%d) vs %s (%d)\n", 
        atacante->nome, dadoAtacante, defensor->nome, dadoDefensor
    );
    
    if (dadoAtacante > dadoDefensor){
        // ataque bem-sucedido
        printf("\n%s atacou com sucesso o território de %s!\n", atacante->nome, defensor->nome);
        
        // muda o dono do território
        strcpy(defensor->cor, atacante->cor);
        
        int mover;
        if (maxMover < 1) {
            printf("%s não tem tropas suficientes para atacar.\n", atacante->nome);
            return;
}
        
        do {
            printf("Quantas tropas deseja mover para %s? (1 a %d): ", defensor->nome, maxMover);
            scanf("%d", &mover);
            limparBuffer();
            if (mover < 1 || mover > maxMover) {
                printf("Valor inválido! Deve ser entre 1 e %d.\n", maxMover);
            }
        } while (mover < 1 || mover > maxMover);
        
        defensor->tropas = mover;
        atacante->tropas -= mover;
        
        // exibe informações completas do território conquistado
        printf("\n-> %s agora domina %s!\n", atacante->nome, defensor->nome);
        printf("-> Exército: %s | Tropas no território: %d\n", defensor->cor, defensor->tropas);
        printf("-> %s tem %d tropas no território original.\n", atacante->nome, atacante->tropas);

    } else if(dadoAtacante == dadoDefensor){ // caso haja empate
        printf("\nEmpate! Nenhum território foi conquistado.\n");
    } else{ // caso o ataque falhe
        atacante->tropas--;
        printf("\n%s defendeu com sucesso!\n", defensor->nome);
        printf("%s perdeu uma tropa e agora tem %d tropas.\n", atacante->nome, atacante->tropas);
    }
}
