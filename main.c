#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void) {

  /* Declaração de variáveis */
  char bi1[9], bi2[9], bi3[9];
  int vet1[8], vet2[8], vet3[8];
  int vetOpAux[8], vetOpFinal[8];
  char op1, op2;
  int controle;
  int v1, v2, v3, result;
  char h1[3], h2[3], h3[3], hresult[3];

  printf("=========================\n");
  printf("Seja bem vindo ao CalcBi!\n");
  printf("=========================\n");
  printf("\n");

  printf("O sistema vai perguntar 3 números em binário e suas respectivas operações, após isso o programa irá fazer o cálculo dos dados e retornar a soma dos respectivos números informados juntamente com a conversão deles para decimal com sinal e hexadecimal.");
  printf("\n\n");

  controle = 1;

  while (controle) {
    printf("Digite o primeiro número binário (-1 para encerrar): ");
    scanf("%s", bi1);
    printf("\n");

    if (strcmp(bi1, "-1") != 0) {
      printf("Digite o primeiro operando (+ ou -): ");
      scanf(" %c", &op1);
      printf("\n");

      printf("Digite o seugndo número binário: ");
      scanf("%s", bi2);
      printf("\n");

      printf("Digite o segundo operando (+ ou -): ");
      scanf(" %c", &op2);
      printf("\n");

      printf("Digite o terceiro número binário: ");
      scanf("%s", bi3);
      printf("\n");

      varCharParaBinario(bi1, vet1);
      varCharParaBinario(bi2, vet2);
      varCharParaBinario(bi3, vet3);

      if (op1 == '+') {
        somaBinaria(vet1, vet2, vetOpAux);
      } else {
        if (op1 == '-') {
          subtracaoBinaria(vet1, vet2, vetOpAux);
        } else {
          printf("Operação Inválida!");
        }
      }

      if (op2 == '+') {
        somaBinaria(vetOpAux, vet3, vetOpFinal);
      } else {
        if (op2 == '-') {
          subtracaoBinaria(vetOpAux, vet3, vetOpFinal);
        } else {
          printf("Operação Inválida!");
        }
      }

      v1 = binarioParaDecimal(vet1);
      v2 = binarioParaDecimal(vet2);
      v3 = binarioParaDecimal(vet3);
      result = binarioParaDecimal(vetOpFinal);

      binarioParaHex(vet1, h1);
      binarioParaHex(vet2, h2);
      binarioParaHex(vet3, h3);
      binarioParaHex(vetOpFinal, hresult);

      printf("==========================\n");
      printf("========Resultados========\n");
      printf("==========================\n");
      printf("\n--------------------------\n\n");
      mostravetores(vet1);
      printf("b ( ");
      printf("%di ", v1);
      mostrarHex(h1);
      printf("h )\n");
      printf("%c\n", op1);
      mostravetores(vet2);
      printf("b ( ");
      printf("%di ", v2);
      mostrarHex(h2);
      printf("h )\n");
      printf("%c\n", op2);
      mostravetores(vet3);
      printf("b ( ");
      printf("%di ", v3);
      mostrarHex(h3);
      printf("h )\n");
      printf("=\n");
      mostravetores(vetOpFinal);
      printf("b ( ");
      printf("%di ", result);
      mostrarHex(hresult);
      printf("h )\n");

    } else {
      printf("Encerrando o programa!\n");
      controle = 0;
    }

    printf("\n---------------------------\n\n");
  }
  
  return 0;
}