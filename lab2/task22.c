#include <stdio.h>

int main(){
	int a[10] = {0, 2, 4, 6, 8, 7, 6, 4, 2, 0};
	int *pa = &a[1], *pb = &a[8], *pc;

	printf("1. *(a + 6) = %d\n", *(a + 6));
	//6
	printf("2. pb - pa = %d\n", pb - pa);
	//pb = dieythhnsh tou a[8]
	//pa = dieythhnsh tou a[1]
	printf("3. pb[1] = %d\n", pb[1]);
	//to periexomeno tou keliou *(pb + 1)
	//0
	printf("4. &pb[1] = %d\n", &pb[1]);
	//dieythhnsh (pb + 1)
	printf("5. *pa += 3 = %d\n", *pa += 3);
	//to pa exei thn dieythhnsh tou a[1]
	//auxanei thn timh ths dieythhnshs auths kata 3
	//5
	printf("6. *(pb -= 3) = %d\n", *(pb -= 3));
	//to pb exei thn dieythhnsh tou a[8]
	//pame 3 kelia pio panw apo authn thn dieythhnsh
	//kai pairnoume to periexomeno
	//7
	printf("4.1 To periexomeno tou 9ou keliou tou pinaka einai  %d\n", *(pb + 3));
	//0
	printf("5.1 To periexomeno tou 4ou keliou tou pinake einai  %d\n", *(pa +2));
	//6
	printf("6.1 H dieythhnsh tou 5ou keliou tou pinaka einai  %d\n", (pb - 1));
	
	pc = &a[0];
	printf("Timh mhdenikou keliou tou pinaka %d\n", *pc);
	return 0;
}
