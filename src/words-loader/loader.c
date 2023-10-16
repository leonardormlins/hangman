#include <stdio.h>
#include <string.h>

void main() {
  FILE *fptr;
  int option = -1;

  while(option != 1 && option != 2 && option != 3){
    printf("Loader de palavras do modo single player. Escolha uma opcao:\n");
    printf("[1] Listar dicas e palavras existentes\n");
    printf("[2] Adicionar uma nova dica/palavra\n");
    printf("[3] Limpar todas as dicas e palavras\n");
    scanf("%d", &option);
    if(option != 1 && option != 2 && option != 3){
      system("cls");
      printf("Opcao incorreta!\nEscolha uma das opcoes apresentadas 1, 2 ou 3");
      system("pause");
      system("cls");
    }
  }

  if(option == 1){
    system("cls");
    fptr = fopen("../../assets/words_tips.txt", "r");

    char line[100];
    char *token;
    int counter=1;

    if (fptr != NULL) {
      while(fgets(line, 100, fptr)){
        printf("%d - ", counter);
        token = strtok(line, "=");
        printf("Dica: %s ", token);
        token = strtok(NULL, "=");
        printf("Palavra: %s", token);
        counter++;
      }
    } else {
      printf("Not able to open the file!");
    }
    fclose(fptr);
  }

  if(option  == 2){
    system("cls");
    fptr = fopen("../../assets/words_tips.txt", "a");

    char dica[50];
    char palavra[50];

    printf("Insira a dica: ");
    scanf("%s", &dica);

    printf("Insira a palavra: ");
    scanf("%s", &palavra);

    fprintf(fptr, "\n%s=%s", dica, palavra);
    fclose(fptr);
  }

  if(option  == 3){
    int sure = 0;

    printf("\nTem certeza? Essa acao nao pode ser desfeita.");
    printf("\n[0] Nao");
    printf("\n[1] Sim");
    scanf("%d", &sure);

    if(sure){
      printf("\nCleaning up...");
      fptr = fopen("../../assets/words_tips.txt", "w");
      fclose(fptr);
      printf("\nDone!");
    }
  }
}