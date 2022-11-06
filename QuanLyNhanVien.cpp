#include "QuanLyNhanVien.h"
#include <fstream>
#include <iomanip>
void QuanLyNhanVien::HamChuanHoa(string& a){
    while(a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }

    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1 );// a.end() - 1;
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ' && a[i+1] == ' '){
            a.erase(a.begin() + i);
            i--;
        }
    }

    if (a[0] >= 97 && a[0] <= 122)
    {
        a[0] -= 32;
    }

    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == ' '){
            i++;
            if (a[i] >= 97 && a[i] <= 122)
            {
                a[i] -= 32;
            }
        }
        else{
                if (a[i] >= 65 && a[i] <= 90){
                    a[i] += 32;
                }
        }
    }
}
QuanLyNhanVien::QuanLyNhanVien(){
    this->lengthNV = 0;
}
QuanLyNhanVien::~QuanLyNhanVien(){}
// Getter Setter
void QuanLyNhanVien::setLengthNV(int lengthNV)
{
    this->lengthNV = lengthNV;
}
int QuanLyNhanVien::getLengthNV()
{
    return lengthNV;
}
void QuanLyNhanVien::Readf()
{
    ifstream filein;
    filein.open("NhanVien.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
        int maNV;
        string tenNV;
        int gioi_tinh;
        Date ngay_sinh;
        string sdt;
        string dia_chi;
        double luongcoban;
        int chuc_vu;
        char x;
        string gioi_tinh_chuoi;
        string chuc_vu_chuoi;
    while (filein.eof() !=true)
    {
        filein >> maNV;
        filein >> x;
        getline(filein, tenNV, x);
        filein.ignore();
        getline(filein, gioi_tinh_chuoi, x);
        if (gioi_tinh_chuoi == "Nam") gioi_tinh = 1;    else gioi_tinh = 0;
        filein.ignore();
        filein >> ngay_sinh;
        filein.ignore(2);
        getline(filein, sdt, x);
        filein.ignore();
        getline(filein, dia_chi, x);
        filein.ignore();
        getline(filein, chuc_vu_chuoi);
        if (chuc_vu_chuoi == "Ban Hang") chuc_vu = 0;   else chuc_vu = 1;
        HamChuanHoa(tenNV);
        // Kiem tra ma nhan vien co trung khong 
        if (FindIndex(maNV) != -1)
        {
            cout << "\n\t\t\t\t\t\tMa nhan vien " << maNV << " da ton tai!" << endl;
            return;
        }
        NhanVien *nv = new NhanVien(maNV, tenNV, gioi_tinh, ngay_sinh, sdt, dia_chi, chuc_vu);
        nv->setLuongCoBan();
        databaseNV.push_back(nv);
        (this->lengthNV)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}
void QuanLyNhanVien::Show()
{
    cout << "\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN";
    cout << "\n\t\t\t---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t"<< "|Ma NV|" << setw(20) << "Ten nhan vien|" << setw(9) << "Gioi tinh|" 
    << setw(4) << "Ngay sinh |"<< setw(14) << "SDT|" <<  setw(20) << "Dia chi|"<< setw(10) << "Chuc vu|" << setw(10)  << "Luong|" << endl;
    cout << "\n\t\t\t---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->getLengthNV(); i++)
    {
        cout << *databaseNV[i];
    }
    cout << "\t\t\t---------------------------------------------------------------------------------------------------" << endl;
}
void QuanLyNhanVien::Insert()
{
    NhanVien *nv = new NhanVien;
    int maNV;
    cout << "\t\t\t\t\t\tNhap ma nhan vien: ";   cin >> maNV;
    // kiem tra ma  nhan vien co trung khong
    if (FindIndex(maNV) != -1)
    {
            cout << "\n\t\t\t\t\t\tMa nhan vien da ton tai!" << endl;
            return;
    }
    nv->Input(*this, maNV);
    string ten = nv->getTenNV();
    HamChuanHoa(ten);   nv->setTenNV(ten);
    databaseNV.push_back(nv);
    this->lengthNV++;
    cout << "\t\t\t\t\t\tThem hang hoa thanh cong!" << endl;
}

void QuanLyNhanVien::Writef()
{
    ofstream fileout;
    fileout.open("XuatNhanVien.txt");
    fileout << "\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN";
    fileout << "\n\t\t\t---------------------------------------------------------------------------------------------------" << endl;
    fileout << "\t\t\t" << setw(7) << "|Ma NV|" << setw(20) <<  "Ten nhan vien|" << setw(10) << "Gioi tinh|" 
    << setw(11) << "Ngay sinh|" << setw(11) << "SDT|"  <<  setw(20) << "Dia chi|" << setw(10) 
    << "Chuc vu|" << setw(10) << "Luong|";
    fileout << "\n\t\t\t---------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->getLengthNV(); i++)
    {
        fileout << *databaseNV[i];
    }
    fileout << "\t\t\t---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
void QuanLyNhanVien::Find()
{
    int maNV;
    cout << "\t\t\t\t\t\tNhap ma: ";    cin >> maNV;
    int n = FindIndex(maNV);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }else{
            cout << "\n\t\t\t\t\t\t\t\tDANH SACH NHAN VIEN";
            cout << "\n\t\t\t\t---------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(7) << "|Ma NV|" << setw(20) <<  "Ten nhan vien|" << setw(10) << "Gioi tinh|" 
            << setw(11) << "Ngay sinh|" << setw(11) << "SDT|"  <<  setw(20) << "Dia chi|" << setw(10) 
            << "Chuc vu|" << setw(10) << "Luong|";
            cout << "\n\t\t\t\t---------------------------------------------------------------------------------------------------" << endl;
            cout << *databaseNV[n];
            cout << "\t\t\t\t---------------------------------------------------------------------------------------------------" << endl;
        }
}
int QuanLyNhanVien::FindIndex(const int& index){
    for (int i = 0; i < this->lengthNV; i++)
    {
        if (databaseNV[i]->getMaNV() == index) return i;
    }
    return -1;
}
bool up(string x, string y)
{
    return (x < y) ? true : false;
}
bool down(string x, string y)
{
    return (x > y) ? true : false;
}

void QuanLyNhanVien::selectionsortTen(bool (*cmp)(string,string)){
    for(int i = 0; i < this->lengthNV - 1; i++){
        for (int j = i + 1; j < this->lengthNV; j++){
            if (cmp(databaseNV[i]->getTenNV(), databaseNV[j]->getTenNV())){
                swap(databaseNV[i], databaseNV[j]);
            }
        }
    }
}

void QuanLyNhanVien::Sort()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    cout << "\n\t\t\t\t\t\t|1. Sap xep theo chieu giam ten nhan vien|";
    cout << "\n\t\t\t\t\t\t|2. Sap xep theo chieu tang ten nhan vien|";
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    cout << "\n\t\t\t\t\t\tNhap lua chon:\t";
    int luachon; cin >> luachon;
    switch(luachon){
        case 1:
        {
            selectionsortTen(down);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        case 2:
        {
            selectionsortTen(up);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            break;

        }
    }
}