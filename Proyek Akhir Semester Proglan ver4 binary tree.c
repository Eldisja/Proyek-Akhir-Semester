/*
Program Menentukan Rangking Mahasiswa

Christian Franky Siburian - 2106731434
Eldisja Hadasa - 2106640133
Naufal Febriyanto - 2106702674

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "functionrev4.h"

void panduan();
int  panduanouput(int x);



int main(){
	int menu = 0, pilihan = 0, sentinelMenu = 0, n;
	int nilai;
	char nama[100];
	char npm[10];
	struct node *root = NULL;
	
	do {
		system("cls"); 
		printf("======================================================\n");
		printf(" 	         SELAMAT DATANG  \n");
		printf("    PROGRAM MENENTUKAN RANGKING MAHASISWA\n");
		printf("======================================================\n\n");
		printf("1. Menu Input Data\n");
		printf("2. Menu Delete Data\n");
		printf("3. Menu Tampilan Data\n");
		printf("4. Menu Pencarian\n");
		printf("5. Menu Panduan\n");
		printf("6. Keluar\n");
		printf("Masukkan nomor menu yang anda inginkan: ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				system("cls"); 
				printf("================================================\n");
				printf(" 	      MENU INPUT DATA  \n");
				printf("     PROGRAM MENENTUKAN RANGKING MAHASISWA\n");
				printf("================================================\n\n");
				printf("\nMasukkan data :\n");
				
				printf("nama : ");
        		scanf(" %[^\n]", nama);
        
        		printf("npm : ");
       			scanf("%s", &npm);
        
        		printf("nilai : ");
        		scanf("%d", &nilai);
        
        		printf("\n");
				
				root = insert(root, nama, npm, nilai);
				break;
			case 2:
				system("cls");
				if (root == NULL){
					printf("Tidak ada data yang disimpan\n");
					system("pause");
					break;
				}
				printf("================================================\n");
				printf(" 	      MENU DELETE DATA  \n");
				printf("     PROGRAM MENENTUKAN RANGKING MAHASISWA\n");
				printf("================================================\n\n");
				printf("Pilihan Menu: \n");
				printf("1. Delete dengan input nama\n");
				printf("2. Delete dengan input NPM\n");
				printf("3. Kembali ke menu?\n");
				printf("Menu Pilihan Anda: ");
				scanf("%d", &menu);
			
				switch(menu){
					case 1:
						//linear search
						system("cls");
						printf("Input nama (case sensitive): ");
						scanf(" %[^\n]", &nama);
						nilai = deleteNama(root, nama);
						root = deleteNode(root, nilai);
						system("pause");
						break;
					case 2: 
						//linear search
						system("cls");
						printf("Input npm: ");
						scanf(" %s", &npm);
						nilai = deleteNPM(root, npm);
						root = deleteNode(root, nilai);
						system("pause");
						break;
					case 3 :
						break;
					default:
						printf("Invalid input\n\n");
						system("pause");
						break;
				}
				break;
			case 3:
				system("cls"); 
				if (root == NULL){
					printf("Tidak ada data yang disimpan\n");
					system("pause");
					break;
				}
				printData(root);
				break;
			case 4:
				system("cls"); 
				if (root == NULL){
					printf("Tidak ada data yang disimpan\n");
					system("pause");
					break;
				}
				searchData(root);
				break;				
			case 5:
				system("cls"); 
				panduan();
				break;
			case 6:
				system("cls"); 
				exitProgram();
				
				free(root);
				
				return 0;
			default:
				printf("\nPilihan tidak ditemukan\n\n");
				system("pause");
				break;
				
		}
	}while(sentinelMenu != 1);
}

void panduan(){
	int input, menu;
	
	system("cls");
	printf("================================================\n");
	printf(" 	      MENU PANDUAN  \n");
	printf("     PROGRAM MENENTUKAN RANGKING MAHASISWA\n");
	printf("================================================\n\n");
	printf("1. Panduan input data mahasiswa\n");
	printf("2. Panduan mencari data mahasiswa\n");
	printf("3. Panduan menghapus data mahasiswa\n");
	printf("4. Kembali ke menu?\n");
	printf("Menu Pilihan Anda: ");
	scanf("%d", &input);
	
	menu =  panduanouput(input);
	
	if(menu == 1){
		panduan();
	}
}

int panduanouput(int x){
	int kembali;
	
		switch (x){
			case 1: 
				system("cls");
				printf("===========================================================================================\n");
				printf("              \t  Panduan Memasukkan Data Mahasiswa\n");
				printf("===========================================================================================\n\n");
				printf("1. Masukkan nama mahasiswa\n");
				printf("2. Masukkan Nomor Pokok Mahasiswa\n");
				printf("3. Masukkan nilai mahasiswa\n");
				printf("Input 1 apabila ingin kembali ke panduan : ");
				scanf("%d", &kembali);
				return kembali;
				system("pause");
				break;
			case 2:
				system("cls");
				printf("========================================================================================\n");
				printf("                \tPanduan Pencarian Data Mahasiswa\n");
				printf("========================================================================================\n\n");
				printf("Catatan: key search setiap hurufnya harus sama persis dengan data yang telah di-input\n");
				printf("         (huruf kapital atau tidak)\n");
				printf("1. Pilih ingin mencari dengan input nama atau NPM\n");
				printf("2. Masukkan key search mahasiswa yang dicari datanya\n");
				printf("\tCatatan: untuk menu cari dengan input nama key search berupa nama mahasiswa\n");
				printf("\tCatatan: untuk menu cari dengan input NPM key search berupa NPM mahasiswa\n");
				printf("Input 1 apabila ingin kembali ke panduan : ");
				scanf("%d", &kembali);
				return kembali;
				system("pause");
				break;
			case 3: 
				system("cls");
				printf("========================================================================================\n");
				printf("                \tPanduan Delete Data Mahasiswa\n");
				printf("========================================================================================\n\n");
				printf("Catatan: key search setiap hurufnya harus sama persis dengan data yang telah di-input\n");
				printf("         (huruf kapital atau tidak)\n");
				printf("1. Pilih ingin menghapus dengan input nama atau NPM\n");
				printf("2. Masukkan key delete mahasiswa yang akan dihapus datanya\n");
				printf("\tCatatan: untuk menu delete dengan input nama key delete berupa nama mahasiswa\n");
				printf("\tCatatan: untuk menu delete dengan input NPM key delete berupa NPM mahasiswa\n");
				printf("Input 1 apabila ingin kembali ke panduan : ");
				scanf("%d", &kembali);
				return kembali;
				system("pause");
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Invalid input\n\n");
				system("pause");
				panduan();
				break;
			}
}
