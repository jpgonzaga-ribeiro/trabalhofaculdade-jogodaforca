#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int main()
{
    char vetFrutas[][100]=
    {
        "morango", "kiwi", "banana", "melancia", "abacaxi", "abacate", "amora", "caju", "carambola", "cacau", "goiaba", "graviola", "groselha", "maca", "pera", "uva", "jabuticaba", "jambo", "limao", "laranja"
    };

    char vetFrutasd1[][100]=
    {
        "hmmm bolo de ...", "barulho q o trem faz", "macaco gosta de...", "e redonda mas no japao existe quadrada", "tem coroa", "guacamole", "namora", "caduu", "carambolas", "um show de fruta", "goiabada", "tem viola", "talkshow", "bom pra garganta mas sem cedilha", "para", "scar light de uva", "jabutiranha", "jambosta", "azedo", "cor laranja"
    };
    char vetFrutasd2[][100]=
    {
        "hmmm bolo de ...", "barulho q o trem faz", "macaco gosta de ...", "e redonda mas no japao existe quadrada", "tem coroa", "guacamole", "namora", "caduu", "carambolas", "um show de fruta", "goiabada", "tem viola", "talkshow", "bom pra garganta mas sem cedilha", "para", "scar light de uva", "jabutiranha", "jambosta", "azedo", "cor laranja"
    };
    char vetFrutasd3[][100]=
    {
        "hmmm bolo de ...", "barulho q o trem faz", "macaco gosta de...", "e redonda mas no japao existe quadrada", "tem coroa", "guacamole", "namora", "caduu", "carambolas", "um show de fruta", "goiabada", "tem viola", "talkshow", "bom pra garganta mas sem cedilha", "para", "scar light de uva", "jabutiranha", "jambosta", "azedo", "cor laranja"
    };
    char vetFrutasd4[][100]=
    {
        "hmmm bolo de ...", "barulho q o trem faz", "macaco gosta de...", "e redonda mas no japao existe quadrada", "tem coroa", "guacamole", "namora", "caduu", "carambolas", "um show de fruta", "goiabada", "tem viola", "talkshow", "bom pra garganta mas sem cedilha", "para", "scar light de uva", "jabutiranha", "jambosta", "azedo", "cor laranja"
    };

    printf("Bem vindo ao jogo da forta (forca com fruta)!!\n");
    printf("Esse jogo da forca possui 5 vidas e 4 dicas...\nUse-as sabiamente e boa sorte!!\n");
    puts("Aperte Enter para iniciar");
    getch();
    fflush(stdin);
    system("cls");

    //sorteio e ofuscar a palavra
    srand(time(NULL));
    int s=(rand()%20);

    char ffrutas[100], lac[100];
    strcpy(lac, vetFrutas[s]);
    strcpy(ffrutas, vetFrutas[s]);

    for (int i=0;i<strlen(ffrutas);i++)
    {
        lac[i]='*';
    }
    //fim do sorteio e ofuscar a palavra

    int vida=5;
    int pontuacao=0;
    char letra;

    while(vida>0 && pontuacao!=strlen(vetFrutas[s]))
    {
        printf("\t%s\n", lac);
        printf("Vidas ");
        for(int i=0; i<vida; i++)
        {
            printf("0");
        }

        //dicas

        switch(vida)
        {
        case 5:
            printf("\nAqui vao aparecer as dicas\n");
            break;
        case 4:
            printf("\nVoce perdeu uma vida hein, cuidado,\n Dica : %s", vetFrutasd1[s]);
            break;
        case 3:
            printf("\nVoce perdeu a segunda vida hein, cuidado\n Dica : %s", vetFrutasd2[s]);
            break;
        case 2:
            printf("\nVoce perdeu A TERCEIRA vida hein, CUIDADO\n Dica : %s", vetFrutasd3[s]);
            break;
        case 1:
            printf("\nVoce perdeu TODAS AS VIDAS\n Dica : %s", vetFrutasd4[s]);
            break;
        }
        //fimdicas

        printf("A palavra possui qual letra? ");
        fflush(stdin);
        scanf(" %c", &letra);

        int certoerrado=1;
        for(int i=0;i<strlen(lac);i++)
        {
            if(letra==ffrutas[i])
            {
                lac[i]=letra;
                certoerrado--;
                pontuacao++;
            }
        }
        if(certoerrado==1)
        {
            vida--;
        }
        system("cls");
    }
    //acabo o jogo

    if(vida>0)
    {
        printf(" Parabens, acertou a palavra! Fez %d pontos", pontuacao);
    }
    else
    {
        printf("Perdeu!!\n Mais sorte da proxima vez");

    }
    if(vida>2)
    {
        printf("Por ter sobrado %d vidas vc ganhou um multiplicador de %d pontos\n", vida, vida*2);
        printf("Voce ficou com um total de %d pontos", (vida*2)*pontuacao);
        return 0;
    }

}
