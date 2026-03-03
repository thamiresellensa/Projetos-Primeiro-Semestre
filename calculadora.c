//Projeto de Calculadora simples em C
#include <stdio.h>

double abertura(double a, double b, double result, char op, int loop);

double calculadora(double a, double *b, char op);

void menu();

int main(){
    int loop;
    double x=0, y=0, resultado=0;
    char operacao;
    
    do{
    loop = abertura(x, y, resultado, operacao, loop);
    }while(loop == 1);


    return 0;
}
double abertura(double a, double b, double result, char op, int loop){

    double *B;
    printf("\n****************** CALCULADORA **********************\n");

    printf("\nEscolha um valor para x: ");
    scanf("%lf", &a);

    printf("\nAgora um valor para y: ");
    scanf("%lf", &b);

    B = &b;

    menu();
    scanf(" %c", &op);
        result = calculadora(a,&b,op);
        printf("\nCalculando...\n");
        printf("\nRESULTADO\n= %.1lf %c %.1lf = %.2lf\n",a,op,b,result);
    
        printf("\nDigite:\n0 -> sair\n1 -> para continuar calculando\n");
        scanf("%d", &loop);

    return loop;
}

double calculadora(double a, double *b, char op){
switch(op){
    case '+':
    return a + *b;
    break;

    case '-':
    return a - *b;
    break;

    case '*':
    return a * *b;
    break;

    case '/':
    while(*b == 0){
    printf("\nNão é possivel divisão por 0, escolha outro numero: ");
    scanf("%lf", &*b);
    }
     return a / *b;
     break;
    
}
return 0;
}

void menu(){
    printf("\n-----------------------------------------------------\n");
    printf("\n|                 MENU DE OPERAÇÕES                 |\n");
    printf("\n|+ -> Soma                                          |\n");
    printf("\n|- -> Subtração                                     |\n");
    printf("\n|* -> Multiplicação                                 |\n");
    printf("\n|/ -> Divisão                                       |\n");
    printf("\n---------------------------------------------------\n\n");
    printf("Escolha uma operação: ");
}