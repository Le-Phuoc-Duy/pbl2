#include <iostream>
#include <iomanip>
#include "ChiTietHoaDon.h"
#include "QuanLyHang.h"
using namespace std;

//Ham dung va ham huy
ChiTietHoaDon::ChiTietHoaDon(){}

ChiTietHoaDon::ChiTietHoaDon(int maHH, double don_gia, int so_luong)
{
    this->maHH = maHH;
    this->don_gia = don_gia;
    this->so_luong = so_luong;
}
ChiTietHoaDon::~ChiTietHoaDon(){}

//Ham Setter

void ChiTietHoaDon::setMaHH(int maHH)
{
    this->maHH = maHH;
}
void ChiTietHoaDon::setDonGia(double don_gia)
{
    this->don_gia = don_gia;
}
void ChiTietHoaDon::setSoLuong(int so_luong)
{
     this->so_luong = so_luong;
}

// Ham Getter
int ChiTietHoaDon::getMaHH()
{
    return maHH;
}
double ChiTietHoaDon::getDonGia()
{
    return don_gia;
}
int ChiTietHoaDon::getSoLuong()
{
    return so_luong;
}
void ChiTietHoaDon::Input(QuanLyHang& hh){
    int n;
    do {    
    cout << "\n\t\t\t\t\t\tNhap ma hang hoa: "; cin >> maHH;
    n = hh.FindIndex(maHH);
    if (n == -1) cout << "\t\t\t\t\t\tMa hang hoa chua ton tai. Nhap lai!" << endl;
    }while(n == -1);

    cout << "\t\t\t\t\t\tNhap so luong: "; cin >> so_luong;
    while ((hh.databaseK[n]->getSoLuong()) < so_luong)
    {
        int luachon;
        cout << "\t\t\t\t\t\tSo luong hang hoa khong du. Kho chi con " << hh.databaseK[n]->getSoLuong() << " mon" << endl;
        cout << "\t\t\t\t\t\tBan muon thay doi so luong khong?" << endl;
        cout << "\t\t\t\t\t\t1. Co              0. Khong" << endl;
        cout << "\t\t\t\t\t\tNhap lua  chon: "; cin >> luachon;
        if (luachon != 1){
            so_luong = 0;   return;
        }
        else {
            cout << "\t\t\t\t\t\tNhap so luong: ";  cin >> this->so_luong;
        }
    }
    hh.databaseK[n]->setSoLuong(hh.databaseK[n]->getSoLuong() - this->so_luong);
    don_gia = so_luong * hh.databaseK[n]->getGiaBan();
}

void ChiTietHoaDon::Output( QuanLyHang& hh)
{
    int n = hh.FindIndex(maHH);
    cout << "\n\t\t\t\t\t\t|" << setw(18) << hh.databaseK[n]->getTenHH() << "|" << setw(8) << so_luong << "|" 
    << setw(14) << setprecision(13) << don_gia << "|";
}