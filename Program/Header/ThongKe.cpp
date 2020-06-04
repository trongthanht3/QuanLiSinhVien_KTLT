//
// Created by Thanh on 5/26/2020.
//

#include "ThongKe.h"

void ThongKe::test()
{
    cout << printClass;
    cout << endLinePrintClass;
    cout << printPoint;
    cout << endLinePrintPoint;
}

bool ThongKe::Menu()
{
    system("CLS");
    //get data from InDanhSach
    InDanhSach input;
    input.importData();
    DanhSach = input.getData();

    int choice;
    cout << "\nThong ke sinh vien:" << endl;
    cout << "       1. Thong ke so luong theo lop"  << endl
         << "       2. Thong ke theo ti le hoc luc" << endl
         << "       3. Quay lai"                    << endl
         << "Chon: ";
    do {
        cin >> choice;
    } while (choice<1 || choice>3);

    Lop = PhanTichSoLuong(DanhSach);
    switch (choice) {
        case 1: {
            printByClass(Lop, DanhSach.size());
            break;
        }
        case 2: {
            PhanTichChiTiet(Lop);
            printByPercent(Lop, DanhSach.size());
            break;
        }
        case 3: {
            return true;
        }
        default:
            cout << "Error, please report to developer";
    }
    return false;
}

vector<LopHocPhan> ThongKe::PhanTichSoLuong(vector<SinhVien> _DanhSach) {
    // su dung 1 class LopHocPhan de luu cac thuoc tinh va thanh vien cua lop do
    // mot vector<LopHocPhan> se luu cac lop nhan duoc
    vector<LopHocPhan> _Lop;
    for (int i=0; i<_DanhSach.size(); i++) {
        if (_Lop.empty()) {
            LopHocPhan firstLop;
            firstLop.addSinhVien(_DanhSach[i]);
            firstLop.setMaLop(_DanhSach[i].getMaLop());         //set MaLop = Malop cua hoc sinh dau tien tim dc
            _Lop.push_back(firstLop);
        }
        else {
            int check = 0;
            for (int j=0; j<_Lop.size(); j++) {
                if (_DanhSach[i].getMaLop() == _Lop[j].getMaLop()) {    //tim trong mang de tim lop cua sv do
                    _Lop[j].addSinhVien(_DanhSach[i]);                  //neu co thi them vao, neu khong tao lop moi
                    check = 1;
                }
            }
            if (check == 0) {
                LopHocPhan nextLop;
                nextLop.addSinhVien(_DanhSach[i]);
                nextLop.setMaLop(_DanhSach[i].getMaLop());
                _Lop.push_back(nextLop);
            }
        }
    }
    return _Lop;
}

vector<LopHocPhan> ThongKe::PhanTichChiTiet(vector<LopHocPhan> &_Lop)
{
    // trong cac LopHocPhan deu co thuoc tinh ve hoc luc
    // xet tuan tu va tang dan cac chi so trong do
    for (int i=0; i<_Lop.size(); i++) {
        vector<SinhVien> tempDS = _Lop[i].getDanhSach();
        for (int j=0; j<tempDS.size(); j++) {
            if (tempDS[j].getDiemTB() >= 9)
                _Lop[i].addXuatSac();
            else if (tempDS[j].getDiemTB() > 8)
                _Lop[i].addGioi();
            else if (tempDS[j].getDiemTB() > 7)
                _Lop[i].addKha();
            else if (tempDS[j].getDiemTB() > 6)
                _Lop[i].addTrungBinh();
            else
                _Lop[i].addYeu();
        }
    }
    return _Lop;
}

void ThongKe::printByClass(vector<LopHocPhan> _Lop, int totalSinhVien)
{
    cout << printClass;
    for (int i=0; i<_Lop.size(); i++) {
        cout << "|" << InDanhSach::centerString(_Lop[i].getMaLop(), 12)
             << "|" << InDanhSach::centerStringint(_Lop[i].getTongSinhVien(), 20) << "|" << endl;
    }
    cout << endLinePrintClass;
    cout << midLinePrintClass;
    cout << "|    Tong    |" + InDanhSach::centerStringint(totalSinhVien, 20) + "|\n";
    cout << endLinePrintClass;
    system("PAUSE");
}

void ThongKe::printByPercent(vector<LopHocPhan> _Lop, int totalSinhVien)
{
    cout << printPoint;
    for (int i=0; i<_Lop.size(); i++) {
        cout << "|" << InDanhSach::centerString(_Lop[i].getMaLop(), 14)
             << "|" << InDanhSach::centerStringint(_Lop[i].getXuatSac(), 9)
             << "|" << InDanhSach::centerStringfloat((float)_Lop[i].getXuatSac()/_Lop[i].getTongSinhVien()*100, 9)
             << "|" << InDanhSach::centerStringint(_Lop[i].getGioi(), 9)
             << "|" << InDanhSach::centerStringfloat((float)_Lop[i].getGioi()/_Lop[i].getTongSinhVien()*100, 9)
             << "|" << InDanhSach::centerStringint(_Lop[i].getKha(), 9)
             << "|" << InDanhSach::centerStringfloat((float)_Lop[i].getKha()/_Lop[i].getTongSinhVien()*100, 9)
             << "|" << InDanhSach::centerStringint(_Lop[i].getTrungBinh(), 9)
             << "|" << InDanhSach::centerStringfloat((float)_Lop[i].getTrungBinh()/_Lop[i].getTongSinhVien()*100, 9)
             << "|" << InDanhSach::centerStringint(_Lop[i].getYeu(), 9)
             << "|" << InDanhSach::centerStringfloat((float)_Lop[i].getYeu()/_Lop[i].getTongSinhVien()*100, 9)
             << "|"
             << endl;
    }
    cout << endLinePrintPoint;
    cout << "|" << InDanhSach::centerString("Tong", 14)
         << "|" << InDanhSach::centerStringint(getTongXuatSac(_Lop), 9)
         << "|" << InDanhSach::centerStringfloat((float)getTongXuatSac(_Lop)/totalSinhVien*100, 9)
         << "|" << InDanhSach::centerStringint(getTongGioi(_Lop), 9)
         << "|" << InDanhSach::centerStringfloat((float)getTongGioi(_Lop)/totalSinhVien*100, 9)
         << "|" << InDanhSach::centerStringint(getTongKha(_Lop), 9)
         << "|" << InDanhSach::centerStringfloat((float)getTongKha(_Lop)/totalSinhVien*100, 9)
         << "|" << InDanhSach::centerStringint(getTongTrungBinh(_Lop), 9)
         << "|" << InDanhSach::centerStringfloat((float)getTongTrungBinh(_Lop)/totalSinhVien*100, 9)
         << "|" << InDanhSach::centerStringint(getTongYeu(_Lop), 9)
         << "|" << InDanhSach::centerStringfloat((float)getTongYeu(_Lop)/totalSinhVien*100, 9)
         << "|"
         << endl;
    cout << endLinePrintPoint;
    system("PAUSE");
}

int ThongKe::getTongXuatSac(vector<LopHocPhan> _Lop) {
    int Tong = 0;
    for (int i=0; i<_Lop.size(); i++) {
        Tong += _Lop[i].getXuatSac();
    }
    return Tong;
}

int ThongKe::getTongGioi(vector<LopHocPhan> _Lop) {
    int Tong = 0;
    for (int i=0; i<_Lop.size(); i++) {
        Tong += _Lop[i].getGioi();
    }
    return Tong;
}

int ThongKe::getTongKha(vector<LopHocPhan> _Lop) {
    int Tong = 0;
    for (int i=0; i<_Lop.size(); i++) {
        Tong += _Lop[i].getKha();
    }
    return Tong;
}

int ThongKe::getTongTrungBinh(vector<LopHocPhan> _Lop) {
    int Tong = 0;
    for (int i=0; i<_Lop.size(); i++) {
        Tong += _Lop[i].getTrungBinh();
    }
    return Tong;
}

int ThongKe::getTongYeu(vector<LopHocPhan> _Lop) {
    int Tong = 0;
    for (int i=0; i<_Lop.size(); i++) {
        Tong += _Lop[i].getYeu();
    }
    return Tong;
}