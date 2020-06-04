#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "SinhVien.h"
#include "InDanhSach.h"
#include "SapXep.h"
#include "TimKiem.h"
#include "ThongKe.h"
#include "ConstString.h"
#include "Tools.h"

class Menu
{
	private:
		int choiceMenu;
	public:
		Menu();
		~Menu();
		bool HienThi();
		void thoat();
	protected:
};

#endif
