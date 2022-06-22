#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//NguyenThiMyTran-20520322-BTTH4.3

struct Date {
	int ngay;
	int thang;
	int nam;
};

class Nguoi {
protected:
	char HoTen[30];
	int Tuoi;
	Date NgaySinh;
public:
	Nguoi();
	~Nguoi();
	virtual void Nhap();
	virtual void Xuat();
};

Nguoi::Nguoi() {
}

Nguoi::~Nguoi() {
}

void Nguoi::Nhap() {
	cout << "Ho va Ten:";
	cin.ignore();
	gets_s(HoTen);
	cout << "Nhap tuoi ";
	cin >> Tuoi;
	cout << "Nhap ngay sinh:" << endl;
	cout << "Nhap ngay: ";
	cin >> NgaySinh.ngay;
	cout << "Nhap thang: ";
	cin >> NgaySinh.thang;
	cout << "Ngap nam: ";
	cin >> NgaySinh.nam;
}

void Nguoi::Xuat() {
	cout << "Ho va ten: " << HoTen << endl;
	cout << "Tuoi: " << Tuoi << endl;
	cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
}

class SinhVien : virtual public Nguoi {
protected:
	string MSSV;
	float Diem;
public:
	SinhVien();
	~SinhVien();
	virtual void Nhap();
	virtual void Xuat();
};

SinhVien::SinhVien() {
}

SinhVien::~SinhVien() {
}

void SinhVien::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap ma so sinh vien ";
	cin >> MSSV;
	cout << "Nhap diem";
	cin >> Diem;
}
void SinhVien::Xuat(){
	Nguoi::Xuat();
	cout << "MSSV: " << MSSV << endl;
	cout << "Diem: " << Diem << endl;
	cout << endl;
}

class HocSinh : virtual public Nguoi {
protected:
	string Lop;
	float Diem;
public:
	HocSinh();
	~HocSinh();
	virtual void Nhap();
	virtual void Xuat();
};

HocSinh::HocSinh() {
}

HocSinh::~HocSinh() {
}

void HocSinh::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap lop cua hoc sinh ";
	cin >> Lop;
	cout << "Nhap diem";
	cin >> Diem;
}
void HocSinh::Xuat() {
	Nguoi::Xuat();
	cout << "Lop: " << Lop << endl;
	cout << "Diem: " << Diem << endl;
	cout << endl;
}

class CongNhan : virtual public Nguoi {
protected:
	int SoNgay;
	long Luong;
public:
	CongNhan();
	~CongNhan();
	virtual void Nhap();
	virtual void Xuat();
};

CongNhan::CongNhan() {
}


CongNhan::~CongNhan() {
}

void CongNhan::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap so ngay lam viec cua cong nhan: ";
	cin >> SoNgay;
	Luong = SoNgay * 100000;
}

void CongNhan::Xuat() {
	Nguoi::Xuat();
	cout << "So ngay lam viec cua cong nhan: " << SoNgay << endl;
	cout << "Luong: " << Luong << endl;
	cout << endl;
}

class NgheSi : virtual public Nguoi {
protected:
	char LinhVuc[30];
	char NgheDanh[30];
	int TuoiNghe;
public:
	NgheSi();
	~NgheSi();
	virtual void Nhap();
	virtual void Xuat();
};

NgheSi::NgheSi() {
}


NgheSi::~NgheSi() {
}

void NgheSi::Nhap() {
	Nguoi::Nhap();
	cin.ignore();
	cout << "Nhap nghe danh cua nghe Si: ";
	gets_s(NgheDanh);
	cout << "Nhap linh vuc cua nghe si: ";
	gets_s(LinhVuc);
	cout << "Nhap tuoi nghe cua nghe si: ";
	cin >> TuoiNghe;
}
void NgheSi::Xuat() {
	Nguoi::Xuat();
	cout << "Nghe danh: " << NgheDanh << endl;
	cout << "Linh Vuc: " << LinhVuc << endl;
	cout << "Tuoi nghe: " << TuoiNghe << endl;
}

class CaSi :virtual public Nguoi {
protected:
	char NgheDanh[30];
	char GiaiThuong[30];
public:
	CaSi();
	~CaSi();
	virtual void Nhap();
	virtual void Xuat();
};

CaSi::CaSi() {
}


CaSi::~CaSi() {
}

void CaSi::Nhap() {
	Nguoi::Nhap();
	cin.ignore();
	cout << " Nhap nghe danh cua Ca Si: ";
	gets_s(NgheDanh);
	cout << "Nhap giai thuong ma ca si do dat duoc: ";
	gets_s(GiaiThuong);
}

void CaSi::Xuat() {
	Nguoi::Xuat();
	cout << " Nghe danh: " << NgheDanh << endl;
	cout << " Giai Thuong: " << GiaiThuong << endl;
	cout << endl;
}

int main() {
	Nguoi** ng;
	ng = new Nguoi * [100];
	int n = 0;
	int mn;
	cout << "Nhap vao danh sach." << endl;
	for (int i= 0;;i++) {
		do {
			cout << "Loai nghe nghiep: " << endl;
			cout << "1. Sinh vien" << endl;
			cout << "2. Hoc sinh" << endl;
			cout << "3. Cong nhan" << endl;
			cout << "4. Ca si" << endl;
			cout << "5. Nghe si" << endl;
			cout << "6. Ket thuc" << endl;
			cout << "Lua chon cua ban: ";
			cin >> mn;
			if (mn != 1 && mn != 2 && mn != 3 && n != 4 && mn != 5 && mn != 6)
				cout << "Khong hop le. Chon lai." << endl;
		} while (mn != 1 && mn != 2 && mn != 3 && mn != 4 && mn != 5 && mn != 6);
			if (mn == 6)
				break;
			else
				if (mn == 1) {
					n++;
					ng[i] = new SinhVien;
				}
				else
					if (mn == 2) {
						n++;
						ng[i] = new HocSinh;
					}
					else
						if (mn == 3) {
							n++;
							ng[i] = new CongNhan;
						}
						else
							if (mn == 4) {
								n++;
								ng[i] = new CaSi;
							}
							else {
								n++;
								ng[i] = new NgheSi;
							}
		ng[i]->Nhap();
	}
	cout << "Xuat danh sach." << endl;
	cout << "So nhan vien = " << n << endl;
	for (int i = 0;i < n;i++) {
		cout << "Nguoi thu: " << i + 1 << endl;
		ng[i]->Xuat();
	}
	
	system("pause");
	return 0;
}

