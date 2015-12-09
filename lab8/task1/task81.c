#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#define N 200

struct leitourgies{
	char lektiko[N];
	char path[N];
	char name[N];	
};
typedef struct leitourgies leitourgies_t;

leitourgies_t *create_menou(int flag){
	leitourgies_t *table;
	
	table = (leitourgies_t *)malloc(7*(sizeof(leitourgies_t)));
	
	strcpy(table[0].lektiko, "1. run firefox");
	strcpy(table[0].path, "/usr/bin/firefox");
	strcpy(table[0].name, "firefox");
	strcpy(table[1].lektiko, "2. run firefox (and wait)");
	strcpy(table[1].path, "/usr/bin/firefox");
	strcpy(table[1].name, "firefox");
	strcpy(table[2].lektiko, "3. run gedit");
	strcpy(table[2].path, "/usr/bin/gedit");
	strcpy(table[2].name, "gedit");
	strcpy(table[3].lektiko, "4. run gedit (and wait)");
	strcpy(table[3].path, "/usr/bin/gedit");
	strcpy(table[3].name, "gedit");
	strcpy(table[4].lektiko, "5. run gnome-calculator");
	strcpy(table[4].path, "/usr/bin/gnome-calculator");
	strcpy(table[4].name, "gnome-calculator");
	strcpy(table[5].lektiko, "6. run gnome-calculator (and wait)");
	strcpy(table[5].path, "/usr/bin/gnome-calculator");
	strcpy(table[5].name, "gnome-calculator");
	strcpy(table[6].lektiko, "0. exit");
	strcpy(table[6].path, "exit");
	strcpy(table[6].name, "exit");

	return(table);
}

void show_menou(leitourgies_t *table, int flag){
	int i;
	char str[N];

	for(i = 0; i < 7; i++){
		sprintf(str, "%s\n", table[i].lektiko);
		fputs(str, stdout);
	}
	printf("\n");
	
	return ;
}
int main(){
	leitourgies_t *table;
	char choose;
	int value_op, ret;

	table = create_menou(7);
	printf("Choose operation 0-6\n");
	show_menou(table, 7);
	scanf("%c", &choose);
	value_op = choose - '0';	

	//fork to paidi
	ret = fork();
	if(value_op == 1 || value_op == 3 || value_op == 5){
		//o pateras na mhn perimenei to paidi
		if(ret == 0){
			//child
			printf("I am the child (%d)\n", getpid());
			execl(table[value_op - 1].path, table[value_op - 1].name, NULL);
			printf("Apetyxe kapoia apo tis entoles 1, 3, 5\n");
			
		}
		else{
			//parent
			printf("I am the parent (%d)\n", getpid());
		}
	}
	else if(value_op == 0){
		//na kanei exit
		exit(1);
	}
	else{
		//o pateras na perimenei to paidi
		if(ret == 0){
			//child
			printf("I am the child (%d)\n", getpid());
                     execl(table[value_op - 1].path, table[value_op - 1].    name, NULL);
                     printf("Apetyxe kapoia apo tis entoles 2, 4, 6\n");

		}
		else{
			//parent wait for the child
			printf("I am the parent (%d)\n", getpid());
			waitpid(-1, NULL, 0);
		}
	}
	
	return 0;
}
