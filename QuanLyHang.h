#include "QuanLy.h"
#include "List.h"
#include "Kho.h"
#pragma once
class QuanLyHang : public QuanLy{
    private:
        List <Kho*> databaseK;
        List <PhanLoai*> databasePL;
        int lengthK;
        int lengthPL;
    public:
        QuanLyHang();
        ~QuanLyHang();
        //Ham getter setter
        int getLengthK() ;
        void setLengthK(int);
        int getLengthPL() ;
        void setLengthPL(int);

        void Readf();
        void Show();
        void Insert();
        void Update();
        void Remove();
        void Writef();
        void Find();
        void Sort();
        void selectionsortGiaBan(bool (*cmp)(double,double));
        void selectionsortGiaVon(bool (*cmp)(double,double));
        int FindIndex(const int&);
        int FindIndexTen(const string&);
        int FindIndexDM(const int&);
        int FindIndexTenDM(const string&);

        void ReadfPL();
        void ShowPL();
        void InsertPL();
        void RemovePL();
        void WritefPL();
        void FindPL();
        int FindIndexPL(const int&);
        int FindIndexTenPL(const string&);
        void UpdatePL();
        
        friend class ChiTietHoaDon;
};
