#include <stdio.h>
void numincr(char *, int);

int main(){
	char symbols[] = "af298h";
	int size, i, count;
	char *p, *w;

	p = symbols;
	w = symbols;
	size = sizeof(symbols) / sizeof(char);
	count = 0;
	for(i = 0; i < size; i++){
		if(*w >= '0' && *w <= '8'){
			count = count + 1;
		}
		w = w + 1;	
	}
	printf("%s -> ", symbols);
	numincr(p, count);
	printf("%s\n", symbols);
	return 0;
}

void numincr(char *i, int n){	
	int count;

	count = 0;
	while(count < n){
		if(*i >= '0' && *i <= '8'){
			*i = (char)(((int)*i) + 1);
			count = count + 1;
		}
		i = i + 1;
	}
	return;
}
