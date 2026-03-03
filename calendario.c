//Imprimindo um calendário
#include <stdio.h>

//funcao para calcular se o ano é bissexto
int bissexto(int ano);

//funcao para calcular que dia vai cair o primeiro dia do ano
int primeirodia(int ano);
int main(){

    int ano;
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril",  "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *dias[] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};
    int quant[] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int B;
    
    printf("---------------------------------------------\n");
    printf("-> Digite um ano para visualizar o calendário: ");
    scanf("%d", &ano);

    B = bissexto(ano);

    if(B==1){
        quant[1]= 29;
    }
    int num;
    num = primeirodia(ano);
    printf("\n\n----------------- Calendário de %d ---------------------\n",ano);
    
    for(int mes = 0; mes <12; mes++){
        int aux=0;
    printf("\n------------- %s --------------\n",meses[mes]);
    
     for(int dia=0; dia<7; dia++){
        printf(" %s ", dias[dia]);
     }
     printf("\n");

     while(num>0){
            printf("     ");
            num--;
            aux++;
    }
     for(int i = 1; i<=quant[mes]; i++){
        printf("%4d ",i);
        aux++;
        if(aux>=7){
            printf("\n");
            aux=0;
        }
     }
      num = aux;
     printf("\n");
    
    }
      
    
}

int bissexto(int ano){
    if(ano%4 == 0 && ano%100 != 0 || ano%400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int primeirodia(int ano){
    int dia;
    dia = (((ano-1)*365)+((ano-1)/4)-((ano-1)/100)+((ano)/400)+1)%7;
    return dia;
}