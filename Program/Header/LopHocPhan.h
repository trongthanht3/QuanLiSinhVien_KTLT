//
// Created by Thanh on 6/1/2020.
//

#ifndef QUANLISINHVIEN_LOPHOCPHAN_H
#define QUANLISINHVIEN_LOPHOCPHAN_H

#include <iostream>
#include <string>
#include <vector>
#include "SinhVien.h"

using namespace std;

class LopHocPhan {
    private:
        vector<SinhVien> DanhSach;
        string MaLop;
        int TongSinhVien;
        int XuatSac;
        int Gioi;
        int Kha;
        int TrungBinh;
        int Yeu;
    public:
        LopHocPhan();
        void addSinhVien(SinhVien SvMoi);

        const vector<SinhVien> &getDanhSach() const;
        void setDanhSach(const vector<SinhVien> &danhSach);

        const string &getMaLop() const;
        void setMaLop(const string &maLop);

        int getTongSinhVien();
        void setTongSinhVien(int tongSinhVien);

        int getGioi() const;
        void setGioi(int gioi);
        void addGioi();

        int getKha() const;
        void setKha(int kha);
        void addKha();

        int getTrungBinh() const;
        void setTrungBinh(int trungBinh);
        void addTrungBinh();

        int getXuatSac() const;
        void setXuatSac(int xuatSac);
        void addXuatSac();

        int getYeu() const;
        void setYeu(int yeu);
        void addYeu();

};


#endif //QUANLISINHVIEN_LOPHOCPHAN_H
