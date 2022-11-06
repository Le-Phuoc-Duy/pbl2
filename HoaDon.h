#pragma once
#include "Date.h"
#include "List.h"
#include "ChiTietHoaDon.h"
#include "QuanLyKH.h"
#include "QuanLyNV.h"
class HoaDon
{
    private:
        int maHD, lengthCTHD;
        Date ngay_lap;
        double thanh_tien;
        string sdt;
        int maNV;
        List<ChiTietHoaDon*> cthd;
    public:
        HoaDon();
        HoaDon(int, int,string, Date, double);
        ~HoaDon();
        //getter
        int getMaHD();
        string getSDT();
        int getLengthCTHD();
        Date getNgayLap();
        double getThanhTien();
        int getMaNV();
        //setter
        void setMaHD(int);
        void setSDT(string);
        void setLengthCTHD(int);
        void setNgayLap(Date);
        void setThanhTien(double);
        void setMaNV(int);

        void Input(QuanLyKH&, QuanLyNV&, QuanLyHang&, int, int, string);
        void Output (QuanLyHang&);
};