#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#define MAX_ITENS 20
#define PRETO            0
#define AZUL             1
#define VERDE            2
#define CIANO            3
#define VERMELHO         4
#define MAGENTA          5
#define AMARELO_ESCURO   6
#define CINZA_CLARO      7
#define CINZA            8
#define AZUL_CLARO       9
#define VERDE_CLARO      10
#define CIANO_CLARO      11
#define VERMELHO_CLARO   12
#define ROSA             13
#define AMARELO          14
#define BRANCO           15

typedef struct {
    char nome[50];
    int vida, vidaMax;
    int ataque, defesa;
    int nivel, experiencia;
    int ouro;
    int inventario[MAX_ITENS];
    int qtdItens;
} Personagem;

enum {
    POCAO_P = 1,
    POCAO_G,
    ESPADA,
    ARMADURA,
    ESCUDO
};

Personagem jogador;

/* --- DECLARAÇÃO DE PROTÓTIPOS --- */
void cor(int c);
void titulo(char t[]);
void escrever(char texto[]);
void loading(char texto[]);
void tocarSom(char arquivo[]);
void trocarMusica(char arquivo[]);
void iniciarMusica();
void pararMusica();
void barraVida(int atual, int maximo);
void telaInicial();
void tremor();
void goblin();
void dragao();
void introBoss();
void vitoriaFinal();

/* --- FUNÇÕES DE ÁUDIO E INTERFACE --- */
void cor(int c) { 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

void titulo(char t[]) {
    cor(CIANO_CLARO);
    printf("\n====================================================\n");
    printf("%s\n", t);
    printf("====================================================\n");
    cor(BRANCO);
}

void escrever(char texto[]) {
    for(int i = 0; texto[i] != '\0'; i++) {
        printf("%c", texto[i]);
        Sleep(15);
    }
}

void loading(char texto[]) {
    printf("%s", texto);
    for(int i = 0; i < 20; i++) {
        printf("%c", 219);
        Sleep(30);
    }
    printf("\n");
}

void tocarSom(char arquivo[]) {
    PlaySound(arquivo, NULL, SND_FILENAME | SND_ASYNC);
}

void iniciarMusica() {
    mciSendString("open \"musica.mp3\" type mpegvideo alias bgm", NULL, 0, NULL);
    mciSendString("play bgm repeat", NULL, 0, NULL);
}

void trocarMusica(char arquivo[]) {
    mciSendString("close bgm", NULL, 0, NULL);
    char cmd[200];
    sprintf(cmd, "open \"%s\" type mpegvideo alias bgm", arquivo);
    mciSendString(cmd, NULL, 0, NULL);
    mciSendString("play bgm repeat", NULL, 0, NULL);
}

void pararMusica() { 
    mciSendString("close bgm", NULL, 0, NULL); 
}

void barraVida(int atual, int maximo) {
    int total = 25;
    int preenchido = (atual * total) / maximo;

    if (preenchido < 0) preenchido = 0;

    printf("HP [");
    for(int i = 0; i < total; i++) {
        if(i < preenchido) {
            if(atual > maximo * 0.6)
                cor(VERDE_CLARO);
            else if(atual > maximo * 0.3)
                cor(AMARELO);
            else
                cor(VERMELHO_CLARO);
            printf("%c", 219);
        } else {
            cor(CINZA);
            printf("%c", 176);
        }
    }
    cor(BRANCO);
    printf("] %d/%d\n", atual < 0 ? 0 : atual, maximo);
}

void telaInicial() {
    system("cls");
    cor(CIANO_CLARO);
    printf("\n");
    printf("#########################################################\n");
    printf("#                                                       #\n");
    printf("#              RPG DE TEXTO - SENAI EDITION            #\n");
    printf("#                                                       #\n");
    printf("#########################################################\n");
    cor(BRANCO);
    Sleep(2000);
}

void tremor() {
    // Tom grave e longo de impacto
    Beep(120, 200); 

    // Posição 1: Esquerda com fundo Vermelho Vivo
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n\n\n");
    printf("##################################################\n");
    printf("#####             !!! DANO !!!               #####\n");
    printf("##################################################\n");
    Sleep(120); // Tempo suficiente para o olho perceber

    // Posição 2: Empurrado muito para a DIREITA com texto vermelho
    system("cls");
    cor(VERMELHO_CLARO);
    printf("\n\n\n");
    printf("                  ##################################################\n");
    printf("                  #####             !!! DANO !!!               #####\n");
    printf("                  ##################################################\n");
    Sleep(120);

    // Posição 3: Meio termo / Centro
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("\n\n\n");
    printf("        ##################################################\n");
    printf("        #####             !!! DANO !!!               #####\n");
    printf("        ##################################################\n");
    Sleep(120);

    // Posição 4: Volta para a esquerda
    system("cls");
    cor(VERMELHO_CLARO);
    printf("\n\n\n");
    printf("##################################################\n");
    printf("#####             !!! DANO !!!               #####\n");
    printf("##################################################\n");
    Sleep(120);

    // Limpa a tela e restaura a cor padrão
    system("cls");
    cor(BRANCO);
}

/* --- ARTE ASCII --- */
void goblin() {
    cor(VERDE_CLARO);
    printf("\n");
    printf("     ,      ,\n");
    printf("    /(.-\"\"-.)\\\\\n");
    printf("    |\\  \\/  /|\n");
    printf("    | \\ /.= \\ |\n");
    printf("    \\\\( o\\/o )/\n");
    cor(BRANCO);
}

void dragao() {
    cor(VERMELHO_CLARO);
    printf("\n");
    printf("                 /           /\n");
    printf("        /' .,,,,  ./\n");
    printf("       /';'     ,/\n");
    printf("      / /   ,,//\n");
    printf("     ( ,, '_,  ,,,\n");
    printf("     |    /@  ,,,\n");
    printf("    /    .   ,''\n");
    cor(BRANCO);
}

void introBoss() {
    system("cls");
    cor(VERMELHO_CLARO);
    printf("\n");
    printf("#################################################\n");
    printf("#                                               #\n");
    printf("#       DRAGAO DAS SOMBRAS DESPERTOU!           #\n");
    printf("#                                               #\n");
    printf("#################################################\n");
    tocarSom("sons\\boss.wav");
    Sleep(3000);
    cor(BRANCO);
}

void vitoriaFinal() {
    tocarSom("sons\\vitoria.wav");
    cor(VERDE_CLARO);
    printf("\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*          VOCE SALVOU O REINO!             *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    cor(BRANCO);
}

/* --- PERSISTÊNCIA --- */
void salvar() {
    FILE *f = fopen("save.dat", "wb");
    if(f) { 
        fwrite(&jogador, sizeof(Personagem), 1, f); 
        fclose(f);
    }
}

int carregar() {
    FILE *f = fopen("save.dat", "rb");
    if(!f) return 0;
    fread(&jogador, sizeof(Personagem), 1, f);
    fclose(f);
    return 1;
}

/* --- MECÂNICAS DO JOGO --- */
void subirNivel() {
    while(jogador.experiencia >= 100) {
        jogador.experiencia -= 100;
        jogador.nivel++;
        jogador.ataque += 5;
        jogador.defesa += 3;
        jogador.vidaMax += 20;
        jogador.vida = jogador.vidaMax;
        cor(VERDE_CLARO);
        printf("\nLEVEL UP! Nivel %d\n", jogador.nivel);
        cor(BRANCO);
    }
}

void criarPersonagem() {
    titulo("CRIAR PERSONAGEM");
    printf("Nome: ");
    scanf("%49s", jogador.nome);

    jogador.vida = 100;
    jogador.vidaMax = 100;
    jogador.ataque = 10;
    jogador.defesa = 5;
    jogador.nivel = 1;
    jogador.experiencia = 0;
    jogador.ouro = 50;
    jogador.qtdItens = 0;

    printf("\nPersonagem %s criado com sucesso!\n", jogador.nome);
}

void status() {
    titulo("STATUS");
    printf("Nome: %s\n", jogador.nome);
    barraVida(jogador.vida, jogador.vidaMax);
    printf("Ataque: %d\n", jogador.ataque);
    printf("Defesa: %d\n", jogador.defesa);
    printf("Nivel: %d\n", jogador.nivel);
    printf("XP: %d/100\n", jogador.experiencia);
    printf("Ouro: %d\n", jogador.ouro);
}

void adicionarItem(int item) {
    if(jogador.qtdItens < MAX_ITENS) {
        jogador.inventario[jogador.qtdItens++] = item;
    } else {
        printf("Inventario cheio! Item perdido.\n");
    }
}

void listarItens() {
    for(int i = 0; i < jogador.qtdItens; i++) {
        printf("%d - ", i + 1);
        switch(jogador.inventario[i]) {
            case POCAO_P: printf("Pocao Pequena (+20 HP)"); break;
            case POCAO_G: printf("Pocao Grande (+50 HP)"); break;
            case ESPADA: printf("Espada (+5 ATQ)"); break;
            case ARMADURA: printf("Armadura (+5 DEF)"); break;
            case ESCUDO: printf("Escudo (+3 DEF)"); break;
        }
        printf("\n");
    }
}

void usarItem() {
    int op;
    if(jogador.qtdItens == 0) { printf("Inventario vazio!\n"); return; }

    listarItens();
    printf("Escolha o item para usar: ");
    scanf("%d", &op);
    op--;

    if(op < 0 || op >= jogador.qtdItens) return;

    int item = jogador.inventario[op];

    switch(item) {
        case POCAO_P:
            jogador.vida += 20;
            if(jogador.vida > jogador.vidaMax) jogador.vida = jogador.vidaMax;
            printf("Usou Pocao Pequena!\n");
            break;
        case POCAO_G:
            jogador.vida += 50;
            if(jogador.vida > jogador.vidaMax) jogador.vida = jogador.vidaMax;
            printf("Usou Pocao Grande!\n");
            break;
        case ESPADA:
            jogador.ataque += 5;
            printf("Equipou Espada! Ataque aumentou.\n");
            break;
        case ARMADURA:
            jogador.defesa += 5;
            printf("Equipou Armadura! Defesa aumentou.\n");
            break;
        case ESCUDO:
            jogador.defesa += 3;
            printf("Equipou Escudo! Defesa aumentou.\n");
            break;
    }

    for(int i = op; i < jogador.qtdItens - 1; i++)
        jogador.inventario[i] = jogador.inventario[i + 1];

    jogador.qtdItens--;
}

void inventario() {
    int op;
    do {
        titulo("INVENTARIO");
        printf("1-Visualizar\n2-Usar Item\n0-Voltar\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: listarItens(); break;
            case 2: usarItem(); break;
        }
    } while(op != 0);
}

void combate(char nome[], int vidaMonstro, int atkMonstro) {
    int op;
    
    if(strcmp(nome, "Goblin") == 0) goblin();
    else if(strcmp(nome, "Dragao das Sombras") == 0) dragao();

    while(vidaMonstro > 0 && jogador.vida > 0) {
        printf("\n--- %s (HP: %d) ---\n", nome, vidaMonstro);
        barraVida(jogador.vida, jogador.vidaMax);

        printf("\n1-Atacar  2-Defender  3-Fugir\nOpcao: ");
        scanf("%d", &op);

        if(op == 1) {
            int danoCausado = jogador.ataque;
            vidaMonstro -= danoCausado;
            printf("Voce causou %d de dano!\n", danoCausado);
        } else if(op == 2) {
            int danoDefendendo = (atkMonstro / 2) - (jogador.defesa / 2);
            if(danoDefendendo < 1) danoDefendendo = 1;
            jogador.vida -= danoDefendendo;
            tremor();
            printf("Voce se defendeu e tomou apenas %d de dano!\n", danoDefendendo);
            continue;
        } else if(op == 3) {
            if(rand() % 2) {
                printf("Fuga bem sucedida!\n");
                return;
            }
            printf("Falha ao fugir!\n");
        }

        if(vidaMonstro > 0) {
            int danoSofrido = atkMonstro - (jogador.defesa / 2);
            if(danoSofrido < 1) danoSofrido = 1;
            jogador.vida -= danoSofrido;
            tremor();
            printf("%s atacou voce e causou %d de dano!\n", nome, danoSofrido);
        }
    }

    if(jogador.vida <= 0) {
        cor(VERMELHO_CLARO);
        printf("\nVOCE FOI DERROTADO... GAME OVER!\n");
        cor(BRANCO);
        exit(0);
    }

    cor(VERDE_CLARO);
    printf("\n%s derrotado!\n", nome);
    cor(BRANCO);
    
    int expGanha = 20 + rand() % 30;
    int ouroGanho = 10 + rand() % 25;
    
    jogador.experiencia += expGanha;
    jogador.ouro += ouroGanho;
    printf("Recompensas: +%d XP | +%d Ouro\n", expGanha, ouroGanho);
    
    subirNivel();
}

void explorar() {
    titulo("EXPLORAR");
    loading("Explorando a regiao ");

    int e = (rand() % 5) + 1;

    switch(e) {
        case 1: {
            int m = rand() % 4;
            if(m == 0) combate("Goblin", 30, 5);
            else if(m == 1) combate("Esqueleto", 50, 8);
            else if(m == 2) combate("Orc", 80, 12);
            else combate("Lobisomem", 120, 15);
            break;
        }
        case 2:
            tocarSom("sons\\tesouro.wav");
            cor(AMARELO);
            printf("\n");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf("$                                 $\n");
            printf("$       TESOURO ENCONTRADO!       $\n");
            printf("$                                 $\n");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            cor(BRANCO);
            jogador.ouro += 30;
            printf("Voce ganhou +30 de ouro!\n");
            break;
        case 3:
            tocarSom("sons\\pocao.wav");
            cor(ROSA);
            printf("\nVoce encontrou uma pocao magica!\n");
            cor(BRANCO);
            adicionarItem((rand() % 2) + 1);
            break;
        case 4:
            // 1. Toca o som e FAZ A TELA TREMER PRIMEIRO
            tocarSom("sons\\dano.wav");
            tremor();

            // 2. AGORA imprime o aviso de armadilha (não vai mais ser apagado pelo tremor)
            cor(VERMELHO_CLARO);
            printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
            printf("      ARMADILHA !!!\n");
            printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
            cor(BRANCO);

            jogador.vida -= 15;
            printf("Voce perdeu 15 de vida!\n");
            barraVida(jogador.vida, jogador.vidaMax);

            if(jogador.vida <= 0) {
                printf("\nVoce morreu na armadilha! GAME OVER!\n");
                exit(0);
            }
            break;
        default:
            escrever("Voce andou por um tempo e nada aconteceu...\n");
    }
}

void loja() {
    int op;
    titulo("LOJA");
    printf("Seu Ouro: %d\n\n", jogador.ouro);
    printf("1-Pocao P (20 o)\n2-Pocao G (40 o)\n3-Espada (100 o)\n4-Armadura (120 o)\n5-Escudo (80 o)\n0-Sair\nOpcao: ");
    scanf("%d", &op);

    int preco[6] = {0, 20, 40, 100, 120, 80};

    if(op > 0 && op < 6) {
        if(jogador.ouro >= preco[op]) {
            jogador.ouro -= preco[op];
            adicionarItem(op);
            printf("Compra realizada com sucesso!\n");
        } else {
            printf("Ouro insuficiente!\n");
        }
    }
}

void descansar() {
    titulo("DESCANSAR");
    jogador.vida += 30;
    if(jogador.vida > jogador.vidaMax)
        jogador.vida = jogador.vidaMax;
    printf("Voce descansou na fogueira e recuperou vida.\n");
    barraVida(jogador.vida, jogador.vidaMax);
}

void chefeFinal() {
    if(jogador.nivel < 5) {
        printf("Nivel insuficiente! Nivel minimo para o Boss: 5 (Seu nivel: %d)\n", jogador.nivel);
        return;
    }

    introBoss();
    trocarMusica("boss.mp3");

    titulo("DRAGAO DAS SOMBRAS");
    combate("Dragao das Sombras", 300, 25);

    trocarMusica("musica.mp3");
    vitoriaFinal();
}

/* --- MAIN --- */
int main() {
    telaInicial();
    srand((unsigned int)time(NULL));
    iniciarMusica();

    int op;

    if(carregar()) {
        printf("Save carregado para o jogador %s!\n", jogador.nome);
        Sleep(1500);
    }

    do {
        system("cls");
        titulo("RPG DE TEXTO - MENU");
        printf("1-Criar Personagem\n");
        printf("2-Status\n");
        printf("3-Explorar\n");
        printf("4-Loja\n");
        printf("5-Inventario\n");
        printf("6-Descansar\n");
        printf("7-Chefe Final\n");
        printf("8-Salvar\n");
        printf("0-Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: criarPersonagem(); break;
            case 2: status(); break;
            case 3: explorar(); break;
            case 4: loja(); break;
            case 5: inventario(); break;
            case 6: descansar(); break;
            case 7: chefeFinal(); break;
            case 8: salvar(); printf("Jogo salvo com sucesso!\n"); break;
        }

        if(op != 0) {
            printf("\nPressione ENTER para voltar ao menu...");
            fflush(stdin);
            getchar();
            getchar();
        }

    } while(op != 0);

    salvar();
    pararMusica();
    return 0;
}