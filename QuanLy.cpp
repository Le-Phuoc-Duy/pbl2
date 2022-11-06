#include "QuanLy.h"
#include <iostream>

void QuanLy::HamChuanHoa(string& a){
    while(a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }

    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1 );
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ' && a[i+1] == ' '){
            a.erase(a.begin() + i);
            i--;
        }
    }

    if (a[0] >= 97 && a[0] <= 122)
    {
        a[0] -= 32;
    }

    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == ' '){
            i++;
            if (a[i] >= 97 && a[i] <= 122)
            {
                a[i] -= 32;
            }
        }
        else{
                if (a[i] >= 65 && a[i] <= 90){
                    a[i] += 32;
                }
        }
    }
}
QuanLy::QuanLy(){}
QuanLy::~QuanLy(){}