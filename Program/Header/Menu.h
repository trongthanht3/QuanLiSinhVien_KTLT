#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "SinhVien.h"
#include "InDanhSach.h"

class Menu
{
	private:
		int choiceMenu;
		static const string nhapsai;
		static const string baotri;
	public:
		Menu();
		~Menu();
		void hienThi();
		
		void sapXep();				//se duoc tach ra class rieng
		int algoSapXep();		
			
		void timKiem();				//se duoc tach ra class rieng
		int algoTimKiem();
		
		int chonKhoa();		//return ve key-type cho cac thuat toan sapxep/timkiem
		void thongKe();
		
		void thoat();
	protected:
};

#endif
