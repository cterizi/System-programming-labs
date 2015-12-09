#include <stdio.h>
char *string_end(char *);
void string_reverse(char *);

int main(){
	char string[51];
	
	printf("Give the string : ");
	fgets(string, 50, stdin);
	
	string_reverse(string);

	printf("%s\n", string);
	return 0;
}

char *string_end(char *str){
	char c;

	if(*str == '\0'){
		return str;
	}
	
	c = *(str + 1);
	while( c != '\0'){
		str = str + 1;
		c = *(str);
	}
	return str;
}

void string_reverse(char *str){
	char start;
	char *last;
	
	last = string_end(str);

	start = *str;
	*str = *last;
	*last = start;
	return;
}
