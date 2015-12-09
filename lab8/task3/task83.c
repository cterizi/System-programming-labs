#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define N 200
#include <string.h>
#include <sys/wait.h>

int main(){
	int pfd[2], ret, x;
	char command[N];

	if(pipe(pfd) < 0){
		perror("pipe() \n");
		exit(1);
	}
	ret = fork();
	if(ret == 0){
		//child, close write, read only
		close(pfd[1]);
		printf("I am the child (%d)\n", getpid());
		x = dup2(pfd[0], STDIN_FILENO);
		if(x < 0){
			perror("dup2() \n");
			exit(1);
		}
		execl("/usr/bin/gnuplot", "gnuplot", NULL);
		printf("gnuplot den ektelesthke swsta\n");
	}
	else{
		//parent, write, close read
		printf("I am the parent (%d)\n", getpid());
		close(pfd[0]);
		//thelw na kanw to paidi na perimenei ton patera	
		while(1){
			printf("Give command : \n");
			if(fgets(command, N, stdin) == NULL){
				break;
			}
			write(pfd[1], command, strlen(command));
		}
		//strcat(command, "\n");
		//dup2(pfd[1], STDOUT_FILENO);
		//write(pfd[1], command, N);
		waitpid(-1, NULL, 0);
	}
	return 0;
}
