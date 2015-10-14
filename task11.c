#include <stdio.h>

int main(){
	int a, A;
	float pr1, pr2, TE, BE, GR;

	printf("Give the number of your absences : ");
	scanf("%d", &a);

	printf("PR1 : ");
	scanf("%f", &pr1);

	printf("PR2 : ");
	scanf("%f", &pr2);

	printf("TE : ");
	scanf("%f", &TE);

	if(a == 0){
		A = 10;
	}
	else if(a == 1){
		A = 5;
	}
	else{
		A = 0;
	}

	BE = (A*0.2) + (pr1*0.4) + (pr2*0.4);
	if(BE < 4.5){
		printf("\n Apotyxia sta ergasthria \n");
		return 0;
	}

	if(TE < 4.5){
		printf("Apotyxia sthn telikh exetash \n");
		return 0;
	}

	GR = (BE*0.4) + (TE*0.6);
	printf("Epityxia sto ply410 me bathmo %f", GR);

	return 0;
}
