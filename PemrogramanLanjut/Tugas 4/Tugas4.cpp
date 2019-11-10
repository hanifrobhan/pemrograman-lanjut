#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tanggal_lahir {
	int tanggal;
	char bulan[10];
	int tahun;
};

struct alamat {
	char jalan[35];
	char kota[35];
	char provinsi[35];
};

struct rekening {
	char nama[35];
	char no_rekening[12];
	float saldo;
	int umur;
	char bank[35];
	struct alamat alamat;
	struct tanggal_lahir tanggal_lahir;
};

int main() {
	struct rekening rekening[5];
	char mencari[35];
	int ulang=1,kasus,i=0,terbesar,terkecil,umur;
	float terbesar_sementara,terkecil_sementara,akumulasi_saldo;
	while (ulang==1) {
		system("cls");
		printf("1. Masukkan Data Nasabah Baru\n2. Tampilkan Data\n3. Cari Nasabah\n0. Selesai\n");
		scanf("%d",&kasus);
		fflush(stdin);
		switch(kasus){
			case 0:
				{
					ulang=0;
					break;
				}
			case 1:
				{
				system("cls");
				fflush(stdin);
				printf("Masukkan nama nasabah :\n");
				gets(rekening[i].nama);
				fflush(stdin);
				printf("Masukkan nomor rekening nasabah	:\n");
				gets(rekening[i].no_rekening);
				fflush(stdin);
				printf("Masukkan nama bank :\n");
				gets(rekening[i].bank);
				fflush(stdin);
				printf("Masukkan saldo nasabah :\n");
				scanf("%f", &rekening[i].saldo);
				fflush(stdin);
				printf("\nAlamat\n");
				printf("Masukkan nama jalan	:\n");
				gets(rekening[i].alamat.jalan);
				fflush(stdin);
				printf("Masukkan nama kota :\n");
				gets(rekening[i].alamat.kota);
				fflush(stdin);
				printf("Masukkan nama provinsi :\n");
				gets(rekening[i].alamat.provinsi);
				fflush(stdin);
				printf("\nTanggal lahir\n");
				printf("Masukkan tanggal :\n");
				scanf("%d", &rekening[i].tanggal_lahir.tanggal);
				fflush(stdin);
				printf("Masukkan bulan :\n");
				gets(rekening[i].tanggal_lahir.bulan);
				fflush(stdin);
				printf("Masukkan masukkan tahun	:\n");
				scanf("%d", &rekening[i].tanggal_lahir.tahun);
				fflush(stdin);
				i++;
				break;
				}
			case 2:
				{
					system("cls");
					printf("1. Semua Data Nasabah\n2. Nasabah dengan Tabungan Terbanyak\n3. Nasabah dengan Tabungan Paling Sedikit\n4. Nasabah dibawah Umur 18 Tahun\n5. Total Keseluruhan Saldo Nasabah\n0. Kembali\n");
					scanf("%d",&kasus);
					for(int index=0; index<i; index++){
						if(rekening[index].saldo>terkecil_sementara){
				 			terbesar = index;
							terbesar_sementara = rekening[index].saldo;
						}
						else if(rekening[index].saldo<terkecil_sementara){
							terkecil = index;
							terkecil_sementara = rekening[index].saldo;
						}
				    }
					switch(kasus){
						case 0:
							{
								break;
							}
						case 1:
							{
							if(i!=0){
								system("cls");
								for(int index=0; index<i; index++){
					            	printf("Nama nasabah : %s\n", rekening[index].nama);
					            	printf("Nomor rekening : %s\n", rekening[index].no_rekening);
					            	printf("Nama bank : %s\n", rekening[index].bank);
					            	printf("Saldo : %f\n", rekening[index].saldo);
					            	printf("Alamat : %s, %s, %s\n", rekening[index].alamat.jalan, rekening[index].alamat.kota, rekening[index].alamat.provinsi);
					            	printf("Tanggal lahir : %i %s %i\n\n", rekening[index].tanggal_lahir.tanggal, rekening[index].tanggal_lahir.bulan, rekening[index].tanggal_lahir.tahun);
					            }
					            system("pause");
					           }
					        else{
					        		system("cls");
									printf("Data Kosong\n");
					        		system("pause");
							    }
							break;
							}
						case 2:
							{
								system("cls");
							    printf("Nasabah dengan saldo terbesar adalah : %s, dengan saldo %f\n", rekening[terbesar].nama, rekening[terbesar].saldo);
							    system("pause");
								break;
							}
						case 3:
							{
								system("cls");
							    printf("Nasabah dengan saldo terkecil adalah : %s, dengan saldo %f\n", rekening[terkecil].nama, rekening[terkecil].saldo);
							    system("pause");
							    break;
							}
						case 4:
							{
								system("cls");
								printf("Berikut Nama Nasabah dengan umur dibawah 18 tahun :\n");
								for(int index = 0; index < i; index++){
									umur = 2019-rekening[index].tanggal_lahir.tahun;
									if(umur<18){
										printf("%s\n", rekening[index].nama);
							        }
							    }
								system("pause");
							    break;
							}
						case 5:
							{
								system("cls");
								for(int index = 0; index < i; index++){
									akumulasi_saldo = akumulasi_saldo + rekening[index].saldo;
								}
								printf("Akumulasi saldo nasabah sebesar %f\n", akumulasi_saldo);
								system("pause");
							    break;
							}
					}
					break;
				}
			case 3:
				{
					system("cls");
					printf("1. Cari Berdasarkan Provinsi\n2. Cari Berdasarkan Kota\n0. Kembali\n");
					scanf("%d",&kasus);
					fflush(stdin);
					int ada=0;
					switch(kasus){
						case 0:
							{
								break;
							}
						case 1:
							{
								system("cls");
							    printf("Masukkan nama provinsi : \n");
							    gets (mencari);
							    for(int index=0; index<i; index++) {
							    	if(strstr(rekening[index].alamat.provinsi,mencari)){		
					                	printf("\nNama nasabah : %s\n", rekening[index].nama);
					            	    printf("Nomor rekening : %s\n", rekening[index].no_rekening);
					            	    printf("Nama bank : %s\n", rekening[index].bank);
					            	    printf("Saldo : %f\n", rekening[index].saldo);
					            	    printf("Alamat : %s, %s, %s\n", rekening[index].alamat.jalan, rekening[index].alamat.kota, rekening[index].alamat.provinsi);
					            	    printf("Tanggal lahir : %i %s %i\n\n", rekening[index].tanggal_lahir.tanggal, rekening[index].tanggal_lahir.bulan, rekening[index].tanggal_lahir.tahun);
									    ada+=1;
									}
									else if(ada==0){
										system("cls");
										printf("Pencarian berdasarkan '%s' tidak menemukan hasil yang cocok",&mencari);
									}
								}
								system("pause");
								break;
							}
						case 2:
							{
								system("cls");
							    printf("Masukkan nama kota : \n");
							    gets (mencari);
							    for(int index=0; index<i; index++) {
							    	if(strstr(rekening[index].alamat.kota,mencari)){		
					                	printf("\nNama nasabah : %s\n", rekening[index].nama);
					            	    printf("Nomor rekening : %s\n", rekening[index].no_rekening);
					            	    printf("Nama bank : %s\n", rekening[index].bank);
					            	    printf("Saldo : %f\n", rekening[index].saldo);
					            	    printf("Alamat : %s, %s, %s\n", rekening[index].alamat.jalan, rekening[index].alamat.kota, rekening[index].alamat.provinsi);
					            	    printf("Tanggal lahir : %i %s %i\n\n", rekening[index].tanggal_lahir.tanggal, rekening[index].tanggal_lahir.bulan, rekening[index].tanggal_lahir.tahun);
									    ada+=1;
									}
									else if(ada==0){
										system("cls");
										printf("Pencarian berdasarkan '%s' tidak menemukan hasil yang cocok",&mencari);
									}
									system("pause");
									break;
								}
								
							}
					}
					break;
				}
		}
	}
	system("cls");
	printf("OK");
	return 0;
}
