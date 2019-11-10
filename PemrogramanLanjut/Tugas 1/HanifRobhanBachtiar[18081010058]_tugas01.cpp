#include<stdio.h>
#include<stdlib.h>
int x;
char nama[50]="Kosong",ttl[40]="Kosong",alamat[50]="Kosong",telepon[15]="Kosong";
main()
{
	awal:
	system("cls");
	printf("Pengisian Biodata Diri\n1. Isi Biodata\n2. Tampilkan Biodata\n");
	scanf("%d",&x);
	fflush(stdin);
	if(x==1)
		goto input;
	else if(x==2)
		goto output;	
		
	input:
	system("cls");
	printf("Masukkan Nama :\n");
	scanf("%[^\n]s",&nama);
	fflush(stdin);
	printf("Masukkan Tempat dan Tanggal Lahir :\n");
	scanf("%[^\n]s",&ttl);
	fflush(stdin);
	printf("Masukkan alamat :\n");
	scanf("%[^\n]s",&alamat);
	fflush(stdin);
	printf("Masukkan Nomor Telepon :\n");
	scanf("%[^\n]s",&telepon);
	fflush(stdin);	
    goto awal;
    
    output:
    system("cls");
	printf("Nama                     : %s\n",nama);
	printf("Tempat dan Tanggal Lahir : %s\n",ttl);
	printf("Alamat                   : %s\n",alamat);
	printf("Nomor Telepon            : %s\n",telepon);
	printf("\n\n");
	printf("1. Kembali ke awal\n2. Selesai\n");
	scanf("%d",&x);
	if(x==1)
		goto awal;
	else if(x==2)
		goto akhir;
	
	akhir:
	system("cls");
	printf("Terima Kasih Telah Mengisi Biodata");		
}
