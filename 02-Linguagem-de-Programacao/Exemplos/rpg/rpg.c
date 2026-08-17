#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#define MAX_ITENS 20

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

void cor(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void titulo(char t[]){
    cor(11);
    printf("\n====================================================\n");
    printf("%s\n", t);
    printf("====================================================\n");
    cor(15);
}

void iniciarMusica(){
    mciSendString("open \"musica.mp3\" type mpegvideo alias bgm",NULL,0,NULL);
    mciSendString("play bgm repeat",NULL,0,NULL);
}

void pararMusica(){ mciSendString("close bgm",NULL,0,NULL); }

void salvar(){
    FILE *f=fopen("save.dat","wb");
    if(f){ fwrite(&jogador,sizeof(Personagem),1,f); fclose(f);}
}

int carregar(){
    FILE *f=fopen("save.dat","rb");
    if(!f) return 0;
    fread(&jogador,sizeof(Personagem),1,f);
    fclose(f);
    return 1;
}

void subirNivel(){
    while(jogador.experiencia>=100){
        jogador.experiencia-=100;
        jogador.nivel++;
        jogador.ataque+=5;
        jogador.defesa+=3;
        jogador.vidaMax+=20;
        jogador.vida=jogador.vidaMax;
        cor(10);
        printf("\nLEVEL UP! Nivel %d\n",jogador.nivel);
        cor(15);
    }
}

void criarPersonagem(){
    titulo("CRIAR PERSONAGEM");
    printf("Nome: ");
    scanf("%49s", jogador.nome);

    jogador.vida=100;
    jogador.vidaMax=100;
    jogador.ataque=10;
    jogador.defesa=5;
    jogador.nivel=1;
    jogador.experiencia=0;
    jogador.ouro=50;
    jogador.qtdItens=0;

    printf("Personagem criado!\n");
}

void status(){
    titulo("STATUS");
    printf("Nome: %s\n", jogador.nome);
    printf("Vida: %d/%d\n", jogador.vida, jogador.vidaMax);
    printf("Ataque: %d\n", jogador.ataque);
    printf("Defesa: %d\n", jogador.defesa);
    printf("Nivel: %d\n", jogador.nivel);
    printf("XP: %d/100\n", jogador.experiencia);
    printf("Ouro: %d\n", jogador.ouro);
}

void adicionarItem(int item){
    if(jogador.qtdItens<MAX_ITENS)
        jogador.inventario[jogador.qtdItens++]=item;
}

void listarItens(){
    int i;
    for(i=0;i<jogador.qtdItens;i++){
        printf("%d - ", i+1);
        switch(jogador.inventario[i]){
            case POCAO_P: printf("Pocao Pequena"); break;
            case POCAO_G: printf("Pocao Grande"); break;
            case ESPADA: printf("Espada"); break;
            case ARMADURA: printf("Armadura"); break;
            case ESCUDO: printf("Escudo"); break;
        }
        printf("\n");
    }
}

void usarItem(){
    int op;
    if(jogador.qtdItens==0){ printf("Inventario vazio!\n"); return; }

    listarItens();
    printf("Escolha: ");
    scanf("%d",&op);
    op--;

    if(op<0 || op>=jogador.qtdItens) return;

    int item=jogador.inventario[op];

    switch(item){
        case POCAO_P:
            jogador.vida+=20;
            if(jogador.vida>jogador.vidaMax) jogador.vida=jogador.vidaMax;
            break;
        case POCAO_G:
            jogador.vida+=50;
            if(jogador.vida>jogador.vidaMax) jogador.vida=jogador.vidaMax;
            break;
        case ESPADA:
            jogador.ataque+=5;
            break;
        case ARMADURA:
            jogador.defesa+=5;
            break;
        case ESCUDO:
            jogador.defesa+=3;
            break;
    }

    for(int i=op;i<jogador.qtdItens-1;i++)
        jogador.inventario[i]=jogador.inventario[i+1];

    jogador.qtdItens--;
}

void inventario(){
    int op;
    do{
        titulo("INVENTARIO");
        printf("1-Visualizar\n2-Usar Item\n0-Voltar\n");
        scanf("%d",&op);

        switch(op){
            case 1: listarItens(); break;
            case 2: usarItem(); break;
        }
    }while(op!=0);
}

void combate(char nome[], int vidaMonstro, int atkMonstro){
    int op;
    while(vidaMonstro>0 && jogador.vida>0){
        printf("\n%s HP:%d\n", nome, vidaMonstro);
        printf("%s HP:%d/%d\n", jogador.nome, jogador.vida, jogador.vidaMax);

        printf("1-Atacar 2-Defender 3-Fugir\n");
        scanf("%d",&op);

        if(op==1){
            vidaMonstro-=jogador.ataque;
        }else if(op==2){
            jogador.vida -= (atkMonstro/2);
            continue;
        }else if(op==3){
            if(rand()%2){
                printf("Fuga bem sucedida!\n");
                return;
            }
        }

        if(vidaMonstro>0){
            int dano=atkMonstro-jogador.defesa/2;
            if(dano<1) dano=1;
            jogador.vida-=dano;
        }
    }

    if(jogador.vida<=0){
        printf("GAME OVER!\n");
        exit(0);
    }

    printf("%s derrotado!\n", nome);
    jogador.experiencia+=20+rand()%30;
    jogador.ouro+=10+rand()%25;
    subirNivel();
}

void explorar(){
    titulo("EXPLORAR");
    int e=(rand()%5)+1;

    switch(e){
        case 1:{
            int m=rand()%4;
            if(m==0) combate("Goblin",30,5);
            else if(m==1) combate("Esqueleto",50,8);
            else if(m==2) combate("Orc",80,12);
            else combate("Lobisomem",120,15);
            break;
        }
        case 2:
            printf("Tesouro encontrado!\n");
            jogador.ouro+=30;
            break;
        case 3:
            printf("Encontrou uma pocao!\n");
            adicionarItem((rand()%2)+1);
            break;
        case 4:
            printf("Armadilha!\n");
            jogador.vida-=15;
            break;
        default:
            printf("Nada aconteceu.\n");
    }
}

void loja(){
    int op;
    titulo("LOJA");
    printf("Ouro: %d\n", jogador.ouro);
    printf("1-Pocao P (20)\n2-Pocao G (40)\n3-Espada (100)\n4-Armadura (120)\n5-Escudo (80)\n0-Sair\n");
    scanf("%d",&op);

    int preco[6]={0,20,40,100,120,80};

    if(op>0 && op<6){
        if(jogador.ouro>=preco[op]){
            jogador.ouro-=preco[op];
            adicionarItem(op);
            printf("Compra realizada!\n");
        }else{
            printf("Ouro insuficiente!\n");
        }
    }
}

void descansar(){
    jogador.vida+=30;
    if(jogador.vida>jogador.vidaMax)
        jogador.vida=jogador.vidaMax;
}

void chefeFinal(){
    if(jogador.nivel<5){
        printf("Nivel minimo: 5\n");
        return;
    }

    titulo("DRAGAO DAS SOMBRAS");
    combate("Dragao das Sombras",300,25);

    cor(10);
    printf("\nVOCE SALVOU O REINO!\n");
    cor(15);
}

int main(){
    srand(time(NULL));
    iniciarMusica();

    int op;

    if(carregar())
        printf("Save carregado!\n");

    do{
        titulo("RPG DE TEXTO - PROFESSOR");
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
        scanf("%d",&op);

        switch(op){
            case 1: criarPersonagem(); break;
            case 2: status(); break;
            case 3: explorar(); break;
            case 4: loja(); break;
            case 5: inventario(); break;
            case 6: descansar(); break;
            case 7: chefeFinal(); break;
            case 8: salvar(); printf("Jogo salvo!\n"); break;
        }

        system("pause");
        system("cls");

    }while(op!=0);

    salvar();
    pararMusica();
    return 0;
}
