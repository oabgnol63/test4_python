#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Dichvu
{
    private:
        long maDV;
        string tenDV;
        double giacuoc;
    public:
        Dichvu(){};
        Dichvu(long a, string b, double c)
            {
                this->maDV = a;
                this->tenDV = b;
                this->giacuoc = c;
            }
        void Nhap() 
            {
                cout << "Nhap ma dich vu: "; cin >> maDV;
                cout << "Nhap ten dich vu: "; cin.ignore(); getline(cin,tenDV);
                cout << "Nhap gia dich vu: "; cin >> giacuoc; 
            }
        void Xuat()
            {
                cout << "Ma dich vu: " << maDV << endl;
                cout << "Ten dich vu: " << tenDV << endl;
                cout << "Gia cuoc: " << giacuoc << endl;
            }
        double Laygiacuoc()
            {
                return this->giacuoc;
            }
        string getDV()
            {
                return this->tenDV;
            }
};
class Nguoi
{
    protected:
        string name, addr, tel;
    public:
        Nguoi(){};
        Nguoi(string a,string b,string c)
            {
                this->name = a;
                this->addr = b;
                this->tel = c;
            }
        void Nhap() 
            {
                cout << "Nhap ho ten: "; getline(cin,this->name);
                cout << "Nhap dia chi: "; getline(cin,this->addr);
                cout << "Nhap so dien thoai: "; getline(cin,this->tel);
            }
        void Xuat()
            {
                cout << "Ho ten: " << name << endl;
                cout << "Dia chi: " << addr << endl;
                cout << "So dien thoai: " << tel << endl;
            }
};

class Khachhang : public Nguoi
{
    private:
        int Soluongdichvu;
        Dichvu dv[100];
    public:
        Khachhang(){};
        void Nhap()
            {
                Nguoi::Nhap();
                cout << "Nhap so luong dich vu: "; cin >> Soluongdichvu;
                for(int i = 0; i<Soluongdichvu; i++)
                    {
                        dv[i].Nhap();
                    }
            }
        void Xuat()
            {
                Nguoi::Xuat();
                for(int i = 0; i<Soluongdichvu; i++)
                    {
                        dv[i].Xuat();
                    }
                cout << endl;
            }
        void XuatDv()
            {
                Nguoi::Xuat();
                cout << "Cac dich vu su dung: " << endl;
                for(int i = 0; i<Soluongdichvu; i++)
                    {
                       cout << "\t" << dv[i].getDV() << " -- " << dv[i].Laygiacuoc() << endl;
                    }
            }
        void Phidichvu()
            {   
                cout << "-----------------------------------------------------------------------------------------------------" << endl;
                Khachhang::XuatDv();
                double tong = 0;
                for(int i = 0; i<Soluongdichvu; i++)
                    {
                        tong += dv[i].Laygiacuoc();
                    }
                cout << "=======>" << "Phi_dich_vu: "; 
                cout << fixed << setprecision(2) << tong << "<=======" << endl;
            }
        int Get_SoLuongDichVu()
            {
                return this->Soluongdichvu;
            }
        string _print()
            {
                string s;
                cout << "Nhap chuoi: ";
                cin.ignore();
                getline(cin,s);
                cout << s << endl;
                return s;
            }
};

#endif

