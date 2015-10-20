#include <stdio.h>
void numincr(char *, int);

int main(){
	char symbols[] = {'a', '2', '4', 'q', 'r', '\0'};
	int size, i;
	char *p;

	//p = NULL;
	p = &symbols[0];
	printf("p = %d\n", p);
	size = sizeof(symbols) / sizeof(char);
	//printf("size = %d\n", size);
	for(i = 0; i < size; i++){
		printf("%c", symbols[i]);
	}
	printf("\n");
	numincr(&p, 2);
	/*for(i = 0; i < size; i++){
		printf("%c", symbols[i]);
	}*/
	return 0;
}

void numincr(char *i, int n){
	int count;
	//char *i;
	
	//i = *p;
	count = 0;
	printf("%d\n", i);
	/*while(count < n){
		if(*p >= '0' && *p <= '8'){
			*p = *p + 1;
			printf("%c\n", *p);
			count = count + 1;
			p = p + 1;
		}
	}*/
	return;
}
