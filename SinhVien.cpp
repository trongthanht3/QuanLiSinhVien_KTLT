#include "SinhVien.h"

//using namespace std;

SinhVien::SinhVien()
{
}

SinhVien::SinhVien(string MaLop, int MaSV, string HoTen, int Ngay, int Thang, int Nam, float DiemTB)
{
	this->MaLop = MaLop;
	this->MaSV = MaSV;
	this->HoTen = HoTen;
	this->Ngay = Ngay;
	this->Thang = Thang;
	this->Nam = Nam;
	this->DiemTB = DiemTB;
}

void SinhVien::ThemHoSo()
{
	cout << "Nhap ho so sinh vien!" << endl;
	
	cout << "Ma lop: ";
	getline(cin, MaLop);
	cout << "Ma sinh vien: ";
	cin >> MaSV;
	cin.ignore();
	cout << "Ho va ten: ";
	getline(cin, HoTen);
	cout << "Ngay sinh (ngay/thang/nam): ";
	cin >> Ngay >> Thang >> Nam;
	cout << "Diem trung binh tich luy: ";
	cin >> DiemTB;
}

void SinhVien::setMaLop(string MaLop)
{
	this->MaLop = MaLop;
}
string SinhVien::getMaLop()
{
	return MaLop;
}

void SinhVien::setMaSV(int MaSV)
{
	this->MaSV = MaSV;
}
int SinhVien::getMaSV()
{
	return MaSV;
}

void SinhVien::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}
string SinhVien::getHoTen()
{
	return HoTen;
}

void SinhVien::setNgaySinh(int Ngay, int Thang, int Nam)
{
	this->Ngay = Ngay;
	this->Thang = Thang;
	this->Nam = Nam;
}
int SinhVien::getNgay()
{
	return Ngay;
}
int SinhVien::getThang()
{
	return Thang;
}
int SinhVien::getNam()
{
	return Nam;
}
string SinhVien::toString_NgaySinh()
{
	ostringstream date;
	date << Ngay << "/" << Thang << "/" << Nam;
	return date.str();
}

void SinhVien::setDiemTB(float DiemTB)
{
	this->DiemTB = DiemTB;
}
float SinhVien::getDiemTB()
{
	return DiemTB;
}

string SinhVien::toString_SinhVien()
{
	ostringstream _SinhVien;
	_SinhVien << MaLop << "|" << MaSV  << "|" << HoTen << "|" << toString_NgaySinh() << "|" << DiemTB;

	return _SinhVien.str();
}







