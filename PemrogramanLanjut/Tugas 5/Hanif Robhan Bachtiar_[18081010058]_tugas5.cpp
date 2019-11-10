#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct mhs{
	char matkul[30];
	float nilai;
	char huruf[5];
};

int main(){
	mhs mhs[5][2];
	float ip;
	int i=0,j=0;
	for(int i=0;i<5;i++){
		fflush(stdin);	
		printf("\nMatkul-%d : ",i+1);
		gets(mhs[i][j].matkul);
		printf("Nilai	: ");
		scanf("%f",&mhs[i][1].nilai);
		ip += (mhs[i][1].nilai/25)/5;
		if(mhs[i][1].nilai==70){
			strcpy(mhs[i][2].huruf,"B");
		}
		else if(mhs[i][1].nilai<=75 && mhs[i][1].nilai>70){
			strcpy(mhs[i][2].huruf,"B+");
		}
		else if(mhs[i][1].nilai<80 && mhs[i][1].nilai>75){
			strcpy(mhs[i][2].huruf,"A-");
		}
		else if(mhs[i][1].nilai>=80){
			strcpy(mhs[i][2].huruf,"A");
		}
		else{
			strcpy(mhs[i][2].huruf,"C");
		}
	}

	printf("\nMatkul		Nilai");
	for(int i=0;i<5;i++){
		printf("\n%s		",mhs[i][j].matkul);
		printf("%f		",mhs[i][1].nilai);
		printf("%s",mhs[i][2].huruf);
	}
	printf("\n\nIPS : %f",ip);
	return 0;
}
