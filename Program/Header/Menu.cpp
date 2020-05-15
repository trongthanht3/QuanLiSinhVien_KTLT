#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

//const string use so much


void Menu::HienThi()
{
	cout << "\n****************************************************" << endl
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
            SinhVien sinhVienTemp;            //khoi tao object temp
            sinhVienTemp.ThemHoSo();
            sinhVienTemp.exportData();
//            cin.get();
            break;
        }
        case 2: {
            InDanhSach DanhSach;
            DanhSach.ask();
//            cin.get();
            break;
        }
		case 3: {
		    cout << "\nSap xep: ";
            SapXep menuSapXep;
            menuSapXep.ChonKhoa();
            break;
        }
		case 4: {
            cout << "\nTim kiem: " << endl;
            TimKiem menuTimKiem;
            menuTimKiem.ChonKhoa();
            break;
        }
		case 5:
			cout << "\nThong ke: " << endl;
			thongKe();
			break;
		case 6:
			thoat();
			break;
		default:
			cout << ConstString::nhapsai;
			break;
	}
}

void Menu::thongKe()
{
	int choice;
	cout << "\nLoai thong ke: 					   " << endl
		 << "1. Bao cao so luong sinh vien theo lop" << endl
		 << "2. Ti le phan loai KQHT			   " << endl;
	
	do {
		cin >> choice;
		switch (choice) {
			case 1:
			case 2:
				cout << ConstString::baotri << endl;
			default:
				cout << ConstString::nhapsai;
		}
	} while (choice < 1 || choice > 2);
}

void Menu::thoat()
{
	cout << "Chuong trinh ket thuc. Hen gap lai." << endl;
	cin.get();
	return;
}


























