#ifndef functionrev4.h
#define functionrev4.h
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct node{
	int nilai;
	char nama[100];
	char npm[10];
	struct node *left, *right;
};

struct node *newNode(char nama[], char npm[], int item) {
 	struct node *temp = (struct node *)malloc(sizeof(struct node));
  	temp->nilai = item;
  	strcpy(temp->nama, nama);
  	strcpy(temp->npm, npm);
  	temp->left = temp->right = NULL;
 	return temp;
}//bener

struct node *insert(struct node *node, char nama[], char npm[], int key) {
	if (node == NULL) 
	return newNode(nama, npm, key);
	
	if (key <= node->nilai)//kurang dari sama dengan
		node->left = insert(node->left, nama, npm, key);
	else
	    node->right = insert(node->right, nama, npm, key);
	
	return node;
}//bener

void printlist(struct node root, int i){
	printf("\n%2d \t\t%s \t\t%s  \t%d", i+1, root.nama, root.npm, root.nilai);
}

int inorder(struct node *root, int i) {
	if(root != NULL){
		struct node temp;
		if(root->right != NULL){
		i = inorder(root->right, i);
		}
		strcpy(temp.nama, root->nama);
		strcpy(temp.npm, root->npm);
		temp.nilai = root->nilai;
		printlist(temp, i);
		i++;
		if(root->left != NULL){
		i = inorder(root->left, i);
		}
	}
	return i;
}//bener

struct node *minValueNode(struct node *node) {
	struct node *current = node;
	
	
	while (current && current->left != NULL)
		current = current->left;
	
	return current;
}//bener

struct node *deleteNode(struct node *root, int key) {
	if(root == NULL){
		return root;
	}
	if (key < root->nilai)
	    root->left = deleteNode(root->left, key);
	else if (key > root->nilai)
	    root->right = deleteNode(root->right, key);
	
	else {
    	if (root->left == NULL) {
	    	struct node *temp = root->right;
	    	free(root);
	   		return temp;
		} 
		else if (root->right == NULL) {
	    	struct node *temp = root->left;
	    	free(root);
	    	return temp;
    	}

    	struct node *temp = minValueNode(root->right);
    	
   		root->nilai = temp->nilai;
   		strcpy(root->nama, temp->nama);
   		strcpy(root->npm, temp->npm);
		root->right = deleteNode(root->right, temp->nilai);
	}
	return root;
}

int searchNama(struct node *root, char search[], int *error, int i){
	system("cls");
	char temp1[100], temp2[100];
	if (root != NULL) {
		if(root->right != NULL){
		i = searchNama(root->right, search, error, i);
		}
		
		if(strstr(root->nama, search) != NULL){
		printf("\nData yang dicari memiliki nama %s dengan NPM %s dengan rangking %d\n\n", root->nama, root->npm, i + 1);
		*error = 2;
		}
		i++;
		if(root->left != NULL){
		i = searchNama(root->left, search, error, i);
		}
	}
	return i;
}

int searchNPM(struct node *root, char search[], int *error, int i){
	system("cls");
	if (root != NULL) {
		if(root->right != NULL){
		i = searchNama(root->right, search, error, i);
		}
		
		if(strstr(root->npm, search) != NULL){
		printf("\nData yang dicari memiliki nama %s dengan NPM %s dengan rangking %d\n\n", root->nama, root->npm, i + 1);
		*error = 2;
		}
		i++;
		if(root->left != NULL){
		i = searchNama(root->left, search, error, i);
		}
	}
	return i;
}

int deleteNama(struct node *root, char search[]){
	int nilai;
	char temp1[100], temp2[100];
	if (root != NULL) {
		if(root->left != NULL){
			nilai = deleteNama(root->left, search);
		}
	
		if(strstr(root->nama, search) != NULL){
			nilai = root->nilai;
			return nilai;
		}
		if(root->right != NULL){
			nilai = deleteNama(root->right, search);
		}
	}
	return nilai;
}

int deleteNPM(struct node *root, char search[]){
	int nilai;
	if (root != NULL) {
		if(root->left != NULL){
			nilai = deleteNPM(root->left, search);
		}
		if(strstr(root->npm, search) != NULL){
			nilai = root->nilai;
			return nilai;
		}
		if(root->right != NULL){
			nilai = deleteNPM(root->right, search);
		}
	}
	return nilai;
}

void printData(struct node *root){
	int i = 0;
	
	system("cls"); 
	printf("===============================================================================================\n");
	printf(" 	\t\t      MENU TAMPILAN DATA  \n");
	printf("   \t\t  PROGRAM MENENTUKAN RANGKING MAHASISWA\n");
	printf("===============================================================================================\n");
	printf("\nRanking\t\tNama\t\t\tNPM\t\tNilai");
	printf("\n-------------------------------------------------------------------------------------------");
	
	inorder(root, i);
	printf("\n-------------------------------------------------------------------------------------------\n\n");
	system("pause");

}

void searchData(struct node *root){
	int i = 0, menu, error = 1;
	char searchnama[100], searchnpm[10];
	system("cls");
	printf("================================================================================================\n");
	printf(" 	     \t\t MENU PENCARIAN  \n");
	printf("     \t\tPROGRAM MENENTUKAN RANGKING MAHASISWA\n");
	printf("================================================================================================\n\n");
	printf("Pilihan Menu: \n");
	printf("1. Cari dengan input nama\n");
	printf("2. Cari dengan input NPM\n");
	printf("3. Kembali ke menu?\n");
	printf("Menu Pilihan Anda: ");
	scanf("%d", &menu);

	switch(menu){
		case 1:
			//linear search
			system("cls");
			printf("Input nama (case sensitive): ");
			scanf(" %[^\n]", &searchnama);
			searchNama(root, searchnama, &error, i);
			if (error != 2){
				printf("Data mahasiswa tidak ditemukan\n");
			}
			system("pause");
			break;
		case 2: 
			//linear search
			system("cls");
			printf("Input npm: ");
			scanf(" %s", &searchnpm);
			searchNPM(root, searchnpm, &error, i);
			if (error != 2){
				printf("Data mahasiswa tidak ditemukan\n");
			}
			system("pause");
			break;
		case 3 :
			return;
			break;
		default:
			printf("Invalid input\n\n");
			system("pause");
			break;
	}
}

void exitProgram(void){
	printf("================================================\n");
 	printf("   Terima Kasih Telah Menggunakan Program Ini\n");
 	printf("================================================\n");
	system("pause");
 	system("cls"); 
 	exit(EXIT_SUCCESS);
}

#endif
