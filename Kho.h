#include "Date.h"
#pragma once
#include "PhanLoai.h"
class Kho
{
private:
    int maHH;
    string tenHH;
    PhanLoai phan_loai;
    double gia_von;
    double gia_ban;
    int so_luong;
    Date ngay_nhap; 
public:
    // Ham getter
        int getMaHH();
        string getTenHH();
        int getPhanLoai();
        double getGiaVon();
        double getGiaBan();
        int getSoLuong();
        Date getNgayNhap();
    // Ham setter
        void setMaHH(int);
        void setTenHH(string);
        void setGiaVon(double);
        void setGiaBan(double);
        void setSoLuong(int);
        void setNgayNhap(Date);
        void setMaPLl(int);
    // Ham constructor
        Kho();
        Kho(int, string, double, double, int, Date, int);
    // Ham destructor
        ~Kho();
        friend istream& operator>>(istream&, Kho&);
        friend ostream& operator<<(ostream&, Kho&);
        friend class QuanLyHang;
};
