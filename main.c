#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Codigo para calcular frações(somar, subtrair, dividir, multiplicar)
void obterfracoes (int *num1, int *num2, int *num3, int *num4)
{
    printf("Informe O numerador da primeira fração:\n");
    scanf("%d", num1);
    printf("\nInforme o denominador da primeira fração:\n");
    scanf("%d", num2);
    printf("\nInforme o numerador da segunda fração:\n");
    scanf("%d", num3);
    printf("\nInforme o denominador da segunda fração:\n");
    scanf("%d", num4);

    if(*num2 == 0 || *num4 == 0)//Caso o usuario escrever 0 no denominador
    {
        printf("\nNão é possível ter uma fração com denominador zero, pois a divisão por zero é indefinida. ");
        exit(1);//Finaliza o programa retornando o numero 1 para o int main
    }
}
//soma das frações
void somarfra(int num1, int num2, int num3, int num4, int *num, int *den)
{
    *num = num1 * num4 + num3 * num2;
    *den = num2 * num4;
}
//subtração das frações
void subtrairfra(int num1, int num2, int num3, int num4, int *num, int *den)
{
    *num = num1 * num4 - num3 * num2;
    *den = num2 * num4;
}
//multiplicação das frações
void multiplicarfra(int num1, int num2, int num3, int num4, int *num, int *den)
{
    *num = num1 * num3;
    *den = num2 * num4;
}
//divisão das frações
void dividirfra(int num1, int num2, int num3, int num4, int *num, int *den)
{
    *num = num1 * num4;
    *den = num2 * num3;
}
//mdc
void mdc(int *num, int *den)
{
    int numA = *num;
    int numB = *den;
    int temp;
    while (numB != 0)
    {
        temp = numB;
        numB = numA % numB;
        numA = temp;
    }
    *num /= numA;
    *den /= numA;
}
int main()
{
    int numA, numB, numC, numD, numres, denres, opcao;
    char resp;

    setlocale( LC_ALL, "portuguese");//Torna possivel utilizar acentos
    do
    {
        system("cls");//Limpa a tela
        printf("1-Somar!\n");
        printf("2-Subtrair!\n");
        printf("3-Multiplicar!\n");
        printf("4-Dividir!\n");
        printf("5-Encerrar!\n");
        printf("Qual calculo gostaria?\n");
        scanf(" %c", &resp);

        opcao = resp - '0';

        switch(opcao)
        {
        case 1:
            obterfracoes(&numA, &numB, &numC, &numD);
            somarfra(numA, numB, numC, numD, &numres, &denres);
            mdc(&numres, &denres);
            printf("O resultado é: %d/%d\n", numres, denres);
            break;
        case 2:
            obterfracoes(&numA, &numB, &numC, &numD);
            subtrairfra(numA, numB, numC, numD, &numres, &denres);
            mdc(&numres, &denres);
            printf("O resultado é: %d/%d\n", numres, denres);
            break;
        case 3:
            obterfracoes(&numA, &numB, &numC, &numD);
            multiplicarfra(numA, numB, numC, numD, &numres, &denres);
            mdc(&numres, &denres);
            printf("O resultado é: %d/%d\n", numres, denres);
            break;
        case 4:
            obterfracoes(&numA, &numB, &numC, &numD);
            dividirfra(numA, numB, numC, numD, &numres, &denres);
            mdc(&numres, &denres);
            printf("O resultado é: %d/%d\n", numres, denres);
            break;
        case 5:
            printf("Encerrando programa");
            exit(1);
        default:
            printf("Opção invalida\n");
            break;
        }
    }
    while(opcao != 5);

    return 0;
}
