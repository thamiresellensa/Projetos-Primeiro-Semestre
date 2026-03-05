//Sistema de gestão bancária
#include <stdio.h>
#include <string.h>


typedef struct{
  char nome[100];
  int idade;
  int cpf;
  int senha;
  double saldo;
} Cliente;

//funcao para salvar os dados dos clientes
int salvarCliente(Cliente cliente[]){
  
  FILE *arq = fopen("clientes.txt", "wb");

  if(arq == NULL){
    printf("\n❌erro ao tentar encessar!\n");
    return 1;
  }
  fwrite(cliente,sizeof(Cliente), 1, arq);

  
  fclose(arq);

  printf("\nVolte sempre ao nosso Banco DD 🐝!\n");

  return 0;
}

int verificarCliente(Cliente cliente[],char nome[100]){

  FILE *arq = fopen("clientes.txt","rb");

  if(arq==NULL){
    return 0;
  }
    fseek(arq, SEEK_SET, 0); // vai até o inicio do arquivo
    while(!feof(arq)){
        fread(cliente->nome,100,1,arq);
        if(!strcmp(cliente->nome,nome)) // compara o nome da musica com o nome da musica desejada
        fread(cliente,sizeof(Cliente),1,arq);     
        return 2; // retorna a musica se encontrar
    }
  fclose(arq);
  
  return 1;
}

double transferir(Cliente cliente[]);
double deposito(Cliente cliente[]);
void abrir(Cliente cliente[]);
void mostrarsaldo(Cliente cliente[]);
void acao(Cliente cliente[]);
void menu();



int main(){
      
    Cliente cliente;
    char nome[100];

    printf("\n------------------------------------\n");
    printf("\n|    💲 Bem-Vindo ao banco DD 🐝    |\n");
    printf("\n------------------------------------\n\n");
    
    printf("Insira seu nome completo: ");
    fgets(nome,100,stdin);
    int cliente_existente;
    cliente_existente = verificarCliente(&cliente, nome);

    if(cliente_existente==1){
    acao(&cliente);
    }
    else{
    abrir(&cliente);
    }
  
     return 0;
}
void abrir(Cliente cliente[]){
printf("\nPercebermos que você ainda não tem uma conta!\n\n");
printf("\n------------------------------------\n");
printf("\n|       Criando a sua conta...      |\n");
printf("\n------------------------------------\n");
printf("\nPreencha os dados abixo:\n");
printf("Nome completo: ");
fgets(cliente->nome,100,stdin);
printf("Idade: ");
scanf("%d", &cliente->idade);
printf("Cpf: ");
scanf("%d", &cliente->cpf);
printf("\n------------------------------------\n");
printf("Agora para finalizar o processamento da sua conta,\nvamos precisar de uma senha com 5 digitos.\n");
printf("Senha: ");
scanf("%d", &cliente->senha);
printf("\n------------------------------------\n");
cliente->saldo = 0.0;
printf("\nConta criada com sucesso!\n");
printf("\n------------------------------------\n");
printf("\n|            💰Banco DD             |\n");
printf("\n------------------------------------\n");
printf("\n🐝 %s\n",cliente->nome);
printf("\nSaldo atual: $%.2lf\n",cliente->saldo);
printf("\n------------------------------------\n");
acao(cliente);

}

void menu(){
    printf("\n------------------------------------\n");
    printf("\n|       💰Operações Bancárias      |\n");
    printf("\n------------------------------------\n");
    printf("\n|1 - Visualizar saldo              |\n");
    printf("\n|2 - Depósito                      |\n");
    printf("\n|3 - transferir                    |\n");
    printf("\n|4 - Sair                          |\n");
    printf("\n------------------------------------\n");
    printf("Escolha uma operação: ");
}
void mostrarsaldo(Cliente cliente[]){
    printf("\n------------------------------------\n");
    printf("\n|              💰Saldo              |\n");
    printf("\n------------------------------------\n");
    printf("nome - %s\n",cliente->nome);
    printf("\nSaldo = %.2lf\n",cliente->saldo);
    printf("\n------------------------------------\n");
}
double deposito(Cliente cliente[]){
    double deposito;
  printf("\n------------------------------------\n");
  printf("\n|            💰Depósito             |\n");
  printf("\n------------------------------------\n");
  printf("Digite o valor que vai ser depositado: ");
  scanf("%lf", &deposito);
  cliente->saldo += deposito;
  printf("\nDepósito concluida!\n");
  mostrarsaldo(cliente);

  return 0.0;
}
double transferir(Cliente cliente[]){
    double trasnferir;
    printf("\n------------------------------------\n");
  printf("\n|          💰Transferência            |\n");
  printf("\n------------------------------------\n");
  printf("Digite o valor que vai ser trasnferido: ");
  scanf("%lf", &trasnferir);
  if(trasnferir>cliente->saldo){
    printf("\nSaldo insuficiente!\n");
  }
  else{
    printf("\nTransferência concluida!\n");
    cliente->saldo -=trasnferir;
    mostrarsaldo(cliente);

  }
  return 0.0;
}
void acao(Cliente cliente[]){
  int opcao;
 do{
    menu();
    scanf("%d", &opcao);
    switch(opcao){
        case 1: 
        mostrarsaldo(cliente);
        break;
        case 2: 
        deposito(cliente);
        break;
        case 3: 
        transferir(cliente);
        break;
        case 4: 
        salvarCliente(cliente);
        break;
        default:
        printf("Escolha inválida!\n");
        break;
    }
    }while(opcao != 4);
}