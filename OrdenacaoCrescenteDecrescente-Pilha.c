
#include <stdio.h>
#include "pilha.h" 
#include <string.h>


void ordena(int numero[], int qtd, int opc, int opcc) {    

    Pilha a = pilha(qtd); //pilha que vai ficar ordenada 
    Pilha b = pilha(qtd); //pilha de manobra 

    //percorrer array de int c os numeros do usuário
    for (int aa=0;aa<qtd; aa++) { 
        
        switch (opc) 
        { 
            case 1: { while (!vaziap(a) && numero[aa]>topo(a)) //crescente
            empilha(desempilha(a),b); // enquanto pilha a tiver coisa e aquele numero for maior do q o topo, tira do a e poe no b -- se a pilha tiver vazia portanto a primeira preposicao vai ser falsa, aí posso empilhar no a pq eh o primeiro numero da array provavelmente kkk
            break; 
            }
            case 2:  { while (!vaziap(a) && numero[aa]<topo(a)) //decrescente
            empilha(desempilha(a),b);
            break; 
            }
        }
       
        
        switch (opcc)
        {
            case 1: if (vaziap(a) || numero[aa]!=topo(a))  empilha(numero[aa],a); // SEM REPETIÇÃO
        //so vou empilhar se nao for repetido o numero, se for igual vamos IGNORAR 
        // entao ou seja eu so vou empilhar qd 
        // estiver vazia pq ai eh o primeiro numero da array q to vendo 
        // ou topo for diferente do numero q to avaliando na array afinal estamos ANILIQUILANDO a repetiçao 
        // se for IGUAL ele tem q SEGUIR A VIDA passar pro proximo, BOLA PRA FRENTE 
        break; 

            case 2: empilha(numero[aa],a); //com repetição 
        }

         //agora q empilhei o numero no a, volto todos os numeros q estavam na pilha de manobra b ate o b ficar vazio, antes de continuar percorrendo a array 
        while(!vaziap(b)) empilha(desempilha(b),a); // se a pilha b tiver VAZIA, ele vai ignorar e muito que BEM vida q SEGUE 
    }

    int bb = 0;
        puts("\nDESEMPILHADO:");
    while (!vaziap(a)) { //na pilha a ta ordenado, o topo eh o menor numero
         printf(" \n %d ",desempilha(a));
        bb++;
    }
    //destroi as pilhas
    destroip(&a);
    destroip(&b); 
}



int main (void) {
    printf("quantos numeros voce quer ordenar?\n"); 
    int qtd; 
    scanf("%d",&qtd);

    int numero[qtd]; //array de NUMEROS inteiros q a pessoa vai colocar c quantidade q ela disse

     for (int z=0; z<qtd; z++){ 
        printf("digite o %do numero: \n",z+1);
        scanf("%d",&numero[z]);    // guardando no array de inteiros todos os numeros q a pessoa colocou
    }

    puts("\nqual ordem vc quer? 1) crescente 2) decrescente"); 
    int opc;
    scanf("%d",&opc);
    
    puts("\nquer tirar os numeros repetidos? 1) sim, tirar repeticoes 2) nao, manter numeros repetidos");
    int opcc;
    scanf("%d",&opcc);

    ordena(numero,qtd,opc,opcc); 
    return 0;
}


