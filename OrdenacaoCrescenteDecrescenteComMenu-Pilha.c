#include <stdio.h>
#include "pilha.h" 
#include <string.h>

// recebe o vetor e verifica quantos digitos tem no total, acrescenta o deslocamento de um espaço e devolve pra alocar na memoria esse espaço 
int contatamanho(int numero[], int qtd){
    int r = 1;
    int c = 0;
    int n = 1;
    int total = 0; 
    for (int a=0; a<qtd; a++){
        n = numero[a];

        while (r!=0) {
        r=n/10;
        n=n/10; 
        c+=1;
                     }
     
     total += c + 1; //mais um pra alocar o espaço pós-numero
        c = 0; r= 1; 
                          }

printf("\ntotal de digitos p alocar string: %d\n",total);
    return (total);
}

// recebe um numero e retorna quantos digitos ele tem (correspondente ao deslocamento na string)  
int contaumavariavel (int numero){
    int r = 1;
    int c = 0;
    int n = numero;
     while (r!=0) {
        r=n/10;
        n=n/10; 
        c+=1;
                     }
    printf("deslocamento do numero %d: %d\n",numero,c);
    return c; 
}

// ordena o vetor usando pilha com os numeros do input e retorna uma string com os valores e espaços 
char *ordena(int numero[], int qtd, int opc, int opcc) {    

    Pilha a = pilha(qtd); //pilha que vai ficar ordenada 
    Pilha b = pilha(qtd); //pilha de manobra 

    char *ordenada = (char *) malloc((contatamanho(numero,qtd))*sizeof(char)); //array de string que vai ser retornada contendo os numeros ordenados, vai alocar a quantidade de digitos total q tem digitado no vetor + 1 espaço após cada um

    //percorrer array de int
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

//taca a resposta da pilha a na string agora....
//a pilha o topo eh o menor numero, entao quando eu for desempilhar, o menor numero vai ficar no começo da string, entao a ideia no final eh retornar ordem decrescente, do maior pro menor 
    int ss = 0;
    while (!vaziap(a)){ //na pilha a ta ordenado, o topo eh o menor numero entao ENQUANTO a pilha A tiver coisa 
        //vai guardando na string o numero do topo e depois um espaço
         int x = desempilha(a);
        sprintf(&ordenada[ss],"%d ",x);
        //agora preciso saber quantas posicoes aquele numero ocupou na string, e deslocar array de string p nao subscrever
        ss += (contaumavariavel(x)+1); //+1 pq tem q deslocar o espaço... senao vai sobrescrever no espaço 
    }
   
    ordenada[ss] = '\0'; //sobrescreve o ultimo espaço com \0

    //destroi as pilhas
    destroip(&a);
    destroip(&b); 
    return ordenada; 
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

    printf("A ordem fica: %s",ordena(numero,qtd,opc,opcc)); 
    return 0;
}




