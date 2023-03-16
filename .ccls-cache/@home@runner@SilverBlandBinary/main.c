#include <stdio.h>

#define TAM_NOME 40
#define TAM_ARRAY 3

typedef struct {
  int matr;
  char nome[TAM_NOME + 1];
}ALUNO;

ALUNO registros[TAM_ARRAY];

void preencherArray(){
  
  for(int i = 0; i < TAM_ARRAY; i++){
    printf("Informe a matricula do aluno:\n");
    scanf("%d",&registros[i].matr);
    printf("Informe o nome do aluno:\n");
    scanf("%s",registros[i].nome);
  }
  
}

void ordenarArray(){
  for(int i = 0;  i < TAM_ARRAY - 1; i++){
    int posMenor = i;
    for(int j = i + 1; j < TAM_ARRAY; j++){
      if(registros[j].matr < registros[posMenor].matr){
        posMenor = j;
      }
    }
    int auxMatr = registros[i].matr;
    char auxNome[TAM_NOME + 1];
    strcpy(auxNome,registros[i].nome);
    
    registros[i].matr = registros[posMenor].matr;
    strcpy(registros[i].nome, registros[posMenor].nome);
    registros[posMenor].matr = auxMatr;
    strcpy(registros[posMenor].nome, auxNome);
  }
}

int realizarBuscaBinaria(int num){
  int base = 0;
  int topo = TAM_ARRAY - 1;
  int meio = (topo + TAM_ARRAY - 1) / 2;
  int resultado = -1;

  for(int i = meio; i < base; i ++){
    if(num > meio){
      topo = meio + 1;
    }
    else if(num < meio){
      base = meio - 1;
    }
  }
  return resultado;
}

int main(void) {

  int num;
  preencherArray();
  ordenarArray();
  int resp = realizarBuscaBinaria(num);

  for(int i = 0; i < TAM_ARRAY; i++){
    printf("\nmatricula: %d\nnome: %s\n",registros[i].matr, registros[i].nome);
  }
  
  return 0;
}