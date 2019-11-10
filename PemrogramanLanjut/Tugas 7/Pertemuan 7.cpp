#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	 int data;
    struct node *next;
};
typedef struct node node;

node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
void deleteNode(node **head, node *pPre, node *pCur);
void hapusData(node **head);
void deleteList(node *head);
void jumlahkan_semua_data(node *head);
void hapus_data_di_awal(node **head);
void hapus_data_di_akhir(node **head);
void tambah_data_di_akhir(node **head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
    //untuk membersihkan tampilan
    //untuk windows
    system("cls");
    //untuk linux
     //system("clear");

     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. hapus data\n");
     printf("4. cetak isi list\n");
     printf("5. jumlahkan semua data\n");
     printf("6. hapus data di awal\n");
     printf("7. hapus data di akhir\n");
     printf("8. tambah data di akhir\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
     		hapusData(&head);
     else if (pilih == '4'){
     		tranverse(head);
     		getch();
     		}
     else if (pilih == '5'){
     		jumlahkan_semua_data(head);
            getch();
            }
     else if (pilih == '6'){
			hapus_data_di_awal(&head);
     		getch();
     		}
     else if (pilih == '7'){
     		hapus_data_di_akhir(&head);
     		getch();
	 		}
	 else if (pilih == '8'){
	 		tambah_data_di_akhir(&head);
			getch();			
			}
  } while (pilih != 'q');
  deleteList(head);
}

//========================================================

node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pTemp;

  //untuk membersihkan tampilan
  //untuk windows
  system("cls");
  //untuk linux
  //system("clear");
  fflush(stdin);
  printf("masukkan bilangan integer : ");
  fflush(stdin);
  scanf("%d", &bil);
  pTemp = (node *)malloc(sizeof(node));

  if (pTemp != NULL){
  		pTemp->data = bil;
      pTemp->next = NULL;
      insertNode(head, NULL, pTemp);
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pTemp, *pCur;

  //untuk membersihkan tampilan
  //untuk windows
  system("cls");
  //untuk linux
  //system("clear");

  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nData yang disisipkan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pTemp = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pTemp == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pTemp->data = bil;
     pTemp->next = NULL;
     insertNode(head, pCur, pTemp);
  }
}

//========================================================

void tranverse(node *head){
   //traverse linked list
	node *pWalker;

    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d->", pWalker -> data);
   	pWalker = pWalker -> next;
	}
   printf("NULL");
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //menambahkan diawal atau pada empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //menambahkan node di tengah atau di akhir
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================

void deleteNode(node **head, node *pPre, node *pCur)
{
	if (pPre == NULL)
	   *head = pCur -> next;
	else
       pPre -> next = pCur -> next;
	free(pCur);
}

//========================================================

void hapusData(node **head)
{
  int pos;
  node *pCur, *pPre;

  //clrscr();
  system("cls");
  tranverse(*head);
  printf("\nData yang akan dihapus : ");
  fflush(stdin);
  scanf("%d", &pos);

  pPre = NULL;
  pCur = *head;
  //cari target value sampai ditemukan atau sampai pada akhir list
  while (pCur != NULL && pCur -> data != pos) {
    pPre = pCur;
    pCur = pCur -> next;
  }

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else
     deleteNode(head, pPre, pCur);
}

//========================================================

void deleteList(node *head){
  node *pTemp;


  while(head != NULL){
     pTemp = head;
     head = head->next;
     free(pTemp);
  }
}

//========================================================

void jumlahkan_semua_data(node *head){
	int sum=0;
	node *pTemp;
	
	while(head != NULL){
	 pTemp = head;
     head = head->next;
     sum = sum+pTemp->data;
	}
	system("cls");
	printf("Jumlah semua data : %d",sum);
}

//========================================================

void hapus_data_di_awal(node **head){
	system("cls");
	node *pTemp = *head;
	if (pTemp != NULL){
		*head=pTemp->next;
		printf("Ok");
	}
	else{
		printf("Data masih kosong");
	}
	free(pTemp);
}

//========================================================

void hapus_data_di_akhir(node **head){
	system("cls");
	node *pTemp = *head, *pPrev = *head;
	if (pTemp != NULL && pPrev->next != NULL){
		while (pTemp->next != NULL)
		{
			pPrev = pTemp;
			pTemp = pTemp->next;
		}
		free(pTemp);
		pPrev->next = NULL;
		printf("Ok");
	}
	else if(pTemp == NULL){
		printf("Data masih kosong");
	}
	else if(pPrev->next == NULL){
		*head=NULL;
		printf("Ok");
	}
}

//========================================================

void tambah_data_di_akhir(node **head){
	system("cls");
	int bil;
	node *pNew,*pPre=*head;
	printf("Masukkan bilangan integer :");
	fflush(stdin);
	scanf("%d",&bil);
	pNew=(node *)malloc(sizeof(node));
	if (pPre != NULL){
		while(pPre->next != NULL){
			pPre=pPre->next;
		}
        pNew->next=pPre->next;
        pPre->next=pNew;
		pNew->data=bil;		
		printf("\nOk\n");
	}
	else if(pPre == NULL){
	    pNew->next=*head;
		pNew->data=bil;
		*head = pNew;
		printf("\nOk\n");		
	}
}
