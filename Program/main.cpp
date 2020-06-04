#include <iostream>
#include <string>
#include <Windows.h>
#include "Header/Tools.h"
#include "Header/Menu.h"
// https://github.com/trongthanht3/QuanLiSinhVien_KTLT

using namespace std;

int main(int argc, char** argv)
{

    Menu mainMenu;
    while (!mainMenu.HienThi()) {
    }

    system("PAUSE");
}

