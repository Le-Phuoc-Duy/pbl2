#include <string>
#include "Date.h"
using namespace std;
#pragma once

class QuanLyNV;
class NhanVien
{
    private:
        int maNV;
        string ho_dem_NV;
        string tenNV;
        int gioi_tinh;
        Date ngay_sinh;
        string sdt;
        string dia_chi;
        double luong;
        int chuc_vu;
    public:
    NhanVien();
    NhanVien(int, string, string, int, Date,string, string, int, double);
    ~NhanVien();
    //Ham Setter
    void setMaNV(int);
    void setTenNV(string);
    void setHoDemNV(string);
    void setGioiTinh(int);
    void setNgaySinh(Date);
    void setSDT(string);
    void setDiaChi(string);
    void setLuong();
    void setChucVu(int);
    //Ham Getter
    int getMaNV();
    string getTenNV();
    string getHoDemNV();
    string getHoTenNV();
    string getGioiTinh();
    Date getNgaySinh();
    string getSDT();
    string getDiaChi();
    double getLuong();
    string getChucVu();
    // Ham da nang hoa
    friend ostream& operator<<(ostream&, NhanVien&);
    void Input(QuanLyNV&, int);
};