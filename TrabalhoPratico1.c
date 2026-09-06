
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXvendedores 20
#define MAXclientes 20
#define MAXatendimento 2000

struct vendedor
{
    char nome[50];
    char telefone[14];
};
typedef struct vendedor Vendedor;

struct cliente
{
    char nome[50];
    char telefone[14];
};
typedef struct cliente Cliente;

struct atendimento
{
    char nomeCliente[50];
    char nomeVendedor[50];
    char dataAtendimento[11];
    float notaAtendimento;
};
typedef struct atendimento Atendimento;

void limpaBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void corrigeFGets(char string[])
{
    string[strlen(string)-1] = '\0';
}
void exibeMenu()
{
    system("cls");
    printf("\nMenu");
    printf("\n1. Cadastrar novo vendedor");
    printf("\n2. Cadastrar novo cliente");
    printf("\n3. Avaliar atendimento");
    printf("\n4. Exibir historico individual de avaliassoes do vendedor");
    printf("\n5. Exibir ranking de vendedores");
    printf("\nS. Sair");
}
bool consultarVendedor(Vendedor vendedores[], int contadorVendedor, char nomeVendedor[]);
Vendedor cadastraVendedor(Vendedor vendedores[], int contadorVendedor)
{
    Vendedor dadosVendedor;
    limpaBuffer();
    bool achouVendedor = false;
    printf("\nDigite o nome: ");
    fgets(dadosVendedor.nome, 50, stdin);
    corrigeFGets(dadosVendedor.nome);

    achouVendedor = consultarVendedor(vendedores, contadorVendedor, dadosVendedor.nome);
    if(achouVendedor)
    {
        printf("\nVendedor jah existente, nao eh possivel cadastrar novamente.");
        limpaBuffer();
    }
    else
    {
        printf("\nDigite o numero de telefone: ");
        fgets(dadosVendedor.telefone, 14, stdin);
        corrigeFGets(dadosVendedor.telefone);
        printf("\nVendedor cadastrado com sucesso!!");
        limpaBuffer();
    }
    return dadosVendedor;
}

Cliente cadastraCliente(char nomeCliente[])
{
    Cliente dadosCliente;

    strcpy(dadosCliente.nome, nomeCliente);

    printf("\nDigite o numero de telefone: ");
    fgets(dadosCliente.telefone, 14, stdin);
    corrigeFGets(dadosCliente.telefone);

    limpaBuffer();

    return dadosCliente;
}

void inserirVendedor(Vendedor vendedores[], int *contador)
{

    vendedores[*contador] =cadastraVendedor(vendedores, *contador);
    *contador = *contador + 1;

}
bool consultarCliente(Cliente clientes[], int contadorClientes, char nomeCliente[]);// chamei novamente para usar na função inserir clientes
void inserirCliente(Cliente clientes[], int *contador)
{
    bool achouCliente = false;
    char nomeCliente[50];

    printf("\nDigite o nome do Cliente: ");
    fgets(nomeCliente, 50, stdin);
    corrigeFGets(nomeCliente);

    achouCliente = consultarCliente(clientes, *contador, nomeCliente);

    if(!achouCliente)
    {
        clientes[*contador] = cadastraCliente(nomeCliente);
        *contador = *contador + 1;
        printf("Cliente cadastrado com sucesso!!");
    }
    else
    {
        printf("\nCliente ja existente, nao eh possivel cadastrar novamente");
    }
}
void inserirAtendimento
(
    Atendimento atendimentos[],
    char nomeVendedor[],
    char nomeCliente[],
    char data[],float nota, int *contadorAtendimentos)
{
    Atendimento novoAtendimento;
    strcpy(novoAtendimento.nomeVendedor, nomeVendedor);
    strcpy(novoAtendimento.nomeCliente, nomeCliente);
    strcpy(novoAtendimento.dataAtendimento, data);
    novoAtendimento.notaAtendimento= nota;
    atendimentos[*contadorAtendimentos] = novoAtendimento;
    *contadorAtendimentos = *contadorAtendimentos + 1;
}
char pegaOpcao()
{
    printf("\nDigite sua opcao: ");
    return(getchar());
}

void mediaAtendimentos(int contadorAtendimentos,Atendimento atendimentos[],Vendedor vendedores[],int contadorVendedores)
{
float mediaVendedor[MAXvendedores]={0};
float somaVendedor[MAXvendedores]={0};
int AtendimentosVendedor[MAXatendimento]={0};
int i=0;


    for(int i =0; i <contadorAtendimentos; i ++)
    {

        printf("\ncliente:%s ",atendimentos[i].nomeCliente);
        printf(" vendendor:%s ",atendimentos[i].nomeVendedor);
        printf(" data:%s ",atendimentos[i].dataAtendimento);
        printf(" nota:%.2f ",atendimentos[i].notaAtendimento);
    }
            printf("\n----------------------------------------");
     for(int j=0;j<contadorVendedores;j++){
    for(i =0; i <contadorAtendimentos; i ++)
    {
        if(strcmp(atendimentos[i].nomeVendedor, vendedores[j].nome) == 0){
           AtendimentosVendedor[j] ++;
           somaVendedor[j]+= atendimentos[i].notaAtendimento;
        mediaVendedor[j] =  somaVendedor[j]/ AtendimentosVendedor[j];
        }
    }
    printf("\n\n vendendor:%s \n Media: %.2f",vendedores[j].nome,mediaVendedor[j]);
    }
}



bool consultarVendedor(Vendedor vendedores[], int contadorVendedor, char nomeVendedor[])
{
    int i;
    bool achouVendedor = false;
    for(i = 0; i < contadorVendedor && !achouVendedor; i++)
    {
        if(strcmp(nomeVendedor, vendedores[i].nome) == 0)
        {
            achouVendedor = true;
        }

    }
    return achouVendedor;
}
bool consultarCliente(Cliente clientes[], int contadorClientes, char nomeCliente[])
{
    int i;
    bool achouCliente = false;
    for(i = 0; i < contadorClientes && !achouCliente; i++)
    {
        if(strcmp(nomeCliente, clientes[i].nome) == 0)
        {
            achouCliente = true;
        }
    }
    return achouCliente;
}

int main()
{

    Vendedor vendedores[MAXvendedores];
    Cliente clientes[MAXclientes];
    Atendimento atendimentos[MAXatendimento];
    char opcao;
    int contadorVendedor=0;
    int contadorClientes=0;
    int contadorAtendimentos=0;
    bool achouVendedor;
    bool achouCliente;
    do
    {
        exibeMenu();
        opcao = pegaOpcao();

        switch(toupper(opcao))
        {
        case '1': /// cadastrar novo vendendor
        {
            if (contadorVendedor == MAXvendedores) /// array cheio
            {
                printf("\a\nERRO. Armazenamento cheio, acione o suporte T.I. ");
            }
            else ///tem espaco no array
            {
                limpaBuffer();
                inserirVendedor(vendedores, &contadorVendedor);
            }

            break;
        }
        case '2': /// cadastrar novo Cliente
        {

            if (contadorClientes == MAXclientes) /// array cheio
            {
                printf("\a\nERRO. Armazenamento cheio, acione o suporte T.I. ");
            }
            else ///tem espaco no array
            {
                limpaBuffer();
                inserirCliente(clientes, &contadorClientes);
            }
        }

        break;


        case '3': /// cadastrar atendimento
        {
            char nomeVendedor[50];
            char nomeCliente[50];
            char data[11];
            float nota;
            achouVendedor = false;
            achouCliente = false;
            limpaBuffer();
            printf("\nDigite o nome do vendedor: ");
            fgets(nomeVendedor, 50, stdin);
            corrigeFGets(nomeVendedor);
            achouVendedor = consultarVendedor(vendedores,contadorVendedor,nomeVendedor);
            if(achouVendedor)
            {
                printf("\nDigite o nome do Cliente: ");
                fgets(nomeCliente, 50, stdin);
                corrigeFGets(nomeCliente);
                achouCliente = consultarCliente(clientes,contadorClientes,nomeCliente);
            }
            if(achouVendedor && achouCliente)
            {
                printf("\nInforme a data:");
                fgets(data,11,stdin);
                corrigeFGets(data);
                printf("\nInforme a nota do atendimento feito pelo vendedor %s:",nomeVendedor);
                scanf("%f",&nota);

                inserirAtendimento(atendimentos,nomeVendedor,nomeCliente,data,nota, &contadorAtendimentos);
                printf("\nAtendimento cadastrado com sucesso!!");
            }
            else if(!achouVendedor)
            {
                printf("\nvendedor informado noo existe");
            }
            else if(!achouCliente)
            {
                printf("\nCliente informado nao existe");
            }
            break;
        }
        case '4':
        {
            mediaAtendimentos(contadorAtendimentos,atendimentos,vendedores,contadorVendedor);
            break;
        }

        }
        printf("\n\n");
        system("pause");

    }
    while(toupper(opcao) != 'S');

    return 0;
}
