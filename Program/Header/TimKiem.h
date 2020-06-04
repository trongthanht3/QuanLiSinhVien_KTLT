//
// Created by Thanh on 5/8/2020.
//

#ifndef QUANLISINHVIEN_TIMKIEM_H
#define QUANLISINHVIEN_TIMKIEM_H

#include <iostream>
#include "InDanhSach.h"
#include "Tools.h"

class TimKiem {
    private:
        vector<SinhVien> DanhSach;
        SinhVien temp;
        InDanhSach foundSinhVien;
        vector<SinhVien> found;
    public:
        TimKiem();
        TimKiem(vector<SinhVien> _DanhSach);
        bool ChonKhoa();
        bool chonThuatToan(int keyType);
        void nhapTuKhoa(int keyType);
        void inKetQua();
        bool sequenceSearch(vector<SinhVien> _DanhSach, int keyType);
        bool binarySearch(vector<SinhVien> _DanhSach, int keyType, int l, int r, bool checkRun);

};


#endif //QUANLISINHVIEN_TIMKIEM_H
