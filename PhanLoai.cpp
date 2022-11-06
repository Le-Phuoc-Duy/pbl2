#include <iostream>
#include "PhanLoai.h"
#include <iomanip>
// Ham getter
string PhanLoai::getTenPL(){
    return this->tenPL;
}
int PhanLoai::getMaPL(){
    return this-> maPL;
}
// Ham setter
void PhanLoai::setTenPL(string tenPL){
    this->tenPL = tenPL;
}
void PhanLoai::setMaPL(int  maPL){
    this-> maPL =  maPL;
}
// Ham constructor
PhanLoai::PhanLoai(){}
PhanLoai::PhanLoai(int  maPL, string tenPL){
    this-> maPL =  maPL;
    this->tenPL = tenPL;
}
// Ham destructor
PhanLoai::~PhanLoai(){}

istream& operator>>(istream& in, PhanLoai& pl)
{
    cout << "\t\t\t\t\t\tNhap ma phan loai: ";   in >> pl.maPL;
    in.ignore();
    cout << "\t\t\t\t\t\tNhap ten phan loai: ";  getline(in, pl.tenPL);
    return in;
}
ostream& operator<<(ostream& out, const PhanLoai& pl)
{
    out << "\t\t\t\t\t\t\t |" << setw(12) << pl.maPL << "|" << setw(14) << pl.tenPL <<  "|" << endl;
    return out;
}