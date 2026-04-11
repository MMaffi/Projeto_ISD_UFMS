#include <stdio.h>
#include "functions.h"

int main(void) {

  /* Declaração de variáveis */
  int bi1, bi2, bi3;
  int vet1[8], vet2[8], vet3[8];
  char op1, op2;
  int controle;

  printf("=========================\n");
  printf("Seja bem vindo ao CalcBi!\n");
  printf("=========================\n");
  printf("\n");

  printf("O sistema vai perguntar 3 números em binário e suas respectivas operações, após isso o programa irá fazer o cálculo dos dados e retornar a soma dos respectivos números informados juntamente com a conversão deles para decimal com sinal e hexadecimal.");
  printf("\n\n");

  controle = 1;

  while (controle) {
    printf("Digite o primeiro número binário (-1 para encerrar): ");
    scanf("%d", &bi1);
    printf("\n");

    if (bi1 != -1) {
      printf("Digite o primeiro operando (+ ou -): ");
      scanf(" %c", &op1);
      printf("\n");

      printf("Digite o seugndo número binário: ");
      scanf("%d", &bi2);
      printf("\n");

      printf("Digite o segundo operando (+ ou -): ");
      scanf(" %c", &op2);
      printf("\n");

      printf("Digite o terceiro número binário: ");
      scanf("%d", &bi3);
      printf("\n");

      intParaBinario(bi1, vet1);
      intParaBinario(bi2, vet2);
      intParaBinario(bi3, vet3);

      calculosoma();

      mostravetores(vet1);
      printf("\n");
      mostravetores(vet2);
      printf("\n");
      mostravetores(vet3);

    } else {
      printf("Encerrando o programa!\n");
      controle = 0;
    }

    printf("\n---------------------------\n\n");
  }
  
  return 0;
}