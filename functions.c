#include "functions.h"
#include <stdio.h>

void somaBinaria(int a[8], int b[8], int resultado[8]) {
  int carry = 0;
  int i, soma;

  for (i = 7; i >= 0; i--) {
    soma = a[i] + b[i] + carry;

    resultado[i] = soma % 2;
    carry = soma / 2;
  }

  /* Verificação de overflow */
  if ((a[0] == b[0]) && (resultado[0] != a[0])) {
    printf("Overflow detectado!\n");
  }
}

void subtracaoBinaria(int a[8], int b[8], int resultado[8]) {
  
  int borrow = 0;
  int i, sub;

  for (i = 7; i >= 0; i--) {
    sub = a[i] - b[i] - borrow;

    if (sub >= 0) {
      resultado[i] = sub;
      borrow = 0;
    } else {
      resultado[i] = sub + 2;
      borrow = 1;
    }
  }

  /* Verificação de overflow (complemento de 2) */
  if ((a[0] != b[0]) && (resultado[0] != a[0])) {
      printf("Overflow detectado na subtracao!\n");
  }
}

int binarioParaDecimal(int bin[8]) {
  int decimal = 0;
  int i, comp[8], carry, soma;

  /* Se for positivo */
  if (bin[0] == 0) {
    for (i = 0; i < 8; i++) {
      decimal = decimal * 2 + bin[i];
    }
  } else {

    for (i = 0; i < 8; i++) {
      comp[i] = (bin[i] == 0) ? 1 : 0;
    }

    carry = 1;
    for (i = 7; i >= 0; i--) {
      soma = comp[i] + carry;
      comp[i] = soma % 2;
      carry = soma / 2;
    }

    for (i = 0; i < 8; i++) {
      decimal = decimal * 2 + comp[i];
    }

    decimal = -decimal; /* aplica sinal negativo */
  }

  return decimal;
}

void binarioParaHex(int bin[8], char hex[3]) {
  int valor1 = 0, valor2 = 0;
  int i;

  /* Primeiros 4 bits */
  for (i = 0; i < 4; i++) {
    valor1 = valor1 * 2 + bin[i];
  }

  /* Últimos 4 bits */
  for (i = 4; i < 8; i++) {
    valor2 = valor2 * 2 + bin[i];
  }

  /* Conversão do primeiro dígito */
  if (valor1 < 10) {
    hex[0] = valor1 + '0';
  } else {
    hex[0] = valor1 - 10 + 'A';
  }

  /* Conversão do segundo dígito */
  if (valor2 < 10) {
    hex[1] = valor2 + '0';
  } else {
    hex[1] = valor2 - 10 + 'A';
  }

  hex[2] = '\0';
}

void varCharParaBinario(char num[9], int vet[8]) {
  int i;

  for (i = 0; i < 8; i++) {
    if (num[i] == '0') {
      vet[i] = 0;
    } else if (num[i] == '1') {
      vet[i] = 1;
    } else {
      vet[i] = 0;
    }
  }
}

void mostravetores(int vet[8]) {
	int i;

	for (i = 0; i <= 7; i++) {
		printf("%d", vet[i]);
	}
}

void mostrarHex(char hex[3]) {
  printf("%s", hex);
}