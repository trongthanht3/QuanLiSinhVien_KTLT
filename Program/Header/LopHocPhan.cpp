//
// Created by Thanh on 6/1/2020.
//

#include "LopHocPhan.h"

LopHocPhan::LopHocPhan()
{
    XuatSac = Gioi = Kha = TrungBinh = Yeu = TongSinhVien = 0;
    MaLop = "";
}

void LopHocPhan::addSinhVien(SinhVien SvMoi)
{
    DanhSach.push_back(SvMoi);
}

const vector<SinhVien> &LopHocPhan::getDanhSach() const {
    return DanhSach;
}

void LopHocPhan::setDanhSach(const vector<SinhVien> &danhSach) {
    DanhSach = danhSach;
}

const string &LopHocPhan::getMaLop() const {
    return MaLop;
}

void LopHocPhan::setMaLop(const string &maLop) {
    MaLop = maLop;
}

int LopHocPhan::getTongSinhVien() {
    TongSinhVien = DanhSach.size();
    return TongSinhVien;
}

void LopHocPhan::setTongSinhVien(int tongSinhVien) {
    TongSinhVien = tongSinhVien;
}

int LopHocPhan::getGioi() const {
    return Gioi;
}
void LopHocPhan::setGioi(int gioi) {
    Gioi = gioi;
}
void LopHocPhan::addGioi() {
    Gioi++;
}

int LopHocPhan::getKha() const {
    return Kha;
}
void LopHocPhan::setKha(int kha) {
    Kha = kha;
}
void LopHocPhan::addKha() {
    Kha++;
}

int LopHocPhan::getTrungBinh() const {
    return TrungBinh;
}
void LopHocPhan::setTrungBinh(int trungBinh) {
    TrungBinh = trungBinh;
}
void LopHocPhan::addTrungBinh() {
    TrungBinh++;
}

int LopHocPhan::getXuatSac() const {
    return XuatSac;
}
void LopHocPhan::setXuatSac(int xuatSac) {
    XuatSac = xuatSac;
}
void LopHocPhan::addXuatSac() {
    XuatSac++;
}

int LopHocPhan::getYeu() const {
    return Yeu;
}
void LopHocPhan::setYeu(int yeu) {
    Yeu = yeu;
}
void LopHocPhan::addYeu() {
    Yeu++;
}
