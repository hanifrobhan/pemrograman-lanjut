#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main ()
{
	int ruang[3][3][3];
	char koordinat[3][15]={"Pertama","Kedua","Ketiga"};
	double lintasan=0;
	int perulangan=0,kasus;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			for(int k=0; k<3; k++)
			{
				ruang[i][j][k] = rand() %10 + 1;
			}
		}
	}
	
	while(perulangan==0)
	{
		system("cls");
		printf("1. Tampilkan data\n2. Hitung lintasan\n0. Selesai\n");
		scanf("%i", &kasus);
		switch(kasus)
		{
			case 0 :
				system("cls");
				printf("Selesai");
				perulangan=1;
				break;
			case 1 :
				system("cls");
				for(int i=0; i<3; i++){
				printf("\nLintasan ke-%i\n", i+1);
				for(int j=0; j<3; j++){
					printf("\nKoordinat %s 	:	", koordinat[j]);
					for(int k=0; k<3; k++){
						printf("%d	", ruang[i][j][k]);
					}
					printf("\n");
				}
				printf("\n\n");
				}
				system("pause");
				break;
			case 2 :
				system("cls");
				for(int i=0; i<3; i++){
					for(int j=1; j<3; j++){
						lintasan = lintasan + sqrt((pow((ruang[i][j][0]-ruang[i][j][0]),2))+(pow((ruang[i][j][1]-ruang[i][j-1][1]),2))+(pow((ruang[i][j][2]-ruang[i][j-1][2]),2)));
					}
					printf("\nLintasan ke-%i : %f\n", i+1, lintasan);
					lintasan=0;
				}
				system("pause");
				break;										
		}		
	}
}
