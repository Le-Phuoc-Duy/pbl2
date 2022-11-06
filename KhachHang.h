#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class KhachHang{
    private:
        int maKH;
        string tenKH;
        string sdt;
        int so_diem;
    public:
    // Ham getter
        int getMaKH();
        string getTenKH();
        string getSDT();
        int getSoDiem();
    // Ham setter
        void setMaKH(int);
        void setTenKH(string);
        void setSDT(string);
        void setSoDiem(int);
    // Ham constructor & destructor
        KhachHang();
        KhachHang(int, string, string, int);
        ~KhachHang();
        friend istream& operator>>(istream&, KhachHang&);
        friend ostream& operator<<(ostream&, KhachHang&);
        friend class QuanLyKH;
};


