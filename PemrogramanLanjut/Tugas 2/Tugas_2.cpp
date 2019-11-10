#include <stdio.h>

int rekursi(int x, int n);
int iterasi(int x, int n);
int num1, num2;

int main(void) {    
    printf("Masukkan bilangan : \n");
    scanf("%d", &num1);
    printf("Masukkan pangkat : \n");
    scanf("%d", &num2);
    
    printf("\n%d pangkat %d menggunakan rekursi = %d\n", num1, num2, rekursi(num1, num2)); 
    printf("\n%d pangkat %d menggunakan iterasi = %d\n", num1, num2, iterasi(num1, num2));
    return 0;
}

int rekursi(int x, int n) {
    if (n == 0)
        return 1;     
    else
        return x * rekursi(x, n - 1);  
}

int iterasi(int x, int n) {
	x=1;
	for (int i=0;i<num2;i++)
		x=x*num1;
	return x;
}
