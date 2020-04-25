//
// Created by Thanh on 4/14/2020.
//

#include "SapXep.h"

SapXep::SapXep()
{
    InDanhSach temp;
    temp.importData();
    DanhSach = temp.getData();
}

SapXep::SapXep(vector<SinhVien> DanhSach)
{

}

void SapXep::ChonKhoa()
{
    int keyType;
    bool check = false;

    cout << "\nChon loai khoa: " << endl
         << "1. Ma sinh vien"	 << endl
         << "2. Ho ten"			 << endl
         << "3. Ngay sinh"		 << endl
         << "4. Diem trung binh" << endl;
    cout << "Chon: ";
    do {
        cin >> keyType;

        switch (keyType) {
            case 1: {
                chonThuatToan();
                check = true;
                break;
            }
            case 2: {
                check = true;
                break;
            }
            case 3:
                break;
            case 4:
                check = true;
//                return keyType;
                break;
            default:
                cout << ConstString::nhapsai;
                break;
        }
    } while (!check);
//    return 0;
}

void SapXep::chonThuatToan()
{
    int algoType;
    bool check = false;
    cout << "\nChon thuat toan sap xep: " << endl
         << "1. Selection sort" 		  << endl
         << "2. Insert sort"			  << endl
         << "3. Quick sort"				  << endl
         << "4. Merge sort"				  << endl
         << "Chon: ";
    do {
        cin >> algoType;
        switch (algoType) {
            case 1: {
                cout << "Selection sort dang chay!" << endl;
                selectionSortMaSV();
                check = true;
                break;
            }
            case 2: {
                cout << "Insert sort dang chay!" << endl;
                insertionSortMaSV();
                check = true;
                break;
            }
            case 3:
                cout << "Quick sort dang chay!" << endl;

                break;
            case 4:
                cout << "Merge sort dang chay!" << endl;
                mergeSortMaSV(DanhSach, 0, DanhSach.size()-1);
                check = true;
                break;
            default:
                cout << ConstString::nhapsai;
                break;
        }
    } while (!check);
}

void SapXep::exportSortedData()
{
    remove("data.txt");
    for (int i=0; i<DanhSach.size(); i++) {
        DanhSach[i].exportData();
    }
}

void SapXep::selectionSortMaSV()
{
    for (int i=0; i<DanhSach.size()-1; i++) {
        int min = DanhSach[i].getMaSV();
        for (int j=i+1; j<DanhSach.size(); j++) {
            if (DanhSach[j].getMaSV() < min) {
                SinhVien tempS = DanhSach[i];
                DanhSach[i] = DanhSach[j];
                DanhSach[j] = tempS;
            }
        }
    }
    exportSortedData();
}

void SapXep::insertionSortMaSV()
{
    for (int i=1; i<DanhSach.size(); i++) {
        int temp = DanhSach[i].getMaSV();
        SinhVien tempS = DanhSach[i];
        int j = i - 1;
        while (j>=0 && temp<DanhSach[j].getMaSV()) {
            DanhSach[j+1] = DanhSach[j];
            j--;
        }
        DanhSach[j+1] = tempS;
    }
    exportSortedData();
}

void SapXep::mergeMaSV(vector<SinhVien> &_DanhSach, int left, int right)
{
    if (left < right) {
        int middle = (right + left) / 2;

        mergeSortMaSV(_DanhSach, left, middle);
        mergeSortMaSV(_DanhSach, middle+1, right);

        mergeMaSV(_DanhSach, left, middle);
    }
}

void SapXep::mergeSortMaSV(vector<SinhVien> &_DanhSach, int left, int right)
{
    int i, j, k;
    int middle = (right + left) / 2;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<SinhVien> leftTemp;
    vector<SinhVien> rightTemp;
    for (int i=0; i<leftSize; i++) {
        leftTemp.push_back(_DanhSach[left+i]);
    }
    for (int j=0; j<rightSize; j++) {
        rightTemp.push_back(_DanhSach[middle+1+j]);
    }

    i = 0;
    j = 0;
    k = left;

    while (i<leftSize && j<rightSize) {
        if (leftTemp[i].getMaSV() <= rightTemp[j].getMaSV()) {
            _DanhSach[k] = leftTemp[i];
            i++;
        }
        else {
            _DanhSach[k] = rightTemp[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        _DanhSach[k] = leftTemp[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        _DanhSach[k] = rightTemp[j];
        j++;
        k++;
    }
}