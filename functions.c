#include "functions.h"
#include <stdio.h>

void calculosoma() {
  printf("Cálculo da soma!\n");
}

void intParaBinario(int num, int vet[8]) {
  int i;

  for (i = 7; i >= 0; i--) {
    vet[i] = num % 10;
    num /= 10;
  }
}

void mostravetores(int vet[8]) {
	int i;

	for (i = 0; i <= 7; i++) {
		printf("%d", vet[i]);
	}
}