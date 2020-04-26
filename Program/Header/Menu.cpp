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
            SapXep menuSapXep;
            menuSapXep.ChonKhoa();
            break;
        }
		case 4:
			cout << "\nTim kiem: " << endl;
			timKiem();
			break;
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

int Menu::chonKhoa()
{
	int keyType;
	bool check = false;
	
	cout << "\nChon loai khoa: " << endl
		 << "1. Ma sinh vien"	 << endl
		 << "2. Ho ten"			 << endl
		 << "3. Ngay sinh"		 << endl
		 << "4. Diem trung binh" << endl;
	if (choiceMenu == 4)
		cout << "5. Ma lop" << endl;
	
	cout << "Chon: ";
	do {
		cin >> keyType;
		
		switch (keyType) {
			case 1:
			case 2:
			case 3:
			case 4:
				check = true;
				return keyType;
				break;
			case 5:
				if (choiceMenu == 4)
					return keyType;
//				else
//					cout << nhapsai;
//				break;
			default:
				cout << ConstString::nhapsai;
				break;
		}
	} while (!check);
	return 0;
}

void Menu::timKiem()
{
	int keyType = chonKhoa();
	cout << "\nDa chon loai: " << keyType << endl;
	int algoType = algoTimKiem();
	//dat thuat toan o day
	cout << ConstString::baotri << endl;
}
int Menu::algoTimKiem()
{
	int algoType;
	cout << "\nChon thuat toan sap xep: " << endl
		 << "1. Selection sort" 		  << endl
		 << "2. Insert sort"			  << endl
		 << "Chon: ";
	
	do {
		cin >> algoType;
		switch (algoType) {
			case 1:
				cout << "Sequence search!" << endl;
				return algoType;
				break;
			case2:
				cout << "Insert sort dang chay!" << endl;
				return algoType;
				break;
			default:
				cout << ConstString::nhapsai;
				break;
		}
	} while (algoType < 1 || algoType > 2);
	return 0;
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


























