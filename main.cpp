#include <iostream>
#include "SinhVien.h"

using namespace std;

int main(int argc, char** argv) {
	SinhVien Thanh;
	Thanh.ThemHoSo();
	cout << Thanh.toString_SinhVien();
	return 0;
}
