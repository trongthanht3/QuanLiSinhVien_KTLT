//
// Created by Thanh on 4/4/2020.
//

#include "InDanhSach.h"

InDanhSach::InDanhSach()
{
}

void InDanhSach::importData()
{
    SinhVien temp;
    fstream dataInput;
    dataInput.open("data.txt", ios::in | ios::out);
    if (dataInput.peek() == EOF) {
        cout << "empty file\n";
        return;
    }
    while (!dataInput.eof()) {
        temp.importData(dataInput, temp);
        DanhSach.push_back(temp);
    }
}

void InDanhSach::printData()
{
    int n = DanhSach.size();
    for (int i=0; i<n; i++) {
        DanhSach[i].toScreen_SinhVien();
//        cout << endl;
    }
}

void InDanhSach::printListStudent() {
    cout << titleM2 << endl;
    string s;
    for (int i = 0; i < DanhSach.size(); ++i) {
        s = "|" + centerString(DanhSach[i].getMaLop(), 12) + "|"
            + centerString(to_string(DanhSach[i].getMaSV()), 18) +
            "|" + centerString(DanhSach[i].getHoTen(), 24) + "|" +
            centerString(DanhSach[i].toString_NgaySinh(), 14) + "|"
            + centerString(DanhSach[i].getDiemTB(), 10) + "|\n" ;
        printM2.push_back(midLineM2);
        printM2.push_back(s);
        cout << s;
    }
    printM2.push_back(endLineM2);
//    pressEnterInM2(keyMoveSelectPrintListStudents(index, printM2));
}

string InDanhSach::centerString(string s, int space) {
    int length = s.length();
    int size = (space - length) / 2;
//    cout << "s: " << size;
//    stringstream stringstream1;
    string string1;

    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    string1 += s;
    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    return string1;
}

string InDanhSach::centerString(int s, int space) {
    int length = 0;
    while (s > 0) {
        s /= 10;
    }
    stringstream ss;
    ss << s;
    int size = (space - length) / 2;
    string string1;
    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    ss >> string1;
    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    return string1;
}

