#include "QuanLyHang.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
// #include "Date.h"

/// ///// THAO TÁC VỚI KHO HANG

QuanLyHang::QuanLyHang()
{
    this->lengthK = 0;
    this->lengthPL = 0;
}
QuanLyHang::~QuanLyHang(){}

int QuanLyHang::getLengthK()
{
    return this->lengthK;
}

void QuanLyHang::setLengthK(int lengthK)
{
    this->lengthK = lengthK;
}


void QuanLyHang::Insert()
{
    Kho *kho = new Kho;
    cin >> *kho;
    // kiem tra ma va ten hang hoa co trung khong
    if (FindIndex(kho->maHH) != -1 && FindIndexTen(kho->tenHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << kho->maHH << " va ten hang hoa " << kho->tenHH << " da ton tai"<< endl;
            return;
        }
        else if (FindIndex(kho->maHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << kho->maHH << " da ton tai" << endl;
            return;
        }
        else if (FindIndexTen(kho->tenHH) != -1)
        {
            cout << "\t\t\t\t\t\tTen hang hoa " << kho->tenHH << " da ton tai" << endl;
            return;
        }
    // kiem tra ma hang hoa ton tai chua
    if (FindIndexPL(kho->getPhanLoai()) == -1 ){
        int opt;
        cout << "\t\t\t\t\t\tMa phan loai chua ton tai. Ban muon them ma phan loai nay khong?";
        cout << "\n\t\t\t\t\t\t1. Co";
        cout << "\n\t\t\t\t\t\t0. Khong";
        cout << "\n\t\t\t\t\t\tNhap lua chon: ";  cin >> opt;
        if(opt != 1) return;
        else {
            string tenPL ;  cin.ignore();
            cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
            HamChuanHoa(tenPL);

            while (FindIndexTenPL(tenPL) != -1){
                cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                cin.ignore(); getline(cin, tenPL);
                HamChuanHoa(tenPL);
            }
            PhanLoai *pl = new PhanLoai(kho->phan_loai.maPL, tenPL);
            databasePL.push_back(pl);
            int n = (this->lengthPL) + 1; this->setLengthPL(n);
            cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
        }
    }

    string ten = kho->getTenHH();
    HamChuanHoa(ten);   kho->setTenHH(ten);

    databaseK.push_back(kho);

    int n = 1 + this->getLengthK(); this->setLengthK(n);
    cout << "\t\t\t\t\t\tThem hang hoa thanh cong!" << endl;
}

void QuanLyHang::Readf()
{
    ifstream filein;
    filein.open("Kho.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    int maHH, so_luong, maPL;
        string tenHH;
        double gia_von, gia_ban;
        Date ngay_nhap;
        char x;
    while (filein.eof() !=true)
    {
        filein >> maHH;
        // filein.ignore();
        // char x = HamKiTu(filein);
        filein >> x;    filein.ignore();
        getline(filein, tenHH, x);
        filein >> gia_von;
        filein.ignore();
        filein >> gia_ban;
        filein.ignore();
        filein >> so_luong;
        filein.ignore();
        filein >> ngay_nhap;
        filein.ignore();
        filein >> maPL;
        filein.ignore();
        HamChuanHoa(tenHH);
        // Kiem tra ma hang hoa va ten hang hoa co trung khong 
        if (FindIndex(maHH) != -1 && FindIndexTen(tenHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " va ten hang hoa " << tenHH << " da ton tai"<< endl;
            continue;
        }
        else if (FindIndex(maHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexTen(tenHH) != -1)
        {
            cout << "\t\t\t\t\t\tTen hang hoa " << tenHH << " da ton tai" << endl;
            continue;
        }
        // Kiem tra ma phan loai da ton tai chua
        if (FindIndexPL(maPL) == -1 ){
            int opt;
            cout << "\n\t\t\t\t\t\tMa phan loai " << maPL << " chua ton tai. Ban muon them ma phan loai nay khong?";
            cout << "\n\t\t\t\t\t\t1. Co";
            cout << "\n\t\t\t\t\t\t0. Khong";
            cout << "\n\t\t\t\t\t\tNhap lua chon: ";  cin >> opt;
            if(opt != 1) continue;
            else{
                string tenPL ;  cin.ignore();
                cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
                HamChuanHoa(tenPL);

                while (FindIndexTenPL(tenPL) != -1){
                    cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                    cin.ignore(); getline(cin, tenPL);
                    HamChuanHoa(tenPL);
                }
                
                PhanLoai *pl = new PhanLoai(maPL, tenPL);
                databasePL.push_back(pl);
                int n = (this->lengthPL) + 1; this->setLengthPL(n);
                cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
            }
        }

        Kho *kho = new Kho(maHH, tenHH, gia_von, gia_ban, so_luong, ngay_nhap, maPL);
        databaseK.push_back(kho);
        (this->lengthK)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

// Tìm kiếm nhân viên theo mã nhân viên
int QuanLyHang::FindIndex(const int &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getMaHH() == index)
            return i;
    }
    return -1;
}

// Tìm kiếm nhân viên theo tên nhân viên
int QuanLyHang::FindIndexTen(const string &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getTenHH() == index)
            return i;
    }
    return -1;
}

void QuanLyHang::Remove()
{
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Xoa theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Xoa theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\tNhap lua chon:\t";

    int luachon; cin >> luachon;

    if (luachon == 1){
        int maHH;
        cout << "\t\t\t\t\t\tNhap ma hang hoa: ";   cin >> maHH;
        if (FindIndex(maHH) == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
            databaseK.erase(FindIndex(maHH));
            this->lengthK--;
            cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
        }
    } 
    if (luachon == 2){
        string tenHH;
        cin.ignore(); 
        cout << "\t\t\t\t\t\tNhap ten hang hoa: ";  getline(cin,tenHH);
        HamChuanHoa(tenHH);
        if (FindIndexTen(tenHH) == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            databaseK.erase(FindIndexTen(tenHH));
            this->lengthK--;
            cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
        }
    }
}

void QuanLyHang::Find(){
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\tNhap lua chon: ";
    int luachon; cin >> luachon;
    if (luachon == 1){
        int maHH;
        cout << "\t\t\t\t\t\tNhap ma: ";    cin >> maHH;
        int n = FindIndex(maHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
                cout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
                cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
                << "Gia Ban|" << setw(9) << "So luong|" << setw(14) << "Ngay nhap|" << setw(10) << "Phan loai|";
                cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
                cout << *databaseK[n];
                cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
        }
    } else
    {
        string tenHH;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenHH);
        HamChuanHoa(tenHH);
        int n = FindIndexTen(tenHH);
        if ( n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
            cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
            << "Gia Ban|" << setw(9) << "So luong|" << setw(14) << "Ngay nhap|" << setw(10) << "Phan loai|";
            cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
            cout << *databaseK[n];
            cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
        }
    }
}
void QuanLyHang::Update(){
    system("cls");
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ma\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Cap nhat phan loai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Cap nhat gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t5. Cap nhat gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t6. Cap nhat so luong\t\t|";
    cout << "\n\t\t\t\t\t\t|\t7. Cap nhat ngay nhap\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------" << endl;
    int luachon; 
    cout << "\t\t\t\t\t\tNhap lua chon: ";
    cin >> luachon;
    if (luachon == 0){
        return;
    }else{
        int hh; cout << "\t\t\t\t\t\tNhap ma so hang hoa can cap nhat: ";
        cin >> hh;
        if (FindIndex(hh) == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        switch (luachon){
            case 1:
            {
                int maHH;
                cout << "\t\t\t\t\t\tNhap ma hang hoa moi: "; cin >> maHH;
                while (FindIndex(maHH) != -1 && maHH != hh){
                    cout << "\t\t\t\t\t\tMa hang hoa da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap ma hang hoa: "; cin >> maHH;
                }
                databaseK[FindIndex(hh)]->setMaHH(maHH);
                break;
            }
            case 2:
            {
                string tenHH;
                cout << "\t\t\t\t\t\tNhap ten hang hoa moi: ";
                cin.ignore(); getline(cin, tenHH);
                HamChuanHoa(tenHH);
                databaseK[FindIndex(hh)]->setTenHH(tenHH);
                break;
            }
            case 3:
            {
                int maPL;
                cout << "\t\t\t\t\t\tNhap ma phan loai moi: ";
                cin >> maPL;
                if (FindIndexPL(maPL) == -1 ){
                    int opt;
                    cout << "\t\t\t\t\t\tMa phan loai chua ton tai! Ban muon them ma phan loai moi khong?";
                    cout << "\n\t\t\t\t\t\t1. Co";
                    cout << "\n\t\t\t\t\t\t0. Khong" << endl;
                    cout << "\n\t\t\t\t\t\tNhap lua chon: ";  cin >> opt;
                    if(opt != 1) return;
                    else{
                        string tenPL ;  cin.ignore();
                        cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
                        HamChuanHoa(tenPL);

                        while (FindIndexTenPL(tenPL) != -1){
                            cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                            cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                            cin.ignore(); getline(cin, tenPL);
                            HamChuanHoa(tenPL);
                        }
                
                        PhanLoai *pl = new PhanLoai(maPL, tenPL);
                        databasePL.push_back(pl);
                        int n = (this->lengthPL) + 1; this->setLengthPL(n);
                        cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
                    }
                }
                databaseK[FindIndex(hh)]->phan_loai.setMaPL(maPL);
                break;
            }
            case 4:
            {
                double giavon;
                cout << "\t\t\t\t\t\tNhap gia von moi: ";
                cin >> giavon;
                databaseK[FindIndex(hh)]->setGiaVon(giavon);
                break;
            }
            case 5:
            {
                double giaban;
                cout << "\t\t\t\t\t\tNhap gia ban moi: ";
                cin >> giaban;
                databaseK[FindIndex(hh)]->setGiaBan(giaban);
                break;
            }
            case 6:
            {
                int soluong;
                cout << "\t\t\t\t\t\tNhap so luong moi: ";
                cin >> soluong;
                databaseK[FindIndex(hh)]->setSoLuong(soluong);
                break;
            }
            case 7:
            {
                Date ngaynhap;
                cout << "\t\t\t\t\t\tNhap ngay nhap moi: ";
                cin >> ngaynhap;
                databaseK[FindIndex(hh)]->setNgayNhap(ngaynhap);
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

void QuanLyHang::Show()
{   
    cout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
    << "Gia Ban|" << setw(10) << "So luong|" << setw(14) << "Ngay nhap|" << setw(10) << "Phan loai|";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < this->getLengthK(); i++)
    {
        cout << *databaseK[i];
    }
    cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
}

void QuanLyHang::Writef(){
    ofstream fileout;
    fileout.open("XuatKho.txt");
    fileout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
    fileout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
    fileout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
    << "Gia Ban|" << setw(9) << "So luong|" << setw(14) << "Ngay nhap|" << setw(10) << "Phan loai|";
    fileout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < this->getLengthK(); i++)
    {
        fileout << *databaseK[i];
    }
    fileout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
bool up(double x, double y)
{
    return (x > y) ? true : false;
}
bool down(double x, double y)
{
    return (x < y) ? true : false;
}

void QuanLyHang::selectionsortGiaBan(bool (*cmp)(double,double)){
    for(int i = 0; i< this->lengthK-1;i++){
        for (int j = i + 1; j < this->lengthK; j++){
            if (cmp(databaseK[i]->getGiaBan(),databaseK[j]->getGiaBan())){
                swap(databaseK[i],databaseK[j]);
            }
        }
    }
}
void QuanLyHang::selectionsortGiaVon(bool (*cmp)(double,double)){
    for(int i = 0; i< this->lengthK-1;i++){
        for (int j = i + 1; j < this->lengthK; j++){
            if (cmp(databaseK[i]->getGiaVon(),databaseK[j]->getGiaVon())){
                swap(databaseK[i],databaseK[j]);
            }
        }
    }
}
void QuanLyHang::Sort(){
    system("cls");
    cout << "\n\t\t\t\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Sap xep theo chieu giam cua gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Sap xep theo chieu tang cua gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Sap xep theo chieu giam cua gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Sap xep theo chieu tang cua gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t\tNhap lua chon:\t";
    int luachon; cin >> luachon;
    switch(luachon){
        case 0:
        {
            break;
        }
        case 1:
        {
            selectionsortGiaBan(down);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        case 2:
        {
            selectionsortGiaBan(up);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        case 3:
        {
            selectionsortGiaVon(down);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        case 4:
        {
            selectionsortGiaVon(up);
            cout << "\t\t\t\t\t\tSap xep thanh cong!" << endl;
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!";
            break;

        }
    }
}
int QuanLyHang::FindIndexDM(const int &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->phan_loai.getMaPL() == index)
            return i;
    }
    return -1;
}
int QuanLyHang::FindIndexTenDM(const string &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->phan_loai.getTenPL() == index)
            return i;
    }
    return -1;
}

///// THAO TAC VOI PHAN LOAI HANG
int QuanLyHang::getLengthPL() 
{
    return this->lengthPL;
}

void QuanLyHang::setLengthPL(int lengthPL)
{
    this->lengthPL = lengthPL;
}

void QuanLyHang::ReadfPL(){
    ifstream filein;
    filein.open("PhanLoai.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    
    while (filein.eof() != true)
    {
        int maPL;
        string tenPL;

        filein >> maPL;
        filein.ignore();
        getline(filein, tenPL);
        HamChuanHoa(tenPL);
        if (FindIndexPL(maPL) != -1 && FindIndexTenPL(tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << maPL << " va ten phan loai " << tenPL << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexPL(maPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << maPL << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexTenPL(tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tTen phan loai " << tenPL << " da ton tai" << endl;
            continue;
        }

        PhanLoai *phan_loai = new PhanLoai(maPL, tenPL);
        databasePL.push_back(phan_loai);
        int n = this->lengthPL + 1; setLengthPL(n);
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

void QuanLyHang::InsertPL(){
    PhanLoai *pl = new PhanLoai;
    cin >> *pl;

    if (FindIndexPL(pl->maPL) != -1 && FindIndexTenPL(pl->tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << pl->maPL << " va ten phan loai " << pl->tenPL << " da ton tai" << endl;
            return;
        }
        else if (FindIndexPL(pl->maPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << pl->maPL << " da ton tai" << endl;
            return;
        }
        else if (FindIndexTenPL(pl->tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tTen phan loai " << pl->tenPL << " da ton tai" << endl;
            return;
        }
    string ten = pl->getTenPL();
    HamChuanHoa(ten)    ; pl->setTenPL(ten);
    databasePL.push_back(pl);
    int n = (this->lengthPL) + 1; this->setLengthPL(n);
    cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
}
void QuanLyHang::RemovePL(){
    int maPL;
    cout << "\t\t\t\t\t\tNhap ma phan loai: ";   cin >> maPL;
    if (FindIndexPL(maPL) == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    } else{
        if (FindIndexDM(maPL) != -1)
        {
            cout << "\t\t\t\t\t\tPhan loai da duoc dang ki boi hang hoa. Khong the xoa!" << endl;
            return;
        }
        databasePL.erase(FindIndexPL(maPL));
        this->lengthPL--;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}

void QuanLyHang::WritefPL(){
    ofstream fileout;
    fileout.open("XuatPhanLoai.txt");

    fileout << "\n\t\t\t\t\t\t\t      DANH SACH CAC PHAN LOAI";
    fileout << "\n\t\t\t\t\t\t\t -----------------------------";
    fileout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
    fileout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
    for (int i = 0; i < this->getLengthPL(); i++)
    {
        fileout << *databasePL[i];
    }
    fileout << "\t\t\t\t\t\t\t -----------------------------" << endl;
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}

void QuanLyHang::ShowPL(){
    cout << "\n\t\t\t\t\t\t\t      DANH SACH CAC PHAN LOAI";
    cout << "\n\t\t\t\t\t\t\t -----------------------------";
    cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
    cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
    for (int i = 0; i < this->getLengthPL(); i++)
    {
        cout << *databasePL[i];
    }
    cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
}
void QuanLyHang::FindPL(){
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\tNhap lua chon: ";
    int luachon; cin >> luachon;
    if (luachon == 1){
        int maPL;
        cout << "\t\t\t\t\t\tNhap ma: ";    cin >> maPL;
        int n = FindIndexPL(maPL);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t\t -----------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
            cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
            cout << *databasePL[n];
            cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
        }
    } else
    {
        string tenPL;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenPL);
        HamChuanHoa(tenPL);
        int n = FindIndexTenPL(tenPL);
        if ( n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t\t -----------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
            cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
            cout << *databasePL[n];
            cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
        }
    }
    
}

int QuanLyHang::FindIndexPL(const int &index)
{
    for (int i = 0; i < this->lengthPL; i++)
    {
        if (databasePL[i]->getMaPL() == index)
            return i;
    }
    return -1;
}
int QuanLyHang::FindIndexTenPL(const string &index)
{
    for (int i = 0; i < this->lengthPL; i++)
    {
        if (databasePL[i]->getTenPL() == index)
            return i;
    }
    return -1;
}
void QuanLyHang::UpdatePL(){
    system("cls");
    cout << "\n\t\t\t\t\t\t---------------------------";
    cout << "\n\t\t\t\t\t\t|1. Cap nhat ma\t\t|";
    cout << "\n\t\t\t\t\t\t|2. Cap nhat ten\t|";
    cout << "\n\t\t\t\t\t\t|0. Thoat\t\t|";
    cout << "\n\t\t\t\t\t\t----------------------------" << endl;
    int luachon; 
    cout << "\t\t\t\t\t\tNhap lua chon: ";
    cin >> luachon;
    if (luachon == 0){
        return;
    }else{
        int maPL; cout << "\t\t\t\t\t\tNhap ma so phan loai can cap nhat: ";
        cin >> maPL;
        if (FindIndexPL(maPL) == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        switch (luachon){
            case 1:
            {
                int maPL;
                cout << "\t\t\t\t\t\tNhap ma phan loai moi: "; cin >> maPL;
                while (FindIndex(maPL) != -1){
                    cout << "\t\t\t\t\t\tMa phan loai da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap ma phan loai: "; cin >> maPL;
                }
                databasePL[FindIndexPL(maPL)]->setMaPL(maPL);
                break;
            }
            case 2:
            {
                string tenPL;
                cout << "\t\t\t\t\t\tNhap ten phan loai moi: ";
                cin.ignore(); getline(cin, tenPL);
                HamChuanHoa(tenPL);
                while (FindIndexTen(tenPL) != -1){
                    cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap ten hang hoa: ";
                    cin.ignore(); getline(cin, tenPL);
                    HamChuanHoa(tenPL);
                }
                databasePL[FindIndexPL(maPL)]->setTenPL(tenPL);
                break;
            }
            default:
            {
                cout << "\t\t\t\t\t\tLua chon khong hop le!";
                cout << "\n\t\t\t\t\t\t"; system("pause");
                break;
            } 
        }
        cout << "\nCap nhat thanh cong!" << endl;
    }
}