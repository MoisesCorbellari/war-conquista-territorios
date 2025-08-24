# WAR: Conquista de Territórios
Jogo feito em C inspirado no tabuleiro WAR, permitindo cadastro, exibição e ataque entre territórios. O sistema utiliza **structs**, **vetores**, **alocação dinâmica** e **modularização**.

---

## Descrição
- O jogo permite:
    - Cadastrar até 5 territórios.
    - Definir o nome de cada território.
    - Escolher a cor do exército (ex: Azul, Verde, Vermelho).
    - Informar o número de tropas.
    - Exibir os territórios cadastrados.
    - Realizar ataques entre territórios, com movimentação de tropas e atualização de cores.

---

## Tecnologias
- Linguagem: **C**
- Bibliotecas:
    - `stdio.h`
    - `stdlib.h`
    - `string.h`
    - `time.h`
    - função para limpar o buffer do teclado: `limpar.h`

---

## Estrutura
```plaintext
war-conquista-territorios/
├── src/
│   ├── limpar.h          # Função para limpar buffer de entrada
│   ├── estrutura.h       # Definição da struct Territorio
│   └── territorio.h      # Implementação das funções: cadastrar, exibir, atacar
├── war.c                 # Código principal do jogo
├── war                   # Executável (gerado após compilação)
└── README.md             # Documentação do projeto
```
---

## Saída
```plaintext
----------------------------------------------
    WAR: Conquista de Territórios
----------------------------------------------
--- Cadastrando Território 1 ---
Nome do território: França
Cor do Exército (ex: Azul, Verde): Azul
Número de tropas: 5

--- Cadastrando Território 2 ---
Nome do território: Alemanha
Cor do Exército (ex: Azul, Verde): Vermelho
Número de tropas: 3

===================================
             Tropas atuais
===================================
1. Nome: França (Exército: Azul, Tropas: 5)
2. Nome: Alemanha (Exército: Vermelho, Tropas: 3)

===================================
               ATACAR
===================================
Escolha o território atacante (1 a 5, ou 0 para sair): 1
Escolha o território defensor (1 a 5): 2

Rolando os dados: França (4) vs Alemanha (2)
França atacou com sucesso o território de Alemanha!
Quantas tropas deseja mover para Alemanha? (1 a 4): 2

-> França agora domina Alemanha!
-> Exército: Azul | Tropas no território: 2
-> França tem 3 tropas no território original.

===================================
             Tropas atuais
===================================
1. Nome: França (Exército: Azul, Tropas: 3)
2. Nome: Alemanha (Exército: Azul, Tropas: 2)
.
.
.
```

## Rodando o jogo
1. **Clonar repositório**
    ```bash
    git clone https://github.com/MoisesCorbellari/war-conquista-territorios.git
   ```
2. **Compilar** (caso não tenha o arquivo executável)
    ```bash
    cd war-conquista-territorios/

    gcc war.c -o war
    ```
3. **Executar**
    ```bash
    ./war
    ```