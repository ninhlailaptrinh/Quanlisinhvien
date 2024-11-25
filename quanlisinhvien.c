#include <stdio.h>
#include <string.h>

// Quan li sinh vien 
struct SINHVIEN
{
	char hoTen[35];
	char maSV[30];
	char lop[20]; 
};

// Định nghĩa  Funcion  
void nhapThongTin(struct SINHVIEN sv[],int soLuong);
void xuatThongTin(struct SINHVIEN sv[],int soLuong);
void NhapDanhSach(struct SINHVIEN ds[],int soLuong);
int main()
{
	struct SINHVIEN ds[1000];
	int soLuong = 0; 
	int daNhap = 0;
	int choice ; 
	
	do {
	printf("=== DANH SACH SINH VIEN ===");
	printf("\n1. Nhap thong tin ");
	printf("\n2. In ra thong tin  ");
	printf("\n3. Thoat ");
	printf("[?] Nhap vao lua chon : ");	
	scanf("%d",&choice);

	switch (choice) {
		printf("\nNhap vao so luong dien thoai : ");
		scanf("%d",&soLuong);
			if (soLuong <= 0 || soLuong >= 1000) {
				printf("So luong khong hop le !");
				break;
			}
			nhapThongTin(ds,soLuong);
			daNhap = 1 ; 
			break;
	}


	}while (choice != 3);
	return 0; 
}
void nhapThongTin(struct SINHVIEN sv[],int soLuong)
{
	for(int i = 0 ; i < soLuong ; i++)
	{
		while(getchar() != '\n');

		printf("\nNhap vao ho ten sinh vien : ");
		fgets(sv->hoTen,sizeof(sv->hoTen),stdin);
		sv->hoTen[strspn(sv->hoTen,"\n")] = 0 ; 	

		printf("\nNhap vao ma sinh vien : ");
		fgets(sv->maSV,sizeof(sv->maSV),stdin);
		sv->maSV[strspn(sv->maSV,"\n")] = 0 ; 

		printf("\nNhap vao lop : ");
		fgets(sv->lop,sizeof(sv->lop),stdin);
		sv->lop[strspn(sv->lop, "\n")] = 0 ; 
	}
}
void NhapDanhSach(struct SINHVIEN ds[],int soLuong)
{
	for ( int i = 0 ; i < soLuong ; i++) 
	{
		printf("Sinh vien thu %d : ",i);
		nhapThongTin(ds ,soLuong);
	} 
}


