//
// Created by Thanh on 4/14/2020.
//

#ifndef QUANLISINHVIEN_SAPXEP_H
#define QUANLISINHVIEN_SAPXEP_H

#include <iostream>
#include <string>
#include <vector>
#include "ConstString.h"
#include "InDanhSach.h"
#include "SinhVien.h"

using namespace std;

class SapXep {
    private:;
        vector<SinhVien> DanhSach;
    public:
        SapXep();
        SapXep(vector<SinhVien> &_DanhSach);
        void ChonKhoa();
        void chonThuatToan(int keyType);
        void exportSortedData();
        void selectionSort(vector<SinhVien> &_DanhSach, int keyType);
        void insertionSort(vector<SinhVien> &_DanhSach, int keyType);
        int quickSortPartition(vector<SinhVien> &_DanhSach, int left, int right, int keyType);
        void quickSort(vector<SinhVien> &_DanhSach, int left, int right, int keyType);
        void merge(vector<SinhVien> &_DanhSach, int left, int right, int keyType);
        void mergeSort(vector<SinhVien> &_DanhSach, int left, int right, int keyType);
};


#endif //QUANLISINHVIEN_SAPXEP_H
