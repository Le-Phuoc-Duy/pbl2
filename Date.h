#pragma once
#include <iostream>
using namespace std;
class Date{
    private:
        int ngay, thang, nam;
    public:
    // Ham getter
        int getNgay();
        int getThang();
        int getNam();
    // Ham setter
        void setNgay(int);      
        void setThang(int);       
        void setNam(int);   
    //
    
    // Ham constructor

    Date();
    Date(int, int, int);
    // Ham destructor
    ~Date();
    // Ham da nang hoa
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);

    friend bool HamThoiGian(const Date&);
};