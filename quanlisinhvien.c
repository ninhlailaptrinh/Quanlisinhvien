/*==============================================================================
 * Project: Quản Lý Sinh Viên
 * Author: [Dương Văn Ninh]
 * Version: 1.0
 *============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================================
 * ĐỊNH NGHĨA CẤU TRÚC DỮ LIỆU
 *============================================================================*/
struct date {
    unsigned char ngay;
    unsigned char thang;
    unsigned int nam;
};

struct sinhVien {
    char maSv[20];          /* Mã sinh viên */
    char hoTen[35];         /* Họ tên sinh viên */
    struct date ngayTN;     /* Ngày tốt nghiệp dự kiến */
    char lop[10];           /* Lớp */
    char Nganh[30];         /* Ngành học */
    float diemTB;           /* Điểm trung bình */
    char queQuan[50];       /* Quê quán */
    char soDT[15];          /* Số điện thoại */
    char email[50];         /* Email */
    float diemRL;           /* Điểm rèn luyện */
    int soTinChi;          /* Số tín chỉ đã đạt */
    char trangThai[20];     /* Trạng thái học tập */
    float hocPhi;          /* Học phí còn nợ */
};

/*==============================================================================
 * KHAI BÁO PROTOTYPE CÁC HÀM
 *============================================================================*/

/* === NHÓM CHỨC NĂNG CƠ BẢN === */
void nhapSinhVien(struct sinhVien *sv);
void xuatSinhVien(struct sinhVien sv);
void nhapDanhSach(struct sinhVien ds[], int *n);
void xuatDanhSach(struct sinhVien ds[], int n);
int timSinhVien(struct sinhVien ds[], int n, char maSV[]);
void xoaSinhVien(struct sinhVien ds[], int *n, char maSV[]);
void capNhatSinhVien(struct sinhVien ds[], int n, char maSV[]);

/* === NHÓM CHỨC NĂNG HỌC TẬP === */
void capNhatDiemRL(struct sinhVien ds[], int n, char maSV[]);
void capNhatTinChi(struct sinhVien ds[], int n, char maSV[]);
void capNhatHocPhi(struct sinhVien ds[], int n, char maSV[]);
void danhSachNoCuocHocPhi(struct sinhVien ds[], int n);
void danhSachSVDuDieuKienTN(struct sinhVien ds[], int n);

/* === NHÓM CHỨC NĂNG THỐNG KÊ === */
void thongKeSVTheoKhoaHoc(struct sinhVien ds[], int n);
void thongKeSVTheoHocLuc(struct sinhVien ds[], int n);
void thongKeSVTheoTrangThai(struct sinhVien ds[], int n);
void bangDiemTongHop(struct sinhVien ds[], int n, char maSV[]);
void thongKeHocPhi(struct sinhVien ds[], int n);

/*==============================================================================
 * CÀI ĐẶT CÁC HÀM
 *============================================================================*/

/**
 * Nhập thông tin một sinh viên
 * @param sv Con trỏ đến struct sinh viên cần nhập
 */
void nhapSinhVien(struct sinhVien *sv) {
    printf("\nNhập thông tin sinh viên:");
    printf("\nMã SV: ");
    scanf("%s", sv->maSv);
    getchar();
    printf("Họ tên: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;
    // ... các trường khác tương tự
}

/**
 * Xuất thông tin một sinh viên
 * @param sv Struct sinh viên cần xuất
 */
void xuatSinhVien(struct sinhVien sv) {
    printf("\n╔═══════════════════════════════════╗");
    printf("\n║      THÔNG TIN SINH VIÊN          ║");
    printf("\n╚═══════════════════════════════════╝\n");
    printf("Mã SV: %s\n", sv.maSv);
    printf("Họ tên: %s\n", sv.hoTen);
    printf("Ngày TN: %d/%d/%d\n", sv.ngayTN.ngay, sv.ngayTN.thang, sv.ngayTN.nam);
	// Thêm các trường dữ liệu tương tự vô đây .... 
    // ... xuất các thông tin khác
}

/**
 * Nhập danh sách sinh viên
 * @param ds Mảng sinh viên
 * @param n Con trỏ số lượng sinh viên
 */
void nhapDanhSach(struct sinhVien ds[], int *n) {
    printf("\n╔═══════════════════════════════════╗");
    printf("\n║      NHẬP DANH SÁCH SINH VIÊN     ║");
    printf("\n╚═══════════════════════════════════╝\n");

    printf("Nhập số lượng sinh viên: ");
    scanf("%d", n);
    
    if(*n <= 0 || *n > 100) {
        printf("⚠ Số lượng không hợp lệ!\n");
        return;
    }

    for(int i = 0; i < *n; i++) {
        printf("\n► Sinh viên thứ %d:", i + 1);
        nhapSinhVien(&ds[i]);
    }
}

/**
 * Xuất danh sách sinh viên
 * @param ds Mảng sinh viên
 * @param n Số lượng sinh viên
 */
void xuatDanhSach(struct sinhVien ds[], int n) {
    printf("\n╔═══════════════════════════════════╗");
    printf("\n║      DANH SÁCH SINH VIÊN          ║");
    printf("\n╚═══════════════════════════════════╝\n");

    if(n <= 0) {
        printf("⚠ Danh sách rỗng!\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        printf("\n► Sinh viên thứ %d:", i + 1);
        xuatSinhVien(ds[i]);
    }
}

/**
 * Tìm sinh viên theo mã
 * @param ds Mảng sinh viên
 * @param n Số lượng sinh viên
 * @param maSV Mã sinh viên cần tìm
 * @return Vị trí tìm thấy hoặc -1 nếu không tìm thấy
 */
int timSinhVien(struct sinhVien ds[], int n, char maSV[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(ds[i].maSv, maSV) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Xóa sinh viên theo mã
 * @param ds Mảng sinh viên
 * @param n Con trỏ số lượng sinh viên
 * @param maSV Mã sinh viên cần xóa
 */
void xoaSinhVien(struct sinhVien ds[], int *n, char maSV[]) {
    int viTri = timSinhVien(ds, *n, maSV);
    if(viTri != -1) {
        for(int i = viTri; i < *n - 1; i++) {
            ds[i] = ds[i + 1];
        }
        (*n)--;
    }
}

/**
 * Cập nhật thông tin sinh viên
 * @param ds Mảng sinh viên
 * @param n Số lượng sinh viên
 * @param maSV Mã sinh viên cần cập nhật
 */
void capNhatSinhVien(struct sinhVien ds[], int n, char maSV[]) {
    int viTri = timSinhVien(ds, n, maSV);
    if(viTri != -1) {
        nhapSinhVien(&ds[viTri]);
    }
}

/*==============================================================================
 * HÀM MAIN - ĐIỀU KHIỂN CHƯƠNG TRÌNH
 *============================================================================*/
// Để chạy file test cần đổi file main.c thành mainProgram.c
int main() {
    struct sinhVien dsSV[100];
    int soLuong = 0;
    int luaChon, luaChonPhu;
    char maTemp[20];
    
    do {
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║    QUẢN LÝ THÔNG TIN SINH VIÊN    ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║ 1. Quản lý hồ sơ sinh viên        ║");
        printf("\n║ 2. Quản lý học tập                ║");
        printf("\n║ 3. Quản lý học phí                ║");
        printf("\n║ 4. Thống kê - Báo cáo             ║");
        printf("\n║ 5. Quản lý lớp học                ║");
        printf("\n║ 6. Tiện ích mở rộng               ║");
        printf("\n║ 0. Thoát chương trình             ║");
        printf("\n╚═══════════════════════════════════╝");
        printf("\n► Chọn chức năng: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                printf("\n╔═══════════════════════════════════╗");
                printf("\n║      QUẢN LÝ HỒ SƠ SINH VIÊN      ║");
                printf("\n╠═══════════════════════════════════╣");
                printf("\n║ 1. Thêm sinh viên mới             ║");
                printf("\n║ 2. Cập nhật thông tin			  ║");
                printf("\n║ 3. Xóa sinh viên                  ║");
                printf("\n║ 4. Tìm kiếm sinh viên             ║");
                printf("\n║ 5. Xuất danh sách                 ║");
                printf("\n║ 0. Quay lại                       ║");
                printf("\n╚═══════════════════════════════════╝");
                printf("\n► Chọn chức năng: ");
                scanf("%d", &luaChonPhu);
                
                switch(luaChonPhu) {
                    case 1:
                        nhapDanhSach(dsSV, &soLuong);
                        break;
                    case 2:
                        printf("\nNhập mã sinh viên cần cập nhật: ");
                        scanf("%s", maTemp);
                        capNhatSinhVien(dsSV, soLuong, maTemp);
                        break;
                    case 3:
                        printf("\nNhập mã sinh viên cần xóa: ");
                        scanf("%s", maTemp);
                        xoaSinhVien(dsSV, &soLuong, maTemp);
                        break;
                    case 4:
                        printf("\nNhập mã sinh viên cần tìm: ");
                        scanf("%s", maTemp);
                        int viTri = timSinhVien(dsSV, soLuong, maTemp);
                        if(viTri != -1) {
                            xuatSinhVien(dsSV[viTri]);
                        } else {
                            printf("⚠ Không tìm thấy sinh viên!\n");
                        }
                        break;
                    case 5:
                        xuatDanhSach(dsSV, soLuong);
                        break;
                }
                break;
            // Các case khác sẽ được xử lý sau...
        }
    } while(luaChon != 0);
    
    return 0;
}
