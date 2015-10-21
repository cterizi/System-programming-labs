#include <stdio.h>
double minmaxavg(double *, int, double *, double *);

int main(){
	double array[] = {3,7,5,12,8,5,0,4,3};
	double avg, *max, *min;
	int size;
	
	max = &array[0];
	min = &array[0];
	size = sizeof(array)/sizeof(double);
	//printf("max : %d\n", max);
	avg = minmaxavg(array, size, max, min);
	return 0;
}

double minmaxavg(double *array, int num, double *max, double *min){
	double i;

	//max - min
	for(i = 0; i <= num; i++){
		//max
		if(*(array + i) > *max){
			max = array + i;
		}
		//min
		if(*(array + i) < *min){
			min = array + i;
		}

	}
	printf("min : %d, max : %d", *min, *max);
	//max = *array;
	return 0;
}
