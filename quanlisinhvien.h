/*==============================================================================
 * Project: Quản Lý Sinh Viên
 * Author: [Dương Văn Ninh]
 * Version: 1.0
 * File: quanlisinhvien.h - File header chứa khai báo cấu trúc và prototype
 *============================================================================*/

#ifndef QUANLISINHVIEN_H
#define QUANLISINHVIEN_H

/*==============================================================================
 * INCLUDES
 *============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*==============================================================================
 * CONSTANTS & MACROS
 *============================================================================*/
#define MAX_SINH_VIEN 100
#define MAX_LENGTH_MASV 20
#define MAX_LENGTH_HOTEN 35
#define MAX_LENGTH_LOP 10
#define MAX_LENGTH_NGANH 30
#define MAX_LENGTH_QUEQUAN 50
#define MAX_LENGTH_SDT 15
#define MAX_LENGTH_EMAIL 50
#define MAX_LENGTH_TRANGTHAI 20

/*==============================================================================
 * DATA STRUCTURES
 *============================================================================*/

/* Cấu trúc ngày tháng */
struct date {
    unsigned char ngay;     /* Ngày (1-31) */
    unsigned char thang;    /* Tháng (1-12) */
    unsigned int nam;       /* Năm */
};

/* Cấu trúc sinh viên */
struct sinhVien {
    char maSv[MAX_LENGTH_MASV];          /* Mã sinh viên */
    char hoTen[MAX_LENGTH_HOTEN];        /* Họ tên sinh viên */
    struct date ngayTN;                  /* Ngày tốt nghiệp dự kiến */
    char lop[MAX_LENGTH_LOP];            /* Lớp */
    char Nganh[MAX_LENGTH_NGANH];        /* Ngành học */
    float diemTB;                        /* Điểm trung bình */
    char queQuan[MAX_LENGTH_QUEQUAN];    /* Quê quán */
    char soDT[MAX_LENGTH_SDT];           /* Số điện thoại */
    char email[MAX_LENGTH_EMAIL];        /* Email */
    float diemRL;                        /* Điểm rèn luyện */
    int soTinChi;                        /* Số tín chỉ đã đạt */
    char trangThai[MAX_LENGTH_TRANGTHAI];/* Trạng thái học tập */
    float hocPhi;                        /* Học phí còn nợ */
};

/*==============================================================================
 * FUNCTION PROTOTYPES - BASIC OPERATIONS
 *============================================================================*/
/* Nhóm chức năng cơ bản */
void nhapSinhVien(struct sinhVien *sv);
void xuatSinhVien(struct sinhVien sv);
void nhapDanhSach(struct sinhVien ds[], int *n);
void xuatDanhSach(struct sinhVien ds[], int n);
int timSinhVien(struct sinhVien ds[], int n, char maSV[]);
void xoaSinhVien(struct sinhVien ds[], int *n, char maSV[]);
void capNhatSinhVien(struct sinhVien ds[], int n, char maSV[]);

/*==============================================================================
 * FUNCTION PROTOTYPES - ACADEMIC MANAGEMENT
 *============================================================================*/
/* Nhóm chức năng quản lý học tập */
// TODO: Thêm các hàm quản lý học tập
void capNhatDiemRL(struct sinhVien ds[], int n, char maSV[]);
void capNhatTinChi(struct sinhVien ds[], int n, char maSV[]);
void xemBangDiem(struct sinhVien ds[], int n, char maSV[]);
void kiemTraTotNghiep(struct sinhVien ds[], int n, char maSV[]);

/*==============================================================================
 * FUNCTION PROTOTYPES - FEE MANAGEMENT
 *============================================================================*/
/* Nhóm chức năng quản lý học phí */
// TODO: Thêm các hàm quản lý học phí
void capNhatHocPhi(struct sinhVien ds[], int n, char maSV[]);
void danhSachNoHocPhi(struct sinhVien ds[], int n);
void thongKeHocPhi(struct sinhVien ds[], int n);

/*==============================================================================
 * FUNCTION PROTOTYPES - STATISTICS & REPORTS
 *============================================================================*/
/* Nhóm chức năng thống kê và báo cáo */
// TODO: Thêm các hàm thống kê và báo cáo
void thongKeTheoKhoa(struct sinhVien ds[], int n);
void thongKeTheoHocLuc(struct sinhVien ds[], int n);
void xuatBaoCaoTongHop(struct sinhVien ds[], int n);

/*==============================================================================
 * FUNCTION PROTOTYPES - UTILITIES
 *============================================================================*/
/* Nhóm chức năng tiện ích */
// TODO: Thêm các hàm tiện ích
void sapXepTheoMaSV(struct sinhVien ds[], int n);
void sapXepTheoDiem(struct sinhVien ds[], int n);
void timKiemNangCao(struct sinhVien ds[], int n);

#endif /* QUANLISINHVIEN_H */ 
