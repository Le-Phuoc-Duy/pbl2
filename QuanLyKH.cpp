#include "QuanLyKH.h"
#include "QuanLyHD.h"
#include <fstream>
#include <iostream>
#include <iomanip>

QuanLyKH::QuanLyKH()
{
    this->lengthKH = 0;
}

QuanLyKH::~QuanLyKH() {}

int QuanLyKH::getLengthKH()
{
    return this->lengthKH;
}
void QuanLyKH::setLengthKh(int length)
{
    this->lengthKH = length;
}
// Tìm kiếm khach hang theo mã KH
int QuanLyKH::FindIndex(const int &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getMaKH() == index)
            return i;
    }
    return -1;
}

// Tìm kiếm khach hang theo tên KH
int QuanLyKH::FindIndexTen(const string &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getTenKH() == index)
            return i;
    }
    return -1;
}
// Tìm kiếm khach hang theo sdt
int QuanLyKH::FindIndexSDT(const string &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getSDT() == index)
            return i;
    }
    return -1;
}
void QuanLyKH::Insert()
{
    KhachHang *khachhang = new KhachHang;
    cin >> *khachhang;
    // kiem tra ma va ten khach hang co trung khong
    if (FindIndexSDT(khachhang->sdt) != -1)
    {
        cout << "\t\t\t\t\t\tSo dien thoai da ton tai" << endl;
        return;
    }
    else if (FindIndex(khachhang->maKH) != -1)
    {
        cout << "\t\t\t\t\t\tMa khach hang " << khachhang->maKH << " da ton tai" << endl;
        return;
    }

    string ten = khachhang->getTenKH();
    HamChuanHoa(ten);
    khachhang->setTenKH(ten);

    databaseKH.push_back(khachhang);
    this->lengthKH++;
    cout << "\t\t\t\t\t\tThem hang hoa thanh cong!" << endl;
}

void QuanLyKH::Readf()
{
    ifstream filein;
    filein.open("KhachHang.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    int maKH, so_diem;
    string tenKH, sdt;
    char x;
    while (filein.eof() != true)
    {
        filein >> maKH;
        filein >> x;
        filein.ignore();
        getline(filein, tenKH, x);
        filein.ignore();
        getline(filein, sdt, x);
        filein.ignore();
        filein >> so_diem;
        filein.ignore();
        // Kiem tra ma hang hoa va ten hang hoa co trung khong
        if (FindIndex(maKH) != -1)
        {
            cout << "\t\t\t\t\t\tMa khach hang " << maKH << " da ton tai" << endl;
            return;
        }
        else if (FindIndexSDT(sdt) != -1)
        {
            cout << "\t\t\t\t\t\tSo dien thoai " << sdt << " da ton tai" << endl;
            return;
        } 
        HamChuanHoa(tenKH);
        KhachHang *khachhang = new KhachHang(maKH, tenKH, sdt, so_diem);
        databaseKH.push_back(khachhang);
        (this->lengthKH)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

void QuanLyKH::Show()
{
    cout << "\n\t\t\t\t\t\t\t\tDANH SACH KHACH HANG";
    cout << "\n\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(10) << " SDT|" << setw(5)
         << "So Diem|" << endl;
    cout << "\t\t\t\t\t\t-------------------------------------------------" << endl;

    for (int i = 0; i < this->getLengthKH(); i++)
    {
        cout << *databaseKH[i];
    }
    cout << "\t\t\t\t\t\t-------------------------------------------------" << endl;
}

// void QuanLyKH::Remove()
// {
//     int maKH;
//     cout << "\t\t\t\t\t\tNhap SDT khach hang: "; cin >> maKH;
//     // cin.ignore(); getline(cin, sdt);
//     if (FindIndex(maKH) == -1)
//     {
//         cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//         return;
//     }
//     // if (ql_hd.FindIndex(sdt) != -1){
//     //     cout << "\t\t\t\t\t\tKhach hang da duoc dang ki boi hoa don. Khong the xoa!" << endl;
//     //     return;
//     // }
//     else
//     {
//         databaseKH.erase(FindIndex(maKH));
//         this->lengthKH--;
//         cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
//     }
// }

void QuanLyKH::Find()
{

    string sdt;
    cout << "\t\t\t\t\t\tNhap so dien thoai: ";
    cin.ignore();
    getline(cin, sdt);
    int n = FindIndexSDT(sdt);
    if (n == -1)
    {
        cout << "\t\t\t\t\t\tSDT khong ton tai!" << endl;
        return;
    }
    else
    {
            cout << "\n\t\t\t\t\t\t\t\tDANH SACH KHACH HANG";
            cout << "\n\t\t\t\t\t\t-------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(10) << " SDT|" << setw(5)
                << "So Diem|" << endl;
            cout << "\t\t\t\t\t\t-------------------------------------------------" << endl;
                cout << *databaseKH[n];
            cout << "\t\t\t\t\t\t-------------------------------------------------" << endl;
            }
}
void QuanLyKH::Writef()
{
    ofstream fileout;
    fileout.open("XuatKH.txt");
    fileout << "\n\t\t\t\t\t\t\t\tDANH SACH KHACH HANG";
    fileout << "\n\t\t\t\t\t\t-------------------------------------------------" << endl;
    fileout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(10) << " SDT|" << setw(5)
         << "So Diem|" << endl;
    fileout << "\t\t\t\t\t\t-------------------------------------------------" << endl;

    for (int i = 0; i < this->getLengthKH(); i++)
    {
        fileout << *databaseKH[i];
    }
    fileout << "\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
// void QuanLyKH::Update(){
//     system("cls");
//     cout << "\n\t\t\t\t\t\t---------------------------------";
//     cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ma\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t2. Cap nhat ten\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t3. Cap nhat SDT\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t|";
//     cout << "\n\t\t\t\t\t\t---------------------------------" << endl;
//     int luachon; 
//     cout << "\t\t\t\t\t\tNhap lua chon: ";
//     cin >> luachon;
//     if (luachon == 0){
//         return;
//     }else{
//         int kh; cout << "\t\t\t\t\t\tNhap ma so khach hang can cap nhat: ";
//         cin >> kh;
//         if (FindIndex(kh) == -1){
//             cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//             return;
//         }
//         switch (luachon){
//             case 1:
//             {
//                 int maKH;
//                 cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> maKH;
//                 while (FindIndex(maKH) != -1){
//                     cout << "\t\t\t\t\t\tMa khach hang da ton tai. Nhap lai!";
//                     cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> maKH;
//                 }
//                 databaseKH[FindIndex(kh)]->setMaKH(maKH);
//                 break;
//             }
//             case 2:
//             {
//                 string tenKH;
//                 cout << "\t\t\t\t\t\tNhap ten khach hang: ";
//                 cin.ignore(); getline(cin, tenKH);
//                 // HamChuanHoa(tenKH);
//                 while (FindIndexTen(tenKH) != -1){
//                     cout << "\t\t\t\t\t\tTen khach hang da ton tai. Nhap lai!";
//                     cout << "\n\t\t\t\t\t\tNhap ten khach hang: ";
//                     cin.ignore(); getline(cin, tenKH);
//                     // HamChuanHoa(tenKH);
//                 }
//                 databaseKH[FindIndex(kh)]->setTenKH(tenKH);
//                 break;
//             }
//             case 3:
//             {
//                 string sdt;
//                 cout << "\t\t\t\t\t\tNhap so dien thoai khach hang: ";
//                 cin.ignore(); getline(cin, sdt);
//                 while (FindIndexTen(sdt) != -1){
//                     cout << "\t\t\t\t\t\tTen khach hang da ton tai. Nhap lai!";
//                     cout << "\n\t\t\t\t\t\tNhap ten khach hang: ";
//                     cin.ignore(); getline(cin, sdt);
//                 }
//                 databaseKH[FindIndex(kh)]->setSDT(sdt);
//                 // int n;
//                 // do{
//                 //     n = hd.FindIndex(sdt);
//                 //     hd.databaseHD[n]->setSDT(sdt);
//                 // }while (n != -1);
//                 break;
//             }
//             default:
//             {
//                 cout << "\t\t\t\t\t\tLua chon khong hop le!";
//                 cout << "\n\t\t\t\t\t\t"; system("pause");
//                 break;
//             } 
//         }
//         cout << "\n\t\t\t\t\t\tCap nhat thanh cong!" << endl;
//     }
// }

void QuanLyKH::Remove(QuanLyHD& ql_hd)
{
    int ma;
    cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> ma;
    if (FindIndex(ma) == -1)
    {
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    string sdt = databaseKH[FindIndex(ma)]->getSDT();
    if (ql_hd.FindIndex(sdt) != -1){
        cout << "\t\t\t\t\t\tKhach hang da duoc dang ki boi hoa don. Khong the xoa!" << endl;
        return;
    }
    else
    {
        databaseKH.erase(FindIndex(ma));
        lengthKH --;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}

void QuanLyKH::Update(QuanLyHD& ql_hd){
    system("cls");
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat SDT\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------" << endl;
    int luachon; 
    cout << "\t\t\t\t\t\tNhap lua chon: ";
    cin >> luachon;
    if (luachon == 0){
        return;
    }else{
        int ma; 
        cout << "\t\t\t\t\t\tNhap ma so khach hang can cap nhat: ";  cin >> ma;
        if (FindIndex(ma) == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        switch (luachon){
            case 1:
            {
                string ten;
                cout << "\t\t\t\t\t\tNhap ten khach hang: ";
                cin.ignore(); getline(cin, ten);
                HamChuanHoa(ten);
                databaseKH[FindIndex(ma)]->setTenKH(ten);
                break;
            }
            case 2:
            {
                string sdt;
                cout << "\t\t\t\t\t\tNhap so dien thoai khach hang: ";
                cin.ignore(); getline(cin, sdt);
                while (FindIndexSDT(sdt) != -1){
                    cout << "\t\t\t\t\t\tSDT da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap SDT: ";
                    cin.ignore(); getline(cin, sdt);
                }
                string SDT = databaseKH[FindIndex(ma)]->getSDT();
                databaseKH[FindIndex(ma)]->setSDT(sdt);

                int n = ql_hd.FindIndex(SDT);
                while (n != -1){
                    ql_hd.databaseHD[n]->setSDT(sdt);
                    n = ql_hd.FindIndex(SDT);
                }
                break;
            }
            default:
            {
                cout << "\t\t\t\t\t\tLua chon khong hop le!";
                cout << "\n\t\t\t\t\t\t"; system("pause");
                break;
            } 
        }
        cout << "\n\t\t\t\t\t\tCap nhat thanh cong!" << endl;
    }
}