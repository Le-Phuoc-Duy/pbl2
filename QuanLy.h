#pragma once
#include <string>
using namespace std;

class QuanLy
{
protected:
public:
    QuanLy();
    virtual ~QuanLy();
    // virtual void Readf() = 0;
    // virtual void Insert() = 0;
    // virtual void Show() = 0;
    // virtual void Update() = 0;
    // virtual void Delete() = 0;
    // virtual void Writef() = 0;

    void HamChuanHoa(string&);
};

