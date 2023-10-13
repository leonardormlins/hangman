#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define TAMANHO_LISTA_PALAVRAS 10


char dicas[] = "ANIMALCENOURACOMPUTADORCASACARROCAMAROUPATRANCARALOARTE";
char palavras[] = "MACACOCOELHOMOUSETELHADOVOLANTETRAVESSEIROCAMISETAFECHADURAESCOAMENTOQUADRO";
int indice_dicas[TAMANHO_LISTA_PALAVRAS] = {0, 6, 13, 23, 27, 32, 36, 41, 47, 51};
int indice_palavras[TAMANHO_LISTA_PALAVRAS] = {0, 6, 12, 17, 24, 31, 42, 50, 59, 69};

void imprimir_todas_palavras(char *palavras, int *indice_palavras){
    int i = 0;
    int l = 0;

    while(i < TAMANHO_LISTA_PALAVRAS){
        if(i == TAMANHO_LISTA_PALAVRAS - 1){
            while(palavras[l] != '\0'){
                printf("%c", palavras[l]);
                l++;
            }
        }
        while(l < indice_palavras[i + 1]){
            printf("%c", palavras[l]);
            l++;
        }
        printf("\n");
        i++;
    }
}

int sortear_indice(){
    srand(time(NULL));
    return rand() % (TAMANHO_LISTA_PALAVRAS);
}

void imprimir_via_indice(int indice_comeco, int indice_final, char *palavras){
    int indice = indice_comeco;
    if(indice_comeco == indice_final){
        while(palavras[indice] != '\0'){
            printf("%c", palavras[indice]);
            indice++;
        }
    }
    while(indice < indice_final){
        printf("%c", palavras[indice]);
        indice++;
    }
    printf("\n");
}

char* inicializar_hud(int size){
    char* hud = (char*)malloc((size + 1) * sizeof(char));

    if(hud != NULL){
        for(int i=0; i < size; i++){
            hud[i] = '_';
        }
        hud[size] = '\0';
    }
    return hud;
}

char* pegar_palavra(int indice_comeco, int indice_final){
    int tamanho_palavra=0;
    if(indice_comeco == indice_final){
        while(palavras[indice_final]!='\0'){
            indice_final++;
            tamanho_palavra++;
        }
    } else {
        tamanho_palavra = indice_final - indice_comeco;
    }

    char* palavra = (char*)malloc((tamanho_palavra + 1) * sizeof(char));
    int i=0;

    for(int j=indice_comeco; j<indice_final;j++){
        palavra[i] = palavras[j];
        i++;
    }
    palavra[i] = '\0';

    return palavra;
}

int pegar_tamanho_palavra(int indice_final, int indice_comeco){
    int tamanho = 0;
    if(indice_comeco == indice_final){
        for(int i=indice_comeco; palavras[i] != '\0';i++){
            tamanho++;
        }
    } else {
        tamanho = indice_final - indice_comeco;
    }
    return tamanho;
}

char* atualizar_hud(char letra,char *palavra, char *hud, int size){
    char* new_hud = (char*)malloc((size + 1) * sizeof(char));
    int i = 0;
    if (new_hud != NULL){
        while(palavra[i]!='\0'){
            printf("%c", hud[i]);
            if(letra == palavra[i]){
                new_hud[i] = letra;
            } else if(hud[i] == '_'){
                new_hud[i] = '_';
            } else {
                new_hud[i] = palavra[i];
            }
            i++;
        }
        new_hud[i] = '\0';
    }
    return new_hud;
}

int ganhou(char *hud){
    for(int i=0;hud[i]!='\0';i++){
        printf("\nCHECANDO VITORIA: %c", hud[i]);
        if(hud[i]=='_'){
            return 0;
        }
    }
    return 1;
}

char maiusculo(char letra){
    switch(letra){
        case 'a':
            return 'A';
        case 'b':
            return 'B';
        case 'c':
            return 'C';
        case 'd':
            return 'D';
        case 'e':
            return 'E';
        case 'f':
            return 'F';
        case 'g':
            return 'G';
        case 'h':
            return 'H';
        case 'i':
            return 'I';
        case 'j':
            return 'J';
        case 'k':
            return 'K';
        case 'l':
            return 'L';
        case 'm':
            return 'M';
        case 'n':
            return 'N';
        case 'o':
            return 'O';
        case 'p':
            return 'P';
        case 'q':
            return 'Q';
        case 'r':
            return 'R';
        case 's':
            return 'S';
        case 't':
            return 'T';
        case 'u':
            return 'U';
        case 'v':
            return 'V';
        case 'w':
            return 'W';
        case 'y':
            return 'Y';
        case 'Z':
            return 'Z';
        default:
            return letra;
    }
}

void main ()
{
    int modo_de_jogo;

    while(modo_de_jogo != 1 && modo_de_jogo != 2){
        printf("[1] UM JOGADOR");
        printf("\n[2] DOIS JOGADORES");
        printf("\n\nESCOLHA UM MODO DE JOGO: ");
        scanf("%d", &modo_de_jogo);
        if(modo_de_jogo != 1 && modo_de_jogo != 2){
            printf("\nOPCAO INCORRETA, DIGITE 1 OU 2");
        } else {
            system("cls");
        }
    }

    if(modo_de_jogo == 1){
        printf("REGRAS DO JOGO:");
        printf("\n- O NUMERO DE CHANCES QUE O JOGADOR TERA SERA O TAMANHO DA PALAVRA + 2!");
        printf("\n- CASO O JOGADOR DESCUBRA A PALAVRA, ELE SERA O VENCEDOR");
        printf("\n- CASO O JOGADOR NAO DESCUBRA A PALAVRA, PERDERA O JOGO");
        printf("\n\nPRESSIONE ENTER PARA CONTINUAR...\n\n\n");
        system("pause");
        system("cls");

        int indice_comeco = sortear_indice();
        int indice_final;
        if(indice_comeco == (TAMANHO_LISTA_PALAVRAS - 1)){
            indice_final = indice_comeco;
        }else{
            indice_final = indice_comeco + 1;
        }

        int tamanho_palavra = pegar_tamanho_palavra(indice_palavras[indice_final], indice_palavras[indice_comeco]);
        int tentativas = tamanho_palavra + 2;
        char letra[2];

        char *hud = inicializar_hud(tamanho_palavra);
        char *palavra = pegar_palavra(indice_palavras[indice_comeco], indice_palavras[indice_final]);

        while(tentativas>0){
            printf("Dica: ");
            imprimir_via_indice(indice_dicas[indice_comeco], indice_dicas[indice_final], &dicas);
            printf("%d letras\n", tamanho_palavra);
            printf("%d tentativas\n", tentativas);
            printf("\n\n%s\n", hud);
            printf("Insira uma letra: ");
            scanf("%s", &letra);
            letra[0] = maiusculo(letra[0]);
            hud = atualizar_hud(letra[0], palavra, hud, tamanho_palavra);
            if(ganhou(hud)){
                system("cls");
                printf("\n\nYOU WIN!");
                printf("\nPalavra: %s", palavra);
                printf("\nTentativas restantes: %d", tentativas);
                return;
            }
            tentativas--;
            system("cls");
        }
        printf("\n\nGAME OVER!!");
        printf("\nA palavra era: %s", palavra);
    }

    if(modo_de_jogo == 2){
        char jogador_1[50];
        char jogador_2[50];

        char dica_dj[50];
        char palavra_dj[50];

        printf("REGRAS DO JOGO:");
        printf("\n- O JOGADOR UM VAI PASSAR UMA DICA E UMA PALAVRA PARA O JOGADOR DOIS");
        printf("\n- O NUMERO DE CHANCES QUE O JOGADOR DOIS VAI TER SERA O TAMANHO DA PALAVRA + 2!");
        printf("\n- CASO O JOGADOR DOIS DESCUBRA A PALAVRA, ELE SERA O VENCEDOR");
        printf("\n- CASO O JOGADOR DOIS NAO DESCUBRA A PALAVRA, O JOGADOR DOIS SERA O VENCEDOR");
        printf("\n\nPRESSIONE ENTER PARA CONTINUAR...\n\n\n");
        system("pause");
        system("cls");

        printf("NOME DO JOGADOR UM: ");
        scanf("%s", &jogador_1);
        printf("\nNOME DO JOGADOR DOIS: ");
        scanf("%s", &jogador_2);
        system("cls");

        printf("%s, SUA VEZ!", jogador_1);
        printf("\nQUANDO O %s NAO ESTIVER OLHANDO DIGITE ENTER...\n\n\n", jogador_2);
        system("pause");
        system("cls");

        printf("INSIRA UMA DICA:");
        scanf("%s", &dica_dj);

        printf("INSIRA UMA PALAVRA:");
        scanf("%s", &palavra_dj);

        printf("PARA LIMPAR A TELA E PASSAR PRO %s, DIGITE ENTER...\n\n\n", jogador_2);
        system("pause");
        system("cls");

        int tamanho_palavra_dj = 0;

        for(int i = 0; dica_dj[i] != '\0';i++){
            dica_dj[i] = maiusculo(dica_dj[i]);
        }
        for(int i = 0; palavra_dj[i] != '\0';i++){
            palavra_dj[i] = maiusculo(palavra_dj[i]);
            tamanho_palavra_dj++;
        }
        int tentativas_dj = tamanho_palavra_dj + 2;
        char *hud_dj = inicializar_hud(tamanho_palavra_dj);
        char letra_dj[2];

        while(tentativas_dj>0){
            printf("Dica: %s", dica_dj);
            printf("\n%d letras\n", tamanho_palavra_dj);
            printf("%d tentativas\n", tentativas_dj);
            printf("\n\n%s\n", hud_dj);
            printf("Insira uma letra: ");
            scanf("%s", &letra_dj);
            letra_dj[0] = maiusculo(letra_dj[0]);
            hud_dj = atualizar_hud(letra_dj[0], palavra_dj, hud_dj, tamanho_palavra_dj);
            if(ganhou(hud_dj)){
                system("cls");
                printf("%s GANHOU!", jogador_2);
                printf("\nPalavra: %s", palavra_dj);
                printf("\nTentativas restantes: %d", tentativas_dj);
                return;
            }
            tentativas_dj--;
            system("cls");
        }
        printf("\n\n%s GANHOU!", jogador_1);
        printf("\nA palavra era: %s", palavra_dj);

    }
}
