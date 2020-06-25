#include "SinhVien.h"

using namespace std;

SinhVien::SinhVien()
{
	this->MaLop = "";
	this->MaSV = -1;
	this->HoTen = "";
//	this->NgaySinh.Date(1,1,1);
	this->DiemTB = 0;
}

SinhVien::SinhVien(string MaLop, int MaSV, string HoTen, Date NgaySinh, float DiemTB)
{
	this->MaLop = MaLop;
	this->MaSV = MaSV;
	this->HoTen = HoTen;
	this->NgaySinh = NgaySinh;
	this->DiemTB = DiemTB;
}

//SinhVien::~SinhVien()
//{
//	cout << "\nSinh vien: " << this->MaSV << " da duoc xoa khoi he thong.\n";
//}

void SinhVien::ThemHoSo()
{
    int n;
	cout << "\nNhap ho so sinh vien!" << endl;
	cout << "So sinh vien can nhap (0. Quay lai): ";
    if (n <= 0) {
        do {
            cin.clear();        //clears the error flag on cin (so that future I/O operations will work correctly)
            cin.ignore(numeric_limits<streamsize>::max(),'\n');        //skips to the next newline (to ignore anything else on the same line as the non-number)
            cin >> n;
            if (n == 0) {
                return;
            }
        } while (n <= 0);
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	for (int i=0; i<n; i++) {
	    cout << "Sinh vien " << i+1 << ": \n";
        cin.ignore();
        cout << "Ma lop: ";
        getline(cin, MaLop);
        cout << "Ma sinh vien: ";
        cin >> MaSV;
        //	cout << MaSV;
        if (cin.fail()) {
            cout << "Khong hop le! Nhap lai toi khi dung: ";
            do {
                cin.clear();        //clears the error flag on cin (so that future I/O operations will work correctly)
                cin.ignore();        //skips to the next newline (to ignore anything else on the same line as the non-number)
                cin >> MaSV;
            } while (cin.fail());
        }
        cin.ignore();
        cout << "Ho va ten: ";
        getline(cin, HoTen);
        chuanHoaString();
        cout << "Ngay sinh (ngay/thang/nam): ";
        NgaySinh.userInput();
        cin.ignore();
        cout << "Diem trung binh tich luy: ";
        cin >> DiemTB;
        if (DiemTB <= 0 || DiemTB > 10) {
            cout << "Khong hop le! Nhap lai toi khi dung: ";
            do {
                cin.clear();        //clears the error flag on cin (so that future I/O operations will work correctly)
                cin.ignore();        //skips to the next newline (to ignore anything else on the same line as the non-number)
                cin >> DiemTB;
            } while (DiemTB <= 0 || DiemTB > 10);
        }
//        while (DiemTB < 0 || DiemTB > 10) {
//            cout << ConstString::nhapsai;
//            cin >> DiemTB;
//        }
        exportData();
    }
//	_sleep(1000);
	system("CLS");
}

void SinhVien::setMaLop(string MaLop)
{
	this->MaLop = MaLop;
}
string SinhVien::getMaLop()
{
	return MaLop;
}

void SinhVien::setMaSV(int MaSV)
{
	this->MaSV = MaSV;
}
int SinhVien::getMaSV()
{
	return MaSV;
}

void SinhVien::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}
string SinhVien::getHoTen()
{
	return HoTen;
}
string SinhVien::getLastHoTen()
{
    int i = HoTen.find_last_of(' ');
    return HoTen.substr(i+1);
}

void SinhVien::setNgaySinh(int Ngay, int Thang, int Nam)
{
	NgaySinh.setDate(Thang, Ngay, Nam);
}
void SinhVien::setNgaySinh(Date _NgaySinh)
{
    NgaySinh = _NgaySinh;
}
Date SinhVien::getNgaySinh()
{
	return NgaySinh;
}

string SinhVien::toString_NgaySinh()
{
    return NgaySinh.asString();
}

void SinhVien::setDiemTB(float DiemTB)
{
	this->DiemTB = DiemTB;
}
float SinhVien::getDiemTB()
{
	return DiemTB;
}

string SinhVien::toString_SinhVien()
{
	ostringstream _SinhVien;
	_SinhVien << MaLop << "|" << MaSV  << "|" << HoTen << "|" << NgaySinh.asString() << "|" << DiemTB;

	return _SinhVien.str();
}

void SinhVien::toScreen_SinhVien()
{
    setw(12);
    cout << MaLop << "|";
    setw(12);
    cout << MaSV << "|";
    setw(24);
    cout << HoTen << "|";
    setw(12);
    cout << NgaySinh.asString() << "|";
    setw(6);
    setprecision(2);
    cout << DiemTB;
}

string SinhVien::chuanHoaString()
{
    string ten = this->HoTen;
    int n=ten.length();
    // xoa space thua
        //xoa space o dau string
    while (ten[0] == ' ') {
        for (int j=0; j<n-1; j++) {
            ten[j] = ten[j+1];
        }
    }
        //xoa space o cac khoang giua
    int j=0;
    while (j<n) {
        if ((ten[j]==' ') && (ten[j+1]==' ')) {
            ten.erase(ten.begin()+j);
            ten.erase(ten.end()-1);
        }
        else {
            j++;
        }
    }

    // format lai ten thanh chu hoa
    int i=0;
    if (ten[0] != ' ')
        ten[0] = toupper(ten[0]);
    do {
        if (ten[i] == ' ')
            ten[i+1] = toupper(ten[i+1]);
        i++;
    } while (i<n);
    this->HoTen = ten;
    return ten;
}

void SinhVien::exportData()
{
    fstream out;
    out.open("data.txt", ios::out | ios::app);
//    cout << "open?: " << out.is_open();
    out.seekg(0, ios::end);
    if (out.tellg() == 0) {
        out.clear();
        out << toString_SinhVien();
    }
    else {
        out.clear();
        out << "\n" << toString_SinhVien();
    }
//    cout << toString_SinhVien();
//    out << toString_SinhVien();
    out.close();
}

void SinhVien::importData(fstream &dataInput, SinhVien &temp)
{
    if (dataInput.peek() == '\n') {
        dataInput.clear();
        dataInput.ignore(1);
    }
    dataInput.clear();
    getline(dataInput, MaLop, '|');
    if (MaLop == "\n")
        return;
    string buffer;
    istringstream s(buffer);
    dataInput.clear();
    getline(dataInput, buffer, '|');
//    cout << "b: " << buffer;
    MaSV = stoi(buffer);
    getline(dataInput, HoTen, '|');
    int d, m, y;
    dataInput >> d;
    dataInput.ignore(1);
    dataInput >> m;
    dataInput.ignore(1);
    dataInput >> y;
    dataInput.ignore(1);
    NgaySinh.setDate(m, d, y);
    dataInput >> DiemTB;
//    cout << "Da nhap sinh vien vao ho so." << endl;
//    cout << toString_SinhVien();
}





















