//
// Created by Thanh on 5/26/2020.
//

#ifndef QUANLISINHVIEN_THONGKE_H
#define QUANLISINHVIEN_THONGKE_H
#include <iostream>
#include <vector>
#include <string>
#include "InDanhSach.h"
#include "LopHocPhan.h"

using namespace std;

class ThongKe {
    private:
        vector<SinhVien> DanhSach;
        vector<LopHocPhan> Lop;
    public:
        void test();
        string printClass =   "\n _________________________________\n"
                              "|            |                    |\n"
                              "|   Ma lop   |    So sinh vien    |\n"
                              "|____________|____________________|\n";
        string printPoint =   "\n __________________________________________________________________________________________________________________\n"
                              "|              |                   |                   |                   |                   |                   |\n"
                              "|              |      Xuat sac     |        Gioi       |        Kha        |    Trung binh     |        Yeu        |\n"
                              "|              |___________________|___________________|___________________|___________________|___________________|\n"
                              "|    Ma lop    |         |         |         |         |         |         |         |         |         |         |\n"
                              "|              |    SL   |    %    |    SL   |    %    |    SL   |    %    |    SL   |    %    |    SL   |    %    |\n"
                              "|______________|_________|_________|_________|_________|_________|_________|_________|_________|_________|_________|\n";


        string midLinePrintClass =  "|            |                    |\n",
               endLinePrintClass =  "|____________|____________________|\n",
               midLinePrintPoint =  "|              |         |         |         |         |         |         |         |         |         |         |\n",
               endLinePrintPoint =  "|______________|_________|_________|_________|_________|_________|_________|_________|_________|_________|_________|\n";

        bool Menu();
        vector<LopHocPhan> PhanTichSoLuong(vector<SinhVien> _DanhSach);
        vector<LopHocPhan> PhanTichChiTiet(vector<LopHocPhan> &_Lop);
        void printByClass(vector<LopHocPhan> _Lop, int totalSinhVien);
        void printByPercent(vector<LopHocPhan> _Lop, int totalSinhVien);

        int getTongXuatSac(vector<LopHocPhan> _Lop);
        int getTongGioi(vector<LopHocPhan> _Lop);
        int getTongKha(vector<LopHocPhan> _Lop);
        int getTongTrungBinh(vector<LopHocPhan> _Lop);
        int getTongYeu(vector<LopHocPhan> _Lop);
};


#endif //QUANLISINHVIEN_THONGKE_H
