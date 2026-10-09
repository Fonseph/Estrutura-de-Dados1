#include<stdio.h>

int main()
{
/*
1. Crie um programa que contenha um array de inteiros contendo 5 elementos.
Utilizando apenas aritmética de ponteiros,
 leia esse array do teclado e imprima o dobro de cada valor lido.
*/
int valores[5];
int *ptrvalores[5];
int i,j;
for(i;i<5;i++)
{
printf("Informe o valor %i:\n",i);
scanf("%i",&valores[i]);
}

for(j=0;j<5;j++)
{
 ptrvalores[j] = &valores[j];
 *ptrvalores[j]=*ptrvalores[j]*2;
 printf("\n%i",*ptrvalores[j]);
}

/*
2. Crie um programa que contenha um array contendo 10
elementos inteiros.
 Leia esse array do teclado e imprima o endereço
  das posições contendo valores pares.
*/
int i,
array[10];
int *ptrarray[10];
for(i=0;i<10;i++)
{
printf("Informe o valor %i:\n",i);
scanf("%i",&array[i]);

}
for(i=0;i<10;i++){
if(array[i]%2==0){
ptrarray[i]=&array[i];
printf("\nvalor %i:\n",array[i]);
printf("\tenderesso do valor %p:\n",ptrarray[i]);
}
}

return 0;
}


