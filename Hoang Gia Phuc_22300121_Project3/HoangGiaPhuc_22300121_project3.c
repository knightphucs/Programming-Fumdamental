#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

struct staff {
	int id, year, salary;
	char name[63];
	char position[30];
};
typedef struct staff Staff;

//function prototype
void NhapThongTin(Staff st[], int num);
void Sort(Staff st[], int num, int new);
void InDanhSach(Staff st[], int num);
void Add(Staff st[], int num, int new);
void InDanhSach_SauKhiDaThem(Staff st[], int num, int new);
int Delete(Staff st[], int num, int new, int index);
void InDanhSach_SauKhiDaXoa(Staff st[], int num, int new, int index);
void TimMaNV(Staff st[], int num, int new, int index);
void TimChucVuNV(Staff st[], int num, int new, int index);
void TimNamSinhNV(Staff st[], int num, int new, int index);
void TimLuongNV(Staff st[], int num, int new, int index);
void Write(Staff st[], int num, int new, int index);
void OutPut(Staff st[], int num, int new, int index);

int main() {
	Staff staff[MAX];
	int n, choose, new_list, more, del;
	char search;
	printf("Hoang Gia Phuc_22300121_Project 3");
	printf("\n");
	printf("Nhap so luong nhan vien: ");
	scanf("%d", &n);
	printf("=========Thong tin cua nhan vien========\n");
	NhapThongTin(staff, n);
	InDanhSach(staff, n);
	printf("So luong nhan vien nhap them: ");
	scanf("%d", &more);
	fflush(stdin);
	Add(staff, n, more);
	Sort(staff, n, more);
	InDanhSach_SauKhiDaThem(staff, n, more);
	printf("Xoa nhan vien trong danh sach(chon STT): ");
	Delete(staff, n, more, del);
	InDanhSach_SauKhiDaXoa(staff, n, more, del);
	Write(staff, n, more, del);
	OutPut(staff, n, more, del);
	do {
		printf("\n=========Danh sach tim kiem thong tin nhan vien=============\n");
		printf("1. Tim kiem bang ma id\n2. Tim kiem thong qua Chuc vu\n3. Tim kiem nam sinh\n4. Tim kiem dua theo muc luong");
		printf("\n");
		printf("Ban muon tim kiem theo cach so may ?: ");
		scanf("%d", &choose);

		switch(choose) {
			case 1:
				TimMaNV(staff, n, more, del);
				break;
			case 2:
				TimChucVuNV(staff, n, more, del);
				break;
			case 3:
				TimNamSinhNV(staff, n, more, del);
				break;
			case 4:
				TimLuongNV(staff, n, more, del);
				break;
			default:
				printf("Khong co trong danh sach tim kiem");
				break;	
		}
		printf("\n");
		printf("Tiep tuc tim kiem(y/n)? : ");
		fflush(stdin);
		scanf("%c", &search);
	}
	while (search == 'y' || search == 'Y');
	
	printf("Lap danh sach moi(1 or 0)?: ");
	scanf("%d", &new_list);
	
	switch(new_list) {
		case 1:
			do {
				printf("Nhap so luong nhan vien: ");
				scanf("%d", &n);
				printf("=========Thong tin cua nhan vien========\n");
				NhapThongTin(staff, n);
				InDanhSach(staff, n);
				printf("So luong nhan vien nhap them: ");
				scanf("%d", &more);
				fflush(stdin);
				Add(staff, n, more);
				Sort(staff, n, more);
				InDanhSach_SauKhiDaThem(staff, n, more);
				printf("Xoa nhan vien trong danh sach: ");
				scanf("%d", &del);
				Delete(staff, n, more, del);
				InDanhSach_SauKhiDaXoa(staff, n, more, del);
				Write(staff, n, more, del);
				OutPut(staff, n, more, del);
				do {
					printf("\n=========Danh sach tim kiem thong tin nhan vien=============\n");
					printf("1. Tim kiem bang ma id\n2. Tim kiem thong qua Chuc vu\n3. Tim kiem nam sinh\n4. Tim kiem dua theo muc luong");
					printf("\n");
					printf("Ban muon tim kiem theo cach so may ?: ");
					scanf("%d", &choose);
					switch(choose) {
						case 1:
							TimMaNV(staff, n, more, del);
							break;
						case 2:
							TimChucVuNV(staff, n, more, del);
							break;
						case 3:
							TimNamSinhNV(staff, n, more, del);
							break;
						case 4:
							TimLuongNV(staff, n, more, del);
							break;
						default:
							printf("Khong co trong danh sach tim kiem");
							break;	
					}
					printf("\n");
					printf("Tiep tuc tim kiem(y/n)? : ");
					fflush(stdin);
					scanf("%c", &search);
				}
				while (search == 'Y' || search == 'y');
				printf("Lap danh sach moi(1 or 0)?: ");
				scanf("%d", &new_list);
			}
			while (new_list == 1);
			break;
		case 0:
			printf("Danh sach da xong");
			break;
	}
	
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

void InDanhSach (Staff st[], int num) {
	int i;
	printf("----------------------Danh sach nhan vien-------------------------\n");
	printf("\n");
	for (i = 0; i < num; i++) {
		printf("%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
}

void TimMaNV(Staff st[], int num, int new, int index) {
	int i, x, count = 0;
	printf("\n");
	printf("----------------------Tim nhan vien bang ma id---------------------\n");
	printf("\nNhap id de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < Delete(st, num, new, index); i++){
		if (st[i].id == x) {
			printf("\n%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, x, st[i].name, st[i].year, st[i].position, st[i].salary);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
}

void TimChucVuNV(Staff st[], int num, int new, int index) {
	int i, count = 0;
	char x[20];
	printf("\n");
	printf("----------------------Tim nhan vien thong qua Chuc vu---------------------\n");
	printf("\nNhap chuc vu de xem thong tin nhan vien: ");
	fflush(stdin);
	gets(x);
	for (i = 0; i < Delete(st, num, new, index); i++){
		if (strcmp(st[i].position, x) == 0) {
			printf("\n%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, x, st[i].salary);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
}

void TimNamSinhNV(Staff st[], int num, int new, int index) {
	int i, x, count = 0;;
	printf("\n");
	printf("----------------------Tim nhan vien bang nam sinh---------------------\n");
	printf("\nNhap nam sinh de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < Delete(st, num, new, index); i++){
		if (st[i].year == x) {
			printf("\n%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, x, st[i].position, st[i].salary);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
}

void TimLuongNV(Staff st[], int num, int new, int index) {
	int i, x, count = 0;
	printf("\n");
	printf("----------------------Tim nhan vien theo muc luong---------------------\n");
	printf("\nNhap muc luong de xem thong tin nhan vien: ");
	scanf("%d", &x);
	for (i = 0; i < Delete(st, num, new, index); i++){
		if (st[i].salary == x) {
			printf("\n%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, x);
			count++;
		}
	}
	printf("==> Tim thay %d ket qua", count);
}

void Write(Staff st[], int num, int new, int index) {
	FILE *f = fopen("D:\\Quanlynhanvien.txt", "w");
	if (f == NULL) {
		printf("Khong mo duoc file");
		exit(1);
	}
	
		fprintf(f, "======================Danh sach nhan vien======================\n");
	
	int i;
	for (i = 0; i < Delete(st, num, new, index); i++)
		fprintf(f, "%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);

	fclose(f);
}

void Sort(Staff st[], int num, int new) {
    int i, j;
    Staff temp;
    for (i = 0; i < num + new - 1; i++) {
        for (j = i + 1; j < num + new; j++) {
            if (strcmp(st[i].name, st[j].name) > 0) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}

void OutPut(Staff st[], int num, int new, int index) {
	FILE *f = fopen("D:\\Quanlynhanvien.txt", "r");
	if (f == NULL) {
		printf("Khong mo duoc file");
		exit(1);
	}
	int i;
	for (i = 0; i < Delete(st, num, new, index); i++) {
		fprintf(f, "%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
	fclose(f);
}

void Add(Staff st[], int num, int new) {
	int i; 
	for (i = num; i < num + new; i++) {
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
	num += new;
}

void InDanhSach_SauKhiDaThem(Staff st[], int num, int new) {
	int i;
	printf("----------------------Danh sach nhan vien-------------------------\n");
	printf("\n");
	for (i = 0; i < num + new; i++) {
		printf("%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
}

int Delete(Staff st[], int num, int new, int index) {
	int i, L = num + new;
	if (index == 0) {
		return L;
	}
	else if (index >= num+new+1) {
		return 0;
	}
	else {
		for (i = index - 1; i < num + new - 1; i++) {
			st[i] = st[i + 1];
		}

		num = num + new - 1;
		return num;
	}
}

void InDanhSach_SauKhiDaXoa(Staff st[], int num, int new, int index) {
	int i;
	for (i = 0; i < Delete(st, num, new, index); i++) {
		printf("%d. %8d\t%-21s\t%d\t%-10s\t%d \n", i + 1, st[i].id, st[i].name, st[i].year, st[i].position, st[i].salary);
	}
}




