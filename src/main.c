#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define LENGTH_WORDS_LISTS 10


char tips[] = "ANIMALCENOURACOMPUTADORCASACARROCAMAROUPATRANCARALOARTE";
char words[] = "MACACOCOELHOMOUSETELHADOVOLANTETRAVESSEIROCAMISETAFECHADURAESCOAMENTOQUADRO";
int index_tips[LENGTH_WORDS_LISTS] = {0, 6, 13, 23, 27, 32, 36, 41, 47, 51};
int index_words[LENGTH_WORDS_LISTS] = {0, 6, 12, 17, 24, 31, 42, 50, 59, 69};

void print_all_words(char *words, int *index_words){
    int i = 0;
    int l = 0;

    while(i < LENGTH_WORDS_LISTS){
        if(i == LENGTH_WORDS_LISTS - 1){
            while(words[l] != '\0'){
                printf("%c", words[l]);
                l++;
            }
        }
        while(l < index_words[i + 1]){
            printf("%c", words[l]);
            l++;
        }
        printf("\n");
        i++;
    }
}

int draw_index(){
    srand(time(NULL));
    return rand() % (LENGTH_WORDS_LISTS);
}

void print_via_index(int index_beginning, int index_end, char *words){
    int index = index_beginning;
    if(index_beginning == index_end){
        while(words[index] != '\0'){
            printf("%c", words[index]);
            index++;
        }
    }
    while(index < index_end){
        printf("%c", words[index]);
        index++;
    }
    printf("\n");
}

char* initialize_hud(int size){
    char* hud = (char*)malloc((size + 1) * sizeof(char));

    if(hud != NULL){
        for(int i=0; i < size; i++){
            hud[i] = '_';
        }
        hud[size] = '\0';
    }
    return hud;
}

char* get_word(int index_beginning, int index_end){
    int length_word=0;
    if(index_beginning == index_end){
        while(words[index_end]!='\0'){
            index_end++;
            length_word++;
        }
    } else {
        length_word = index_end - index_beginning;
    }

    char* word = (char*)malloc((length_word + 1) * sizeof(char));
    int i=0;

    for(int j=index_beginning; j<index_end;j++){
        word[i] = words[j];
        i++;
    }
    word[i] = '\0';

    return word;
}

int get_length_word(int index_end, int index_beginning){
    int length = 0;
    if(index_beginning == index_end){
        for(int i=index_beginning; words[i] != '\0';i++){
            length++;
        }
    } else {
        length = index_end - index_beginning;
    }
    return length;
}

char* update_hud(char letter,char *word, char *hud, int size){
    char* new_hud = (char*)malloc((size + 1) * sizeof(char));
    int i = 0;
    if (new_hud != NULL){
        while(word[i]!='\0'){
            printf("%c", hud[i]);
            if(letter == word[i]){
                new_hud[i] = letter;
            } else if(hud[i] == '_'){
                new_hud[i] = '_';
            } else {
                new_hud[i] = word[i];
            }
            i++;
        }
        new_hud[i] = '\0';
    }
    return new_hud;
}

int win(char *hud){
    for(int i=0;hud[i]!='\0';i++){
        if(hud[i]=='_'){
            return 0;
        }
    }
    return 1;
}

char upper(char letter){
    switch(letter){
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
            return letter;
    }
}

void main ()
{
    int game_mode;

    while(game_mode != 1 && game_mode != 2){
        printf("[1] UM JOGADOR");
        printf("\n[2] DOIS JOGADORES");
        printf("\n\nESCOLHA UM MODO DE JOGO: ");
        scanf("%d", &game_mode);
        if(game_mode != 1 && game_mode != 2){
            printf("\nOPCAO INCORRETA, DIGITE 1 OU 2");
        } else {
            system("cls");
        }
    }

    if(game_mode == 1){
        printf("REGRAS DO JOGO:");
        printf("\n- O NUMERO DE CHANCES QUE O JOGADOR TERA SERA O TAMANHO DA PALAVRA + 2!");
        printf("\n- CASO O JOGADOR DESCUBRA A PALAVRA, ELE SERA O VENCEDOR");
        printf("\n- CASO O JOGADOR NAO DESCUBRA A PALAVRA, PERDERA O JOGO");
        printf("\n\nPRESSIONE ENTER PARA CONTINUAR...\n\n\n");
        system("pause");
        system("cls");

        int index_beginning = draw_index();
        int index_end;
        if(index_beginning == (LENGTH_WORDS_LISTS - 1)){
            index_end = index_beginning;
        }else{
            index_end = index_beginning + 1;
        }

        int length_word = get_length_word(index_words[index_end], index_words[index_beginning]);
        int attempts = length_word + 2;
        char letter[2];

        char *hud = initialize_hud(length_word);
        char *word = get_word(index_words[index_beginning], index_words[index_end]);

        while(attempts>0){
            printf("Dica: ");
            print_via_index(index_tips[index_beginning], index_tips[index_end], &tips);
            printf("%d letras\n", length_word);
            printf("%d tentativas\n", attempts);
            printf("\n\n%s\n", hud);
            printf("Insira uma letra: ");
            scanf("%s", &letter);
            letter[0] = upper(letter[0]);
            hud = update_hud(letter[0], word, hud, length_word);
            if(win(hud)){
                system("cls");
                printf("\n\nVOCE VENCEU!");
                printf("\npalavra: %s", word);
                printf("\ntentativas restantes: %d", attempts);
                return;
            }
            attempts--;
            system("cls");
        }
        printf("\n\nGAME OVER!!");
        printf("\nA palavra era: %s", word);
    }

    if(game_mode == 2){
        char jogador_1[50];
        char jogador_2[50];

        char dica_dj[50];
        char word_dj[50];

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
        scanf("%s", &word_dj);

        printf("PARA LIMPAR A TELA E PASSAR PRO %s, DIGITE ENTER...\n\n\n", jogador_2);
        system("pause");
        system("cls");

        int length_word_dj = 0;

        for(int i = 0; dica_dj[i] != '\0';i++){
            dica_dj[i] = upper(dica_dj[i]);
        }
        for(int i = 0; word_dj[i] != '\0';i++){
            word_dj[i] = upper(word_dj[i]);
            length_word_dj++;
        }
        int attempts_dj = length_word_dj + 2;
        char *hud_dj = initialize_hud(length_word_dj);
        char letter_dj[2];

        while(attempts_dj>0){
            printf("Dica: %s", dica_dj);
            printf("\n%d letras\n", length_word_dj);
            printf("%d tentativas\n", attempts_dj);
            printf("\n\n%s\n", hud_dj);
            printf("Insira uma letra: ");
            scanf("%s", &letter_dj);
            letter_dj[0] = upper(letter_dj[0]);
            hud_dj = update_hud(letter_dj[0], word_dj, hud_dj, length_word_dj);
            if(win(hud_dj)){
                system("cls");
                printf("%s ganhou!", jogador_2);
                printf("\npalavra: %s", word_dj);
                printf("\ntentativas restantes: %d", attempts_dj);
                return;
            }
            attempts_dj--;
            system("cls");
        }
        printf("\n\n%s ganhou!", jogador_1);
        printf("\nA palavra era: %s", word_dj);

    }
}
