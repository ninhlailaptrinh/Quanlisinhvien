#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    unsigned char ngay;
    unsigned char thang;
    unsigned int nam;
};

struct sinhVien {
    char maSv[20];
    char hoTen[35];
    struct date ngayTN;
    char lop[10];
    char Nganh[30];
    float diemTB;
    char queQuan[50];
    char soDT[15];
    char email[50];
    float diemRL;         // Điểm rèn luyện
    int soTinChi;        // Số tín chỉ đã đạt
    char trangThai[20];  // Đang học/Bảo lưu/Đã tốt nghiệp
    float hocPhi;        // Học phí còn nợ
};

// === NHÓM CHỨC NĂNG CƠ BẢN ===
void nhapSinhVien(struct sinhVien *sv);
void xuatSinhVien(struct sinhVien sv);
void nhapDanhSach(struct sinhVien ds[], int *n);
void xuatDanhSach(struct sinhVien ds[], int n);
int timSinhVien(struct sinhVien ds[], int n, char maSV[]);
void xoaSinhVien(struct sinhVien ds[], int *n, char maSV[]);
void capNhatSinhVien(struct sinhVien ds[], int n, char maSV[]);

// === NHÓM CHỨC NĂNG HỌC TẬP ===
void capNhatDiemRL(struct sinhVien ds[], int n, char maSV[]);
void capNhatTinChi(struct sinhVien ds[], int n, char maSV[]);
void capNhatHocPhi(struct sinhVien ds[], int n, char maSV[]);
void danhSachNoCuocHocPhi(struct sinhVien ds[], int n);
void danhSachSVDuDieuKienTN(struct sinhVien ds[], int n);

// === NHÓM CHỨC NĂNG THỐNG KÊ MỞ RỘNG ===
void thongKeSVTheoKhoaHoc(struct sinhVien ds[], int n);
void thongKeSVTheoHocLuc(struct sinhVien ds[], int n);
void thongKeSVTheoTrangThai(struct sinhVien ds[], int n);
void bangDiemTongHop(struct sinhVien ds[], int n, char maSV[]);
void thongKeHocPhi(struct sinhVien ds[], int n);

// === NHÓM CHỨC NĂNG QUẢN LÝ LỚP HỌC ===
void danhSachLopTruong(struct sinhVien ds[], int n);
void phanCongLopTruong(struct sinhVien ds[], int n, char maSV[]);
void danhSachSVTheoDoiTuong(struct sinhVien ds[], int n);
void capNhatThongTinLop(struct sinhVien ds[], int n, char lop[]);

// === NHÓM CHỨC NĂNG BÁO CÁO ===
void xuatBaoCaoTongHop(struct sinhVien ds[], int n);
void xuatDanhSachTheoDiem(struct sinhVien ds[], int n, float diemMin);
void thongKeSVBiCanhBao(struct sinhVien ds[], int n);
void danhSachSVDatHocBong(struct sinhVien ds[], int n);

// === NHÓM CHỨC NĂNG TIỆN ÍCH MỞ RỘNG ===
void xuatTheoDiaChi(struct sinhVien ds[], int n, char tinh[]);
void timKiemNangCao(struct sinhVien ds[], int n);
void sapXepDaChieuSV(struct sinhVien ds[], int n);
void thongKeTheoNhieuTieuChi(struct sinhVien ds[], int n);

int main() {
    struct sinhVien dsSV[100];
    int soLuong = 0;
    int luaChon, luaChonPhu;
    char maTemp[20], tenTemp[35], lopTemp[10];
    
    do {
        puts("\n=== CHUONG TRINH QUAN LY SINH VIEN ===");
        puts("1. Quan ly ho so sinh vien");
        puts("2. Quan ly hoc tap");
        puts("3. Quan ly hoc phi");
        puts("4. Thong ke - Bao cao");
        puts("5. Quan ly lop hoc");
        puts("6. Tien ich mo rong");
        puts("7. Quan ly du lieu");
        puts("0. Thoat");
        puts("Nhap lua chon cua ban: ");
        
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1: // Quản lý hồ sơ
                puts("1. Them sinh vien moi");
                puts("2. Cap nhat thong tin");
                puts("3. Xoa sinh vien");
                puts("4. Tim kiem sinh vien");
                puts("5. Xuat danh sach");
                printf("Nhap lua chon: ");
                scanf("%d", &luaChonPhu);
                
                switch(luaChonPhu) {
                    case 1:
                        nhapDanhSach(dsSV, &soLuong);
                        break;
                        
                    case 2:
                        printf("\nNhap ma sinh vien can cap nhat: ");
                        scanf("%s", maTemp);
                        capNhatSinhVien(dsSV, soLuong, maTemp);
                        break;
                        
                    case 3:
                        printf("\nNhap ma sinh vien can xoa: ");
                        scanf("%s", maTemp);
                        xoaSinhVien(dsSV, &soLuong, maTemp);
                        break;
                        
                    case 4:
                        printf("\nNhap ma sinh vien can tim: ");
                        scanf("%s", maTemp);
                        int viTri = timSinhVien(dsSV, soLuong, maTemp);
                        if(viTri != -1) {
                            xuatSinhVien(dsSV[viTri]);
                        } else {
                            printf("\nKhong tim thay sinh vien!");
                        }
                        break;
                        
                    case 5:
                        xuatDanhSach(dsSV, soLuong);
                        break;
                        
                    default:
                        printf("\nLua chon khong hop le!");
                }
                break;
                
            case 2: // Quản lý học tập
                puts("1. Cap nhat diem ren luyen");
                puts("2. Cap nhat tin chi");
                puts("3. Xem bang diem");
                puts("4. Danh sach canh bao hoc tap");
                puts("5. Danh sach du dieu kien tot nghiep");
                // Xử lý lựa chọn...
                break;
                
            case 3: // Quản lý học phí
                puts("1. Cap nhat hoc phi");
                puts("2. Danh sach no hoc phi");
                puts("3. Thong ke thu hoc phi");
                // Xử lý lựa chọn...
                break;
                
            case 4: // Thống kê - Báo cáo
                puts("1. Thong ke theo khoa");
                puts("2. Thong ke theo hoc luc");
                puts("3. Bao cao tong hop");
                puts("4. Danh sach hoc bong");
                // Xử lý lựa chọn...
                break;
                
            case 5: // Quản lý lớp học
                puts("1. Phan cong lop truong");
                puts("2. Cap nhat thong tin lop");
                puts("3. Danh sach theo doi tuong");
                // Xử lý lựa chọn...
                break;
                
            case 6: // Tiện ích
                puts("1. Tim kiem nang cao");
                puts("2. Sap xep da tieu chi");
                puts("3. Thong ke da chieu");
                // Xử lý lựa chọn...
                break;
                
            case 7: // Quản lý dữ liệu
                puts("1. Sao luu du lieu");
                puts("2. Phuc hoi du lieu");
                puts("3. Xuat bao cao");
                // Xử lý lựa chọn...
                break;
        }
    } while(luaChon != 0);
    
    return 0;
}

void nhapSinhVien(struct sinhVien *sv) {
    while(getchar() != '\n'); // Xóa bộ nhớ đệm

    printf("\nNhap ma sinh vien: ");
    fgets(sv->maSv, sizeof(sv->maSv), stdin);
    sv->maSv[strcspn(sv->maSv, "\n")] = 0;

    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;

    printf("Nhap ngay tot nghiep (ngay thang nam): ");
    scanf("%hhu %hhu %u", &sv->ngayTN.ngay, &sv->ngayTN.thang, &sv->ngayTN.nam);

    while(getchar() != '\n');
    printf("Nhap lop: ");
    fgets(sv->lop, sizeof(sv->lop), stdin);
    sv->lop[strcspn(sv->lop, "\n")] = 0;

    printf("Nhap nganh: ");
    fgets(sv->Nganh, sizeof(sv->Nganh), stdin);
    sv->Nganh[strcspn(sv->Nganh, "\n")] = 0;

    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->diemTB);

    while(getchar() != '\n');
    printf("Nhap que quan: ");
    fgets(sv->queQuan, sizeof(sv->queQuan), stdin);
    sv->queQuan[strcspn(sv->queQuan, "\n")] = 0;

    printf("Nhap so dien thoai: ");
    fgets(sv->soDT, sizeof(sv->soDT), stdin);
    sv->soDT[strcspn(sv->soDT, "\n")] = 0;

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
    sv->email[strcspn(sv->email, "\n")] = 0;

    printf("Nhap diem ren luyen: ");
    scanf("%f", &sv->diemRL);

    printf("Nhap so tin chi da dat: ");
    scanf("%d", &sv->soTinChi);

    while(getchar() != '\n');
    printf("Nhap trang thai (Dang hoc/Bao luu/Da tot nghiep): ");
    fgets(sv->trangThai, sizeof(sv->trangThai), stdin);
    sv->trangThai[strcspn(sv->trangThai, "\n")] = 0;

    printf("Nhap hoc phi con no: ");
    scanf("%f", &sv->hocPhi);
}

void xuatSinhVien(struct sinhVien sv) {
    printf("\n=== THONG TIN SINH VIEN ===");
    printf("\nMa SV: %s", sv.maSv);
    printf("\nHo ten: %s", sv.hoTen);
    printf("\nNgay tot nghiep: %02d/%02d/%04d", sv.ngayTN.ngay, sv.ngayTN.thang, sv.ngayTN.nam);
    printf("\nLop: %s", sv.lop);
    printf("\nNganh: %s", sv.Nganh);
    printf("\nDiem TB: %.2f", sv.diemTB);
    printf("\nQue quan: %s", sv.queQuan);
    printf("\nSDT: %s", sv.soDT);
    printf("\nEmail: %s", sv.email);
    printf("\nDiem ren luyen: %.2f", sv.diemRL);
    printf("\nSo tin chi dat: %d", sv.soTinChi);
    printf("\nTrang thai: %s", sv.trangThai);
    printf("\nHoc phi con no: %.2f\n", sv.hocPhi);
}

void nhapDanhSach(struct sinhVien ds[], int *n) {
    printf("\nNhap so luong sinh vien: ");
    scanf("%d", n);
    
    if(*n <= 0 || *n > 100) {
        printf("So luong khong hop le!\n");
        return;
    }

    for(int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:", i + 1);
        nhapSinhVien(&ds[i]);
    }
}

void xuatDanhSach(struct sinhVien ds[], int n) {
    if(n <= 0) {
        printf("\nDanh sach rong!");
        return;
    }

    printf("\n=== DANH SACH SINH VIEN ===");
    for(int i = 0; i < n; i++) {
        printf("\n\nSinh vien thu %d:", i + 1);
        xuatSinhVien(ds[i]);
    }
}

// Hàm tìm kiếm sinh viên theo mã
int timSinhVien(struct sinhVien ds[], int n, char maSV[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(ds[i].maSv, maSV) == 0) {
            return i;
        }
    }
    return -1;
}

// Hàm xóa sinh viên
void xoaSinhVien(struct sinhVien ds[], int *n, char maSV[]) {
    int viTri = timSinhVien(ds, *n, maSV);
    if(viTri == -1) {
        printf("\nKhong tim thay sinh vien!");
        return;
    }

    // Dịch chuyển mảng
    for(int i = viTri; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    (*n)--;
    printf("\nDa xoa sinh vien!");
}

// Hàm cập nhật thông tin sinh viên
void capNhatSinhVien(struct sinhVien ds[], int n, char maSV[]) {
    int viTri = timSinhVien(ds, n, maSV);
    if(viTri == -1) {
        printf("\nKhong tim thay sinh vien!");
        return;
    }

    printf("\nNhap thong tin moi cho sinh vien:");
    nhapSinhVien(&ds[viTri]);
    printf("\nDa cap nhat thong tin sinh vien!");
}
