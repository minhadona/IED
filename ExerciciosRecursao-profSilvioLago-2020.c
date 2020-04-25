// NOME: GABRIELLA DESTRO BORGES
// MATR: 20111099

#include <stdio.h>
#include <string.h>

// EXERCÍCIO 1
// Crie a função recursiva soma_digitos(n),
// que devolve a soma dos dígitos que compõem
// o número natural n>=0. Por exemplo, a chamada
// soma_digitos(7859) deve devolver a resposta
// 29 (pois 7+8+5+9 = 29).

int soma_digitos(int n) {
   if( n==0 ) return 0;
   return ((n%10) + soma_digitos(n/10)); 
}

// EXERCÍCIO 2
// Crie a função recursiva qtde_digitos(n), que
// devolve a quantidade de dígitos necessários
// para representar um número natural n>=0
// em binário. Por exemplo, a chamada
// qtde_digitos(13) deve devolver a resposta
// 4 (pois 13 em binário é 1101).

int qtde_digitos(int n) {
   if( n<2 ) return 1;
   return (1+ qtde_digitos(n/2));
}

// EXERCÍCIO 3
// Crie a função recursiva hanoi(n), que devolve
// o número mínimo de movimentos necessários para
// resolver o problema das Torres de Hanói com
// n>0 discos.

int hanoi(int n) {
   if( n<2 ) return n;
   return ((2*hanoi(n-1))+1);
}

// EXERCÍCIO 4
// Crie a função recursiva inversa(c,p,u), que
// inverte uma cadeia de caracteres c, cujo primeiro
// caractere está na posição p e cujo último
// caractere está na posição u. Por exemplo, se a
// cadeia c for "amor", após a chamada
// inversa(c,0,3), a cadeia c deverá ser "roma".
// Note que a função deve inverter a cadeia c e
// devolver seu próprio endereço como resposta.

char *inversa(char *c, int p, int u) {
   if( p>=u ) return c;
   char x = c[p];
   c[p] = c[u];
   c[u] = x;
   return inversa(c,p+1,u-1); 
}

// EXERCÍCIO 5
// Crie a função recursiva palindroma(c,p,u), que
// determina se uma cadeia de caracteres c, cujo
// primeiro caractere está na posição p e cujo
// último caractere está na posição u, é palíndroma.
// Espaços em branco devem ser ignorados; por exemplo,
// a chamada palindroma("subi no onibus",0,13) deve
// devolver 1 como resposta.

int palindroma(char *c, int p, int u) {
   if(p>=u) return 1;
   if(c[p]==' ') return palindroma(c,p+1,u);
   if(c[u]==' ') return palindroma(c,p,u-1);
   if(c[p]==c[u]) return palindroma(c,p+1,u-1);
   return 0;
}

int main(void) {
   printf("soma_digitos(   0) = %d\n", soma_digitos(   0));
   printf("soma_digitos(  17) = %d\n", soma_digitos(  17));
   printf("soma_digitos( 859) = %d\n", soma_digitos( 859));
   printf("soma_digitos(1234) = %d\n", soma_digitos(1234));
   printf("\n");
   printf("qtde_digitos(   0) = %d\n", qtde_digitos(   0));
   printf("qtde_digitos(  13) = %d\n", qtde_digitos(  13));
   printf("qtde_digitos( 255) = %d\n", qtde_digitos( 255));
   printf("qtde_digitos(9876) = %d\n", qtde_digitos(9876));
   printf("\n");
   printf("hanoi(0) = %d\n", hanoi(0));
   printf("hanoi(1) = %d\n", hanoi(1));
   printf("hanoi(2) = %d\n", hanoi(2));
   printf("hanoi(3) = %d\n", hanoi(3));
   printf("hanoi(4) = %d\n", hanoi(4));
   printf("\n");
   char c1[5] = "amor";
   char c2[6] = "teste";
   char c3[9] = "maratona";
   char c4[15] = "subi no onibus";
   printf("inversa(c1,0, 3) = %s\n", inversa(c1,0, 3));
   printf("inversa(c2,0, 4) = %s\n", inversa(c2,0, 4));
   printf("inversa(c3,0, 7) = %s\n", inversa(c3,0, 7));
   printf("inversa(c4,0,13) = %s\n", inversa(c4,0,13));
   printf("\n");
   char c5[5] = "amor";
   char c6[6] = "teste";
   char c7[17] = "a sacada da casa";
   char c8[28] = "anotaram a data da maratona";
   printf("palindroma(c5,0, 3) = %d\n", palindroma(c5,0, 3));
   printf("palindroma(c6,0, 5) = %d\n", palindroma(c6,0, 5));
   printf("palindroma(c7,0,15) = %d\n", palindroma(c7,0,15));
   printf("palindroma(c8,0,26) = %d\n", palindroma(c8,0,26));
   return 0;
}
