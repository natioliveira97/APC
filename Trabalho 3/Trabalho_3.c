/* Natalia Oliviera Borges
   Matricula: 16/0015863
   Algoritmo: Ahmbirinto Gravitacional com Placar*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A biblioteca unistd.h foi adicionada para usar a função "sleep" e a biblioteca stdlid.h foi adicionada para usar a funcao "system" */

/* 
 facil.txt
 ############
 #@#    #   #
 # # #      #
 #     #    #
 ##         #
 #          #
 #     X    #
 #  #    #  #
 #          #
 #    #     #
 #          #
 ############
 
 medio.txt
 #################
 # #    #        #
 #   #      #   ##
 #     #         #
 ##      #       #
 #  #   #   #    #
 #@              #
 #  #    #    #  #
 #               #
 #    #     #    #
 #    #      #   #
 #    #    #     #
 #    #          #
 #    #          #
 #    #          #
 #         #X    #
 #################

 dificil.txt
 ######################
 # #     #      #     #
 #   #      #        ##
 #     #  #    ###    #
 #     #  #      #  # #
 #    #   #      #    #
 # #    # #      #    #
 ##       ##        # #
 #  #   #   #       # #
 #@       #     #   # #
 # #    # #     #     #
 #  #    #    #       #
 #      #   #     #   #
 #### # #   #     ##  #
 # #        #         #
 #  #####   #    ###  #
 #    #   ##   ##     #
 #    #      #        #
 #    #      #  ##### #
 #    #    #       #  #
 #        #X   #   #  #
 ######################
*/

#define FACIL 12
#define MEDIO 17
#define DIFICIL 22

typedef struct{
    char nome[30];
    char jogo[20];
    int jogadas;
    
}resultado;

char decisao(){
    char escolha='\n';
    while (escolha=='\n') {
        scanf("%c",&escolha);
        while (getchar()!='\n');
    }
    return escolha;
}

char caixa_alta_ou_baixa(char caracter){
    char auxcaracter;
    
    if (caracter>='A' && caracter<='Z') {
        auxcaracter=caracter+('a'-'A');
    }
    else if (caracter>='a' && caracter<='z') {
        auxcaracter=caracter+('A'-'a');
    }
    else {
        auxcaracter=caracter;
    }
    return auxcaracter;
}

void mostra_matriz_10(char matriz[FACIL][FACIL]) {
    int i,j;
    for (i=0; i<FACIL; ++i) {
        j=0;
        for (j=0; j<FACIL; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void mostra_matriz_15(char matriz[MEDIO][MEDIO]) {
    int i,j;
    for (i=0; i<MEDIO; ++i) {
        j=0;
        for (j=0; j<MEDIO; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void mostra_matriz_20(char matriz[DIFICIL][DIFICIL]) {
    int i,j;
    for (i=0; i<DIFICIL; ++i) {
        j=0;
        for (j=0; j<DIFICIL; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void parabens(char ahm, char *arquivo, int jogadas,char *registro){
    char c='a';
    int i=1,j=0,k;
    FILE *fp;
    resultado placar[10];
    
    for (j=0; j<20; ++j) {
        placar[0].jogo[j]='\0';
    }
    
    system("clear");
    printf("Parabéééééééééééééns!!!!!!!!\n");
    printf("Você conseguiu recuperar o seu ahm!\n\n");
    printf("              _______\n");
    printf("             |       |\n");
    printf("             |  ^_^  |\n");
    printf("             | ______|\n");
    printf("             |/\n ");
    printf("            %c\n\n\n",ahm);

    fp = fopen(registro, "r");
    if (!fp) {
        printf("Não foi possível realizar a tarefa\n");
        return;
    }
    while (fread(&c, sizeof(c),1,fp)==1 && i<10) {
        j=1;
        placar[i].nome[0]=c;
        while(c!='\0'){
            fread(&c, sizeof(c),1,fp);
            placar[i].nome[j]=c;
            ++j;
        }
        c='a';
        j=0;
        while(c!='\0'){
            fread(&c, sizeof(c),1,fp);
            placar[i].jogo[j]=c;
            ++j;
        }
        fread(&placar[i].jogadas, sizeof(placar[i].jogadas), 1, fp);
        ++i;
    }
    fclose(fp);
    
    printf("Escreva seu nome:");
    scanf("%29[^\n]s", placar[0].nome);
    while (getchar()!='\n');
    for (j=0; arquivo[j]!='\0'; ++j) {
        placar[0].jogo[j]=arquivo[j];
    }
    placar[0].jogadas=jogadas;
    
    fp = fopen(registro, "wb+");
    if (!fp) {
        printf("Não foi possível realizar a tarefa\n");
        return;
    }
    j=0;
    while (j<i){
        k=0;
        while (placar[j].nome[k]!='\0') {
            fwrite(&placar[j].nome[k], sizeof(placar[j].nome[k]), 1, fp);
            ++k;
        }
        fwrite(&placar[j].nome[k], sizeof(placar[j].nome[k]), 1, fp);
        k=0;
        while (placar[j].jogo[k]!='\0') {
            fwrite(&placar[j].jogo[k], sizeof(placar[j].jogo[k]), 1, fp);
            ++k;
        }
        fwrite(&placar[j].jogo[k], sizeof(placar[j].jogo[k]), 1, fp);
        fwrite(&placar[j].jogadas, sizeof(placar[j].jogadas), 1, fp);
        ++j;
    }
    fclose(fp);
    
    printf("Aperte 'enter' para voltar:\n");
    while (getchar()!='\n');
}

void desistiu(char ahm){
    system("clear");
    printf("Aaaaaaaaaaaaaah nããããããããããão!!!!!!!!\n");
    printf("Você desistiu de recuperar o seu ahm!\n\n");
    printf("              _______\n");
    printf("             |       |\n");
    printf("             |  ;_;  |\n");
    printf("             | ______|\n");
    printf("             |/\n ");
    printf("            %c\n\n",ahm);
    printf("Aperte 'enter' para voltar:\n");
    while (getchar()!='\n');
}

void tchau(char ahm){
    system("clear");
    printf("Aaaaaah você já vai!!!!!\n");
    printf("Eu vou ficar com muita saudade! Volta logo!\n\n");
    printf("              _______\n");
    printf("             |       |\n");
    printf("             |  *_*  |\n");
    printf("             | ______|\n");
    printf("             |/\n ");
    printf("            %c\n\n",ahm);
}

char validacao(char teste, char caracter1, char caracter2, char caracter3, char caracter4,char caracter5){
    char auxcaracter1,auxcaracter2,auxcaracter3,auxcaracter4,auxcaracter5;
    
    auxcaracter1=caixa_alta_ou_baixa(caracter1);
    auxcaracter2=caixa_alta_ou_baixa(caracter2);
    auxcaracter3=caixa_alta_ou_baixa(caracter3);
    auxcaracter4=caixa_alta_ou_baixa(caracter4);
    auxcaracter5=caixa_alta_ou_baixa(caracter5);
    
    teste=decisao();
    putchar('\n');
    while (teste==caracter1 || teste==caracter2 || teste==caracter3 || teste==caracter4 || teste==caracter5 || teste==auxcaracter1 || teste==auxcaracter2 || teste==auxcaracter3 || teste==auxcaracter4 || teste==auxcaracter5 || teste==' ' || teste=='\n') {
        printf("Esse caractere não pode, escolha outro:");
        teste=decisao();
        putchar('\n');
    }
    return teste;
}

int nivel_facil(char facil[FACIL][FACIL],char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino,char *arquivo, char *registro){
    int i,j,sair=0,jogadas=0;
    char auxmatriz[FACIL][FACIL],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    
    aux_sentido_h=caixa_alta_ou_baixa(sentido_h);
    aux_sentido_ah=caixa_alta_ou_baixa(sentido_ah);
    aux_tecla_de_termino=caixa_alta_ou_baixa(tecla_de_termino);
    
    system("clear");
    mostra_matriz_10(facil);
    printf("Aperte 'enter' para começar:");
    while (getchar()!='\n');
    putchar('\n');
    system("clear");
    
    while (sair==0) {
        system("clear");
        mostra_matriz_10(facil);
        sleep(1);
        for (i=0; i<FACIL; ++i) {
            for (j=0; j<FACIL; ++j) {
                if (facil[i][j]==ahm && facil[i+1][j]==' '){
                    facil[i][j]=' ';
                    facil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_10(facil);
                    sleep(1);
                }
            }
        }
        for (i=0; i<FACIL; ++i) {
            for (j=0; j<FACIL; ++j) {
                if (facil[i][j]==ahm && facil[i+1][j]==saida){
                    facil[i][j]=' ';
                    facil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_10(facil);
                    sleep(1);
                    sair=1;
                    parabens(ahm,arquivo,jogadas,registro);
                    break;
                }
            }
        }
        for (i=0; i<FACIL; ++i) {
            for (j=0; j<FACIL; ++j) {
                auxmatriz[i][j]=facil[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando==aux_sentido_h) {
                for (i=0; i<FACIL; ++i) {
                    for (j=0; j<FACIL; ++j) {
                        facil[i][j]=auxmatriz[11-j][i];
                    }
                }
                ++jogadas;
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<FACIL; ++i) {
                    for (j=0; j<FACIL; ++j) {
                        facil[j][i]=auxmatriz[i][11-j];
                    }
                }
                ++jogadas;
            }
            else if (comando==tecla_de_termino || comando==aux_tecla_de_termino){
                desistiu(ahm);
                sair=1;
                break;
            }
            else {
                system("clear");
                printf("Comando inválido, tente novamente\n");
                sleep(2);
            }
        }
    }
    return jogadas;
}

int nivel_medio(char medio[MEDIO][MEDIO],char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino,char *arquivo,char *registro){
    int i,j,sair=0,jogadas=0;
    char auxmatriz[MEDIO][MEDIO],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    
    aux_sentido_h=caixa_alta_ou_baixa(sentido_h);
    aux_sentido_ah=caixa_alta_ou_baixa(sentido_ah);
    aux_tecla_de_termino=caixa_alta_ou_baixa(tecla_de_termino);
    
    system("clear");
    mostra_matriz_15(medio);
    printf("Aperte 'enter' para começar:");
    while (getchar()!='\n');
    putchar('\n');
    system("clear");
    
    while (sair==0) {
        system("clear");
        mostra_matriz_15(medio);
        sleep(1);
        for (i=0; i<MEDIO; ++i) {
            for (j=0; j<MEDIO; ++j) {
                if (medio[i][j]==ahm && medio[i+1][j]==' '){
                    medio[i][j]=' ';
                    medio[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_15(medio);
                    sleep(1);
                }
            }
        }
        for (i=0; i<MEDIO; ++i) {
            for (j=0; j<MEDIO; ++j) {
                if (medio[i][j]==ahm && medio[i+1][j]==saida){
                    medio[i][j]=' ';
                    medio[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_15(medio);
                    sleep(1);
                    sair=1;
                    parabens(ahm,arquivo,jogadas,registro);
                    break;
                }
            }
        }
        for (i=0; i<MEDIO; ++i) {
            for (j=0; j<MEDIO; ++j) {
                auxmatriz[i][j]=medio[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando== aux_sentido_h) {
                for (i=0; i<MEDIO; ++i) {
                    for (j=0; j<MEDIO; ++j) {
                        medio[i][j]=auxmatriz[16-j][i];
                    }
                }
                ++jogadas;
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<MEDIO; ++i) {
                    for (j=0; j<MEDIO; ++j) {
                        medio[j][i]=auxmatriz[i][16-j];
                    }
                }
                ++jogadas;
            }
            else if (comando==tecla_de_termino || comando==aux_tecla_de_termino){
                desistiu(ahm);
                sair=1;
                break;
            }
            else {
                system("clear");
                printf("Comando inválido, tente novamente\n");
                sleep(2);
            }
        }
    }
    return jogadas;
}

int nivel_dificil(char dificil[DIFICIL][DIFICIL],char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino,char *arquivo,char *registro){
    int i,j,sair=0,jogadas=0;
    char auxmatriz[DIFICIL][DIFICIL],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    
    aux_sentido_h=caixa_alta_ou_baixa(sentido_h);
    aux_sentido_ah=caixa_alta_ou_baixa(sentido_ah);
    aux_tecla_de_termino=caixa_alta_ou_baixa(tecla_de_termino);
    
    system("clear");
    mostra_matriz_20(dificil);
    printf("Aperte 'enter' para começar:");
    while (getchar()!='\n');
    putchar('\n');
    system("clear");
    
    while (sair==0) {
        system("clear");
        mostra_matriz_20(dificil);
        sleep(1);
        for (i=0; i<DIFICIL; ++i) {
            for (j=0; j<DIFICIL; ++j) {
                if (dificil[i][j]==ahm && dificil[i+1][j]==' '){
                    dificil[i][j]=' ';
                    dificil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_20(dificil);
                    sleep(1);
                }
            }
        }
        for (i=0; i<DIFICIL; ++i) {
            for (j=0; j<DIFICIL; ++j) {
                if (dificil[i][j]==ahm && dificil[i+1][j]==saida){
                    dificil[i][j]=' ';
                    dificil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_20(dificil);
                    sleep(1);
                    sair=1;
                    parabens(ahm,arquivo,jogadas,registro);
                    break;
                }
            }
        }
        for (i=0; i<DIFICIL; ++i) {
            for (j=0; j<DIFICIL; ++j) {
                auxmatriz[i][j]=dificil[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando==aux_sentido_h) {
                for (i=0; i<DIFICIL; ++i) {
                    for (j=0; j<DIFICIL; ++j) {
                        dificil[i][j]=auxmatriz[21-j][i];
                    }
                }
                ++jogadas;
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<DIFICIL; ++i) {
                    for (j=0; j<DIFICIL; ++j) {
                        dificil[j][i]=auxmatriz[i][21-j];
                    }
                }
                ++jogadas;
            }
            else if (comando==tecla_de_termino || comando==aux_tecla_de_termino){
                desistiu(ahm);
                sair=1;
                break;
            }
            else {
                system("clear");
                printf("Comando inválido, tente novamente\n");
                sleep(2);
            }
        }
    }
    return jogadas;
}

int abre_facil(char *arquivo,char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino, char *registro) {
    int i,j;
    char facil[FACIL][FACIL],arquivo_facil[FACIL][FACIL+1];
    
    FILE *fp = fopen(arquivo, "r");
    if(!fp){
        printf("Não foi possível abrir o labirinto\n");
        sleep(2);
        return EXIT_FAILURE;
    }
    fread(arquivo_facil, sizeof(arquivo_facil), 1, fp);
    fclose(fp);
    
    for (i=0; i<FACIL; ++i) {
        for (j=0; j<FACIL; ++j) {
            if (arquivo_facil[i][j]=='#') {
                facil[i][j]=parede;
            }
            else if (arquivo_facil[i][j]=='X') {
                facil[i][j]=saida;
            }
            else if (arquivo_facil[i][j]=='@') {
                facil[i][j]=ahm;
            }
            else
                facil[i][j]=' ';
        }
    }
    return nivel_facil(facil,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,arquivo,registro);
}

int abre_medio(char *arquivo,char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino,char *registro) {
    int i,j;
    char medio[MEDIO][MEDIO],arquivo_medio [MEDIO][MEDIO+1];
    
    FILE *fp = fopen(arquivo, "r");
    if(!fp){
        printf("Não foi possível abrir o labirinto\n");
        sleep(2);
        return EXIT_FAILURE;
    }
    fread(arquivo_medio, sizeof(arquivo_medio), 1, fp);
    fclose(fp);
    
    for (i=0; i<MEDIO; ++i) {
        for (j=0; j<MEDIO; ++j) {
            if (arquivo_medio[i][j]=='#') {
                medio[i][j]=parede;
            }
            else if (arquivo_medio[i][j]=='X') {
                medio[i][j]=saida;
            }
            else if (arquivo_medio[i][j]=='@') {
                medio[i][j]=ahm;
            }
            else
                medio[i][j]=' ';
        }
    }
    return nivel_medio(medio,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,arquivo,registro);
}

int abre_dificil(char *arquivo,char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino, char *registro) {
    int i,j;
    char dificil[DIFICIL][DIFICIL],arquivo_dificil [DIFICIL][DIFICIL+1];
    
    FILE *fp = fopen(arquivo, "r");
    if(!fp){
        printf("Não foi possível abrir o labirinto\n");
        sleep(2);
        return EXIT_FAILURE;
    }
    fread(arquivo_dificil, sizeof(arquivo_dificil), 1, fp);
    fclose(fp);
    
    for (i=0; i<DIFICIL; ++i) {
        for (j=0; j<DIFICIL; ++j) {
            if (arquivo_dificil[i][j]=='#') {
                dificil[i][j]=parede;
            }
            else if (arquivo_dificil[i][j]=='X') {
                dificil[i][j]=saida;
            }
            else if (arquivo_dificil[i][j]=='@') {
                dificil[i][j]=ahm;
            }
            else
                dificil[i][j]=' ';
        }
    }
    return nivel_dificil(dificil,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,arquivo,registro);
}

char menu_menu(){
    char escolha='4';
    
    while (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
        system("clear");
        printf("*****************************************\n*        AhmBIRINTO GRAVITACIONAL       *\n*****************************************\n\n\n\n\n");
        printf("MENU\n\n");
        printf("1 - Jogar\n\n");
        printf("2 - Configuraçōes\n\n");
        printf("3 - Placar\n\n");
        printf("0 - Sair\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
            system("clear");
            printf("Essa opção não existe, pode escolher outra!\n");
            sleep(2);
        }
    }
    return escolha;
}

char menu_configuracoes(){
    char escolha='4';
   
    while (escolha!='1' && escolha!='2' && escolha!='3' && escolha!='0') {
        system("clear");
        printf("CONFIGURAÇÕES\n\n");
        printf("1 - Dificuldade\n\n");
        printf("2 - Controles\n\n");
        printf("3 - Configuração Visual\n\n");
        printf("0 - Voltar\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
            system("clear");
            printf("Essa opção não existe, pode escolher outra!\n");
            sleep(2);
        }
    }
    return escolha;
}

char menu_configuracoes_de_dificuldade(int nivel){
    char escolha='4';
    
    while (escolha!='1' && escolha!='2' && escolha!='3' && escolha!='0') {
        system("clear");
        printf("DIFICULDADE\n");
        printf("1 - Fácil (10x10) ");
        if (nivel==10) {
            printf("<-");
        }
        printf("\n\n2 - Médio (15X15) ");
        if (nivel==15) {
            printf("<-");
        }
        printf("\n\n3 - Díficil (20x20) ");
        if (nivel==20) {
            printf("<-");
        }
        printf("\n\n0 - Voltar\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
            system("clear");
            printf("Essa opção não existe, pode escolher outra!\n");
            sleep(2);
        }
    }
    return escolha;
}

char menu_configuracoes_de_controle(char sentido_h,char sentido_ah, char tecla_de_termino){
    char escolha='4';
    
    while (escolha!='1' && escolha!='2' && escolha!='3' && escolha!='0') {
        system("clear");
        printf("CONTROLES\n\n");
        printf("1 - Sentido Horário: %c\n\n", sentido_h);
        printf("2 - Sentido Anti-horário: %c\n\n", sentido_ah);
        printf("3 - Tecla de Término: %c\n\n", tecla_de_termino);
        printf("0 - Voltar\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
            system("clear");
            printf("Essa opção não existe, pode escolher outra!\n");
            sleep(2);
        }
    }
    return escolha;
}


char menu_configuracoes_de_visual(char parede,char saida,char ahm){
    char escolha='4';
    
    while (escolha!='1' && escolha!='2' && escolha!='3' && escolha!='0') {
        system("clear");
        printf("CONTROLES\n\n");
        printf("1 - Parede: %c\n\n", parede);
        printf("2 - Saída: %c\n\n",saida);
        printf("3 - Ahm: %c\n\n",ahm);
        printf("0 - Voltar\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2' && escolha!='3') {
            system("clear");
            printf("Essa opção não existe, pode escolher outra!\n");
            sleep(2);
        }
    }
    return escolha;
}

void menu_placar(char *registro){
    int i=0,j=0;
    char c,nome[]="NOME", jogo[]="JOGO", jogadas[]="JOGADAS";
    FILE *fp;
    resultado placar[10];
    
    fp = fopen(registro, "r");
    if (!fp) {
        printf("Não foi possível realizar a tarefa\n");
        return;
    }
    while (fread(&c, sizeof(c),1,fp)==1) {
        j=1;
        placar[i].nome[0]=c;
        while(c!='\0'){
            fread(&c, sizeof(c),1,fp);
            placar[i].nome[j]=c;
            ++j;
        }
        c='a';
        j=0;
        while(c!='\0'){
            fread(&c, sizeof(c),1,fp);
            placar[i].jogo[j]=c;
            ++j;
        }
        fread(&placar[i].jogadas, sizeof(placar[i].jogadas), 1, fp);
        ++i;
    }
    fclose(fp);
    
    system("clear");
    printf("PLACAR\n\n");
    if (i==0) {
        printf("Não houve jogos\n");
    }
    else{
        printf("%-30s |%-20s |%-10s\n", nome,jogo,jogadas);
        for (j=0; j<i; ++j) {
            printf("%-30s |%-20s |%d\n",placar[j].nome, placar[j].jogo, placar[j].jogadas);
        }
    }
    printf("\nAperte 'enter' para sair\n");
    while (getchar()!='\n');
}

int main(){
    int nivel=10,jogadas;
    char menu='a',configuracoes,dificuldade,sentido_h='>',sentido_ah='<',tecla_de_termino='x',controle,parede='*',saida='0',visual,ahm='o';
    char arquivo1[] = "facil.txt";
    char arquivo2[] = "medio.txt";
    char arquivo3[] = "dificil.txt";
    char registro[] = "registro.bin";
    
    FILE *fp;
    fp = fopen(registro, "wb+");
    if (!fp) {
        printf("Não foi possível realizar a tarefa\n");
        return EXIT_FAILURE;
    }
    fclose(fp);
    
    while (menu!='0') {
        menu=menu_menu();
        while (menu=='1') {
            if (nivel==10) {
                jogadas=abre_facil(arquivo1,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,registro);
                break;
            }
            if (nivel==15) {
                jogadas=abre_medio(arquivo2,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,registro);
                break;
            }
            if (nivel==20) {
                jogadas=abre_dificil(arquivo3,parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino,registro);
                break;
            }
        }
        while (menu=='2') {
            configuracoes=menu_configuracoes();
            while(configuracoes=='1'){
                dificuldade=menu_configuracoes_de_dificuldade(nivel);
                if (dificuldade=='1') {
                    nivel=10;
                }
                if (dificuldade=='2') {
                    nivel=15;
                }
                if (dificuldade=='3') {
                    nivel=20;
                }
                if (dificuldade=='0') {
                    break;
                }
            }
            while (configuracoes=='2') {
                controle=menu_configuracoes_de_controle(sentido_h,sentido_ah,tecla_de_termino);
                if (controle=='1') {
                    printf("Qual tecla você quer para o sentido horário:");
                    sentido_h=validacao(sentido_h, sentido_ah, tecla_de_termino, parede, saida, ahm);
                }
                if (controle=='2') {
                    printf("Qual tecla você quer para o sentido anti-horário:");
                    sentido_ah=validacao(sentido_ah, sentido_h, tecla_de_termino, parede, saida, ahm);
                }
                if (controle=='3') {
                    printf("Qual tecla você quer para a tecla de término:");
                    tecla_de_termino=validacao(tecla_de_termino, sentido_ah, sentido_h, parede, saida, ahm);
                }
                if (controle=='0') {
                    break;
                }
            }
            while (configuracoes=='3') {
                visual=menu_configuracoes_de_visual(parede, saida,ahm);
                if (visual=='1') {
                    printf("Qual tecla você quer para parede:");
                    parede=validacao(parede, sentido_ah, tecla_de_termino,sentido_h, saida, ahm);
                }
                if (visual=='2') {
                    printf("Qual tecla você quer para saída:");
                    saida=validacao(saida, sentido_ah, tecla_de_termino, parede, sentido_h, ahm);
                }
                if (visual=='3') {
                    printf("Qual tecla você quer para o ahm:");
                    ahm=validacao(ahm, sentido_ah, tecla_de_termino, parede, saida, sentido_h);
                }
                if (visual=='0') {
                    break;
                }
            }
            if (configuracoes=='0') {
                break;
            }
        }
        while (menu=='3'){
            menu_placar(registro);
            break;
        }
    }
    tchau(ahm);
    return 0;
}
