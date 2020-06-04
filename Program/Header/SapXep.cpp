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

SapXep::SapXep(vector<SinhVien> &_DanhSach)
{
    DanhSach = _DanhSach;
}

bool SapXep::ChonKhoa()
{
    system("CLS");
    int keyType;
    bool check = false;
    cout << "\nChon loai khoa: " << endl
         << "       1. Ma sinh vien"	 << endl
         << "       2. Ho ten"			 << endl
         << "       3. Ngay sinh"		 << endl
         << "       4. Diem trung binh"  << endl
         << "       5. Quay lai"         << endl;
    cout << "Chon: ";
    do {
        cin >> keyType;
        if (keyType<1 || keyType>5)
            cout << ConstString::nhapsai;
        else {
            if (keyType == 5)
                return true;
            check = true;
        }
    } while (!check);
    while (!chonThuatToan(keyType)) {};
    return false;
}

bool SapXep::chonThuatToan(int keyType)
{
    system("CLS");
    int algoType;
    bool check = false;
    cout << "\nChon thuat toan sap xep: " << endl
         << "       1. Selection sort" 		  << endl
         << "       2. Insert sort"			  << endl
         << "       3. Quick sort"				  << endl
         << "       4. Merge sort"				  << endl
         << "       5. Quay lai "                 << endl
         << "Chon: ";
    do {
        cin >> algoType;
        switch (algoType) {
            case 1: {
                cout << "Selection sort dang chay!" << endl;
                selectionSort(DanhSach, keyType);
                check = true;
                break;
            }
            case 2: {
                cout << "Insert sort dang chay!" << endl;
                insertionSort(DanhSach, keyType);
                check = true;
                break;
            }
            case 3: {
                cout << "Quick sort dang chay!" << endl;
                quickSort(DanhSach, 0, DanhSach.size() - 1, keyType);
                check = true;
                break;
            }
            case 4: {
                cout << "Merge sort dang chay!" << endl;
                mergeSort(DanhSach, 0, DanhSach.size() - 1, keyType);
                check = true;
                break;
            }
            case 5: {
                return true;
            }
            default:
                cout << ConstString::nhapsai;
                break;
        }
        system("PAUSE");
    } while (!check);

    return false;
}

void SapXep::exportSortedData()
{
    remove("data.txt");
    for (int i=0; i<DanhSach.size(); i++) {
        DanhSach[i].exportData();
    }
}

void SapXep::selectionSort(vector<SinhVien> &_DanhSach, int keyType)
{
    for (int i=0; i<_DanhSach.size()-1; i++) {
        int min = i;
//        cout << _DanhSach[i].getLastHoTen();
        for (int j = i + 1; j < _DanhSach.size(); j++) {
            switch (keyType) {
                case 1: {
                    if (_DanhSach[j].getMaSV() < _DanhSach[min].getMaSV())
                        swap(_DanhSach[i], _DanhSach[j]);
                    break;
                }
                case 2: {
                    if (_DanhSach[j].getLastHoTen() < _DanhSach[min].getLastHoTen())
                        swap(_DanhSach[i], _DanhSach[j]);
                    break;
                }
                case 3: {
                    if (_DanhSach[j].getNgaySinh().isLess(_DanhSach[min].getNgaySinh()))
                        swap(_DanhSach[i], _DanhSach[j]);
                    break;
                }
                case 4: {
                    if (_DanhSach[j].getDiemTB() < _DanhSach[min].getDiemTB())
                        swap(_DanhSach[i], _DanhSach[j]);
                    break;
                }
                case 5: {
                    if (_DanhSach[j].getMaLop() < _DanhSach[min].getMaLop())
                        swap(_DanhSach[i], _DanhSach[j]);
                    break;
                }
                default:
                    break;
            }
        }
    }
    exportSortedData();
}

void SapXep::insertionSort(vector<SinhVien> &_DanhSach, int keyType)
{
    for (int i=1; i<_DanhSach.size(); i++) {
        SinhVien tempS = _DanhSach[i];
        int j = i - 1;
        switch (keyType) {
            case 1: {
                while (j >= 0 && tempS.getMaSV() < _DanhSach[j].getMaSV()) {
                    _DanhSach[j + 1] = _DanhSach[j];
                    j--;
                }
                break;
            }
            case 2: {
                while (j >= 0 && tempS.getLastHoTen() < _DanhSach[j].getLastHoTen()) {
                    _DanhSach[j + 1] = _DanhSach[j];
                    j--;
                }
                break;
            }
            case 3: {
                while (j >= 0 && tempS.getNgaySinh().isLess(_DanhSach[j].getNgaySinh())) {
                    _DanhSach[j + 1] = _DanhSach[j];
                    j--;
                }
                break;
            }
            case 4: {
                while (j >= 0 && tempS.getDiemTB() < _DanhSach[j].getDiemTB()) {
                    _DanhSach[j + 1] = _DanhSach[j];
                    j--;
                }
                break;
            }
            case 5: {
                while (j >= 0 && tempS.getMaLop() < _DanhSach[j].getMaLop()) {
                    _DanhSach[j + 1] = _DanhSach[j];
                    j--;
                }
                break;
            }
            default:
                break;
        }
        _DanhSach[j+1] = tempS;
    }
    exportSortedData();
}

int SapXep::quickSortPartition(vector<SinhVien> &_DanhSach, int left, int right, int keyType)
{
    int pivot = right;      //pick pivot as most right element
    int i = left - 1;       //run index to find where to put pivot

    for (int j=left; j<right; j++) {         //not run to [right]
        switch (keyType) {
            case 1: {
                if (_DanhSach[j].getMaSV() < _DanhSach[pivot].getMaSV()) {
                    i++;
                    swap(_DanhSach[j], _DanhSach[i]);
                }
                break;
            }
            case 2: {
                if (_DanhSach[j].getLastHoTen() < _DanhSach[pivot].getLastHoTen()) {
                    i++;
                    swap(_DanhSach[j], _DanhSach[i]);
                }
                break;
            }
            case 3: {
                if (_DanhSach[j].getNgaySinh().isLess(_DanhSach[pivot].getNgaySinh())) {
                    i++;
                    swap(_DanhSach[j], _DanhSach[i]);
                }
                break;
            }
            case 4: {
                if (_DanhSach[j].getDiemTB() < _DanhSach[pivot].getDiemTB()) {
                    i++;
                    swap(_DanhSach[j], _DanhSach[i]);
                }
                break;
            }
            case 5: {
                if (_DanhSach[j].getMaLop() < _DanhSach[pivot].getMaLop()) {
                    i++;
                    swap(_DanhSach[j], _DanhSach[i]);
                }
                break;
            }
            default:
                break;
        }
    }
    swap(_DanhSach[pivot], _DanhSach[i+1]);
    return i+1;             //return pivot point to divine array
}
void SapXep::quickSort(vector<SinhVien> &_DanhSach, int left, int right, int keyType)
{
    if (left < right) {         //exit condition
        int pivot = quickSortPartition(_DanhSach, left, right, keyType);     //get pivot after partition array
        //'cuz pivot point is sorted, so we dont run to it
        quickSort(_DanhSach, left, pivot-1, keyType);        //left array before pivot
        quickSort(_DanhSach, pivot+1, right, keyType);        //right array after pivot
    }
    exportSortedData();
}

void SapXep::mergeSort(vector<SinhVien> &_DanhSach, int left, int right, int keyType)
{
    if (left < right) {
        int middle = (right+left) / 2;

        mergeSort(_DanhSach, left, middle, keyType);
        mergeSort(_DanhSach, middle+1, right, keyType);

        merge(_DanhSach, left, right, keyType);
    }
    exportSortedData();
}

void SapXep::merge(vector<SinhVien> &_DanhSach, int left, int right, int keyType)
{
    int i, j, k;
    int middle = (right+left) / 2;
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
        switch (keyType) {
            case 1: {
                if (leftTemp[i].getMaSV() <= rightTemp[j].getMaSV()) {
                    _DanhSach[k] = leftTemp[i];
                    i++;
                }
                else {
                    _DanhSach[k] = rightTemp[j];
                    j++;
                }
                break;
            }
            case 2: {
                if (leftTemp[i].getLastHoTen() <= rightTemp[j].getLastHoTen()) {
                    _DanhSach[k] = leftTemp[i];
                    i++;
                }
                else {
                    _DanhSach[k] = rightTemp[j];
                    j++;
                }
                break;
            }
            case 3: {
                if (leftTemp[i].getNgaySinh().isLess(rightTemp[j].getNgaySinh())) {
                    _DanhSach[k] = leftTemp[i];
                    i++;
                }
                else {
                    _DanhSach[k] = rightTemp[j];
                    j++;
                }
                break;
            }
            case 4: {
                if (leftTemp[i].getDiemTB() <= rightTemp[j].getDiemTB()) {
                    _DanhSach[k] = leftTemp[i];
                    i++;
                }
                else {
                    _DanhSach[k] = rightTemp[j];
                    j++;
                }
                break;
            }
            case 5: {
                if (leftTemp[i].getMaLop() <= rightTemp[j].getMaLop()) {
                    _DanhSach[k] = leftTemp[i];
                    i++;
                }
                else {
                    _DanhSach[k] = rightTemp[j];
                    j++;
                }
                break;
            }
            default:
                break;
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
//

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
