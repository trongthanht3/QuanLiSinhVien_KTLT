#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Date.h"
#include "ConstString.h"
#include "iomanip"
#include <exception>

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
		string getLastHoTen();
		
		void setNgaySinh(int Ngay, int Thang, int Nam);
		void setNgaySinh(Date _NgaySinh);
		Date getNgaySinh();
        string toString_NgaySinh();

		void setDiemTB(float DiemTB);
		float getDiemTB();
		
		string toString_SinhVien();
        void toScreen_SinhVien();
		string chuanHoaString();
		void exportData();
		void importData(fstream& dataInput, SinhVien &temp);
		friend void alo();
	protected:
};

#endif
