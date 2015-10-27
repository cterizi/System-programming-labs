#include <stdio.h>
#include <string.h>
void add(char *[]);
void deduction(char *[]);
void multi(char *[]);
void divi(char *[]);

int main(int argc, char *argv[]){
	int result, i, sum;

	printf("Name of file : %s\n", argv[0]);
	if(argc < 3){
		printf("error");
		return 0;
		//exit(1);
	}
	if(*argv[1] == '+'){
		add(argv);
	}
	else if(*argv[1] == '-'){
		deduction(argv);
	}
	else if(*argv[1] == 'm'){
		multi(argv);
	}
	else if(*argv[1] == '/'){
		divi(argv);
	}
	else{
		return 0;
	}
	return 0;

}

void add(char *a[]){
	int i, sum;

	i = 2;
	sum = 0;
	while(a[i]){
		sum = sum + atoi(a[i]);
		i = i + 1;
	}
	printf("Add : %d\n", sum);
	return;
}

void deduction(char *a[]){
	int dedu, i;

	i = 3;
	dedu = atoi(a[2]);
	while(a[i]){
		dedu = dedu - atoi(a[i]);
		i = i + 1;
	}
	printf("Deduction : %d\n", dedu);
	return;
}

void multi(char *a[]){
	int i, value;

	value = 1;
	i = 2;
	while(a[i]){
		value = value * atoi(a[i]);
		i = i + 1;
	}
	printf("Multiple : %d\n", value);
	return;
}

void divi(char *a[]){
	int i;
	float value;

	value = atoi(a[2]);
	printf("%f\n", value);
	i = 3;
	while(a[i]){
		value = value / atoi(a[i]);
		i = i + 1;
	}
	printf("Division : %f\n", value);
	return;
}
