# 🎓 Chương Trình Quản Lý Sinh Viên

<div align="center">

![Version](https://img.shields.io/badge/version-1.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-developing-orange)

</div>

## 📑 Mục Lục
- [Tổng Quan](#-tổng-quan)
- [Tính Năng](#-tính-năng)
- [Cài Đặt](#-cài-đặt)
- [Hướng Dẫn Sử Dụng](#-hướng-dẫn-sử-dụng)
- [Cấu Trúc Dữ Liệu](#-cấu-trúc-dữ-liệu)
- [Đóng Góp](#-đóng-góp)

## 📋 Tổng Quan
Hệ thống quản lý sinh viên toàn diện được phát triển bằng ngôn ngữ C, hỗ trợ các chức năng quản lý từ cơ bản đến nâng cao.

## ⭐ Tính Năng

### 1️⃣ Quản Lý Hồ Sơ Sinh Viên `✅ Hoàn thành`
| Chức năng | Trạng thái |
|-----------|------------|
| Thêm sinh viên | ✅ |
| Cập nhật thông tin | ✅ |
| Xóa sinh viên | ✅ |
| Tìm kiếm sinh viên | ✅ |
| Xuất danh sách | ✅ |

### 2️⃣ Quản Lý Học Tập `⏳ Đang phát triển`
| Chức năng | Trạng thái |
|-----------|------------|
| Cập nhật điểm rèn luyện | ⏳ |
| Cập nhật tín chỉ | ⏳ |
| Xem bảng điểm | ⏳ |
| Cảnh báo học tập | ⏳ |
| Kiểm tra tốt nghiệp | ⏳ |

### 3️⃣ Quản Lý Học Phí `⏳ Đang phát triển`
| Chức năng | Trạng thái |
|-----------|------------|
| Cập nhật học phí | ⏳ |
| Danh sách nợ | ⏳ |
| Thống kê thu phí | ⏳ |

## 🛠 Cài Đặt

### Yêu Cầu Hệ Thống
- Hệ điều hành: Windows/Linux/MacOS
- Trình biên dịch C (GCC)
- RAM: 512MB trở lên
- Dung lượng trống: 50MB

### Các Bước Cài Đặt
1. Clone repository
```bash
git clone https://github.com/your-username/quanlisinhvien.git
cd quanlisinhvien
```

2. Biên dịch
```bash
gcc quanlisinhvien.c -o quanlisinhvien
```

3. Chạy chương trình
```bash
./quanlisinhvien
```

## 📖 Hướng Dẫn Sử Dụng

### Menu Chính
1. **Quản lý hồ sơ sinh viên**
   - Thêm sinh viên mới
   - Cập nhật thông tin
   - Xóa sinh viên
   - Tìm kiếm sinh viên
   - Xuất danh sách

2. **Quản lý học tập**
   - Cập nhật điểm rèn luyện
   - Cập nhật tín chỉ
   - Xem bảng điểm
   - Kiểm tra điều kiện tốt nghiệp

3. **Quản lý học phí**
   - Cập nhật học phí
   - Xem danh sách nợ
   - Thống kê thu phí

### Lưu Ý Khi Sử Dụng
- Nhập đúng định dạng ngày tháng (dd/mm/yyyy)
- Điểm số nhập theo thang điểm 10
- Mã sinh viên không được trùng lặp
- Số tín chỉ phải là số nguyên dương

## 📊 Cấu Trúc Dữ Liệu

### Sinh Viên
```c
struct sinhVien {
    char maSv[20];          // Mã sinh viên
    char hoTen[35];         // Họ tên sinh viên
    struct date ngayTN;     // Ngày tốt nghiệp
    char lop[10];           // Lớp
    char Nganh[30];         // Ngành học
    float diemTB;           // Điểm trung bình
    char queQuan[50];       // Quê quán
    char soDT[15];          // Số điện thoại
    char email[50];         // Email
    float diemRL;           // Điểm rèn luyện
    int soTinChi;          // Số tín chỉ đã đạt
    char trangThai[20];     // Trạng thái học tập
    float hocPhi;          // Học phí còn nợ
};
```

## 🤝 Đóng Góp
1. Fork dự án
2. Tạo nhánh mới (`git checkout -b feature/AmazingFeature`)
3. Commit thay đổi (`git commit -m 'Add some AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Tạo Pull Request

## 📝 Ghi Chú
- ✅ : Đã hoàn thiện
- ⏳ : Đang phát triển
- ❌ : Chưa bắt đầu

## 📜 Giấy Phép
Phân phối dưới giấy phép MIT. Xem `LICENSE` để biết thêm thông tin.

## 👥 Tác Giả
- **Dương Văn Ninh** - *Sinh viên* - [GitHub](https://github.com/ninhlailaptrinh)

## 📞 Liên Hệ
- Email: ninhlailaptrinh@gmail.com
- GitHub: [ninhlailaptrinh](https://github.com/ninhlailaptrinh)

## 🙏 Cảm Ơn
Cảm ơn bạn đã quan tâm đến dự án này!
