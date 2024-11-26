#include <stdio.h>
#include <string.h>
#include "quanlisinhvien.h"

void testChucNang() {
    struct sinhVien dsSV[100];
    int soLuong = 0;
    
    printf("\n=== KIỂM THỬ CHỨC NĂNG QUẢN LÝ SINH VIÊN ===\n");

    // Test case 1: Thêm sinh viên
    printf("\n► Test case 1: Thêm sinh viên mới\n");
    struct sinhVien sv1;
    
    // Khởi tạo dữ liệu cho sv1 bằng strcpy
    strcpy(sv1.maSv, "SV001");
    strcpy(sv1.hoTen, "Nguyen Van A");
    sv1.ngayTN.ngay = 1;
    sv1.ngayTN.thang = 6;
    sv1.ngayTN.nam = 2024;
    strcpy(sv1.lop, "CNTT1");
    strcpy(sv1.Nganh, "Công nghệ thông tin");
    sv1.diemTB = 8.5;
    strcpy(sv1.queQuan, "Hà Nội");
    strcpy(sv1.soDT, "0123456789");
    strcpy(sv1.email, "nva@example.com");
    sv1.diemRL = 85;
    sv1.soTinChi = 120;
    strcpy(sv1.trangThai, "Đang học");
    sv1.hocPhi = 1500000;
    
    dsSV[soLuong++] = sv1;
    printf("✓ Đã thêm sinh viên thử nghiệm\n");
    xuatSinhVien(sv1);
    
    // Test case 2: Tìm kiếm sinh viên
    printf("\n► Test case 2: Tìm kiếm sinh viên\n");
    int viTri = timSinhVien(dsSV, soLuong, "SV001");
    if(viTri != -1) {
        printf("✓ Tìm thấy sinh viên:\n");
        xuatSinhVien(dsSV[viTri]);
    } else {
        printf("⚠ Lỗi: Không tìm thấy sinh viên đã thêm!\n");
    }
    
    // Test case 3: Cập nhật thông tin
    printf("\n► Test case 3: Cập nhật điểm TB\n");
    if(viTri != -1) {
        dsSV[viTri].diemTB = 9.0;
        printf("✓ Đã cập nhật điểm TB thành 9.0\n");
        xuatSinhVien(dsSV[viTri]);
    }
    
    // Test case 4: Xóa sinh viên
    printf("\n► Test case 4: Xóa sinh viên\n");
    xoaSinhVien(dsSV, &soLuong, "SV001");
    if(timSinhVien(dsSV, soLuong, "SV001") == -1) {
        printf("✓ Đã xóa sinh viên thành công\n");
    } else {
        printf("⚠ Lỗi: Xóa sinh viên không thành công!\n");
    }
    
    // Test case 5: Kiểm tra danh sách rỗng
    printf("\n► Test case 5: Kiểm tra xuất danh sách rỗng\n");
    if(soLuong == 0) {
        printf("✓ Danh sách rỗng như mong đợi\n");
    } else {
        printf("⚠ Lỗi: Danh sách không rỗng sau khi xóa!\n");
    }
}

int main() {
    int luaChon;
    
    do {
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║    CHƯƠNG TRÌNH KIỂM THỬ          ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║ 1. Chạy bộ kiểm thử               ║");
        printf("\n║ 0. Thoát                          ║");
        printf("\n╚═══════════════════════════════════╝");
        printf("\n► Chọn chức năng: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                testChucNang();
                break;
            case 0:
                printf("Kết thúc chương trình kiểm thử!\n");
                break;
            default:
                printf("⚠ Lựa chọn không hợp lệ!\n");
        }
    } while(luaChon != 0);
    
    return 0;
} 
