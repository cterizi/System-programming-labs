#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pfd1[2], pfd2[2], ret, number, sum, count, n;
	double avg;

	if(pipe(pfd1) < 0){
		perror("pipe(pfd1) \n");
		exit(1);
	}

	if(pipe(pfd2) < 0){
		perror("pipe(pfd2) \n");
		exit(1);
	}
	
	sum = 0;
	count = 0;	
	ret = fork();
	if(ret == 0){
		//child, write to pfd2, close read pfd2, sum, avg
		close(pfd1[1]);
		close(pfd2[0]);
		while((n = read(pfd1[0], &number, sizeof(int))) >= 0){
			if(n == 0){
				break;
			}
			count = count + 1;
			sum = sum + number;
		}
		avg = sum / (double)count;
		write(pfd2[1], &sum, sizeof(int));
		write(pfd2[1], &avg, sizeof(double));
	}
	else{
		//parent, write to pfd1, close read pfd1
		//number = 0;
		close(pfd1[0]);
		close(pfd2[1]);
		while(1){
			printf("Give number : ");
			scanf("%d", &number);
			if(number == -1){
				close(pfd1[1]);
				break;
			}
			else{
				write(pfd1[1], &number, sizeof(int));
			}
		}
		waitpid(-1, NULL, 0);
		read(pfd2[0], &sum, sizeof(int));
		read(pfd2[0], &avg, sizeof(double));
		printf("sum = %d, avg = %f \n", sum, avg);
	}
	return 0;
}
