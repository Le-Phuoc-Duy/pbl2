#include <iostream>
#include "HoaDon.h"
using namespace std;
// Ham dung va ham huy
HoaDon::HoaDon(){
    this->lengthCTHD = 0;
    thanh_tien = 0;
}

HoaDon::HoaDon(int maHD, int maNV, string sdt,  Date ngay_lap, double thanh_tien){
    this->maHD = maHD;
    this->maNV = maNV;
    this->sdt = sdt;
    this->ngay_lap = ngay_lap;
    this->thanh_tien = thanh_tien;
}
HoaDon::~HoaDon(){}

// Ham Setter
void HoaDon::setMaHD(int maHD)
{
    this->maHD = maHD;
}

void HoaDon::setSDT(string sdt)
{
   this->sdt = sdt;
}

void HoaDon::setLengthCTHD(int lengthcthd)
{
    this->lengthCTHD = lengthCTHD;
}

void HoaDon::setNgayLap(Date ngay_lap)
{
    this->ngay_lap = ngay_lap;
}
void HoaDon::setThanhTien(double thanh_tien)
{
    this->ngay_lap = ngay_lap;
}
void HoaDon::setMaNV(int maNV)
{
    this->maNV = maNV;
}
// Ham Getter
int HoaDon::getMaHD()
{
    return this->maHD;
}

string HoaDon::getSDT()
{
   return this->sdt;
}

int HoaDon::getLengthCTHD()
{
    return this->lengthCTHD;
}

Date HoaDon::getNgayLap()
{
    return this->ngay_lap;
}
double HoaDon::getThanhTien()
{
    return this->thanh_tien;
}
int HoaDon::getMaNV()
{
    return this->maNV;
}
//
void HoaDon::Input(QuanLyKH& kh, QuanLyNV& nv, QuanLyHang& hh, int maHD, int maNV, string sdt){
    this->maHD = maHD; this->sdt = sdt; this->maNV = maNV;
    cout << "\t\t\t\t\t\tNhap ngay lap hoa don: ";  cin >> this->ngay_lap;
    cout << "\t\t\t\t\t\tNhap so luong loai hang: "; cin >> this->lengthCTHD;
    for (int i = 0; i < this->lengthCTHD; i++){
        cout << "\n\t\t\t\t\t\tNhap thong tin chi tiet loai " << i + 1;
        ChiTietHoaDon *p = new ChiTietHoaDon;
        p->Input(hh);
        this->cthd.push_back(p);
        this->thanh_tien = this->thanh_tien + this->cthd[i]->getDonGia();
    }
    int n = kh.FindIndexSDT(sdt);
    double sd_ct = (this->thanh_tien) / 100000;
    double sd_bd = kh.databaseKH[n]->getSoDiem();
    kh.databaseKH[n]->setSoDiem(sd_bd + sd_ct);
    if (sd_bd >= 100)
    {
        int tien = 0;
        cout << "\n\t\t\t\t\t\tKhach hang duoc giam " << sd_bd * 1000 << endl;
        if (sd_bd*1000 <= this->thanh_tien) this->thanh_tien -= sd_bd * 1000;
        else{
            this->thanh_tien = 0;
            tien = (sd_bd * 1000 - thanh_tien)/1000;
        }
        kh.databaseKH[n]->setSoDiem(tien);
    }
    cout << "\n\t\t\t\t\t\tTHANH TIEN: " << (size_t)thanh_tien << endl;
}

void HoaDon::Output(QuanLyHang& hh)
{
    cout << "\n\t\t\t\t\t\t1. Ma hoa don: " << maHD ;
    cout << "\n\t\t\t\t\t\t1. Ma nhan vien nhap: " << maNV ;
    cout << "\n\t\t\t\t\t\t2. SDT khach hang: " << sdt;
    cout << "\n\t\t\t\t\t\t3. Ngay lap: " << ngay_lap << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t\t" << setw(28) << "|      Ten hang hoa|" << setw(9) << "So luong|" << setw(15) << "Don gia|" << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" ;
    for (int i = 0; i < lengthCTHD; i++)
    {
        cthd[i]->Output(hh);
    }
    cout << "\n\n\n\t\t\t\t\t\tTHANH TIEN: " << setprecision(15) << thanh_tien << endl;
}