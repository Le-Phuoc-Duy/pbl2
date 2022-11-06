#include <string>
#pragma once
using namespace std;
class PhanLoai{
    private:
        int maPL;
        string tenPL;
    public:
    // Ham getter
        string getTenPL();
        int getMaPL();
    // Ham setter
        void setTenPL(string);
        void setMaPL(int);
    // Ham constructor
        PhanLoai();
        PhanLoai(int, string);
    // Ham desstructor
        ~PhanLoai();
        friend istream& operator>>(istream&, PhanLoai&);
        friend ostream& operator<<(ostream&, const PhanLoai&);
        friend class QuanLyHang;
};