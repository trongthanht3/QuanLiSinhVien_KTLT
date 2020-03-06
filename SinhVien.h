#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class SinhVien
{
	private:
		string MaLop;
		int MaSV;
		string HoTen;
		int Ngay;
		int Thang;
		int Nam;
		float DiemTB;
		
	public:
		SinhVien();
		SinhVien(string MaLop, int MaSV, string HoTen, int Ngay, int Thang, int Nam, float DiemTB);
		
		void ThemHoSo();
		
		void setMaLop(string MaLop);
		string getMaLop();
		void setMaSV(int MaSV);
		int getMaSV();
		void setHoTen(string HoTen);
		string getHoTen();
		
		void setNgaySinh(int Ngay, int Thang, int Nam);
		int getNgay();
		int getThang();
		int getNam();
		string toString_NgaySinh();
		
		void setDiemTB(float DiemTB);
		float getDiemTB();
		
		string toString_SinhVien();
		
	protected:
};

#endif
