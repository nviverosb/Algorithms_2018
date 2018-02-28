#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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
      matriz1[i][j] = rand()%2;
      matriz2[i][j] = rand()%2;
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
  //return timeUsed;
}

int main(){

  FILE *apf;
  apf = fopen("matricesC.dat","w");
  // printf("Seleccione el tamano de matrics \n");
  int n = 300;
  int r;

  // scanf("%i",&reg);

  double resultados[10][n];
  double promedios[n];

  for(int i=0;i<n;i++){
    promedios[i] = 0;
  }

  for(int i=0;i<10;i++){
    for(int j=0;j<n;j++){
      resultados[i][j] = matriz(j+1);
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      promedios[i] = promedios[i] + resultados[j][i]/10;
    }
  }

  for(int i=0;i<n;i++){
    //printf("%d ", i);
    //printf("%.15f\n", promedios[i]);
    char output[20];
    snprintf(output, 20, "%i %.17f\n", i+1, promedios[i]);
    r = fwrite(output,sizeof(output),1,apf);
    fwrite("\n", sizeof("\n"), 1, apf);
  }

  r = fclose(apf);
}
