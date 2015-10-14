#include <stdio.h>

int main(){
	int N;
	int array[10] = {1};


	printf("Give value for N : ");
	scanf("%d", &N);

	while( N < 1 ){
		printf("Give value for N again : ");
	        scanf("%d", &N);
	}

	int i ; 
	for(i = 1; i <= 10; i++){
		array[i-1] = N * i;
		printf("% d x %d = %d \n", i, N, array[i-1]);
	}

	printf("Give value for N : ");
	scanf("%d", &N);
	while( N > 10 || N < 1){
		printf("Give value for N again : ");
		scanf("%d", &N);
	}
	int array2[10][N];
	int k, l;
	for(l = 1; l <= N; l++){
		for(k = 1; k <= 10; k++){
			array2[k][l] = (k*l);
			printf("%d x %d = %d \n", k, l, array2[k][l]);
		}
		printf("------------\n");
	}

	return 0;
}
