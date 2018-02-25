#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

double matriz(int n){

  clock_t start, end;
  double timeUsed;
  start = clock();
  int matriz2[n][n];
  int matriz1[n][n];
  int matrizResultado[n][n];
  int numberOfInstructions = 2*n*n*n - n*n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      matriz1[i][j] = 1;
      matriz2[i][j] = 2;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
  end = clock();
  timeUsed = ((double) (end - start))/CLOCKS_PER_SEC;

  return timeUsed/numberOfInstructions;
}

int main(){

  // printf("Seleccione el tamano de matrics \n");
  //int reg;
  // scanf("%i",&reg);
  for(int i=0;i<500;i++){
    printf("%d ", i);
    printf("%.15f\n", matriz(i));
  }
}
