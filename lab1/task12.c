#include <stdio.h>

int main(){
	char ch;
	int i, j, count, tcount;
	char table[31] = {'#'};
	int nums[31] = {0};
	j = -1;
	tcount = 0;
	int k;


	printf("Give characters : \n");
	for(i = 0; i<= 76; i++){
		scanf("%c", &ch);
		//printf("i = %d \n", i);
		if(ch == '$'){
			break;
		}
		else if(ch >= 'a' && ch <= 'z'){
			//printf("First : %c \n", ch);
			ch = toupper(ch);
			//printf("Last : %c \n", ch);
			table[i]=ch;
		}
		else if(ch >= 'A' && ch<= 'Z'){
			//printf("First : %c \n", ch);
			ch = tolower(ch);
			//printf("Last : %c \n", ch);
			table[i]=ch;
			   
		}
		else if(ch >= '0' && ch <= '9'){
			j = j + 1;
			table[i] = ch;
			nums[j] = ch - '0';
			tcount = tcount + 1;
			//printf("The number is %c \n", ch);
		}
		else{
			continue;
		}
	}
	
	//printf("tcount : %d", tcount);
	printf("Ta stoixeia tou pinaka einai : \n");
	for(k = 0; k < tcount; k++){
		printf("%d \n", nums[k]);	
	}


	return 0;	
}
