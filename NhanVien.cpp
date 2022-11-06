#include<iostream>
#include <iomanip>
#include "NhanVien.h"

//Ham dung
NhanVien::NhanVien(){}
NhanVien::NhanVien(int maNV, string hodem, string tenNV, int gioi_tinh, Date ngay_sinh, string sdt, string dia_chi, int chuc_vu, double luong)
{
    this->maNV = maNV;
    this->gioi_tinh = gioi_tinh;
    this->ho_dem_NV = hodem;
    this->tenNV = tenNV;
    this->ngay_sinh = ngay_sinh;
    this->sdt = sdt;
    this->dia_chi = dia_chi;
    this->chuc_vu = chuc_vu;
    this->luong = luong;
}
NhanVien::~NhanVien(){}
// Ham Setter
void NhanVien::setMaNV(int maNV)
{
    this->maNV = maNV;
}
void NhanVien::setGioiTinh(int gioi_tinh)
{
    this->gioi_tinh = gioi_tinh;
}
void NhanVien::setTenNV(string tenNV)
{
    this->tenNV = tenNV;
}
void NhanVien::setHoDemNV(string hodem)
{
    this->ho_dem_NV = hodem;
}
void NhanVien::setNgaySinh(Date ngay_sinh)
{
    this->ngay_sinh = ngay_sinh;
}
void NhanVien::setSDT(string sdt)
{
    this->sdt = sdt;
}
void NhanVien::setDiaChi(string dia_chi)
{
    this->dia_chi = dia_chi;
}
void NhanVien::setLuong()
{
    if (chuc_vu == 0) luong = 7000000;
    else luong = 5500000;
}
void NhanVien::setChucVu(int chuc_vu)
{
    this->chuc_vu = chuc_vu;
}
//Ham Getter
int NhanVien::getMaNV()
{
    return maNV;
}
string NhanVien::getTenNV()
{
    return tenNV;
}
string NhanVien::getHoDemNV()
{
    return ho_dem_NV;
}
string NhanVien::getHoTenNV()
{
    return ho_dem_NV + tenNV;
}
string NhanVien::getGioiTinh()
{
    if (gioi_tinh == 1) return "Nam";
    else return "Nu";
}
Date NhanVien::getNgaySinh()
{
    return ngay_sinh;
}
string NhanVien::getSDT()
{
    return sdt;
}
string NhanVien::getDiaChi()
{
    return dia_chi;
}
double NhanVien::getLuong()
{
    return luong;
}
string NhanVien::getChucVu()
{
    if (chuc_vu == 0) return "Ban hang";
    else return "Quan kho";
}

ostream& operator<<(ostream& out, NhanVien& nv)
{
    out << "\t\t\t" << "|" << setw(5) << nv.maNV << "|" << setw(15) << nv.ho_dem_NV + " " << setw(5) << nv.tenNV << "|" << setw(9) << nv.getGioiTinh() 
    <<  "|" << setw(2) << nv.ngay_sinh << "|" << setw(13) << nv.getSDT() << "|" <<  setw(19) << nv.dia_chi << "|" << setw(9) << nv.getChucVu() << "|" 
    <<setw(9) << (size_t)nv.luong << "|" << endl;
    return out;
}
void NhanVien::Input(QuanLyNV& ql_nv, int maNV)
{
    this->maNV = maNV;
    cin.ignore();
    cout << "\t\t\t\t\t\tNhap ho dem nhan vien: ";  getline(cin, ho_dem_NV);
    cout << "\t\t\t\t\t\tNhap ten nhan vien: ";  getline(cin, tenNV);
    do{
        cout << "\t\t\t\t\t\tGioi tinh :    1.Nam       0. Nu" << endl;
        cout << "\t\t\t\t\t\tNhap gioi tinh : "; cin >> gioi_tinh;
    }while(gioi_tinh != 0 && gioi_tinh != 1);
    cout << "\t\t\t\t\t\tNhap ngay sinh: ";     cin >> ngay_sinh;
    cout << "\t\t\t\t\t\tNhap so dien thoai: ";     cin.ignore(); cin >> sdt;
    cout << "\t\t\t\t\t\tNhap dia chi: ";    cin.ignore(); getline(cin, dia_chi);
    do{
        cout << "\t\t\t\t\t\tChuc vu: ";
        cout << "\n\t\t\t\t\t\t 0. Nhan vien ban hang "; 
        cout << "\n\t\t\t\t\t\t 1. Nhan vien quan kho "; 
        cout << "\n\t\t\t\t\t\tNhap chuc vu : ";   cin >> chuc_vu;
    }while(chuc_vu != 0 && chuc_vu != 1);
    setLuong();
}