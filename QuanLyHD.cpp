#include "QuanLyHD.h"

QuanLyHD::QuanLyHD(){
    this->lengthHD = 0;
}
QuanLyHD::~QuanLyHD(){};
int QuanLyHD::getLengthHD(){
    return this->lengthHD;
}
void QuanLyHD::setLengthHD(int lengthHD){
    this->lengthHD = lengthHD;
}

void QuanLyHD::Insert(QuanLyNV& nv, QuanLyKH& kh, QuanLyHang& hh){
    int maHD, maNV; string sdt;
    cout << "\t\t\t\t\t\tNhap ma nhap vien nhap: ";    cin >> maNV;
    while (nv.FindIndex(maNV) == -1){
        cout << "\t\t\t\t\t\tMa nhan vien chua ton tai!" << endl;
        cout << "\t\t\t\t\t\tNhap lai ma nhap vien nhap: ";    cin >> maNV;
    }
    cout << "\t\t\t\t\t\tNhap ma hoa don: ";    cin >> maHD;
    while (FindIndexHD(maHD) != -1){
        cout << "\t\t\t\t\t\tMa hoa don da ton tai!"<< endl;
        cout << "\t\t\t\t\t\tNhap ma hoa don: ";    cin >> maHD;
    }
    cout << "\t\t\t\t\t\tNhap SDT khach hang: "; cin.ignore(); getline(cin, sdt);
    while (kh.FindIndexSDT(sdt) == -1){
        cout << "\t\t\t\t\t\tSDT chua ton tai!" << endl; return;
    }
    HoaDon *hd = new HoaDon;
    hd->Input(kh, nv, hh, maHD, maNV, sdt);
    databaseHD.push_back(hd);
    lengthHD++;
}
int QuanLyHD::FindIndexHD(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaHD() == index)
            return i;
    }
    return -1;
}
int QuanLyHD::FindIndexNV(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaNV() == index)
            return i;
    }
    return -1;
}
// int QuanLyHD::FindIndexHH(const int &index)
// {
//     for (int i = 0; i < this->lengthHD; i++)
//     {
//         int n = this->databaseHD[i]->getLengthCTHD();
//         for (int j = 0; j < n; j++) 
//             if(this->databaseHD[i]->cthd[j]->getMaHH()) return j;
//     }
//     return -1;
// }
int QuanLyHD::FindIndex(const string& a)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getSDT() == a)
            return i;
    }
    return -1;
}

void QuanLyHD::Find(QuanLyHang& hh)
{
    int maHD;
    cout << "\t\t\t\t\t\tNhap ma: ";    cin >> maHD;
    int n = FindIndexHD(maHD);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }else{
            databaseHD[n]->Output(hh);
    }
}
void QuanLyHD::Remove()
{
    int maHD;
    cout << "\t\t\t\t\t\tNhap ma hoa don: ";
    cin >> maHD;
    if (FindIndexHD(maHD) == -1)
    {
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else
    {
        databaseHD.erase(FindIndexHD(maHD));
        this->lengthHD--;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}
void QuanLyHD::Show(QuanLyHang& hh){
    cout << "\n\t\t\t\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    for (int i = 0; i<this->lengthHD; i++){
        cout << "\t\t\t\t\t\tChi tiet hoa don thu " << i + 1;
        databaseHD[i]->Output(hh);
        cout << "\n\n";
    }
}


// void QuanLyHD::RemoveKH(QuanLyKH& kh)
// {
//     int ma;
//     cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> ma;
//     if (kh.FindIndex(ma) == -1)
//     {
//         cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//         return;
//     }
//     string sdt = kh.databaseKH[kh.FindIndex(ma)]->getSDT();
//     if (this->FindIndex(sdt) != -1){
//         cout << "\t\t\t\t\t\tKhach hang da duoc dang ki boi hoa don. Khong the xoa!" << endl;
//         return;
//     }
//     else
//     {
//         kh.databaseKH.erase(kh.FindIndex(ma));
//         kh.lengthKH --;
//         cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
//     }
// }

// void QuanLyHD::UpdateKH(QuanLyKH& kh){
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
//         int ma; 
//         cout << "\t\t\t\t\t\tNhap ma so khach hang can cap nhat: ";  cin >> ma;
//         if (kh.FindIndex(ma) == -1){
//             cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//             return;
//         }
//         switch (luachon){
//             case 1:
//             {
//                 int makh;
//                 cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> makh;
//                 while (kh.FindIndex(makh) != -1 && makh != ma){
//                     cout << "\t\t\t\t\t\tMa khach hang da ton tai. Nhap lai!";
//                     cout << "\t\t\t\t\t\tNhap ma khach hang: "; cin >> makh;
//                 }
//                 kh.databaseKH[kh.FindIndex(ma)]->setMaKH(ma);
//                 break;
//             }
//             case 2:
//             {
//                 string ten;
//                 cout << "\t\t\t\t\t\tNhap ten khach hang: ";
//                 cin.ignore(); getline(cin, ten);
//                 kh.HamXau(ten);
//                 kh.databaseKH[kh.FindIndex(ma)]->setTenKH(ten);
//                 break;
//             }
//             case 3:
//             {
//                 string sdt;
//                 cout << "\t\t\t\t\t\tNhap so dien thoai khach hang: ";
//                 cin.ignore(); getline(cin, sdt);
//                 while (kh.FindIndexSDT(sdt) != -1){
//                     cout << "\t\t\t\t\t\tSDT da ton tai. Nhap lai!";
//                     cout << "\n\t\t\t\t\t\tNhap SDT: ";
//                     cin.ignore(); getline(cin, sdt);
//                 }
//                 string SDT = kh.databaseKH[kh.FindIndex(ma)]->getSDT();
//                 kh.databaseKH[kh.FindIndex(ma)]->setSDT(sdt);

//                 int n = this->FindIndex(SDT);
//                 while (n != -1){
//                     this->databaseHD[n]->setSDT(sdt);
//                     n = this->FindIndex(SDT);
//                 }
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

// void QuanLyHD::UpdateNV(QuanLyNV& ql_nv){
//     system("cls");
//     cout << "\n\t\t\t\t\t\t-----------------------------------------";
//     cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ma\t\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t2. Cap nhat ten\t\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t3. Cap nhat gioi tinh\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t4. Cap nhat ngay sinh\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t5. Cap nhat so dien thoai\t|";
//     cout << "\n\t\t\t\t\t\t|\t6. Cap nhat dia chi\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t7. Cap nhat chuc vu\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
//     cout << "\n\t\t\t\t\t\t-----------------------------------------";
//     int luachon; 
//     cout << "\n\t\t\t\t\t\tNhap lua chon: ";
//     cin >> luachon;
//     if (luachon == 0){
//         return;
//     }else{
//         int nv; cout << "\t\t\t\t\t\tNhap ma so nhan vien can cap nhat: ";
//         cin >> nv;
//         if (ql_nv.FindIndex(nv) == -1){
//             cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//             return;
//         }
//         switch (luachon){
//             case 1:
//             {
//                 int maNV;
//                 cout << "\t\t\t\t\t\tNhap ma nhan vien: "; cin >> maNV;
//                 while (ql_nv.FindIndex(maNV) != -1 && maNV != nv){
//                     cout << "\t\t\t\t\t\tMa nhan vien da ton tai. Nhap lai!";
//                     cout << "\n\t\t\t\t\t\tNhap ma nhan vien: "; cin >> maNV;
//                 }
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setMaNV(maNV);
                
//                 int n = this->FindIndexNV(nv);
//                 while (n != -1){
//                     this->databaseHD[n]->setMaNV(maNV);
//                     n = this->FindIndexNV(nv);
//                 }
//                 break;
//             }
//             case 2:
//             {
//                 string tenNV;
//                 cout << "\t\t\t\t\t\tNhap ten nhan vien: ";
//                 cin.ignore(); getline(cin, tenNV);
//                 ql_nv.HamChuanHoa(tenNV);
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setTenNV(tenNV);
//                 break;
//             }
//             case 3:
//             {
//                 int gioitinh;
//                 cout << "\t\t\t\t\t\tNhap gioi tinh nhan vien: ";
//                 cin >> gioitinh;
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setGioiTinh(gioitinh);
//                 break;
//             }
//             case 4:
//             {
//                 Date ngaysinh;
//                 cout << "\t\t\t\t\t\tNhap ngay sinh nhan vien: ";
//                 cin >> ngaysinh;
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setNgaySinh(ngaysinh);
//                 break;
//             }
//             case 5:
//             {
//                 string sdt;
//                 cout << "\t\t\t\t\t\tNhap so dien thoai nhan vien: ";
//                 cin.ignore(); getline(cin, sdt);
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setSDT(sdt);
//                 break;
//             }
//             case 6:
//             {
//                 string diachi;
//                 cout << "\t\t\t\t\t\tNhap dia chi nhan vien: ";
//                 cin.ignore(); getline(cin,diachi);
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setDiaChi(diachi);
//                 break;
//             }
//             case 7:
//             {
//                 int chucvu;
//                 cout << "\t\t\t\t\t\tNhap chuc vu nhan vien: ";
//                 cin >> chucvu;
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setChucVu(chucvu);
//                 ql_nv.databaseNV[ql_nv.FindIndex(nv)]->setLuong();
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
// void QuanLyHD::RemoveNV(QuanLyNV& ql_nv)
// {
//     int manv;
//     cout << "\t\t\t\t\t\tNhap ma can xoa: ";   cin >> manv;
//     if (ql_nv.FindIndex(manv) == -1){
//         cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//         return;
//     }
//     if (this->FindIndexNV(manv) != -1){
//         cout << "\t\t\t\t\t\tNhan vien da duoc dang ki boi hoa don. Khong the xoa!" << endl;
//         return;
//     }
//         ql_nv.databaseNV.erase(ql_nv.FindIndex(manv));
//         ql_nv.lengthNV--;
//         cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
// }

// void QuanLyHD::UpdateHH(QuanLyHang& ql_hh){
//     system("cls");
//     cout << "\n\t\t\t\t\t\t---------------------------------";
//     cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ma\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t2. Cap nhat ten\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t3. Cap nhat phan loai\t|";
//     cout << "\n\t\t\t\t\t\t|\t4. Cap nhat gia von\t|";
//     cout << "\n\t\t\t\t\t\t|\t5. Cap nhat gia ban\t|";
//     cout << "\n\t\t\t\t\t\t|\t6. Cap nhat so luong\t|";
//     cout << "\n\t\t\t\t\t\t|\t7. Cap nhat ngay nhap\t|";
//     cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t|";
//     cout << "\n\t\t\t\t\t\t-----------------------------------" << endl;
//     int luachon; 
//     cout << "\t\t\t\t\t\tNhap lua chon: ";
//     cin >> luachon;
//     if (luachon == 0){
//         return;
//     }else{
//         int hh; cout << "\t\t\t\t\t\tNhap ma so hang hoa can cap nhat: ";
//         cin >> hh;
//         if (ql_hh.FindIndex(hh) == -1){
//             cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//             return;
//         }
//         switch (luachon){
//             case 1:
//             {
//                 int maHH;
//                 cout << "\t\t\t\t\t\tNhap ma hang hoa moi: "; cin >> maHH;
//                 while (ql_hh.FindIndex(maHH) != -1 && maHH != hh){
//                     cout << "\t\t\t\t\t\tMa hang hoa da ton tai. Nhap lai!";
//                     cout << "\n\t\t\t\t\t\tNhap ma hang hoa: "; cin >> maHH;
//                 }
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setMaHH(maHH);
//                 int n;
//                 do{
//                     n = this->FindIndexHH(nv);
//                     this->databaseHD[n]->setMaNV(nv);
//                 }while (n != -1);
//                 break;
//             }
//             case 2:
//             {
//                 string tenHH;
//                 cout << "\t\t\t\t\t\tNhap ten hang hoa moi: ";
//                 cin.ignore(); getline(cin, tenHH);
//                 ql_hh.HamChuan(tenHH);
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setTenHH(tenHH);
//                 break;
//             }
//             case 3:
//             {
//                 int maPL;
//                 cout << "\t\t\t\t\t\tNhap ma phan loai moi: ";
//                 cin >> maPL;
//                 if (ql_hh.FindIndexPL(maPL) == -1 ){
//                     int opt;
//                     cout << "\t\t\t\t\t\tMa phan loai chua ton tai! Ban muon them ma phan loai moi khong?";
//                     cout << "\n\t\t\t\t\t\t1. Co";
//                     cout << "\n\t\t\t\t\t\t0. Khong" << endl;
//                     cout << "\n\t\t\t\t\t\tNhap lua chon: ";  cin >> opt;
//                     if(opt != 1) return;
//                     else{
//                         string tenPL ;  cin.ignore();
//                         cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
//                         ql_hh.HamChuan(tenPL);

//                         while (ql_hh.FindIndexTenPL(tenPL) != -1){
//                             cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
//                             cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
//                             cin.ignore(); getline(cin, tenPL);
//                             ql_hh.HamChuan(tenPL);
//                         }
                
//                         PhanLoai *pl = new PhanLoai(maPL, tenPL);
//                         ql_hh.databasePL.push_back(pl);
//                         int n = (ql_hh.lengthPL) + 1; ql_hh.setLengthPL(n);
//                         cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
//                     }
//                 }
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setMaPLl(maPL);
//                 break;
//             }
//             case 4:
//             {
//                 double giavon;
//                 cout << "\t\t\t\t\t\tNhap gia von moi: ";
//                 cin >> giavon;
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setGiaVon(giavon);
//                 break;
//             }
//             case 5:
//             {
//                 double giaban;
//                 cout << "\t\t\t\t\t\tNhap gia ban moi: ";
//                 cin >> giaban;
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setGiaBan(giaban);
//                 break;
//             }
//             case 6:
//             {
//                 int soluong;
//                 cout << "\t\t\t\t\t\tNhap so luong moi: ";
//                 cin >> soluong;
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setSoLuong(soluong);
//                 break;
//             }
//             case 7:
//             {
//                 Date ngaynhap;
//                 cout << "\t\t\t\t\t\tNhap ngay nhap moi: ";
//                 cin >> ngaynhap;
//                 ql_hh.databaseK[ql_hh.FindIndex(hh)]->setNgayNhap(ngaynhap);
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
// // void QuanLyHD::RemoveHH(QuanLyHang& ql_hh)
// {
//     cout << "\n\t\t\t\t\t\t---------------------------------";
//     cout << "\n\t\t\t\t\t\t|\t1. Xoa theo ma\t\t|";
//     cout << "\n\t\t\t\t\t\t|\t2. Xoa theo ten\t\t|";
//     cout << "\n\t\t\t\t\t\t---------------------------------";
//     cout << "\n\t\t\t\t\t\tNhap lua chon:\t";

//     int luachon; cin >> luachon;

//     if (luachon == 1){
//         int maHH;
//         cout << "\t\t\t\t\t\tNhap ma hang hoa: ";   cin >> maHH;
//         if (ql_hh.FindIndex(maHH) == -1){
//             cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
//             return;
//         }
//         if (this->FindIndex(maHH) != -1){
//         cout << "\t\t\t\t\t\tNhan vien da duoc dang ki boi hoa don. Khong the xoa!" << endl;
//         return;
//         }
//         else{
//             ql_hh.databaseK.erase(FindIndex(maHH));
//             ql_hh.lengthK--;
//             cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
//         }
//     } 
//     if (luachon == 2){
//         string tenHH;
//         cin.ignore(); 
//         cout << "\t\t\t\t\t\tNhap ten hang hoa: ";  getline(cin,tenHH);
//         ql_hh.HamChuan(tenHH);
//         if (ql_hh.FindIndexTen(tenHH) == -1){
//             cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
//             return;
//         }else{
//             ql_hh.databaseK.erase(ql_hh.FindIndexTen(tenHH));
//             ql_hh.lengthK--;
//             cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
//         }
//     }
// }