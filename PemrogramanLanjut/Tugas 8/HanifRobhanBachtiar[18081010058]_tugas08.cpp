#include<stdio.h>
int s;
int mencari(int a[],int cari,int awal, int akhir)
{
	int tengah=(awal+akhir)/2;
	if(s<0)
	{
		printf("Data tidak ditemukan");
		return 0;
	}
	if (cari==a[tengah])
	{
		printf("Data bilangan %i ditemukan pada indeks ke-%i",a[tengah],tengah);
		return 0;
	}
	else if(cari<a[tengah])
	{
		s--;
		return mencari(a, cari, awal, tengah-1);
	}
	else 
	{
		s--;
		return mencari(a, cari, tengah+1, akhir);
	}
}
int main()
{
	int bilangan[]={3,9,11,13,15,17,31,35},cari,awal=0,akhir=sizeof(bilangan)/sizeof(bilangan[0])-1;
	printf("Data yang tersedia :\n");
	for(int i=0;i<=akhir;i++)
	{
		printf("%i ",bilangan[i]);
	}
	printf("\nMasukkan Bilangan yang dicari :\n");
	scanf("%i",&cari);
	s=akhir;
	mencari(bilangan, cari, awal, akhir);
}

