//Gabriel Henrique Maciel
#include <stdio.h>
#include <locale.h>
//Codigo para calcular frações(somar, subtrair, dividir, multiplicar)

//mdc
int __gcd(int numA, int numB)
{
    if(numB == 0)
    {
        return numA;
    }
    return __gcd(numB, numA % numB);
}
int main()
{
    int numA, denA, numB, denB, numres, denres, op, resp;
    int mmc, num1, num2;
    char fim;

    setlocale( LC_ALL, "portuguese");//Torna possivel utilizar acentos

      while (1)//enquanto o usuario não selecionar 5 o código continua em loop
    {
        printf("1-Somar!\n");
        printf("2-Subtrair!\n");
        printf("3-Multiplicar!\n");
        printf("4-Dividir!\n");
        printf("5-Encerrar!\n");
        printf("Qual calculo gostaria?\n");
        scanf("%d", &op);

         if (op == 5)
        {
            printf("Encerrando o programa.\n");
            break;
        }

        printf("Informe O numerador da primeira fração:\n");
        scanf("%d", &numA);
        printf("\nInforme o denominador da primeira fração:\n");
        scanf("%d", &denA);
        printf("\nInforme o numerador da segunda fração:\n");
        scanf("%d", &numB);
        printf("\nInforme o denominador da segunda fração:\n");
        scanf("%d", &denB);

        switch(op)
        {
        case 1://soma das frações
            mmc = (denA * denB) / __gcd(denA, denB);//calcula mmc
            num1 = numA * (mmc / denA);
            num2 = numB * (mmc / denB);
            numres = num1 + num2;
            int mdc = __gcd(numres, mmc);
            numres /= mdc;
            mmc /= mdc;
            printf("O resultado das frações é: %d/%d\n", numres, mmc);
            break;

        case 2://subtração das frações
            mmc = (denA * denB) / __gcd(denA, denB);//calcula mmc
            num1 = numA * (mmc / denA);
            num2 = numB * (mmc / denB);
            numres = num1 - num2;
            mdc = __gcd(numres, mmc);
            numres /= mdc;
            mmc /= mdc;
            if (mmc < 0)
            {
                numres = -numres;
                mmc = -mmc;
            }
            printf("O resultado das frações é: %d/%d\n", numres, mmc);
            break;

        case 3://multiplicação das frações
            numres = numA * numB;
            denres = denA * denB;
            mdc = __gcd(numres, denres);
            numres /= mdc;
            denres /= mdc;
            printf("O resultado das frações é: %d/%d\n", numres, denres);
            break;

        case 4://divisão das frações
            numres = numA * denB;
            denres = denA * numB;
            mdc = __gcd(numres, denres);
            numres /= mdc;
            denres /= mdc;
            if (denres < 0)
            {
                numres = -numres;
                denres = -denres;
            }
            printf("O resultado das frações é: %d/%d\n", numres, denres);
            break;

        case 5:
            printf("Encerrando programa");
            exit(1);
        default:
            printf("Opção invalida\n");
            break;
        }
    }

        return 0;
    }
