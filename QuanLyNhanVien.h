#include "NhanVien.h"
#include "List.h"
#pragma once

class QuanLyNhanVien
{
private:
    List<NhanVien*> databaseNV;
    int lengthNV;
public:
        QuanLyNhanVien();
        ~QuanLyNhanVien();
        void setLengthNV(int);
        int getLengthNV();

        void Readf();
        void Show();
        void Insert();
        void Writef();
        void Find();
        void Sort();
        void selectionsortTen(bool (*cmp)(string, string));
        int FindIndex(const int&);
        int FindIndexTen(const string&);

        void HamChuanHoa(string& a);
        friend void Input(QuanLyNhanVien&, int, string);
        friend class HoaDon;
        friend class QuanLyHD;
};