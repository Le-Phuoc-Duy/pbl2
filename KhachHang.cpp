#include "KhachHang.h"
// Ham getter
int KhachHang::getMaKH(){
    return this->maKH;
}
string KhachHang::getTenKH(){
    return this->tenKH;
}
string KhachHang::getSDT(){
    return this->sdt;
}
int KhachHang::getSoDiem(){
    return this->so_diem;
}
// Ham setter
void KhachHang::setMaKH(int maKH){
    this->maKH = maKH;
}
void KhachHang::setTenKH(string tenKH){
    this->tenKH = tenKH;
}
void KhachHang::setSDT(string sdt){
    this->sdt = sdt;
}
void KhachHang::setSoDiem(int so_diem){
    this->so_diem = so_diem;
}
// Ham constructor & destructor
KhachHang::KhachHang(){}
KhachHang::KhachHang(int maKH, string tenKH, string sdt, int so_diem){
    this->maKH = maKH;
    this->sdt = sdt;
    this->tenKH = tenKH;
    this->so_diem = so_diem;
}
KhachHang::~KhachHang(){}
istream& operator>>(istream& in, KhachHang& khachhang){
    int maPL;
    cout << "\t\t\t\t\t\tNhap ma khach hang: ";   in >> khachhang.maKH;
    in.ignore();
    cout << "\t\t\t\t\t\tNhap ten khach hang: ";  getline(in, khachhang.tenKH);
    cout << "\t\t\t\t\t\tNhap so dien thoai khach hang: ";     getline(in, khachhang.sdt);
    khachhang.so_diem = 0;
    return in;
}

ostream& operator<<(ostream& out, KhachHang& khachhang)
{
    out << "\t\t\t\t\t\t" << "|" << setw(14) << khachhang.maKH << "|" << setw(14) <<  khachhang.tenKH << "|" << setw(5) << khachhang.sdt 
    << "|" << setw(7) << khachhang.so_diem << "|" << endl;
    return out;
}