#include <stdio.h>
double minmaxavg(double [], int, double *, double *);

int main(){
	double array[] = {3,7,5,12,8,5,0,4,3,-1};
	double avg, max, min;
	int size;
	
	size = sizeof(array)/sizeof(double);
	avg = minmaxavg(array, size, &max, &min);
	printf("avg = %f, min = %f, max = %f", avg, min, max);
	return 0;
}

double minmaxavg(double array[], int num, double *max, double *min){
	double avg, sum;
	int i;
	
	*max = array[0];
	*min = array[0];
	sum = 0;
	//max - min - sum
	for(i = 0; i < num; i++){
		//max
		if(array[i] > *max){
			*max = array[i];
		}
		//min
		if(array[i] < *min){
			*min = array[i];
		}
		//sum
		sum = sum + array[i];

	}

	avg = sum / (double)num;
	return avg;
}
