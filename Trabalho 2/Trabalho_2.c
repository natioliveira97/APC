 /* Natalia Oliviera Borges
    Matricula: 16/0015863
    Algoritmo: Ahmbirinto Gravitacional */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A biblioteca unistd.h foi adicionada para usar a função "sleep" e a biblioteca stdlid.h foi adicionada para usar a funcao "system" */

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

void mostra_matriz_10(char matriz[12][12]) {
    int i,j;
    for (i=0; i<12; ++i) {
        j=0;
        for (j=0; j<12; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void mostra_matriz_15(char matriz[17][17]) {
    int i,j;
    for (i=0; i<17; ++i) {
        j=0;
        for (j=0; j<17; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void mostra_matriz_20(char matriz[22][22]) {
    int i,j;
    for (i=0; i<22; ++i) {
        j=0;
        for (j=0; j<22; ++j) {
            printf("%c ",matriz[i][j]);
        }
        putchar('\n');
    }
}

void parabens(char ahm){
    system("clear");
    printf("Parabéééééééééééééns!!!!!!!!\n");
    printf("Você conseguiu recuperar o seu ahm!\n\n");
    printf("              _______\n");
    printf("             |       |\n");
    printf("             |  ^_^  |\n");
    printf("             | ______|\n");
    printf("             |/\n ");
    printf("            %c\n\n",ahm);
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

char menu_menu(){
    char escolha='3';
    while (escolha!='0' && escolha!='1' && escolha!='2') {
        system("clear");
        printf("*****************************************\n*        AhmBIRINTO GRAVITACIONAL       *\n*****************************************\n\n\n\n\n");
        printf("MENU\n\n");
        printf("1 - Jogar\n\n");
        printf("2 - Configuraçōes\n\n");
        printf("0 - Sair\n\n");
        printf("Sua Escolha:");
        scanf("%c", &escolha);
        while (getchar()!='\n');
        putchar('\n');
        if (escolha!='0' && escolha!='1' && escolha!='2') {
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

int nivel_facil(char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino){
    
    int i,j,sair=0;
    char auxmatriz[12][12],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    char facil[12][12]={{parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede},
                        {parede,ahm,' ',' ',' ',' ',parede,' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',parede,' ',saida,parede},
                        {parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede}};
    
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
        for (i=0; i<12; ++i) {
            for (j=0; j<12; ++j) {
                if (facil[i][j]==ahm && facil[i+1][j]==' '){
                    facil[i][j]=' ';
                    facil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_10(facil);
                    sleep(1);
                }
            }
        }
        for (i=0; i<12; ++i) {
            for (j=0; j<12; ++j) {
                if (facil[i][j]==ahm && facil[i+1][j]==saida){
                    facil[i][j]=' ';
                    facil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_10(facil);
                    sleep(1);
                    sair=1;
                    parabens(ahm);
                    break;
                }
            }
        }
        for (i=0; i<12; ++i) {
            for (j=0; j<12; ++j) {
                auxmatriz[i][j]=facil[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando==aux_sentido_h) {
                for (i=0; i<12; ++i) {
                    for (j=0; j<12; ++j) {
                        facil[i][j]=auxmatriz[11-j][i];
                    }
                }
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<12; ++i) {
                    for (j=0; j<12; ++j) {
                        facil[j][i]=auxmatriz[i][11-j];
                    }
                }
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
    return 0;
}



int nivel_medio(char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino){
    
    int i,j,sair=0;
    char auxmatriz[17][17],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    char medio[17][17]={{parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede},
                        {parede,ahm,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,parede,' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',parede,' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,saida,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                        {parede,parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',parede},
                        {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',parede,parede},
                        {parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede}};
    
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
        for (i=0; i<17; ++i) {
            for (j=0; j<17; ++j) {
                if (medio[i][j]==ahm && medio[i+1][j]==' '){
                    medio[i][j]=' ';
                    medio[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_15(medio);
                    sleep(1);
                }
            }
        }
        for (i=0; i<17; ++i) {
            for (j=0; j<17; ++j) {
                if (medio[i][j]==ahm && medio[i+1][j]==saida){
                    medio[i][j]=' ';
                    medio[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_15(medio);
                    sleep(1);
                    sair=1;
                    parabens(ahm);
                    break;
                }
            }
        }
        for (i=0; i<17; ++i) {
            for (j=0; j<17; ++j) {
                auxmatriz[i][j]=medio[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando== aux_sentido_h) {
                for (i=0; i<17; ++i) {
                    for (j=0; j<17; ++j) {
                        medio[i][j]=auxmatriz[16-j][i];
                    }
                }
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<17; ++i) {
                    for (j=0; j<17; ++j) {
                        medio[j][i]=auxmatriz[i][16-j];
                    }
                }
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
    return 0;
}

int nivel_dificil(char parede, char saida, char ahm, char sentido_h, char sentido_ah,char tecla_de_termino){
    
    int i,j,sair=0;
    char auxmatriz[22][22],comando,aux_sentido_h, aux_sentido_ah,aux_tecla_de_termino;
    char dificil[22][22]={  {parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede},
                            {parede,ahm,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',parede,parede,parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',saida,' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',parede,' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede},
                            {parede,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',parede,parede},
                            {parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede,parede}};
    
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
        for (i=0; i<22; ++i) {
            for (j=0; j<22; ++j) {
                if (dificil[i][j]==ahm && dificil[i+1][j]==' '){
                    dificil[i][j]=' ';
                    dificil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_20(dificil);
                    sleep(1);
                }
            }
        }
        for (i=0; i<22; ++i) {
            for (j=0; j<22; ++j) {
                if (dificil[i][j]==ahm && dificil[i+1][j]==saida){
                    dificil[i][j]=' ';
                    dificil[i+1][j]=ahm;
                    system("clear");
                    mostra_matriz_20(dificil);
                    sleep(1);
                    sair=1;
                    parabens(ahm);
                    break;
                }
            }
        }
        for (i=0; i<22; ++i) {
            for (j=0; j<22; ++j) {
                auxmatriz[i][j]=dificil[i][j];
            }
        }
        if (sair==0) {
            printf("Sua jogada:");
            scanf("%c",&comando);
            while (getchar()!='\n');
            putchar('\n');
            if (comando==sentido_h || comando==aux_sentido_h) {
                for (i=0; i<22; ++i) {
                    for (j=0; j<22; ++j) {
                        dificil[i][j]=auxmatriz[21-j][i];
                    }
                }
            }
            else if (comando==sentido_ah || comando==aux_sentido_ah) {
                for (i=0; i<22; ++i) {
                    for (j=0; j<22; ++j) {
                        dificil[j][i]=auxmatriz[i][21-j];
                    }
                }
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
    return 0;
}

int main(){
    int nivel=10;
    char menu='a',configuracoes,dificuldade,sentido_h='>',sentido_ah='<',tecla_de_termino='x',controle,parede='*',saida='0',visual,ahm='o';

    while (menu!='0') {
        menu=menu_menu();
        while (menu=='1') {
            if (nivel==10) {
                nivel_facil(parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino);
                break;
            }
            if (nivel==15) {
                nivel_medio(parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino);
                break;
            }
            if (nivel==20) {
                nivel_dificil(parede, saida, ahm, sentido_h, sentido_ah, tecla_de_termino);
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
    }
    tchau(ahm);
    return 0;
}
