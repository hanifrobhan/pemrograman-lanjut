#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void insersi(int a[],int n);
int main()
{
	int kode[]={98,61,76,30,42,67,91,53,55,64,20,72,22,29,86,84,99,97,83,95,46,82,21,57};
	printf("Kode awal :\n");
	for(int i=0;i<24;i++)
		printf("%i ",kode[i]);	
	printf("\nPengurutan dengan menggunakan insertion sort :\n");
	insersi(kode,24);
	getch();	
}
void insersi(int a[], int n) 
{
	int sementara,posisi;
	for(int i=0;i<n;i++){
		sementara=a[i];
		posisi=i;
		while(posisi>0 && a[posisi-1]>sementara){
			a[posisi]=a[posisi-1];
			posisi=posisi-1;
		}
		a[posisi]=sementara;
	}
	for(int i=0;i<n;i++)
		printf("%i ",a[i]);	
}

