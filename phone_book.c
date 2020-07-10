#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARAC 50
#define MAX_NUM 8
#define VALOR_MAX 10

char nomes [VALOR_MAX] [MAX_CARAC] = {};
char email [VALOR_MAX] [MAX_CARAC] = {};
char telefone [VALOR_MAX] [MAX_NUM] = {};
int contador = 0;

void limpaFluxo(){
    int ch;
    do{
        ch = fgetc(stdin);
    }
    while (ch != EOF && ch != '\n');
}

void adicionar(){

  printf("\t Voce selecionou a opcao de adicionar um registro \n \n");
  printf("\t Aperte enter para continuar \n \n");

  for (int i = 0; i < VALOR_MAX; i++){
    limpaFluxo();
    printf("Digite o nome a ser  inserido: ");
    fgets(nomes[i], MAX_CARAC, stdin);
    printf("Agora digite o telefone a ser adicionado no contato anterior: " );
    fgets(telefone[i], MAX_NUM, stdin);
    printf("Agora digite o email a ser adicionado no contato anterior: ");
    fgets(email[i], MAX_CARAC, stdin);
  }
  limpaFluxo();
  system("cls");
}

void aparecer(){
  printf("\n \n \t Voce selecionou a funcao Aparecer \n \n");


  for(int i = 0; i < VALOR_MAX; i++){
    printf("contato: %d \n %s %s %s \n \n", contador + i, nomes[i], telefone[i], email[i]);
  }
  limpaFluxo();
  system("cls");
}

void alterar(int numero){
    char alterarnome[50], alteraremail[50], alterartelefone[50];
    limpaFluxo();
    printf("Digite o novo nome: ");
    strcpy(nomes[numero], fgets(alterarnome,50, stdin));
    printf("Digite o novo telefone: ");
    strcpy(telefone[numero], fgets(alterartelefone,50, stdin));
    printf("Digite o novo email: ");
    strcpy(email[numero], fgets(alteraremail, 50, stdin));

    aparecer();
    printf("\t \t Contato alterado! \n\n");
    system("cls");
}

void excluir(){
    for(int i = 0; i < VALOR_MAX; i++){
      memset(nomes[i], 0, sizeof(nomes[50]));
      memset(telefone[i], 0, sizeof(telefone[8]));
      memset(email[i], 0, sizeof(email[50]));
      }
    printf("Todos os contatos apagados");
    system("cls");
 }

void excluir_ultimo(){
    memset(nomes[VALOR_MAX - 1], 0, sizeof(nomes[50]));
    memset(telefone[VALOR_MAX - 1], 0, sizeof(telefone[8]));
    memset(email[VALOR_MAX - 1], 0, sizeof(email[50]));
}

void sair(){
 printf("\n \t \t \t \t Voc� selecionou a opcao para sair da agenda. \n \n");
 printf("\n \t \t \t \t Obrigado por usar nossa agenda! \n \n");
 system("cls");
}

int main(){
  int numero;
  int controle = 0;
  char ch;

while(controle == 0){
printf("\n \t \t \t \t Agenda Telefonica \n \n");
printf("Digite (A) para adicionar um regristro. \n");
printf("Digite (M) para aparecer todos os registros. \n");
printf("Digite (E) para excluir todos registro. \n");
printf("Digite (R) para excluir o ultimo registro \n");
printf("Digite (K) para alterar um registro. \n");
printf("Digite (S) caso queira sair da agenda. \n");
scanf("%c",&ch);
limpaFluxo();
system("cls");

switch(ch){
  case 'A':
     adicionar();
  break;

  case 'M':
     aparecer();
  break;

  case 'E':
     excluir();
  break;

  case 'R':
    excluir_ultimo();
  break;

  case 'K':
      printf("Digite o numero que queira alterar: \n");
      scanf("%d", &numero);
      alterar(numero);
  break;

  case 'S':
     sair();
     controle = 1;
     break;

  default:
  printf("\n \t \t \t \t Opcao invalida. \n \n");
   }
 }
}

