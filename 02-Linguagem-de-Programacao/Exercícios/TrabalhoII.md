# SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL

## UNIDADE DOIS VIZINHOS/PR

**NOME:** _______________________________________________

**TÉCNICO DE ENSINO:** Kevin de Souza Guimarães

**UNIDADE CURRICULAR:** Lógica de Programação

**CURSO:** Programador de Sistemas

---

# TRABALHO PRÁTICO

# RPG DE TEXTO 1.0 – A JORNADA DO HERÓI

---

## LEIA ATENTAMENTE ANTES DE INICIAR

* Leia todo o enunciado antes de começar a programar.
* O trabalho deverá ser desenvolvido individualmente.
* O programa deverá ser implementado exclusivamente em linguagem C.
* É obrigatório o uso de funções para modularização do código.
* O programa deverá permanecer em execução até que o usuário escolha a opção de sair.
* Utilize nomes de variáveis e funções que facilitem a leitura do código.
* O código deverá estar devidamente indentado e organizado.
* Trabalhos que não compilarem receberão desconto na nota.
* É proibido copiar códigos de colegas.
* Todas as funcionalidades descritas neste documento deverão ser implementadas.

---

# OBJETIVO

Desenvolver um jogo de RPG em modo texto capaz de controlar um personagem que deverá explorar um mundo repleto de monstros, tesouros e desafios.

Durante a aventura o jogador deverá:

* Criar seu personagem;
* Explorar o mapa;
* Encontrar monstros;
* Coletar ouro;
* Comprar equipamentos;
* Utilizar itens;
* Evoluir de nível;
* Sobreviver às batalhas;
* Derrotar o chefe final.

O projeto deverá aplicar todos os conteúdos estudados até o momento.

---

# CONTEÚDOS AVALIADOS

O trabalho deverá demonstrar domínio dos seguintes conteúdos:

* Variáveis
* Operadores
* if
* if/else
* else if
* switch/case
* while
* do/while
* for
* Funções
* Vetores
* Modularização
* Entrada e saída de dados

---

# HISTÓRIA DO JOGO

O reino de **C-Nai** está sendo atacado por criaturas sombrias.

Você é um aventureiro escolhido para derrotar o terrível **Dragão das Sombras**, uma criatura poderosa que ameaça destruir todo o reino.

Para conseguir derrotá-lo será necessário:

* Explorar regiões perigosas;
* Enfrentar monstros;
* Ganhar experiência;
* Coletar ouro;
* Comprar equipamentos;
* Evoluir seu personagem.

Somente os aventureiros mais fortes serão capazes de derrotar o dragão.

---

# MENU PRINCIPAL

O sistema deverá apresentar o seguinte menu:

```text
=================================================
          RPG DE TEXTO - A JORNADA DO HERÓI
=================================================

1 - Criar Personagem
2 - Ver Status
3 - Explorar Mapa
4 - Loja
5 - Inventário
6 - Descansar
7 - Enfrentar Chefe Final
0 - Sair

Escolha:
```

Após executar qualquer operação o programa deverá retornar ao menu principal.

---

# ATRIBUTOS DO PERSONAGEM

O jogador deverá possuir os seguintes atributos:

```c
char nome[50];

int vida;
int vidaMaxima;

int ataque;
int defesa;

int nivel;
int experiencia;

int ouro;
```

Valores iniciais sugeridos:

```text
Vida = 100
Vida Máxima = 100

Ataque = 10
Defesa = 5

Nível = 1
Experiência = 0

Ouro = 50
```

---

# INVENTÁRIO

O inventário deverá utilizar um vetor.

Exemplo:

```c
int inventario[20];
```

O vetor deverá armazenar os itens comprados ou encontrados durante a aventura.

---

# FUNCIONALIDADE 1 – CRIAR PERSONAGEM

Ao selecionar esta opção o sistema deverá:

1. Solicitar o nome do personagem.
2. Inicializar todos os atributos.
3. Exibir mensagem de sucesso.

Exemplo:

```text
Digite o nome do herói:
Mr. Ninja

Personagem criado com sucesso!
```

---

# FUNCIONALIDADE 2 – VER STATUS

Exibir:

* Nome
* Vida Atual
* Vida Máxima
* Ataque
* Defesa
* Nível
* Experiência
* Ouro

Exemplo:

```text
Nome: Mr. Ninja

Vida: 100/100
Ataque: 10
Defesa: 5

Nível: 1
Experiência: 0

Ouro: 50
```

---

# FUNCIONALIDADE 3 – EXPLORAR MAPA

Ao explorar o mapa o sistema deverá gerar eventos aleatórios.

Utilizar:

```c
rand()
```

Eventos possíveis:

| Número | Evento            |
| ------ | ----------------- |
| 1      | Encontrou Monstro |
| 2      | Encontrou Tesouro |
| 3      | Encontrou Poção   |
| 4      | Armadilha         |
| 5      | Nada aconteceu    |

---

## TESOURO

Ao encontrar um tesouro:

```text
+ Ouro
```

Exemplo:

```text
Você encontrou um baú!

+30 moedas de ouro
```

---

## POÇÃO

Ao encontrar uma poção:

```text
Poção Pequena
ou
Poção Grande
```

A poção deverá ser adicionada ao inventário.

---

## ARMADILHA

Ao cair em uma armadilha:

```text
Vida -= dano
```

Exemplo:

```text
Você caiu em uma armadilha!

Perdeu 15 pontos de vida.
```

---

# SISTEMA DE MONSTROS

Criar obrigatoriamente os seguintes monstros:

| Monstro   | Vida | Ataque |
| --------- | ---: | -----: |
| Goblin    |   30 |      5 |
| Esqueleto |   50 |      8 |
| Orc       |   80 |     12 |
| Lobisomem |  120 |     15 |
| Dragão    |  300 |     25 |

Os valores podem ser alterados caso o aluno deseje balancear melhor o jogo.

---

# FUNCIONALIDADE 4 – COMBATE

Durante o combate apresentar:

```text
1 - Atacar
2 - Defender
3 - Fugir
```

O combate deverá continuar até que:

* O jogador morra; ou
* O monstro morra.

---

## OPÇÃO 1 – ATACAR

Ao atacar:

```c
dano = ataqueJogador;
```

O dano deverá ser descontado da vida do monstro.

---

## OPÇÃO 2 – DEFENDER

Ao defender:

```c
danoRecebido = danoMonstro / 2;
```

O jogador receberá menos dano no próximo ataque.

---

## OPÇÃO 3 – FUGIR

O jogador poderá tentar fugir.

Sugestão:

```text
50% de chance de sucesso
```

Caso falhe, o monstro realiza um ataque.

---

# RECOMPENSAS

Ao derrotar um monstro:

```text
+ experiência
+ ouro
```

Exemplo:

```text
Goblin derrotado!

+20 XP
+15 Ouro
```

---

# SISTEMA DE EXPERIÊNCIA

Sempre que:

```text
Experiência >= 100
```

Executar:

```text
Nível +1

Ataque +5
Defesa +3

Vida Máxima +20

Restaurar Vida
```

Exemplo:

```text
Parabéns!

Você subiu para o nível 2.
```

---

# FUNCIONALIDADE 5 – LOJA

Itens obrigatórios:

| Item          | Preço |
| ------------- | ----: |
| Poção Pequena |    20 |
| Poção Grande  |    40 |
| Espada        |   100 |
| Armadura      |   120 |
| Escudo        |    80 |

---

## REGRAS DA LOJA

O sistema deverá:

* Mostrar os itens disponíveis.
* Permitir comprar itens.
* Verificar se existe ouro suficiente.
* Descontar o valor do item.
* Adicionar o item ao inventário.

Exemplo:

```text
Você comprou uma Espada.

Ouro restante: 150
```

---

# FUNCIONALIDADE 6 – INVENTÁRIO

O inventário deverá permitir:

```text
1 - Visualizar Itens
2 - Usar Item
3 - Descartar Item
0 - Voltar
```

---

## USAR ITEM

Exemplos:

### Poção Pequena

```text
Recupera 20 de vida
```

### Poção Grande

```text
Recupera 50 de vida
```

### Espada

```text
Ataque +5
```

### Armadura

```text
Defesa +5
```

### Escudo

```text
Defesa +3
```

---

# FUNCIONALIDADE 7 – DESCANSAR

Ao descansar:

```text
Recuperar 30 pontos de vida
```

A vida nunca poderá ultrapassar a vida máxima.

Exemplo:

```text
Vida atual: 70

Após descansar:

Vida atual: 100
```

---

# FUNCIONALIDADE 8 – CHEFE FINAL

O chefe final será o Dragão das Sombras.

O jogador somente poderá enfrentá-lo caso:

```text
Nível >= 5
```

Caso contrário:

```text
Você ainda não está preparado para enfrentar o Dragão.
```

---

# PSEUDOCÓDIGO GERAL

```text
INÍCIO

Criar Variáveis

FAÇA

    Mostrar Menu

    Ler Opção

    ESCOLHA

        Caso 1
            Criar Personagem

        Caso 2
            Mostrar Status

        Caso 3
            Explorar Mapa

        Caso 4
            Loja

        Caso 5
            Inventário

        Caso 6
            Descansar

        Caso 7
            Chefe Final

    FIM ESCOLHA

ENQUANTO Opção != 0

FIM
```

---

# PSEUDOCÓDIGO DA EXPLORAÇÃO

```text
FUNÇÃO explorarMapa

    Gerar número aleatório

    SE evento == 1

        Encontrar Monstro

    SENÃO SE evento == 2

        Encontrar Tesouro

    SENÃO SE evento == 3

        Encontrar Poção

    SENÃO SE evento == 4

        Armadilha

    SENÃO

        Nada acontece

FIM FUNÇÃO
```

---

# PSEUDOCÓDIGO DO COMBATE

```text
FUNÇÃO combate

    ENQUANTO

        Jogador Vivo

        E

        Monstro Vivo

            Mostrar Menu de Combate

            Ler Opção

            SE Atacar

                Causar Dano

            SE Defender

                Reduzir Dano

            SE Fugir

                Tentar Fuga

            Monstro Ataca

    FIM ENQUANTO

    SE Monstro Morreu

        Dar Recompensas

    SE Jogador Morreu

        Exibir Game Over

FIM FUNÇÃO
```

---

# PSEUDOCÓDIGO DE SUBIR NÍVEL

```text
FUNÇÃO subirNivel

    SE experiencia >= 100

        nivel++

        ataque += 5

        defesa += 3

        vidaMaxima += 20

        vida = vidaMaxima

        experiencia = 0

    FIM SE

FIM FUNÇÃO
```

---

# FUNÇÕES OBRIGATÓRIAS

Cada funcionalidade deverá possuir uma função própria.

Exemplo:

```c
void criarPersonagem();
void mostrarStatus();

void explorarMapa();

void combate();

void subirNivel();

void loja();

void inventario();

void descansar();

void chefeFinal();
```

---

# REQUISITOS OBRIGATÓRIOS

* Utilizar funções.
* Utilizar pelo menos um vetor.
* Utilizar switch/case no menu principal.
* Utilizar estruturas de repetição.
* Utilizar números aleatórios.
* Implementar sistema de combate.
* Implementar sistema de experiência.
* Implementar sistema de loja.
* Implementar sistema de inventário.
* Implementar chefe final.

---

# DESAFIOS EXTRAS (BÔNUS)

Cada item implementado corretamente poderá valer até **+0,5 ponto extra**.

* Sistema de Save.
* Sistema de Load.
* Novos Monstros.
* Classes (Guerreiro, Arqueiro e Mago).
* Sistema de Missões.
* Sistema de Chefes Secundários.
* Sistema de Ranking.
* Sistema de Conquistas.

---

# CRITÉRIOS DE AVALIAÇÃO

| Critério                    | Pontos |
| --------------------------- | -----: |
| Menu Principal              |    1,0 |
| Funções                     |    1,5 |
| Exploração                  |    1,5 |
| Sistema de Combate          |    2,0 |
| Loja                        |    1,0 |
| Inventário                  |    1,0 |
| Progressão de Nível         |    1,0 |
| Organização e Modularização |    1,0 |

**Total: 10,0 pontos**

---

# ENTREGA

O aluno deverá entregar:

* Arquivo `.c`
* Código compilando sem erros
* Código comentado
* Código organizado e identado

---

# BOA SORTE, AVENTUREIRO!

O destino do reino de **C-Nai** está em suas mãos. Derrote o Dragão das Sombras e torne-se uma lenda!
