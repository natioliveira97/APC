/* Aluna: Natalia Oliveira Borges 
   Matricula: 16/0015863
   Algoritmo: Trabalho 1 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/* As bibliotecas <time.h> e <stdlib.h> foram usadar na função "senha" para gerar um numero aleatório. E a biblioteca <locale.h> foi usada para adequar o programa ao português */

int senha(){
    int numero, teste=1000001, tentativas=0;
    
    setlocale(LC_ALL, "Portuguese");
    
    srand( (unsigned)time(NULL) ); /* A função srand é responsável por alimentar a função rand e gerar um número aleatório diferente para cada execução. */
    
    numero = (rand() % 100000)+1 ;/*A função rand cria um número aleatório e foi limitada a criar números até um limite de 100000 usando a função módulo. */
    
    printf("****************\n      Senha \n****************\n\n\n");
    
    printf("Tente adivinhar que número estou pensando! Uma dica, está entre 0 e 100000, incluindo os dois.\n");
    
    while (teste != numero) {
        
        /* Validação de entrada. */
        do {
            teste=100001;
            scanf("%d", &teste);
            while (getchar()!='\n');
            
            if (teste>100000) {
                printf("Essa jogada não vale! Tenta outra vez:\n");
            }
            
        }
        while (teste>100000);
        
        if (teste <0){
            break;
        }
        else if (teste > numero) {
            printf("O número é menor que %d.\n\nOutra vez:\n", teste);
        }
        else if (teste < numero) {
            printf("O número é maior que %d.\n\nOutra vez:\n", teste);
        }
        if (teste>=0) {
            ++tentativas;
        }
        
    }
    if (teste>=0) {
        printf("\nParabéns você resolveu em %d tentativas.\n\n\n\n", tentativas);
    }
    else {
        printf("\nQue pena que você desistiu, o número era %d, e você foi penalisado em 100 tentativas.\nAgora seu número de tentativas é %d.\n\n\n\n", numero, tentativas+100);
        
    }
    
    
    return 0;
    
}



int palitinho(){
    int contador = 10, jogador1, jogador2, auxcontador;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("\n\n\n********************\n     Palitinhos \n********************\n\n\n");
    
    while (contador>0) {
        
        auxcontador=contador;
        
        printf("\n");
        while (auxcontador--) {
            printf("|");
            if (auxcontador>=1) {
                printf(" ");
            }
        }
        printf("\n\n");
        
        /* Validação de entrada para o jogador 1. */
        jogador1=0;
        printf("Jogador 1, sua jogada (1 ou 2):\n");
        scanf("%d",&jogador1);
        while (getchar()!='\n'); /*Essa função foi usada para limpar o buffer, e dessa forma validar a resposta para um inteiro desejado.*/
        
        while (jogador1!=1 && jogador1!=2) {
            printf("Jogada inválida! Jogador 1, sua jogada (1 ou 2):\n");
            scanf("%d",&jogador1);
            while (getchar()!='\n');
            
        }
        
        contador=contador-jogador1;
        if (contador<=0) {
            printf("\nAaaeeeeeeee jogador 1, voce ganhou!!!\n\n\n\n");
            break;
        }
        
        auxcontador=contador;
        
        printf("\n");
        while (auxcontador--) {
            printf("|");
            if (auxcontador>=1) {
                printf(" ");
            }
        }
        printf("\n\n");
        
        /* Validação de entrada para o jogador 2. */
        jogador2=0;
        printf("Jogador 2, sua jogada (1 ou 2):\n");
        scanf("%d",&jogador2);
        while (getchar()!='\n');
        
        while (jogador2!=1 && jogador2!=2) {
            printf("Jogada inválida! Jogador 2, sua jogada (1 ou 2):\n");
            scanf("%d",&jogador2);
            while (getchar()!='\n');
            
        }
        
        contador=contador-jogador2;
        if (contador<=0) {
            printf("\nAaaeeeeeeee jogador 2, voce ganhou!!!\n\n\n\n");
        }
        
    }
    
    return 0;
    
}


int pptls(){
    char jogador1, jogador2, jogador3;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("*************************************\n  Pedra-Papel-Tesoura-Lagarto-Spock \n*************************************\n\n\n");
    printf("p) Pedra\nP) Papel\nT) Tesoura\nL) Lagarto\nS) Spock\n\n");
    
    
    /* Validação de entrada para o jogador 1 */
    printf("Jogador 1, sua jogada:\n");
    scanf("%c", &jogador1);
    while (getchar()!='\n');/*Essa função foi usada para limpar o buffer para validar a entrada do caractere desejado.*/
    
    while (jogador1!='p' && jogador1!= 'P' && jogador1!='T' && jogador1!= 'L' && jogador1!='S'){
        
        printf("Jogada inválida! Jogador 1, sua jogada:\n");
        scanf("%c", &jogador1);
        while (getchar()!='\n');
        
    }
    
    
    /* Validação de entrada para o jogador 2 */
    printf("Jogador 2, sua jogada:\n");
    scanf("%c", &jogador2);
    while (getchar()!='\n');
    
    while (jogador2!='p' && jogador2!= 'P' && jogador2!='T' && jogador2!= 'L' && jogador2!='S'){
        
        printf("Jogada inválida! Jogador 2, sua jogada:\n");
        scanf("%c", &jogador2);
        while (getchar()!='\n');
        
    }
    
    
    /* Validação de entrada para o jogador 3 */
    printf("Jogador 3, sua jogada:\n");
    scanf("%c", &jogador3);
    while (getchar()!='\n');
    
    while (jogador3!='p' && jogador3!= 'P' && jogador3!='T' && jogador3!= 'L' && jogador3!='S'){
        
        printf("Jogada inválida! Jogador 3, sua jogada:\n");
        scanf("%c", &jogador3);
        while (getchar()!='\n');
        
    }
    
    
    
    
    if (jogador1=='p' && jogador2!='P' && jogador2!='S' && jogador3!='P' && jogador3!='S' && jogador2!='p' && jogador3!= 'p'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador2=='L') {
            printf("de Lagarto ");
        }
        else if (jogador2=='T') {
            printf("de Tesoura ");
        }
        if (jogador3=='L') {
            printf("e de Lagarto ");
        }
        else if (jogador3=='T') {
            printf("e de Tesoura ");
        }
        printf("com sua Pedra.\n");
    }
    else if (jogador2=='p' && jogador1!='P' && jogador1!='S' && jogador3!='P' && jogador3!='S' && jogador1!='p' && jogador3!= 'p'){
        printf("Jogador 2, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='L') {
            printf("de Lagarto ");
        }
        else if (jogador1=='T') {
            printf("de Tesoura ");
        }
        if (jogador3=='L') {
            printf("e de Lagarto ");
        }
        else if (jogador3=='T') {
            printf("e de Tesoura ");
        }
        printf("com sua Pedra.\n");
    }
    else if (jogador3=='p' && jogador2!='P' && jogador2!='S' && jogador1!='P' && jogador1!='S' && jogador2!='p' && jogador1!= 'p'){
        printf("Jogador 3, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='L') {
            printf("de Lagarto ");
        }
        else if (jogador1=='T') {
            printf("de Tesoura ");
        }
        if (jogador2=='L') {
            printf("e de Lagarto ");
        }
        else if (jogador2=='T') {
            printf("e de Tesoura ");
        }
        printf("com sua Pedra.\n");
    }
    else if (jogador1=='P' && jogador2!='T' && jogador2!='L' && jogador3!='T' && jogador3!='L' && jogador2!='P' && jogador3!= 'P'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador2=='p') {
            printf("de Pedra ");
        }
        else if (jogador2=='S') {
            printf("de Spock ");
        }
        if (jogador3=='p') {
            printf("e de Pedra ");
        }
        else if (jogador3=='S') {
            printf("e de Spock ");
        }
        printf("com seu Papel.\n");
    }
    else if (jogador2=='P' && jogador1!='T' && jogador1!='L' && jogador3!='T' && jogador3!='L' && jogador1!='P' && jogador3!= 'P'){
        printf("Jogador 2, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='p') {
            printf("de Pedra ");
        }
        else if (jogador1=='S') {
            printf("de Spock ");
        }
        if (jogador3=='p') {
            printf("e de Pedra ");
        }
        else if (jogador3=='S') {
            printf("e de Spock ");
        }
        printf("com seu Papel.\n");
    }
    else if (jogador3=='P' && jogador2!='T' && jogador2!='L' && jogador1!='T' && jogador1!='L' && jogador2!='P' && jogador1!= 'P'){
        printf("Jogador 3, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='p') {
            printf("de Pedra ");
        }
        else if (jogador1=='S') {
            printf("de Spock ");
        }
        if (jogador2=='p') {
            printf("e de Pedra ");
        }
        else if (jogador2=='S') {
            printf("e de Spock ");
        }
        printf("com seu Papel.\n");
    }
    else if (jogador1=='T' && jogador2!='p' && jogador2!='S' && jogador3!='p' && jogador3!='S' && jogador2!='T' && jogador3!= 'T'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador2=='P') {
            printf("de Papel ");
        }
        else if (jogador2=='L') {
            printf("de Lagarto ");
        }
        if (jogador3=='P') {
            printf("e de Papel ");
        }
        else if (jogador3=='L') {
            printf("e de Lagarto ");
        }
        printf("com sua Tesoura.\n");
    }
    else if (jogador2=='T' && jogador1!='p' && jogador1!='S' && jogador3!='p' && jogador3!='S' && jogador1!='T' && jogador3!= 'T'){
        printf("Jogador 2, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='P') {
            printf("de Papel ");
        }
        else if (jogador1=='L') {
            printf("de Lagarto ");
        }
        if (jogador3=='P') {
            printf("e de Papel ");
        }
        else if (jogador3=='L') {
            printf("e de Lagarto ");
        }
        printf("com sua Tesoura.\n");
    }
    else if (jogador3=='T' && jogador2!='p' && jogador2!='S' && jogador1!='p' && jogador1!='S' && jogador2!='T' && jogador1!= 'T'){
        printf("Jogador 3, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='P') {
            printf("de Papel ");
        }
        else if (jogador1=='L') {
            printf("de Lagarto ");
        }
        if (jogador2=='P') {
            printf("e de Papel ");
        }
        else if (jogador2=='L') {
            printf("e de Lagarto ");
        }
        printf("com sua Tesoura.\n");
    }
    else if (jogador1=='L' && jogador2!='T' && jogador2!='p' && jogador3!='T' && jogador3!='p' && jogador2!='L' && jogador3!= 'L'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador2=='P') {
            printf("de Papel ");
        }
        else if (jogador2=='S') {
            printf("de Spock ");
        }
        if (jogador3=='P') {
            printf("e de Papel ");
        }
        else if (jogador3=='S') {
            printf("e de spock ");
        }
        printf("com seu Lagarto.\n");
    }
    else if (jogador2=='L' && jogador1!='T' && jogador1!='p' && jogador3!='T' && jogador3!='p' && jogador1!='L' && jogador3!= 'L'){
        printf("Jogador 2, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='P') {
            printf("de Papel ");
        }
        else if (jogador1=='S') {
            printf("de Spock ");
        }
        if (jogador3=='P') {
            printf("e de Papel ");
        }
        else if (jogador3=='S') {
            printf("e de spock ");
        }
        printf("com seu Lagarto.\n");
    }
    else if (jogador3=='L' && jogador2!='T' && jogador2!='p' && jogador1!='T' && jogador1!='p' && jogador2!='L' && jogador1!= 'L'){
        printf("Jogador 3, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='P') {
            printf("de Papel ");
        }
        else if (jogador1=='S') {
            printf("de Spock ");
        }
        if (jogador2=='P') {
            printf("e de Papel ");
        }
        else if (jogador2=='S') {
            printf("e de Spock ");
        }
        printf("com seu Lagarto.\n");
    }
    else if (jogador1=='S' && jogador2!='P' && jogador2!='L' && jogador3!='P' && jogador3!='L' && jogador2!='S' && jogador3!= 'S'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador2=='T') {
            printf("de Tesoura ");
        }
        else if (jogador2=='p') {
            printf("de Pedra ");
        }
        if (jogador3=='T') {
            printf("e de Tesoura ");
        }
        else if (jogador3=='p') {
            printf("e de Pedra ");
        }
        printf("com seu Spock.\n");
    }
    else if (jogador2=='S' && jogador1!='P' && jogador1!='L' && jogador3!='P' && jogador3!='L' && jogador1!='S' && jogador3!= 'S'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='T') {
            printf("de Tesoura ");
        }
        else if (jogador1=='p') {
            printf("de Pedra ");
        }
        if (jogador3=='T') {
            printf("e de Tesoura ");
        }
        else if (jogador3=='p') {
            printf("e de Pedra ");
        }
        printf("com seu Spock.\n");
    }
    else if (jogador3=='S' && jogador2!='P' && jogador2!='L' && jogador1!='P' && jogador1!='L' && jogador2!='S' && jogador1!= 'S'){
        printf("Jogador 1, aaaaaaeeeee, vc ganhou ");
        if (jogador1=='T') {
            printf("de Tesoura ");
        }
        else if (jogador1=='p') {
            printf("de Pedra ");
        }
        if (jogador2=='T') {
            printf("e de Tesoura ");
        }
        else if (jogador2=='p') {
            printf("e de Pedra ");
        }
        printf("com seu Spock.\n");
    }
    else {
        printf("Empatou! Vamos jogar outra vez.\n\n\n");
        pptls();/*Uso de recursividade para começar novamente o jogo no caso de empate.*/
        
    }
    
    return 0;
    
}







int main(){
    char escolha=0;
    
    while (escolha!='4') {
        
        printf("********************\n      JOGUINHOS\n********************\n");
        printf("Menu:\n\t1) Senha\n\t2) Palitinhos\n\t3) Pedra-Papel-Tesoura-Lagarto-Spock\n\t4) Sair\n");
        printf("Digite sua escolha:\n");
        
        escolha=getchar();
        while (getchar()!='\n');
    
    
        while (escolha!='1' && escolha!='2' && escolha!= '3' && escolha!='4') {
        
            printf("Isso não é uma opção! Digite outra vez:\n");
            escolha=getchar();
            while (getchar()!='\n');
        }
    
        switch (escolha) {
            case '1':
                printf("\n\n\n");
                senha();
                break;
            case '2':
                printf("\n\n\n");
                palitinho();
                break;
            case '3':
                printf("\n\n\n");
                pptls();
                break;
            case '4':
                break;
            default:
            break;
        }
    }
    return 0;
    
    
}