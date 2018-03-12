#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_NUMBERS = 1000000 };  // Choose appropriate upper bound

long f(double n)
{
	int f = 1;
      int i;
      for(i = 1; i <= n; i++)
     {
          f *= i;
      }
      return f;
}

void swap(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}

int partition (long arr[], int low, int high)
{
    long pivot = arr[high];    // pivot
    long i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(long arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	int N;
	//fgets(N, sizeof(N), stdin);
	scanf("%d", &N);
	long arr[N];
    char input[N],temp;
	long tmp;


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


	quickSort(arr, 0, N-1);

	int numero = 0;
	int index = arr[0];
	long total = 0;

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
