#pragma once
#include "QuanLy.h"
#include "List.h"
#include "HoaDon.h"
class QuanLyHD : public QuanLy{
    private:
        List <HoaDon*> databaseHD;
        int lengthHD;
    public:
        QuanLyHD();
        ~QuanLyHD();

        int getLengthHD();
        void setLengthHD(int);

        void Insert(QuanLyNV&, QuanLyKH&, QuanLyHang&);
        int FindIndexHD(const int&);
        int FindIndexNV(const int&);
        int FindIndex(const string&);
        int FindIndexHH(const int&);
        void Remove();
        void Show(QuanLyHang&);
        void Find(QuanLyHang&);

        friend class ChiTietHoaDon;
        friend void QuanLyKH::Remove(QuanLyHD&);
        friend void QuanLyKH::Update(QuanLyHD&);
        friend void QuanLyNV::Remove(QuanLyHD&);
        // void UpdateHH(QuanLyHang&);
        // void RemoveHH(QuanLyHang&);
};