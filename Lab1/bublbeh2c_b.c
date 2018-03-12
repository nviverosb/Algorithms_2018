#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_NUMBERS = 1000000 };  // Choose appropriate upper bound

long long f(double n)
{
	int f = 1;
      int i;
      for(i = 1; i <= n; i++)
     {
          f *= i;
      }
      return f;
}

int main(){
	int N;
	//fgets(N, sizeof(N), stdin);
	scanf("%d", &N);
	long long arr[N];
    char input[N],temp;
	long long tmp;


	for(int i=0;i<N;i++){
		if(scanf("%lld", &arr[i]) != 1){
			i--;
		}
	}

	// for(int i=0;i<N*2;i++){
	// 	temp = getchar();
	// 	if(i%2 != 0){
	// 		arr[i/2] = temp - '0';
	// 	}
	// }

	// for(int i=0;i<N;i++){
	// 	printf("%ld \n",arr[i]);
	// }


	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-1;j++){
			if( arr[j] > arr[j+1]){
	            tmp = arr[j];
	            arr[j] = arr[j+1];
	            arr[j+1] = tmp;
			}
		}
	}

	int numero = 0;
	int index = arr[0];
	long long total = 0;

	// for(int i=0;i<N;i++){
	// 	printf("%lld\n",arr[i]);
	// }

	for(int i=0;i<N-1;i++){
		if(i != N-2){
			if (index==arr[i+1]){
				numero++;
			}
		    else{
		        index = arr[i+1];
		        if (numero >= 2){
		             total = total + f(numero+1)/f(2)/f(numero-1);
				}
		        else if(numero == 1){
		            total = total + 1;
				}
		        numero = 0;
			}
		}
		else{
			if (index==arr[i+1]){
				numero++;
			}
			if (numero >= 2){
				 total = total + f(numero+1)/f(2)/f(numero-1);
			}
			else if(numero == 1){
				total = total + 1;
			}
		}
		//printf("TOTAL %lld    NUM %d    I %d     INDEX %d\n",total,numero,i,index);
	}

	printf("%lld",total);
}
