#include <iostream>
#include <string>
#include "Header/SinhVien.h"
#include "Header/Menu.h"
#include "Header/InDanhSach.h"
#include "Header/SapXep.h"
#include "Header/TimKiem.h"
#include <vector>
//https://github.com/trongthanht3/QuanLiSinhVien_KTLT

using namespace std;

int main(int argc, char** argv)
{
//    Menu c;
//    c.HienThi();
    InDanhSach a;
    a.importData();
    TimKiem b(a.getData());
    b.ChonKhoa();
    return 0;
}
