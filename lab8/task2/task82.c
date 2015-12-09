#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#define N 200

int main(){
	int pfd[2], ret, number, n;
	FILE *outfile;
	char str[N];

	//number = 0;
	if(pipe(pfd) < 0){
		perror("pipe() \n");
		exit(1);
	}
	
	outfile = fopen("positive.txt", "w");
	if(outfile == NULL){
		perror("fopen() \n");
		exit(1);
	}
	
	ret = fork();
	if(ret == 0){
		//child
		printf("I am the child (%d)\n", getpid());
		fclose(outfile);
		close(pfd[0]);
		printf("The child read numbers from the keyboard : \n");
		number = 0;
		while(number != -1){
			printf("Give number : \n");
			scanf("%d", &number);
			sprintf(str, "%d", number);
			write(pfd[1], str, sizeof(str));
		}
	}
	else{
		//parent
		printf("I am the parent (%d)\n", getpid());
		//waitpid(-1, NULL, 0);
		close(pfd[1]);
		while((n = read(pfd[0], str, 4)) >= 0){
			if(n == 0){
				break;
			}
			if(atoi(str) > 0){
				fputs(str, outfile);
				fputs("\n", outfile);
			}
		}
	}
	//child write to pipe, read fron keyboard
	//parent read from the pipe
	fclose(outfile);
	return 0;
}
