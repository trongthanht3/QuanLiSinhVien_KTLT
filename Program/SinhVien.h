#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"

using namespace std;

class SinhVien
{
	private:
		string MaLop;
		int MaSV;
		string HoTen;
		Date NgaySinh;
		float DiemTB;
		
	public:
		SinhVien();
		SinhVien(string MaLop, int MaSV, string HoTen, Date NgaySinh, float DiemTB);
//		~SinhVien();
		
		void ThemHoSo();
		
		void setMaLop(string MaLop);
		string getMaLop();
		void setMaSV(int MaSV);
		int getMaSV();
		void setHoTen(string HoTen);
		string getHoTen();
		
		void setNgaySinh(int Ngay, int Thang, int Nam);
		Date getNgaySinh();
		
		void setDiemTB(float DiemTB);
		float getDiemTB();
		
		string toString_SinhVien();
		
		friend void alo();
	protected:
};

#endif
