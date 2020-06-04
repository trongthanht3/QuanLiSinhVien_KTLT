#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

//const string use so much


bool Menu::HienThi()
{
    system("CLS");
	cout << "****************************************************" << endl
		 << "Chuong trinh quan li sinh vien.					   " << endl
		 << "	1. Them ho so								   " << endl
		 << "	2. In danh sach								   " << endl
		 << "	3. Sap xep									   " << endl
		 << "	4. Tim kiem									   " << endl
		 << "	5. Thong ke									   " << endl
		 << "	6. Thoat									   " << endl
		 << "Chon: ";
	
	do {
		cin >> choiceMenu;
		if (choiceMenu < 1 || choiceMenu >6)
			cout << ConstString::nhapsai;
	} while (choiceMenu < 1 || choiceMenu >6);
	
	switch (choiceMenu) {
		case 1: {
		    system("CLS");
            SinhVien sinhVienTemp;            //khoi tao object temp
            sinhVienTemp.ThemHoSo();
//            cin.get();
            break;
        }
        case 2: {
            system("CLS");
            InDanhSach DanhSach;
            DanhSach.ask();
//            cin.get();
            break;
        }
		case 3: {
            system("CLS");
		    cout << "\nSap xep: ";
            SapXep menuSapXep;
            while(!menuSapXep.ChonKhoa());
            break;
        }
		case 4: {
            cout << "\nTim kiem: " << endl;
            TimKiem menuTimKiem;
            while (!menuTimKiem.ChonKhoa()) {};
            break;
        }
		case 5: {
            system("CLS");
            cout << "\nThong ke: " << endl;
            ThongKe menuThongKe;
            while(!menuThongKe.Menu()) {}
            break;
        }
		case 6: {
            thoat();
            return true;
            break;
        }
		default: {
            cout << ConstString::nhapsai;
            break;
        }
	}
	return false;
}

void Menu::thoat()
{
	cout << "Chuong trinh ket thuc. Hen gap lai." << endl;
	cin.get();
	return;
}


























