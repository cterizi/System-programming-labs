#include <stdio.h>
//Otan eisagoume ts stoixeia tha prepei na ta dwsouem ola me thn seira pou theloume
//kai meta to enter
//px: 128a(enter) -> 128
//px: 2(enter) -> 2
//px: a(enter) -> 0
//px: (enter) -> 0
int main(void){
	char chr = '1';
	int num = 0;
	int c;
        
	printf("Give characters: \n");
	while(chr >= '0' && chr <= '9'){
	        scanf("%c",&chr);
		if(chr >= '0' && chr <= '9' ){
			c = chr - '0';
			num = num*10 + c;
		}
		else{
			break;
		}
	}
	printf("Final: %d", num);
	return 0;
}
