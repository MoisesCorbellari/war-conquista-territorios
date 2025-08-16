# WAR: Conquista de Territórios
Jogo feito em **C** para cadastro e exibição de territórios, inspirado no jogo de tabuleiro **WAR**.
O desafio utiliza **structs**, **vetores** e um menu interativo para cadastrar até **5 Territórios**, registrando **nome do território**, **cor do exército** e **número de tropas**.

---

## Descrição
- O jogo permite:
    - Cadastrar até **5 territórios**.
    - Definir o **nome** de cada território.
    - Escolher a **cor do exército** (ex: Azul, Verde e etc.).
    - Informar o **número de tropas**.
    - Listar os terrtórios cadastrados.

---

## Tecnologias
- Linguagem: **C**
- Bibliotecas:
    - `stdio.h`
    - `string`
    - função para limpar o buffer do teclado: `limpar.h`

---
## Estrutura
```plaintext
Desafio/
├── src/
│ └── limpar.h # Função para limpar o buffer de entrada
├── war #arquivo executável
├── war.c # código principal do jogo
└── README.md # documentação do projeto
```
---
## Saída
```plaintext
----------------------------------------------
    WAR: Conquista de Territórios - parte 1
----------------------------------------------
1 - Cadastrar território
2 - Listar territórios
0 - Sair
----------------------------------------------
Digite a opção:

--- Cadastrando Território 1 ---
Nome do território: França
Cor do Exército (ex: Azul, Verde): Azul
Número de tropas: 5

Tropas cadastradas com sucesso!

--- Lista de Territórios ---
1) Nome: França | Dominado pelo exército: Azul | Tropas: 5
```