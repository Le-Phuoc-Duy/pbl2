#pragma once
#include "QuanLy.h"
#include "List.h"
#include "KhachHang.h"
using namespace std;

class QuanLyHD;
class QuanLyKH : public QuanLy{
    private:
        List<KhachHang*> databaseKH;
        int lengthKH;
    public:
        QuanLyKH();
        ~QuanLyKH();
        int getLengthKH();
        void setLengthKh(int);

        void Readf();
        void Insert();
        void Show();
        void Find();
        void Writef();
        void Remove(QuanLyHD&);
        void Update(QuanLyHD&);
        int FindIndex(const int&);
        int FindIndexSDT(const string &);
        int FindIndexTen(const string&);

        friend class HoaDon;
};