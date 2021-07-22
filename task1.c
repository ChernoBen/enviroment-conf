#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 1000
typedef struct key{
  char tipo;
}TipoItem;

typedef struct pilha {
  TipoItem item[max];
  int topo;
}Pilha;

//prototipos
void criarPilha(Pilha *pi);
void empilha(Pilha *pi,TipoItem c);
int taVazia(Pilha pi);
void desempilha(Pilha *pi,TipoItem *x);
int prioridade(char a,char b);
void imprime(Pilha *pi);

int main(){
  int counter =0;
  Pilha pi;
  criarPilha(&pi);
  TipoItem elemento,pop;
  char funcao[max];
  int i,j;
  int p = prioridade('a','b');
  printf("%d\n",p);
  //(2+4)+5
  //regex pra processar entrada
  scanf("%[^\n]",funcao);//https://regexr.com/
  for (i=0;i<strlen(funcao);i++){
    elemento.tipo = funcao[i];
    if((elemento.tipo == '-') || (elemento.tipo == '+') || (elemento.tipo == '/') || (elemento.tipo == '^') || (elemento.tipo == '*') || (elemento.tipo == '(') || (elemento.tipo == ')')){
      if((pi.topo == 0)|| (elemento.tipo == '(')){
        empilha(&pi,elemento);
      }else if((pi.topo == 0)||(elemento.tipo==')')){
        while((pi.topo>0)&&(pop.tipo!='(')){
          //printf("talvez-");
          imprime(&pi);
          desempilha(&pi,&pop);
        }
        desempilha(&pi, &pop);
      }else{
        while(pi.topo>0){
          imprime(&pi);
          desempilha(&pi,&pop);
        }
        empilha(&pi,elemento);
      }
    }else{
      printf("%c",elemento.tipo);
    }
  }
  while(pi.topo>0){
    //printf("---fim-----\n");
    imprime(&pi);
    desempilha(&pi,&pop);
  }
  printf("\n");
  return 0;
}

//funções

void criarPilha(Pilha *pi){
  pi->topo=0;
}

void empilha(Pilha *pi,TipoItem c){
  if(pi->topo == max){
    printf("Pilha cheia.\n");
    return;
  }else{
    pi->item[pi->topo] = c;
    pi->topo++;
  }
}

int taVazia(Pilha pi){
  return (pi.topo == 0);
}

void desempilha(Pilha *pi,TipoItem *x){
  char c;
  if(taVazia(*pi)){
    return;
  }else{
    *x = pi->item[pi->topo-1];
    pi->topo--;
  }
}

int prioridade(char a,char b){
  if('a'<='c'){
    return 1;
  }else{
    return 0;
  }
}

//imprime
void imprime(Pilha *pi){
  TipoItem element;
  TipoItem open,close;
  open.tipo = '(';
  close.tipo = ')';
  if(pi->topo ==0){
    printf("Pilha vazia.\n");
  }else{
    int i;
    for(i = 0;i < pi->topo; i++){
      element = pi->item[i]; 
      if((element.tipo !=open.tipo) && (element.tipo != close.tipo)){
        printf("%c",element.tipo);
      }
    }
  }
}