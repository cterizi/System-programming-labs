#include <stdio.h>

int main(){
	int value = 0;

	while(value != 502){
		printf("Give number : \n");
		scanf("%d", &value);
		if(value == 502){
			break;
		}
		else{
			printbin(value);
		}
		
	}
	return 0;
}

void printbin(int num){
	int array[32] = {2};
	int mod;
	int div = 1;
	int num2 = num;
	int count = 0;
	int i = -1;

	while(div != 0){
		count = count + 1;
		//printf("count : %d \n", count);
		mod = num2 % 2;
		i = i + 1;
		array[i] = mod;
		//printf("The mod is %d \n", mod);
		div = num2 / 2;
		//printf("The div is %d \n", div);
		//printf("%d \n", mod);
		num2 = num2 / 2;
		//printf("The new number is %d \n", num2);
		
	}
	

	int k = count - 1;
	printf("(%d)d -> (" , num) ;
	for(k; k>=0; k--){
		printf("%d", array[k]);
	}
	printf(")b");
	printf("\n");
	return;
}
