#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void tukar(int *a, int *b);
void tampilkan(int a[]);
void acak(int a[]);
 int cek_urutan(int a[]);
 int gelembung(int a[], int i, int j);
 int interpolasi(int a[],int atas,int bawah, int cari);
int main()
{
	char pilihan;
	int kode[]={98,61,76,30,42,67,91,53,55,64,20,72,22,29,86,84,99,97,83,95,46,82,21,57};
	do{
		int pil=1,cari;
		system("cls");
		printf("Data kode :\n");
		tampilkan(kode);
		printf("\n\nMasukkan Pilihan :\n");
		printf("1. Acak kode\n");
		printf("2. Urutkan menggunakan metode bubble sort\n");
		printf("3. Cari kode dalam data dengan metode interpolation search\n");
		printf("q. Keluar\n");
		fflush(stdin);
		scanf("%c",&pilihan);
		if(pilihan=='1'){
			while(pil!=2)
			{
				system("cls");
				printf("Data kode lama :\n");
				tampilkan(kode);
				acak(kode);
				printf("\nData kode baru :\n");
				tampilkan(kode);
				printf("\n\nAcak lagi ? :\n");
				printf("1. Ya\n");
				printf("2. Tidak\n");
				fflush(stdin);
				scanf("%i",&pil);
			}
		}
		else if(pilihan=='2'){
			system("cls");
			printf("Data kode :\n");
			tampilkan(kode);
			if(cek_urutan(kode)==0){
				gelembung(kode,0,0);
				printf("\nData kode setelah diurutkan :\n");
				tampilkan(kode);}
			else
				printf("\nData kode sudah terurut");
			getch();
		}
		else if(pilihan=='3'){
			system("cls");
			printf("Data kode :\n");
			tampilkan(kode);
			if(cek_urutan(kode)==1){
				printf("\nMasukkan kode yang ingin dicari :\n");
				fflush(stdin);
				scanf("%i",&cari);
				interpolasi(kode,23,0,cari);}
			else
				printf("\nData belum terurut");
			getch();			
		}
	}while(pilihan!='q');
	system("cls");
}
void tukar(int *a,int *b) 
{ 
    int c=*a; 
    *a=*b; 
    *b= c; 
}
void tampilkan(int a[])
{
	for(int i=0;i<24;i++)
		printf("%i ",a[i]);	
}
void acak(int a[])
{
    for (int i=0;i<23;i++){
        int j=i+rand()%(23-i)+1;
        tukar(&a[i],&a[j]);}	
}
int cek_urutan(int a[])
{
	for(int i=0;i<23;i++)
		if(a[i]>a[i+1])
			return 0;
	return 1;
}
int gelembung(int a[], int i, int j)
{
	if(i<23 && j<23)
		if(a[i]>a[i+1]){
			tukar(&a[i],&a[i+1]);
			return gelembung(a, i+1, j);}
		else
			return gelembung(a, i+1, j);
	else if(i=23 && j<23)
		return gelembung(a, 0, j+1);
	else if(j=23)
		return 0;
}
int interpolasi(int a[],int atas,int bawah, int cari)
{
	int posisi=(cari-a[bawah])/(a[atas]-a[bawah])*(atas-bawah)+bawah;
	if (cari<a[bawah] || cari>a[atas])
		printf("\nData tidak ditemukan");
	else if(cari==a[posisi])
		printf("\nData bilangan %i ditemukan di indeks ke-%i",a[posisi],posisi);
	else if(cari<a[posisi])
		return interpolasi(a,posisi-1,bawah,cari);
	else
		return interpolasi(a,atas,posisi+1,cari);
}
