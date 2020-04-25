#include <stdio.h>
#include <string.h>
#include "pilha.h" 


char *inverte (char *palavra) {
     Pilha a = pilha(strlen(palavra)); //cria a pilha do tamanho da palavra exatamente  
     for (int i=0; i<strlen(palavra); i++) {
         empilha(palavra[i],a);
     }
     static char invertida[215]; 
     for (int j=0; j<strlen(palavra); j++){
         invertida[j] = desempilha(a);
     }
     destroip(&a);
     return invertida;
}


int main() {
    char palavra[215];
    printf("qual é a palavra que você quer inverter?\n");  
    gets(palavra);
    printf("\ninvertida fica: %s",inverte(palavra));
   return 0;
}



