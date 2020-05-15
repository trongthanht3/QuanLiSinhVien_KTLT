#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "SinhVien.h"
#include "InDanhSach.h"
#include "SapXep.h"
#include "TimKiem.h"
#include "ConstString.h"

class Menu
{
	private:
		int choiceMenu;
	public:
		Menu();
		~Menu();
		void HienThi();
		void thongKe();
		
		void thoat();
	protected:
};

#endif
