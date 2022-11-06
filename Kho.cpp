#include "Kho.h"
#include <iomanip>
#include <iostream>
using namespace std;
// Ham getter
int Kho::getMaHH() {
    return this->maHH;
}
string Kho::getTenHH() {
    return this->tenHH;
}
int Kho::getPhanLoai() {
    return this->phan_loai.getMaPL();
}
// PhanLoai Kho::getNhomHang(){
//     return this->nhom_hang;
// }
double Kho::getGiaVon() {
    return this->gia_von;
}
double Kho::getGiaBan() {
    return this->gia_ban;
}
int Kho::getSoLuong() {
    return this->so_luong;
}
Date Kho::getNgayNhap() {
    return this->ngay_nhap;
}

// Ham setter
void Kho::setMaHH(int maHH){
    this->maHH = maHH;
}
void Kho::setTenHH(string tenHH){
    this->tenHH = tenHH;
} 
// void Kho::setNhomHang(PhanLoai nhom_hang){
//     this->nhom_hang = nhom_hang;
// }
void Kho::setGiaVon(double gia_von){
   this->gia_von = gia_von; 
}
void Kho::setGiaBan(double gia_ban){
    this->gia_ban = gia_ban;
}
void Kho::setSoLuong(int so_luong){
    this->so_luong = so_luong;
}
void Kho::setNgayNhap(Date ngay_nhap){
    this->ngay_nhap = ngay_nhap;
}
void Kho::setMaPLl(int maPL)
{
    this->phan_loai.setMaPL(maPL);
}
// Ham constructor
Kho::Kho()
{
}
Kho::Kho(int maHH, string tenHH, double gia_von, double gia_ban, int so_luong, Date ngay_nhap, int maPL){
    this->maHH = maHH;
    this->tenHH = tenHH;
    this->gia_von = gia_von; 
    this->gia_ban = gia_ban;
    this->so_luong = so_luong;
    this->ngay_nhap = ngay_nhap;
    this->phan_loai.setMaPL(maPL);
}
// Ham destructor
Kho::~Kho(){}
// Da nang hoa toan tu
istream& operator>>(istream& in, Kho& kho){
    int maPL;
    cout << "\t\t\t\t\t\tNhap ma hang hoa: ";   in >> kho.maHH;
    in.ignore();
    cout << "\t\t\t\t\t\tNhap ten hang hoa: ";  getline(in, kho.tenHH);
    cout << "\t\t\t\t\t\tNhap gia nhap vao: ";     in >> kho.gia_von;
    cout << "\t\t\t\t\t\tNhap gia ban ra: ";     in >> kho.gia_ban;
    cout << "\t\t\t\t\t\tNhap so luong con trong kho: ";    in >> kho.so_luong;
    cout << "\t\t\t\t\t\tNhap ngay nhap hang: "; in >> kho.ngay_nhap;
    cout << "\t\t\t\t\t\tNhap ma danh muc: "; in >> maPL;
    kho.phan_loai.setMaPL(maPL);
    return in;
}

ostream& operator<<(ostream& out, Kho& kho)
{
    out << "\t\t\t" << "|" << setw(8) << kho.maHH << "|" << setw(19) <<  kho.tenHH << "|" << setw(14) << setprecision(10) << kho.gia_von 
    << "|" << setw(14) << kho.gia_ban << "|" << setw(9) << kho.so_luong << "|" << setw(5) << kho.ngay_nhap 
    << "|" << setw(9) << kho.phan_loai.getMaPL() << "|"<< endl;
    return out;
}
