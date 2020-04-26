#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "SinhVien.h"
#include "InDanhSach.h"
#include "SapXep.h"
#include "ConstString.h"

class Menu
{
	private:
		int choiceMenu;
	public:
		Menu();
		~Menu();
		void HienThi();

    void timKiem();				//se duoc tach ra class rieng
		int algoTimKiem();
		
		int chonKhoa();		//return ve key-type cho cac thuat toan sapxep/timkiem
		void thongKe();
		
		void thoat();
	protected:
};

#endif
