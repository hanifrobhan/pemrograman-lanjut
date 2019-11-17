#include<stdio.h>
void naik(int a[],int bawah,int tengah,int atas)
{
	int i,j,k;
	int separuh1=tengah-bawah+1;
	int separuh2=atas-tengah;
	int s1[separuh1],s2[separuh2];
	for(int p=0;p<separuh1;p++)
		s1[p]=a[p+bawah];
	for(int p=0;p<separuh2;p++)
		s2[p]=a[p+tengah+1];
	i=0;
	j=0;
	k=bawah;
	while(i<separuh1 && j<separuh2)
	{
		if(s1[i]<=s2[j])
		{
			a[k]=s1[i];
			i++;
		}
		else
		{
			a[k]=s2[j];
			j++;
		}
		k++;
	}
	while(i<separuh1)
	{
		a[k]=s1[i];
		i++;
		k++;		
	}
	while(j<separuh2)
	{
		a[k]=s2[j];
		j++;
		k++;
	}
}
void urutkan(int a[],int bawah, int atas)
{
	if(bawah<atas)
	{
		int tengah=(bawah+atas)/2;
		urutkan(a, bawah, tengah);
		urutkan(a, tengah+1, atas);
		naik(a, bawah, tengah, atas);
	}
}
int main()
{
	int n=8;
	int bilangan[n]={89,67,88,35,54,34,41,90};
	printf("Data Awal :");
	for(int i=0;i<8;i++)
		printf("%i ",bilangan[i]);
	urutkan(bilangan,0,7);
	printf("\nData Setelah diurutkan :");
	for(int i=0;i<8;i++)
		printf("%i ",bilangan[i]);
}
