#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct staff {
	int id, year, salary;
	char name[63];
	char position[30];
};
typedef struct staff Staff;

//function prototype
void NhapThongTin(Staff st[], int num);
void InThongTin(Staff st[], int num);
void TimMaNV(Staff st[], int num);
void TimChucVuNV(Staff st[], int num);
void TimNamSinhNV(Staff st[], int num);
void TimLuongNV(Staff st[], int num);
void Write(Staff st[], int num);
Sort(Staff st[], int num);
void OutPut(Staff st[], int num);

int main() {
	Staff staff[MAX];
	int n, choose ;
	char new_list;
	do {
		printf("Nhap so luong nhan vien: ");
		scanf("%d", &n);
		printf("=========Thong tin cua nhan vien========\n");
		NhapThongTin(staff, n);
		InThongTin(staff, n);
		Sort(staff, n);
		Write(staff, n);
		OutPut(staff, n);
		printf("\n=========Danh sach tim kiem thong tin nhan vien=============\n");
		printf("1. Tim kiem bang ma id\n2. Tim kiem thong qua Chuc vu\n3. Tim kiem nam sinh\n4. Tim kiem dua theo muc luong");
		printf("\n");
		printf("Ban muon tim kiem theo cach so may ?: ");
		scanf("%d", &choose);
		switch(choose) {
			case 1:
				TimMaNV(staff, n);
				break;
			case 2:
				TimChucVuNV(staff, n);
				break;
			case 3:
				TimNamSinhNV(staff, n);
				break;
			case 4:
				TimLuongNV(staff, n);
				break;
			default:
				printf("Khong co trong danh sach tim kiem");
				break;	
		}
		printf("\nLap danh sach moi(y/n)? : ");
		scanf("%c", &new_list);
	}
	while (new_list == 'Y' || new_list == 'y');
	
	return 0;
}

void NhapThongTin(Staff st[], int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("\n");
		printf("<Nhap thong tin nhan vien thu %d>\n", i + 1);
		printf("---------------------------------\n");
		printf("Ma so id nhan vien: ");
		scanf("%d", &st[i].id);
		printf("Ho ten nhan vien: ");
		fflush(stdin);
		gets(st[i].name);
		fflush(stdin);
		printf("Nam sinh cua nhan vien: ");
		scanf("%d", &st[i].year);
		printf("Chuc vu hien tai nhan vien: ");
		fflush(stdin);
		gets(st[i].position);
		printf("Luong hien tai nhan vien: ");
		scanf("%10d", &st[i].salary);
		printf("\n");
	}
}

void InThongTin (Staff st[], int num) {
	int i;
	printf("----------------------Danh sach nhan vien-------------------------\n");
	printf("\n");
	for (i = 0; i < num; i++) {
		printf("%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
}

void TimMaNV(Staff st[], int num) {
	int i, x;
	printf("\n");
	printf("----------------------Tim nhan vien bang ma id---------------------\n");
	printf("\nNhap id de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < num; i++){
		if (st[i].id == x) {
			printf("\n%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, x, st[i].name, st[i].year, st[i].position, st[i].salary);
		}
	}
	fflush(stdin);
}

void TimChucVuNV(Staff st[], int num) {
	int i, count = 0;
	char x[20];
	printf("\n");
	printf("----------------------Tim nhan vien thong qua Chuc vu---------------------\n");
	printf("\nNhap chuc vu de xem thong tin nhan vien: ");
	fflush(stdin);
	gets(x);
	for (i = 0; i < num; i++){
		if (strcmp(st[i].position, x) == 0) {
			printf("\n%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, x, st[i].salary);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
	fflush(stdin);
}

void TimNamSinhNV(Staff st[], int num) {
	int i, x, count = 0;;
	printf("\n");
	printf("----------------------Tim nhan vien bang nam sinh---------------------\n");
	printf("\nNhap nam sinh de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < num; i++){
		if (st[i].year == x) {
			printf("\n%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, x, st[i].position, st[i].salary);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
	fflush(stdin);
}

void TimLuongNV(Staff st[], int num) {
	int i, x, count = 0;
	printf("\n");
	printf("----------------------Tim nhan vien theo muc luong---------------------\n");
	printf("\nNhap muc luong de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < num; i++){
		if (st[i].salary == x) {
			printf("\n%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, x);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
	fflush(stdin);
}

void Write(Staff st[], int num) {
	FILE *f = fopen("D:\\Quanlynhanvien.txt", "w");
	if (f == NULL) {
		printf("Khong mo duoc file");
		exit(1);
	}
	
		fprintf(f, "======================Danh sach nhan vien===================\n");
	
	int i;
	for (i = 0; i < num; i++)
		fprintf(f, "%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);

	fclose(f);
}

Sort(Staff st[], int num) {
	int i, j;
	Staff temp;
	for (i = 0; i < num-1; i++) {
		for (j = num-1; j > i; j--) {
			if(strcmp(st[i].name, st[j].name) < 0) {
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
}

void OutPut(Staff st[], int num) {
	FILE *f = fopen("D:\\Quanlynhanvien.txt", "r");
	if (f == NULL) {
		printf("Khong mo duoc file");
		exit(1);
	}
	int i;
	for (i = 0; i < num; i++) {
		fprintf(f, "%d. %8d\t%21s\t%d\t%10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
	fclose(f);
}

