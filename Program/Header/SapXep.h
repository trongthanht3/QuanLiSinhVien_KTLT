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
    private:
        vector<SinhVien> DanhSach;
    public:
        SapXep(vector<SinhVien> DanhSach);
        void ChonKhoa();
        void chonThuatToan();
        void exportSortedData();
        SapXep();
        void selectionSortMaSV();
        void insertionSortMaSV();
        void mergeMaSV(vector<SinhVien> &_DanhSach, int left, int right);
        void mergeSortMaSV(vector<SinhVien> &_DanhSach, int left, int right);
};


#endif //QUANLISINHVIEN_SAPXEP_H
