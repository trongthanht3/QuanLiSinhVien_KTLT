//
// Created by Thanh on 5/8/2020.
//

#include "TimKiem.h"

TimKiem::TimKiem()
{
}

TimKiem::TimKiem(vector<SinhVien> _DanhSach)
{
    DanhSach = _DanhSach;
}

void TimKiem::ChonKhoa()
{
    int keyType;
    bool check = false;
    cout << "\nChon loai khoa: " << endl
         << "1. Ma sinh vien"	 << endl
         << "2. Ho ten"			 << endl
         << "3. Ngay sinh"		 << endl
         << "4. Diem trung binh" << endl
         << "5. Ma lop"          << endl;
    cout << "Chon: ";
    do {
        cin >> keyType;
        if (keyType<1 || keyType>5)
            cout << ConstString::nhapsai;
        else
            check = true;
    } while (!check);
    chonThuatToan(keyType);
//    return 0;
}

void TimKiem::chonThuatToan(int keyType)
{
    int algoType;
    bool check = false;
    cout << "\nChon thuat toan sap xep: " << endl
         << "1. Tim kiem tuan tu (sequence search)" << endl
         << "2. Tim kiem nhi phan (binary search)"  << endl
         << "Chon: ";
    do {
        cin >> algoType;
        switch (algoType) {
            case 1: {
                sequenceSearch(DanhSach, keyType);
                check = true;
                break;
            }
            case 2: {
                InDanhSach sort(DanhSach);
                sort.askSearch(DanhSach, keyType);
                binarySearch(DanhSach, keyType, 0, DanhSach.size()-1, false);
                check = true;
                break;
            }
            default:
                cout << ConstString::nhapsai;
                break;
        }
    } while (!check);
    inKetQua();
}

void TimKiem::nhapTuKhoa(int keyType)
{
    cout << "Nhap tu khoa: ";
    switch (keyType) {
        case 1: {
            int kwMaSV;
            cin >> kwMaSV;
            temp.setMaSV(kwMaSV);
            break;
        }
        case 2: {
            string kwHoTen;
            cin.ignore();
            getline(cin, kwHoTen);
            temp.setHoTen(kwHoTen);
            break;
        }
        case 3: {
            Date kwDate;
            kwDate.userInput();
            temp.setNgaySinh(kwDate);
            break;
        }
        case 4: {
            float kwDiemTB;
            cin >> kwDiemTB;
            temp.setDiemTB(kwDiemTB);
            break;
        }
        case 5: {
            string kwMaLop;
            cin.ignore();
            getline(cin, kwMaLop);
            temp.setMaLop(kwMaLop);
            break;
        }
        default: {
            cout << "ERROR, PLEASE REPORT TO DEVELOPER!";
            break;
        }
    }
}

void TimKiem::inKetQua()
{
    if (found.empty()) {
        cout << "Khong co sinh vien nay trong danh sach." << endl;
        return;
    }
    foundSinhVien.setData(found);
    foundSinhVien.printListStudent();
}

bool TimKiem::sequenceSearch(vector<SinhVien> _DanhSach, int keyType)
{
    nhapTuKhoa(keyType);
    for (int i=0; i<_DanhSach.size(); i++) {
        switch (keyType) {
            case 1: {
                if (temp.getMaSV() == _DanhSach[i].getMaSV()) {
                    found.push_back(_DanhSach[i]);
                }
                break;
            }
            case 2: {
                if (_DanhSach[i].getHoTen().find(temp.getHoTen()) != string::npos) {
                    found.push_back(_DanhSach[i]);
                }
                break;
            }
            case 3: {
                if (temp.getNgaySinh().isEqual(_DanhSach[i].getNgaySinh())) {
                    found.push_back(_DanhSach[i]);
                }
                break;
            }
            case 4:{
                if (temp.getDiemTB() == _DanhSach[i].getDiemTB()) {
                    found.push_back(_DanhSach[i]);
                }
                break;
            }
            case 5: {
                if (temp.getMaLop() == _DanhSach[i].getMaLop()) {
                    found.push_back(_DanhSach[i]);
                }
                break;
            }
            default: {
                cout << "ERROR, PLEASE REPORT TO DEVELOPER!";
                break;
            }
        }
    }
    if (found.empty()) {
        return false;
    }
    return true;
}

bool TimKiem::binarySearch(vector<SinhVien> _DanhSach, int keyType, int l, int r, bool checkRun) {
    // co the thuc hien tim kiem nhieu phan tu bang binarySearch
    // nhung se tang thoi gian chay > Olog(n)
    // dan den kem hieu qua khi su dung thuat toan nay

    if (!checkRun)
        nhapTuKhoa(keyType);
    checkRun = true;

    while (l <= r) {
        int m = (l+r)/2;
        switch (keyType) {
            case 1: {
                if (temp.getMaSV() == _DanhSach[m].getMaSV()) {
                    found.push_back(_DanhSach[m]);
                    return true;
                } else if (temp.getMaSV() < _DanhSach[m].getMaSV()) {
                    return binarySearch(_DanhSach, keyType, l, m-1, checkRun);
                } else {
                    return binarySearch(_DanhSach, keyType, m + 1, r, checkRun);
                }
                break;
            }
            case 2: {
                if (_DanhSach[m].getHoTen().find(temp.getHoTen()) != string::npos) {
                    found.push_back(_DanhSach[m]);
                    return true;
                } else if (temp.getHoTen() < _DanhSach[m].getHoTen()) {
                    return binarySearch(_DanhSach, keyType, l, m-1, checkRun);
                } else {
                    return binarySearch(_DanhSach, keyType, m + 1, r, checkRun);
                }
                break;
            }
            case 3: {
                if (temp.getNgaySinh().isEqual(_DanhSach[m].getNgaySinh())) {
                    found.push_back(_DanhSach[m]);
                    return true;
                } else if (temp.getNgaySinh().isLess(_DanhSach[m].getNgaySinh()))  {
                    return binarySearch(_DanhSach, keyType, l, m-1, checkRun);
                } else {
                    return binarySearch(_DanhSach, keyType, m + 1, r, checkRun);
                }
                break;
            }
            case 4: {
                if (temp.getDiemTB() == _DanhSach[m].getDiemTB()) {
                    found.push_back(_DanhSach[m]);
                    return true;
                } else if (temp.getDiemTB() < _DanhSach[m].getDiemTB()) {
                    return binarySearch(_DanhSach, keyType, l, m-1, checkRun);
                } else {
                    return binarySearch(_DanhSach, keyType, m + 1, r, checkRun);
                }
                break;
            }
            case 5: {
                if (temp.getMaLop() == _DanhSach[m].getMaLop()) {
                    found.push_back(_DanhSach[m]);
                    return true;
                } else if (temp.getMaLop() < _DanhSach[m].getMaLop()) {
                    return binarySearch(_DanhSach, keyType, l, m-1, checkRun);
                } else {
                    return binarySearch(_DanhSach, keyType, m + 1, r, checkRun);
                }
                break;
            }
            default: {
                cout << "ERROR, PLEASE REPORT TO DEVELOPER!";
                break;
            }
        }
    }
    if (found.empty()) {
        return false;
    }
    return true;
}












