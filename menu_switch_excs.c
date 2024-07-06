#include <stdio.h>
#include <locale.h>
#include <stdlib.h> //para utilizar comandos "system"
#include <conio.h>
#include <ctype.h> //para utilizar função toupper

/*MENU SWITCH
 CAPÍTULOS: | -> | 1(1, 2, 3, 4, 5) opções | -> | Ex.: OPÇÃO 1 (final)
 -1    -4   | -> | 2(1, 2, 3, 4, 5) opções | -> | - Deseja continuar ou sair?
 -2    -5   | -> | 3(1, 2, 3, 4, 5) opções | -> | - SE CONTINUAR...
 -3    -6   | -> | 4(1, 2, 3, 4, 5) opções | -> | - Deseja voltar para o:
                 | 5(1, 2, 3, 4, 5) opções | -> | - MENU INICIAL (1)
                 | 6(1, 2, 3, 4, 5) opções | -> | - MENU DO CAP. 1 (2)
                                                | - INÍCIO DO EX.1  (3)
                                                | -> Entrada: _
*/

/*Caso deseje visualizar o código de um determinado exercício da apostila,
digite Cntrl+F para abrir a aba de pesquisa e C(nº do capítulo)E(nº do exercício).
Ex.: capítulo 2, exercício 3 -> C2E3.*/

/*Caso queira ser redirecionado para o início do programa, digite Cntrl+F para abrir a aba
de pesquisa, em seguida pesquise por "START" e aperte ENTER.*/

#define normal "color 07" //fundo preto com fonte branco brilhante
#define red "color 4f" //fundo vermelho com fonte branco brilhante
#define blue "color 1f" //fundo azul com fonte branco brilhante
#define white "color 70" //fundo branco com fonte preta
#define yellow "color 6f" //fundo amarelo com fonte branco brilhante
#define green "color 2f" //fundo verde com fonte branco brilhante
#define cian "color b0" //fundo verde-água claro com fonte preta
#define gray "color 8f" //fundo cinza com fonte branco brilhante
#define purple "color 5f" //fundo roxo com fonte branco brilhante

//PROTÓTIPO DAS FUNÇÕES (START)

//FUNÇÕES BOXES
void BOX_superior(int TamanhoLinha);
void BOX_nova_linha();
void BOX_linha_branco(int TamanhoLinha);
void BOX_inferior(int TamanhoLinha);

//APRESENTAÇÃO
void Apresentacao_1(int TamanhoLinha);
void Apresentacao_2(int TamanhoLinha);
void Apresentacao_3(int TamanhoLinha);
void DigiteENTER(int TamanhoLinha);
void ValorInvalido(int TamanhoLinha);
void ValorInvalido_SN(int TamanhoLinha);

//MENU DE SELEÇÃO
void PerguntaMenu(int TamanhoLinha);
int ConferenciaLetra(int TemLetra);

//CAPÍTULO 1
void PerguntaCAP1(int TamanhoLinha);

//CAPÍTULO 1 EX1
void PerguntaEnunciado_EX1_CAP1(int TamanhoLinha);
void Enunciado_EX1_CAP1(int TamanhoLinha);
void EX1_CAP1_QUEST(int TamanhoLinha);
int EX1_CAP1_POSITIVO(int Segundos);
void EX1_CAP1_VALOR_INVALIDO(int RetornoFuncaoPositivo, int RetornoScanf, int TemLetra, int TamanhoLinha);
void EX1_CAP1_ANSWER1(int TamanhoLinha);

//CAPÍTULO 1 EX2
void PerguntaEnunciado_EX2_CAP1(int TamanhoLinha);
void Enunciado_EX2_CAP1(int TamanhoLinha);
void Box_Ex2_Variaveis(int TamanhoLinha, int TamanhoLinha2, int contador, short int CopiaShort, float CopiaFloat, long int CopiaLong, double CopiaDouble, int CopiaInt, char CopiaChar);
void EX2_CAP1_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha);
void EX2_CAP1_ANSWER(int TamanhoLinha, int contador, short int CopiaShort, float CopiaFloat, long int CopiaLong, double CopiaDouble, int CopiaInt, char CopiaChar);

//CAPÍTULO 1 EX3
void PerguntaEnunciado_EX3_CAP1(int TamanhoLinha);
void Enunciado_EX3_CAP1(int TamanhoLinha);
void EX3_CAP1_QUEST_1(int TamanhoLinha);
void EX3_CAP1_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha);
void EX3_CAP1_QUEST_2(int TamanhoLinha);
void EX3_CAP1_ANSWER(int TamanhoLinha);

//CAPÍTULO 1 EX4
void PerguntaEnunciado_EX4_CAP1(int TamanhoLinha);
void Enunciado_EX4_CAP1(int TamanhoLinha);
void EX4_CAP1_QUEST_1(int TamanhoLinha);
void EX4_CAP1_QUEST_2(int TamanhoLinha);
void EX4_CAP1_ANSWER(int TamanhoLinha);

//CAPÍTULO 1 EX5
void PerguntaEnunciado_EX5_CAP1(int TamanhoLinha);
void Enunciado_EX5_CAP1(int TamanhoLinha);
void EX5_CAP1_QUEST_1(int TamanhoLinha);
void EX5_CAP1_ANSWER(int TamanhoLinha);

//CAPÍTULO 2
void PerguntaCAP2(int TamanhoLinha);

//CAPÍTULO 2 EX1
void PerguntaEnunciado_EX1_CAP2(int TamanhoLinha);
void Enunciado_EX1_CAP2(int TamanhoLinha);
void EX1_CAP2_QUEST(int numEtapa, int TamanhoLinha);
void EX1_CAP2_ANSWER(int TamanhoLinha);

//CAPÍTULO 2 EX2
void PerguntaEnunciado_EX2_CAP2(int TamanhoLinha);
void Enunciado_EX2_CAP2(int TamanhoLinha);
void EX2_CAP2_QUEST(int Numero, int TamanhoLinha1, int TamanhoLinha2);

//CAPÍTULO 2 EX4
void PerguntaEnunciado_EX4_CAP2(int TamanhoLinha);
void Enunciado_EX4_CAP2(int TamanhoLinha);
void EX4_CAP2_QUEST_1(int TamanhoLinha);
void EX4_CAP2_QUEST_2(int TamanhoLinha, int Contador);
int EX4_CAP2_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha);
void EX4_CAP2_ANSWER(int TamanhoLinha);

//CAPÍTULO 3
void PerguntaCAP3(int TamanhoLinha);

//CAPÍTULO 4
void PerguntaCAP4(int TamanhoLinha);

//CAPÍTULO 5
void PerguntaCAP5(int TamanhoLinha);

//CAPÍTULO 6
void PerguntaCAP6(int TamanhoLinha);

//FUNÇÕES AUXILIARES
int ConferenciaLetra(int TemLetra);
void RESULTADO_box(int TamanhoLinha);
void DESEJA_CONTINUAR_BOX(int TamanhoLinha);
void RETORNAR_QUEST_BOX(int TamanhoLinha, int NumExc, int NumCap);

//FUNÇÃO MAIN
void main()
{
    int opcao, continuar, retorno, letra=0, digitado, c;
    int NLinha=30, NLinha2=40, NLinha3=60, NLinha4=70, NLinha2_3=50, NLinhaP=21; // NL1 (boxes menores) / NL2 (boxes medianas) / NL3 (boxes maiores) / NL4 (boxes imensas) / NL2_3 (boxes maiores-medianas) / NLinhaP (boxes pequenas)
    int color=0;
    int cor=0;
    //EX1 CAP1
    int seg, positivo;
    //EX2 CAP1
    int contador=0; //utilizado também no C1 E4
    short int s;
    float f;
    long int l;
    double d;
    int i;
    char chaar;
    //EX3 CAP1
    int num; //utilizado também no C1 E5 e C2 E4
    int limite;
    //EX4 CAP1
    int var1, var2;
    //EX5 CAP1
    int digit;
    //EX1 CAP2
    int hour, min, sec, time, etapa;
    //EX2 CAP2
    int num1=1, num2=99, teste=50, contando=0;
    char resp;
    //EX4 CAP2
    int aux = 0;
    int numaux = 0;
    int cr=0;

    setlocale(LC_ALL,"");

    Apresentacao_1(NLinha); //APRESENTAÇÃO
    Apresentacao_2(NLinha);
    Apresentacao_3(NLinha);
    DigiteENTER(NLinha);
    do
    {
        opcao=getch();
        if(opcao!=13 && color==0)
        {
            color++;
            system(red);
            ValorInvalido(NLinha);
        }
    }
    while(opcao!=13);

pontoMENU_CAP:
    system("cls");
    system(normal);
    color=0;

    PerguntaMenu(NLinha); //MENU DE SELEÇÃO DOS CAPÍTULOS
    do
    {
        opcao=getch();
        if((opcao>54 || opcao<49) && color==0)
        {
            color++;
            system(red);
            ValorInvalido(NLinha);
        }
    }
    while(opcao>54 || opcao<49);
    color=0;

    system("cls");
    opcao+=-48;

    switch (opcao)
    {
    case 1: //CAPÍTULO 1 (CP1)

pontoCAP1:

        system(blue);
        PerguntaCAP1(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(blue);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 1 EXERCÍCIO 1 (C1E1)

            PerguntaEnunciado_EX1_CAP1(NLinha2);
            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX1_CAP1(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP1_EX1:

            system("cls");
            system(blue);

            do
            {
                EX1_CAP1_QUEST(NLinha);
                retorno=scanf("%d",&seg);
                letra=ConferenciaLetra(letra);
                positivo=EX1_CAP1_POSITIVO(seg);
                EX1_CAP1_VALOR_INVALIDO(positivo, retorno, letra, NLinha);
            }
            while(positivo==0 || retorno!=1 || letra>0);

            system(white);

            EX1_CAP1_ANSWER1(NLinha);
            RESULTADO_box(NLinha);

            printf("-> %dh ", seg/3600);
            seg%=3600;
            printf("%dmin ", seg/60);
            seg%=60;
            printf("%ds\n", seg);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(blue);
                RETORNAR_QUEST_BOX(NLinha2,1,1);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP1_EX1;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP1;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

            break;

        case 2: //CAPÍTULO 1 EXERCÍCIO 2 (C1E2)

            PerguntaEnunciado_EX2_CAP1(NLinha2);
            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX2_CAP1(NLinha4);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP1_EX2:

            system("cls");
            system(blue);
            contador=0;

            do //SHORT INT
            {
                if(contador==0)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%d",&s);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do //FLOAT
            {
                if(contador==1)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%f", &f);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do //LONG INT
            {
                if(contador==2)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%d", &l);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do //DOUBLE
            {
                if(contador==3)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%f", &d);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do //INT
            {
                if(contador==4)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%d", &i);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do //CHAR
            {
                if(contador==5)
                    contador++;
                Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);
                retorno=scanf("%c", &chaar);
                letra=ConferenciaLetra(letra);
                EX2_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            contador++;
            Box_Ex2_Variaveis(NLinha, NLinha2, contador, s, f, l, d, i, chaar);

            do
            {
                opcao=getch();
                if(opcao!=13 && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido(NLinha);
                }
            }
            while(opcao!=13);
            color=0;

            system("cls");
            system(white);

            EX2_CAP1_ANSWER(NLinha4, contador, s, f, l, d, i, chaar);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(blue);
                RETORNAR_QUEST_BOX(NLinha2,2,1);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;
                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP1_EX2;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP1;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }

            }

            break;

        case 3: //CAPÍTULO 1 EXERCÍCIO 3 (C1E3)

            PerguntaEnunciado_EX3_CAP1(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX3_CAP1(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP1_EX3:

            system("cls");
            system(blue);

            do
            {
                EX3_CAP1_QUEST_1(NLinha);
                retorno=scanf("%d",&num);
                letra=ConferenciaLetra(letra);
                letra=(num==0 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do
            {
                EX3_CAP1_QUEST_2(NLinha);
                retorno=scanf("%d",&limite);
                letra=ConferenciaLetra(letra);
                letra=(limite<=num || limite==0 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(white);

            EX3_CAP1_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            printf("-> O menor múltiplo de %d maior\nque %d é: %d\n", num, limite, ((limite/num)+1)*num);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(blue);
                RETORNAR_QUEST_BOX(NLinha2,3,1);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP1_EX3;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP1;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

            break;
        case 4: //CAPÍTULO 1 EXERCÍCIO 4 (C1E4)

            PerguntaEnunciado_EX4_CAP1(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX4_CAP1(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP1_EX4:

            system("cls");
            system(blue);

            do
            {
                EX4_CAP1_QUEST_1(NLinha);
                retorno=scanf("%d",&var1);
                letra=ConferenciaLetra(letra);
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(blue);

            do
            {
                EX4_CAP1_QUEST_2(NLinha);
                retorno=scanf("%d",&var2);
                letra=ConferenciaLetra(letra);
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(white);

            EX4_CAP1_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            var2+=var1;
            var1=var2-var1;
            var2+=-var1;
            printf("-> Variável X: %d\n", var1);
            printf("-> Variável Y: %d\n", var2);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(blue);
                RETORNAR_QUEST_BOX(NLinha2,4,1);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP1_EX4;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP1;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

            break;

        case 5: //CAPÍTULO 1 EXERCÍCIO 5 (C1E5)

            PerguntaEnunciado_EX5_CAP1(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX5_CAP1(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP1_EX5:

            system("cls");
            system(blue);

            do
            {
                EX5_CAP1_QUEST_1(NLinha);
                retorno=scanf("%d",&num);
                letra=ConferenciaLetra(letra);
                letra=(num<100 || num>999 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(white);

            EX5_CAP1_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            printf("-> Número lido = %d\n", num);
            printf("-> Número gerado = ");
            do
            {
                digit=num%10;
                printf("%d",digit);
                num/=10;
                if(num==0)
                    printf("\n");
            }
            while(num!=0);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(blue);
                RETORNAR_QUEST_BOX(NLinha2,5,1);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP1_EX5;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP1;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

            break;
        }
        break; //BREAK DO SWITCH CAPÍTULO 1

    case 2: //CAPÍTULO 2 (CP2)

        pontoCAP2:

        system(yellow);
        PerguntaCAP2(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(yellow);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 2 EXERCÍCIO 1 (C2E1)

        PerguntaEnunciado_EX1_CAP2(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX1_CAP2(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP2_EX1:

            system("cls");
            system(yellow);

            etapa=1;

            do //CHAMADA INICIADA / HORAS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&hour);
                letra=ConferenciaLetra(letra);
                letra=(hour<0 || hour>23 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(yellow);
            etapa++; //etapa = 2

            do //CHAMADA INICIADA / MINUTOS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&min);
                letra=ConferenciaLetra(letra);
                letra=(min<0 || min>59 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(yellow);
            etapa++; //etapa = 3

            do //CHAMADA INICIADA / SEGUNDOS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&sec);
                letra=ConferenciaLetra(letra);
                letra=(sec<0 || sec>59 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(yellow);
            etapa++; //etapa = 4

            time=(hour*3600)+(min*60)+sec;

            do //CHAMADA ENCERRADA / HORAS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&hour);
                letra=ConferenciaLetra(letra);
                letra=(hour<0 || hour>23 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(yellow);
            etapa++; //etapa = 5

            do //CHAMADA ENCERRADA / MINUTOS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&min);
                letra=ConferenciaLetra(letra);
                letra=(min<0 || min>59 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(yellow);
            etapa++; //etapa = 6

            do //CHAMADA ENCERRADA / SEGUNDOS
            {
                EX1_CAP2_QUEST(etapa, NLinha);
                retorno=scanf("%d",&sec);
                letra=ConferenciaLetra(letra);
                letra=(sec<0 || sec>59 || letra>0) ? 1 : 0;
                EX3_CAP1_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            system(white);

            EX1_CAP2_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            time=((hour*3600)+(min*60)+sec)-time;

            time=time<0 ? (86400)-(time*-1) : time;

            printf("-> %dh ", time/3600);
            time%=3600;
            printf("%dmin ", time/60);
            time%=60;
            printf("%ds\n", time);

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(yellow);
                RETORNAR_QUEST_BOX(NLinha2,1,2);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP2_EX1;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP2;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

        break;

        case 2: //CAPÍTULO 2 EXERCÍCIO 2 (C2E2)

        PerguntaEnunciado_EX2_CAP2(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX2_CAP2(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP2_EX2:

            system("cls");
            system(yellow);

            num1=1;
            num2=99;
            teste=50;
            contando=0;

            do{
            do
            {
                if(cr==1) //cor
                system(yellow);
                EX2_CAP2_QUEST(teste, NLinha2, NLinha3);
                retorno=scanf("%c",&resp);
                letra=ConferenciaLetra(letra);
                letra=(resp != '=' && resp != '<' && resp != '>' || letra>0) ? 1 : 0;
                cr=EX4_CAP2_VALOR_INVALIDO(retorno, letra, NLinha);
            }
            while(retorno!=1 || letra>0);

            if(resp == '<')
                    num2=teste--;
                else if (resp =='>')
                    num1=teste++;

                //printf("num1+num2=%d+%d\n", num1, num2);

                teste=(num1+num2)/2;

                //printf("teste=%d\n",teste);

                if(resp != '=')
                contando++;

                //printf("vezes=%d\n", contando);

                if(teste==98 && contando==7)
                    {
                    contando=6;
                    teste=99;
                    num1++;
                    }

                if(contando==7)
                {
                    printf("Você não falou a verdade, na próxima seja mais sincero.\n");
                    goto pontoNumErrado;
                }

            }while(resp != '=');

            system(white);

            EX4_CAP2_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            pontoNumErrado:

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(yellow);
                RETORNAR_QUEST_BOX(NLinha2,2,2);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP2_EX2;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP2;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

        break;

        case 3: //CAPÍTULO 2 EXERCÍCIO 3 (C2E3)

        printf("C2E3");

        break;

        case 4: //CAPÍTULO 2 EXERCÍCIO 4 (C2E4)

        PerguntaEnunciado_EX4_CAP2(NLinha2);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(white);
                Enunciado_EX4_CAP2(NLinha3);
                DigiteENTER(NLinha);
                do
                {
                    opcao=getch();
                    if(opcao!=13 && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao!=13);
                color=0;
            }

pontoCAP2_EX4:

            system("cls");
            system(yellow);

            for(contador=0; aux!=1; contador++)
            {
                do
                {
                    if(cr==1) //cor
                    system(yellow);
                    EX4_CAP2_QUEST_1(NLinha3);
                    EX4_CAP2_QUEST_2(NLinhaP, contador);
                    retorno=scanf("%d",&num);
                    letra=ConferenciaLetra(letra);
                    letra=(num==0 || letra>0) ? 1 : 0;
                    cr=EX4_CAP2_VALOR_INVALIDO(retorno, letra, NLinha);
                }
                while(retorno!=1 || letra>0);
                if (num<0)
                {
                    aux++;
                    contador--;
                }
                else
                    numaux+=num;
            }

            system(white);

            EX4_CAP2_ANSWER(NLinha);
            RESULTADO_box(NLinha);

            printf("-> Soma: %d\n", numaux);
            printf("-> Números positivos: %d\n\n", contador);
            printf("-> Média: %.2f\n", ((float)numaux)/contador);
            aux=0;

            DESEJA_CONTINUAR_BOX(NLinha);

            do
            {
                continuar=getch();
                continuar=toupper(continuar); //COMANDO TOUPPER (conversão para letra maiúscula)
                if(continuar!='S' && continuar!='N' && color==0)
                {
                    color++;
                    system(red);
                    ValorInvalido_SN(NLinha);
                }
            }
            while(continuar!='S' && continuar!='N');
            color=0;

            if(continuar == 'S')
            {
                system("cls");
                system(yellow);
                RETORNAR_QUEST_BOX(NLinha2,4,2);
                do
                {
                    opcao=getch();
                    if((opcao>51 || opcao<49) && color==0)
                    {
                        color++;
                        system(red);
                        ValorInvalido(NLinha);
                    }
                }
                while(opcao>51 || opcao<49);
                color=0;
                opcao+=-48;

                if(opcao==1)
                {
                    system("cls");
                    goto pontoCAP2_EX4;
                }
                else if(opcao==2)
                {
                    system("cls");
                    goto pontoCAP2;
                }
                else
                {
                    system("cls");
                    goto pontoMENU_CAP;
                }
            }

        break;

        case 5: //CAPÍTULO 2 EXERCÍCIO 5 (C2E5)

        printf("C2E5");

        break;
        }

        break; //BREAK DO SWITCH CAPÍTULO 2

    case 3: //CAPÍTULO 3 (CP3)

        //pontoCAP3:

        system(green);
        PerguntaCAP3(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(green);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 3 EXERCÍCIO 1 (C3E1)

        printf("C3E1");

        break;

        case 2: //CAPÍTULO 3 EXERCÍCIO 2 (C3E2)

        printf("C3E2");

        break;

        case 3: //CAPÍTULO 3 EXERCÍCIO 3 (C3E3)

        printf("C3E3");

        break;

        case 4: //CAPÍTULO 3 EXERCÍCIO 4 (C3E4)

        printf("C3E4");

        break;

        case 5: //CAPÍTULO 3 EXERCÍCIO 5 (C3E5)

        printf("C3E5");

        break;
        }

        break; //BREAK DO SWITCH CAPÍTULO 3

    case 4: //CAPÍTULO 4 (CP4)

        //pontoCAP4:

        system(cian);
        PerguntaCAP4(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(cian);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 4 EXERCÍCIO 1 (C4E1)

        printf("C4E1");

        break;

        case 2: //CAPÍTULO 4 EXERCÍCIO 2 (C4E2)

        printf("C4E2");

        break;

        case 3: //CAPÍTULO 4 EXERCÍCIO 3 (C4E3)

        printf("C4E3");

        break;

        case 4: //CAPÍTULO 4 EXERCÍCIO 4 (C4E4)

        printf("C4E4");

        break;

        case 5: //CAPÍTULO 4 EXERCÍCIO 5 (C4E5)

        printf("C4E5");

        break;
        }

        break; //BREAK DO SWITCH CAPÍTULO 4

    case 5: //CAPÍTULO 5 (CP5)

        //pontoCAP5:

        system(gray);
        PerguntaCAP5(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(gray);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 5 EXERCÍCIO 1 (C5E1)

        printf("C5E1");

        break;

        case 2: //CAPÍTULO 5 EXERCÍCIO 2 (C5E2)

        printf("C5E2");

        break;

        case 3: //CAPÍTULO 5 EXERCÍCIO 3 (C5E3)

        printf("C5E3");

        break;

        case 4: //CAPÍTULO 5 EXERCÍCIO 4 (C5E4)

        printf("C5E4");

        break;

        case 5: //CAPÍTULO 5 EXERCÍCIO 5 (C5E5)

        printf("C5E5");

        break;
        }

        break; //BREAK DO SWITCH CAPÍTULO 5

    case 6: //CAPÍTULO 6 (CP6)

        //pontoCAP5:

        system(purple);
        PerguntaCAP6(NLinha);
        do
        {
            opcao=getch();
            if((opcao>53 || opcao<49) && color==0)
            {
                color++;
                system(red);
                ValorInvalido(NLinha);
            }
        }
        while(opcao>53 || opcao<49);
        color=0;

        system("cls");
        system(purple);
        opcao+=-48;

        switch (opcao)
        {
        case 1: //CAPÍTULO 6 EXERCÍCIO 1 (C6E1)

        printf("C6E1");

        break;

        case 2: //CAPÍTULO 6 EXERCÍCIO 2 (C6E2)

        printf("C6E2");

        break;

        case 3: //CAPÍTULO 6 EXERCÍCIO 3 (C6E3)

        printf("C6E3");

        break;

        case 4: //CAPÍTULO 6 EXERCÍCIO 4 (C6E4)

        printf("C6E4");

        break;

        case 5: //CAPÍTULO 6 EXERCÍCIO 5 (C6E5)

        printf("C6E5");

        break;
        }

        break; //BREAK DO SWITCH CAPÍTULO 6
    }

} //FINAL DA FUNÇÃO MAIN

//FUNÇÕES

void BOX_superior(int TamanhoLinha)
{
    int cont;
    setlocale(LC_ALL,"C");
    printf("%c", 201); //TRAVESSAO DO CANTO SUPERIOR ESQUERDO
    for(cont=0; cont<TamanhoLinha; cont++) //LINHA
    {
        printf("%c", 205);
    }
    printf("%c\n", 187); //TRAVESSAO DO CANTO SUPERIOR DIREITO
    printf("%c", 186);
    setlocale(LC_ALL,"");
}

void BOX_nova_linha()
{
    setlocale(LC_ALL,"C");
    printf("%c\n%c", 186, 186);
    setlocale(LC_ALL,"");
}

void BOX_linha_branco(int TamanhoLinha)
{
    int cont;
    for(cont=0; cont<TamanhoLinha; cont++)
    {
        printf(" ");
    }
}

void BOX_inferior(int TamanhoLinha)
{
    int cont;
    setlocale(LC_ALL,"C");
    printf("%c\n", 186);
    printf("%c",200); //TRAVESSAO DO CANTO INFERIOR ESQUERDO
    for(cont=0; cont<TamanhoLinha; cont++) //LINHA
    {
        printf("%c", 205);
    }
    printf("%c", 188); //TRAVESSAO DO CANTO INFERIOR DIREITO
    printf("\n");
    setlocale(LC_ALL,"");
}

void Apresentacao_1(int TamanhoLinha)
{
    system("TITLE Início");
    BOX_superior(TamanhoLinha);
    printf("%3cRESOLUÇÃO APOSTILA ILP010%4c",0,0);
    BOX_nova_linha();
    printf("%6cADS 2ºC / 1ºBIM 2023%6c", 0, 0);
    BOX_inferior(TamanhoLinha);
}

void Apresentacao_2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Professor: Rui Silvestrin%6c",0);
    BOX_inferior(TamanhoLinha);
}

void Apresentacao_3(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Feita por:%21c",0);
    BOX_nova_linha();
    printf("César Martins dos Santos Borba");
    BOX_nova_linha();
    printf("%14ce%17c",0,0);
    BOX_nova_linha();
    printf("%5cErick Santos Lacerda%7c",0,0);
    BOX_inferior(TamanhoLinha);
}

void DigiteENTER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite ENTER para continuar...");
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void ValorInvalido(int TamanhoLinha)
{
    printf("\b\b\b");
    BOX_superior(TamanhoLinha);
    printf("%9cOpção inválida%9c",0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void ValorInvalido_SN(int TamanhoLinha)
{
    printf("\b\b\b\b\b\b\b\b\b");
    BOX_superior(TamanhoLinha);
    printf("%9cOpção inválida%9c",0,0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void PerguntaMenu(int TamanhoLinha)
{
    system("TITLE Menu dos capítulos");
    BOX_superior(TamanhoLinha);
    printf(" QUE CAPÍTULO DESEJA ACESSAR?%2c",0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%6c-6%9c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaCAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 1!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaEnunciado_EX1_CAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1/Exercício 1");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 1 DO CAPÍTULO 1! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX1_CAP1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX1>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("1 - Escreva um programa que receba via teclado um tempo em%3c",0);
    BOX_nova_linha();
    printf("segundos e converta para horas, minutos e segundos.%10c",0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("Ex.: recebe 3850 segundos que converte para 1h 4min 10s.%5c",0);
    BOX_inferior(TamanhoLinha);
}

void EX1_CAP1_QUEST(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite um horário em segundos:");
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

int ConferenciaLetra(int TemLetra)
{
    int Digitado;
    TemLetra=0;
    do
    {
        Digitado=getchar();
        if(Digitado!=10)TemLetra++;
    }
    while(Digitado != '\n');
    return TemLetra;
}

int EX1_CAP1_POSITIVO(int Segundos)
{
    if(Segundos<0)
        return 0;
    else
        return 1;
}

void EX1_CAP1_VALOR_INVALIDO(int RetornoFuncaoPositivo, int RetornoScanf, int TemLetra, int TamanhoLinha)
{
    if(RetornoFuncaoPositivo==0 || RetornoScanf!=1 || TemLetra>0 )
    {
        system("cls");
        system(red);

        BOX_superior(TamanhoLinha);
        printf("%9cValor inválido%9c",0,0);
        BOX_inferior(TamanhoLinha);
    }
    else
    {
        system("cls");
    }
}

void EX1_CAP1_ANSWER1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%6cCONVERSÃO PARA HORAS%6c",0,0);
    BOX_inferior(TamanhoLinha);
}

void RESULTADO_box(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%11cRESULTADO:%11c",0,0);
    BOX_inferior(TamanhoLinha);
}

void DESEJA_CONTINUAR_BOX(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%8cDESEJA CONTINUAR?%7c",0,0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void RETORNAR_QUEST_BOX(int TamanhoLinha, int NumExc, int NumCap)
{
    BOX_superior(TamanhoLinha);
    printf("%5cPARA ONDE VOCÊ DESEJA RETORNAR?%6c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("%5c- 1 Início do programa (ex%d)%9c",0,NumExc,0);
    BOX_nova_linha();
    printf("%5c- 2 Menu dos exercícios (cap%d)%7c",0,NumCap,0);
    BOX_nova_linha();
    printf("%5c- 3 Menu dos capítulos%15c",0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaEnunciado_EX2_CAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1/Exercício 2");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 2 DO CAPÍTULO 1! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX2_CAP1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%28c</ENUNCIADO EX2>%28c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("2 - Escreva um programa que receba dados via teclado para variáveis do");
    BOX_nova_linha();
    printf("tipo short, long, int, float, double e um char e imprima-os no vídeo  ");
    BOX_nova_linha();
    printf("no seguinte formato:%51c",0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("          10        20        30        40        50        60%9c",0);
    BOX_nova_linha();
    printf("%3c12345678901234567890123456789012345678901234567890123456789012345%4c",0,0);
    BOX_nova_linha();
    printf("      short               long                int%22c",0);
    BOX_nova_linha();
    printf("                float               double              char%11c",0);
    BOX_inferior(TamanhoLinha);
}

void Box_Ex2_Variaveis(int TamanhoLinha, int TamanhoLinha2, int contador, short int CopiaShort, float CopiaFloat, long int CopiaLong, double CopiaDouble, int CopiaInt, char CopiaChar)
{
    BOX_superior(TamanhoLinha);
    printf("%11cVARIÁVEIS:%11c",0,0);
    BOX_inferior(TamanhoLinha);
    switch(contador)
    {
    case 1:
        printf("-> short int: \n\n");
        printf("-> float: \n\n");
        printf("-> long int: \n\n");
        printf("-> double: \n\n");
        printf("-> int: \n\n");
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("%3cDigite um número inteiro:%4c",0,0);
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 2:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: \n\n");
        printf("-> long int: \n\n");
        printf("-> double: \n\n");
        printf("-> int: \n\n");
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("%5cDigite um número real:%5c",0,0);
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 3:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: %g\n\n", CopiaFloat);
        printf("-> long int: \n\n");
        printf("-> double: \n\n");
        printf("-> int: \n\n");
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("%2cDigite outro número inteiro:%2c",0,0);
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 4:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: %g\n\n", CopiaFloat);
        printf("-> long int: %d\n\n", CopiaLong);
        printf("-> double: \n\n");
        printf("-> int: \n\n");
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("%3cDigite outro número real:%4c",0,0);
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 5:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: %g\n\n", CopiaFloat);
        printf("-> long int: %d\n\n", CopiaLong);
        printf("-> double: %g\n\n", CopiaDouble);
        printf("-> int: \n\n");
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("Digite mais um número inteiro:");
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 6:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: %g\n\n", CopiaFloat);
        printf("-> long int: %d\n\n", CopiaLong);
        printf("-> double: %g\n\n", CopiaDouble);
        printf("-> int: %d\n\n", CopiaInt);
        printf("-> char: \n");
        BOX_superior(TamanhoLinha);
        printf("%6cDigite um caractere:%6c",0,0);
        BOX_inferior(TamanhoLinha);
        printf("-> ");
        break;
    case 7:
        printf("-> short int: %d\n\n", CopiaShort);
        printf("-> float: %g\n\n", CopiaFloat);
        printf("-> long int: %d\n\n", CopiaLong);
        printf("-> double: %g\n\n", CopiaDouble);
        printf("-> int: %d\n\n", CopiaInt);
        printf("-> char: %c\n", CopiaChar);
        DigiteENTER(TamanhoLinha);
        break;
    }
}

void EX2_CAP1_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha)
{
    if(RetornoScanf!=1 || TemLetra>0 )
    {
        system("cls");
        system(red);

        BOX_superior(TamanhoLinha);
        printf("%9cValor inválido%9c",0,0);
        BOX_inferior(TamanhoLinha);
    }
    else
    {
        system("cls");
    }
}

void EX2_CAP1_ANSWER(int TamanhoLinha, int contador, short int CopiaShort, float CopiaFloat, long int CopiaLong, double CopiaDouble, int CopiaInt, char CopiaChar)
{
    BOX_superior(TamanhoLinha);
    printf("%31cSEQUÊNCIA:%31c",0,0);
    BOX_inferior(TamanhoLinha);
    printf("%4c        10        20        30        40        50        60\n",0);
    printf("%4c12345678901234567890123456789012345678901234567890123456789012345\n",0);
    printf("%12d%19d%19d\n", CopiaShort, CopiaLong, CopiaInt);
    printf("%22g%21lg%18c\n", CopiaFloat, CopiaDouble, CopiaChar);
}

void PerguntaEnunciado_EX3_CAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1/Exercício 3");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 3 DO CAPÍTULO 1! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX3_CAP1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX3>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("3 - Escreva um programa que determine o menor múltiplo de um");
    BOX_nova_linha();
    printf("número inteiro. Este múltiplo deve ser maior que o limite%4c",0);
    BOX_nova_linha();
    printf("mínimo recebido. Recebe os 2 números via teclado.%12c",0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("Ex.: menor múltiplo de 13 maior que 100. Resultado: 104.%5c",0);
    BOX_inferior(TamanhoLinha);
}

void EX3_CAP1_QUEST_1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite um número inteiro:%6c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void EX3_CAP1_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha)
{
    if(RetornoScanf!=1 || TemLetra>0 )
    {
        system("cls");
        system(red);

        BOX_superior(TamanhoLinha);
        printf("%9cValor inválido%9c",0,0);
        BOX_inferior(TamanhoLinha);
    }
    else
    {
        system("cls");
    }
}

void EX3_CAP1_QUEST_2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite um número inteiro maior");
    BOX_nova_linha();
    printf("que o primeiro:%16c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void EX3_CAP1_ANSWER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%9cMÚLTIPLO IDEAL%9c",0,0);
    BOX_inferior(TamanhoLinha);
}

void PerguntaEnunciado_EX4_CAP2(int TamanhoLinha)
{
    system("TITLE Capítulo 2/Exercício 4");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 4 DO CAPÍTULO 2! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX4_CAP2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX4>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("4 - Escreva um programa que receba via teclado números in-%3c",0);
    BOX_nova_linha();
    printf("teiros positivos. Quando o número digitado for negativo o%4c",0);
    BOX_nova_linha();
    printf("programa deve parar e calcular a média dos valores positivos",0);
    BOX_nova_linha();
    printf("digitados.%51c",0);
    BOX_inferior(TamanhoLinha);
}

void EX4_CAP2_QUEST_1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite quantos números desejar. Ao digitar um número negati-");
    BOX_nova_linha();
    printf("vo, será informada a média entre os números digitados.%7c",0);
    BOX_inferior(TamanhoLinha);
}

void EX4_CAP2_QUEST_2(int TamanhoLinha, int Contador)
{
    BOX_superior(TamanhoLinha);
    Contador++;
    if(Contador>=0 && Contador<10)
        printf("Digite o %dº número:%3c", Contador,0);
    else if(Contador>=10 && Contador <=99)
        printf("Digite o %dº número:%2c", Contador,0);
    else
        printf("Digite o %dº número:%1c", Contador,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

int EX4_CAP2_VALOR_INVALIDO(int RetornoScanf, int TemLetra, int TamanhoLinha)
{
    if(RetornoScanf!=1 || TemLetra>0 )
    {
        system("cls");
        system(red);

        BOX_superior(TamanhoLinha);
        printf("%9cValor inválido%9c",0,0);
        BOX_inferior(TamanhoLinha);
        return 0;
    }
    else
    {
        system("cls");
        return 1;
    }
}

void EX4_CAP2_ANSWER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%6cMÉDIA DOS POSITIVOS%7c",0,0);
    BOX_inferior(TamanhoLinha);
}

void PerguntaEnunciado_EX5_CAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1/Exercício 5");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 5 DO CAPÍTULO 1! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX5_CAP1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX5>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("5 - Faça um programa para ler um número inteiro, positivo de");
    BOX_nova_linha();
    printf("três digitos, e gerar outro número formado pelos dígitos in-");
    BOX_nova_linha();
    printf("vertidos do número lido.%37c",0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("Ex.: NúmeroLido = 123%40c",0);
    BOX_nova_linha();
    printf("%6cNúmeroGerado = 321%38c",0,0);
    BOX_inferior(TamanhoLinha);
}

void EX5_CAP1_QUEST_1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite um número de 3 dígitos:");
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void EX5_CAP1_ANSWER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%8cNÚMERO INVERTIDO%8c",0,0);
    BOX_inferior(TamanhoLinha);
}

void PerguntaCAP2(int TamanhoLinha)
{
    system("TITLE Capítulo 2 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 2!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaCAP3(int TamanhoLinha)
{
    system("TITLE Capítulo 3 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 3!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaCAP4(int TamanhoLinha)
{
    system("TITLE Capítulo 4 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 4!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaCAP5(int TamanhoLinha)
{
    system("TITLE Capítulo 5 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 5!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaCAP6(int TamanhoLinha)
{
    system("TITLE Capítulo 6 ");
    BOX_superior(TamanhoLinha);
    printf("%4cVOCÊ ESTÁ NO CAPÍTULO 6!%4c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("QUE EXERCÍCIO DESEJA ACESSAR? ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("    -1\t%5c  |\t%6c-4%9c",0,0,0);
    BOX_nova_linha();
    printf("    -2\t%5c  |\t%6c-5%9c",0,0,0);
    BOX_nova_linha();
    printf("    -3\t%5c  |\t%16c",0,0,0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void PerguntaEnunciado_EX4_CAP1(int TamanhoLinha)
{
    system("TITLE Capítulo 1/Exercício 4");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 4 DO CAPÍTULO 1! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX4_CAP1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX4>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("4 - Escreva um programa que permute o conteúdo de duas vari-");
    BOX_nova_linha();
    printf("áveis sem utilizar uma variável auxiliar.%20c",0);
    BOX_inferior(TamanhoLinha);
}

void EX4_CAP1_QUEST_1(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite o valor da variável X: ");
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void EX4_CAP1_QUEST_2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("Digite o valor da variável Y: ");
    BOX_inferior(TamanhoLinha);
    printf("-> ");
}

void EX4_CAP1_ANSWER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%6cVARIÁVEIS PERMUTADAS%6c",0,0);
    BOX_inferior(TamanhoLinha);
}

void PerguntaEnunciado_EX1_CAP2(int TamanhoLinha)
{
    system("TITLE Capítulo 2/Exercício 1");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 1 DO CAPÍTULO 2! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX1_CAP2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX1>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("1 - As ligacoes telefônicas são cobradas pela sua duração. O");
    BOX_nova_linha();
    printf("sistema registra os instantes em que a ligação foi iniciada ");
    BOX_nova_linha();
    printf("e concluída. Escreva um programa que receba via teclado dois");
    BOX_nova_linha();
    printf("instantes dados em horas, minutos e segundos e determine o  ");
    BOX_nova_linha();
    printf("intervalo de tempo (em horas, minutos e segundos) decorrido ");
    BOX_nova_linha();
    printf("entre eles.%50c",0);
    BOX_inferior(TamanhoLinha);
}

void EX1_CAP2_QUEST(int numEtapa, int TamanhoLinha)
{
    switch(numEtapa)
    {
    case 1:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO INICIADA%8c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em HORAS:%5c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    case 2:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO INICIADA%8c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em MINUTOS:%3c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    case 3:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO INICIADA%8c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em SEGUNDOS: ");
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    case 4:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO ENCERRADA%7c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em HORAS:%5c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    case 5:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO ENCERRADA%7c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em MINUTOS:%3c",0);
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    case 6:

    BOX_superior(TamanhoLinha);
    printf("%8cLIGAÇÃO ENCERRADA%7c",0,0);
    BOX_inferior(TamanhoLinha);
    BOX_superior(TamanhoLinha);
    printf("Digite o horário em SEGUNDOS: ");
    BOX_inferior(TamanhoLinha);
    printf("-> ");

    break;

    }
}

void EX1_CAP2_ANSWER(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%7cDURAÇÃO TELEFONEMA%7c",0,0);
    BOX_inferior(TamanhoLinha);
}

void PerguntaEnunciado_EX2_CAP2(int TamanhoLinha)
{
    system("TITLE Capítulo 2/Exercício 2");
    BOX_superior(TamanhoLinha);
    printf("VOCÊ ESTÁ NO EXERCÍCIO 2 DO CAPÍTULO 2! ");
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("DESEJA VISUALIZAR O ENUNCIADO?%11c",0);
    BOX_inferior(TamanhoLinha);
    printf("->(S/N): ");
}

void Enunciado_EX2_CAP2(int TamanhoLinha)
{
    BOX_superior(TamanhoLinha);
    printf("%23c</ENUNCIADO EX2>%23c",0,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha);
    BOX_nova_linha();
    printf("2 - Escreva um programa para adivinhar um número entre 1 e  ");
    BOX_nova_linha();
    printf("99 que o usuário pensou. Digite via teclado os símbolos =, >");
    BOX_nova_linha();
    printf("ou < a cada pergunta. Utilize o comando if-else.%13c",0);
    BOX_inferior(TamanhoLinha);
}

void EX2_CAP2_QUEST(int Numero, int TamanhoLinha1, int TamanhoLinha2)
{
    BOX_superior(TamanhoLinha1);
    printf("Pense em um número entre 1 e 99 e o pro-");
    BOX_nova_linha();
    printf("grama irá tentar adivinhar.%14c",0);
    BOX_inferior(TamanhoLinha1);
    BOX_superior(TamanhoLinha2);
    if(Numero<10)
    printf("Você está pensando no número %d?%30c", Numero,0);
    else
    printf("Você está pensando no número %d?%29c", Numero,0);
    BOX_nova_linha();
    BOX_linha_branco(TamanhoLinha2);
    BOX_nova_linha();
    printf("(Utilize os símbolos '<', '>', ou '=' para responder)%8c",0);
    BOX_inferior(TamanhoLinha2);
    printf("-> ");
}
