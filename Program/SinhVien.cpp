#include "SinhVien.h"

using namespace std;

SinhVien::SinhVien()
{
	this->MaLop = "";
	this->MaSV = -1;
	this->HoTen = "";
//	this->NgaySinh.Date(1,1,1);
	this->DiemTB = 0;
}

SinhVien::SinhVien(string MaLop, int MaSV, string HoTen, Date NgaySinh, float DiemTB)
{
	this->MaLop = MaLop;
	this->MaSV = MaSV;
	this->HoTen = HoTen;
	this->NgaySinh = NgaySinh;
	this->DiemTB = DiemTB;
}

//SinhVien::~SinhVien()
//{
//	cout << "\nSinh vien: " << this->MaSV << " da duoc xoa khoi he thong.\n";
//}

void SinhVien::ThemHoSo()
{
	cout << "\nNhap ho so sinh vien!" << endl;
	cin.ignore();
	cout << "Ma lop: ";
	getline(cin, MaLop);
	cout << "Ma sinh vien: ";
	cin >> MaSV;
//	cout << MaSV;
	if (MaSV <= 0) {
		do {
			cin.clear();		//clears the error flag on cin (so that future I/O operations will work correctly)
			cin.ignore();		//skips to the next newline (to ignore anything else on the same line as the non-number)
			cout << "Khong hop le! Nhap lai: ";
			cin >> MaSV;
		} while (MaSV <= 0);
	}
	cin.ignore();
	cout << "Ho va ten: ";
	getline(cin, HoTen);
	cout << "Ngay sinh (ngay/thang/nam): ";
	NgaySinh.userInput();
	cin.ignore();
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
	NgaySinh.setDate(Thang, Ngay, Nam);
}
Date SinhVien::getNgaySinh()
{
	return NgaySinh;
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
	_SinhVien << MaLop << "|" << MaSV  << "|" << HoTen << "|" << NgaySinh.asString() << "|" << DiemTB;

	return _SinhVien.str();
}




