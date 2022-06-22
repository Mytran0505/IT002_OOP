#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

int menu();

void Introduce()
{
	cout << "NOP BAI TAP THUC HANH SO 1 - ON TAP VE LAP TRINH C" << endl;
	cout << "Ho va Ten: Nguyen Thi My Tran" << endl;
	cout << "Lop: IT002.L21.HTCL.1" << endl;
	cout << "MSSV: 20520322" << endl;
}

//////////////////////////////////////////////////////////////////

class PhanSo {
private:
	int TuSo;
	int MauSo;
public:
	PhanSo();
	PhanSo(int, int);
	void NhapPS();
	int USCLN();
	void RutGonPS();
	void Bai1_RutGonPhanSo();
	void Bai2_TimPhanSoLonHonVaRutGon(PhanSo&);
	void Cong2PS(PhanSo);
	void Tru2PS(PhanSo);
	void Nhan2PS(PhanSo);
	void Chia2PS(PhanSo);
	void Bai3_Cong_Tru_Nhan_Chia_2PS(PhanSo&);
	~PhanSo();
	void Print();
};

PhanSo::PhanSo() {
	TuSo = 0;
	MauSo = 1;
}

PhanSo::PhanSo(int TuSo, int MauSo) {
	this->TuSo = TuSo;
	this->MauSo = MauSo;
}

void PhanSo::Print() {
	cout << TuSo << "/" << MauSo << endl;
}

void PhanSo::NhapPS() {
	do {
		cout << "Nhap Tu So: ";
		cin >> TuSo;
		cout << "Nhap Mau So: ";
		cin >> MauSo;
		if (MauSo == 0)
			cout << "Phan so nhap khong hop le => Nhap lai." << endl;
	} while (MauSo == 0);
	cout << "Phan So vua nhap la: ";
	this->Print();
	cout << endl;
}

int PhanSo::USCLN() {
	PhanSo a;
	a.TuSo = TuSo;
	a.MauSo = MauSo;
	if (a.TuSo < 0)
		a.TuSo = -a.TuSo;
	if (a.MauSo < 0)
		a.MauSo = -a.MauSo;
	while (a.TuSo > 0 && a.MauSo > 0) {
		if (a.TuSo > a.MauSo)
			a.TuSo = a.TuSo % a.MauSo;
		else
			a.MauSo = a.MauSo % a.TuSo;
	}
	return a.MauSo + a.TuSo;
}

void PhanSo::RutGonPS() {
	int ucln = this->USCLN();
	if (TuSo == 0)
		cout << 0 << endl;
	else
		if (TuSo % MauSo == 0)
			cout << TuSo / MauSo << endl;
		else
			if (MauSo < 0) {
				TuSo /= -ucln;
				MauSo /= -ucln;
				this->Print();
			}
			else {
				TuSo /= ucln;
				MauSo /= ucln;
				this->Print();
			}
}

void PhanSo::Bai1_RutGonPhanSo() {
	this->NhapPS();
	cout << "Phan so sau khi rut gon: ";
	this->RutGonPS();
}


void PhanSo::Bai2_TimPhanSoLonHonVaRutGon(PhanSo& x) {
	cout << "Nhap PS thu 1: " << endl;
	this->NhapPS();
	cout << "Nhap PS thu 2: " << endl;
	x.NhapPS();
	cout << "Hai phan so vua nhap la: " << endl;
	this->Print();
	x.Print();
	cout << "So sanh 2 PS:" << endl;
	if (1.0 * TuSo / MauSo == 1.0 * x.TuSo / x.MauSo)
		cout << "Hai phan so tren bang nhau ";
	else {
		cout << "Phan So lon hon la: ";
		if (1.0 * TuSo / MauSo > 1.0 * x.TuSo / x.MauSo) {
			this->Print();
			cout << "Phan so sau khi rut gon: ";
			this->RutGonPS();
		}
		else {
			x.Print();
			cout << "Phan so sau khi rut gon: ";
			x.RutGonPS();
		}
	}
}

void PhanSo::Cong2PS(PhanSo b) {
	PhanSo c;
	c.TuSo = TuSo * b.MauSo + MauSo * b.TuSo;
	c.MauSo = MauSo * b.MauSo;
	c.RutGonPS();
}

void PhanSo::Tru2PS(PhanSo b) {
	PhanSo c;
	c.TuSo = TuSo * b.MauSo - MauSo * b.TuSo;
	c.MauSo = MauSo * b.MauSo;
	c.RutGonPS();
}

void PhanSo::Nhan2PS(PhanSo b) {
	PhanSo c;
	c.TuSo = TuSo * b.TuSo;
	c.MauSo = MauSo * b.MauSo;
	c.RutGonPS();
}

void PhanSo::Chia2PS(PhanSo b) {
	PhanSo c;
	c.TuSo = TuSo * b.MauSo;
	c.MauSo = MauSo * b.TuSo;
	c.RutGonPS();
}

void PhanSo::Bai3_Cong_Tru_Nhan_Chia_2PS(PhanSo& b) {
	cout << "Nhap PS 1: " << endl;
	this->NhapPS();
	cout << "Nhap Ps 2: " << endl;
	b.NhapPS();
	cout << "Hai Phan So vua nhap la: " << endl;
	this->Print();
	b.Print();
	cout << "Tong 2 Phan So tren la: ";
	this->Cong2PS(b);
	cout << "Hieu 2 Phan So tren la: ";
	this->Tru2PS(b);
	cout << "Tich 2 Phan So tren la: ";
	this->Nhan2PS(b);
	cout << "Thuong 2 Phan So tren la: ";
	this->Chia2PS(b);
}

PhanSo::~PhanSo() {

}

/////////////////////////////////////////////////////

class NgayThangNam {
private:
	int Day;
	int Month;
	int Year;

public:
	NgayThangNam();
	NgayThangNam(int, int, int);
	void NhapDay();
	void Bai4_FindDay();
	void Print();
	~NgayThangNam();
};

NgayThangNam::NgayThangNam() {
	Day = 1;
	Month = 1;
	Year = 1;
}

NgayThangNam::NgayThangNam(int Day, int Month, int Year) {
	this->Day = Day;
	this->Month = Month;
	this->Year = Year;
}

void NgayThangNam::Print() {
	cout << Day << "/" << Month << "/" << Year;
}

void NgayThangNam::NhapDay()
{
	cout << "Moi ban nhap vao mot ngay: " << endl;
	cout << "Nhap ngay: ";
	cin >> Day;
	cout << "Nhap Thang: ";
	cin >> Month;
	cout << "Nhap Nam: ";
	cin >> Year;
	cout << "Ngay vua nhap la : ";
	this->Print();
	cout << endl;
}

void NgayThangNam::Bai4_FindDay()
{
	this->NhapDay();
	if (Day > 31 or Day <= 0) {
		this->Print();
		cout << " la ngay khong hop le. Vui long nhap lai." << endl;
		this->Bai4_FindDay();
	}
	else
		if (Month > 12 or Month == 0) {
			cout << "Thang khong hop le. Vui long nhap lai." << endl;
			this->Bai4_FindDay();
		}
		else
			if (Year == 0) {
				cout << "Nam khong hop le. Vui long nhap lai." << endl;
				this->Bai4_FindDay();
			}
			else
				if (Month == 4 or Month == 6 or Month == 9 or Month == 11)
				{
					if (Day > 30) {
						this->Print();
						cout << " la ngay khong hop le. Vui long nhap lai.";
						this->Bai4_FindDay();
					}
					else
					{
						if (Day == 30)
							cout << "Ngay ke tiep ngay tren la: " << 1 << "/" << Month + 1 << "/" << Year;
						else
							cout << "Ngay ke tiep ngay tren la: " << Day + 1 << "/" << Month << "/" << Year;
					}
				}
				else
					if (Month == 1 or Month == 3 or Month == 5 or Month == 7 or Month == 8 or Month == 10 or Month == 12)
					{
						if (Day > 31) {
							this->Print();
							cout << " la ngay khong hop le. Vui long nhap lai.";
							this->Bai4_FindDay();
						}
						else
						{
							if (Month == 12 and Day == 31)
								cout << "Ngay ke tiep ngay tren la: " << 1 << "/" << 1 << "/" << Year + 1;
							else
								if (Day == 31)
									cout << "Ngay ke tiep ngay tren la: " << 1 << "/" << Month + 1 << "/" << Year;
								else
									cout << "Ngay ke tiep ngay tren la: " << Day + 1 << "/" << Month << "/" << Year;
						}
					}
					else
						if (Month == 2)
						{
							if ((Year % 400 == 0) || (Year % 100 != 0 and Year % 4 == 0))
							{
								if (Day <= 29)
								{
									if (Day == 29)
										cout << "Ngay ke tiep ngay tren la: " << 1 << "/" << 3 << "/" << Year;
									else
										cout << "Ngay ke tiep ngay tren la: " << Day + 1 << "/" << Month << "/" << Year;
								}
								else {
									this->Print();
									cout << " la ngay khong hop le. Vui long nhap lai.";
									this->Bai4_FindDay();
								}
							}
							else
							{
								if (Day <= 28)
								{
									if (Day == 28)
										cout << "Ngay ke tiep ngay tren la: " << 1 << "/" << 3 << "/" << Year;
									else
										cout << "Ngay ke tiep ngay tren la: " << Day + 1 << "/" << Month << "/" << Year;
								}
								else {
									this->Print();
									cout << " la ngay khong hop le. Vui long nhap lai.";
									this->Bai4_FindDay();
								}
							}
						}

}

NgayThangNam::~NgayThangNam() {

}

/////////////////////////////////////////////////////////////////

class ThongTinSV
{
private:
	char HoVaTen[30];
	float DiemToan, DiemVan;
protected:
	float DTB;
public:
	ThongTinSV();
	void NhapThongTinSV();
	void TinhDTB();
	void XuatThongTinSV();
	void Bai5_XuatThongTinSV();
	~ThongTinSV();
};

ThongTinSV::ThongTinSV() {

}

void ThongTinSV::NhapThongTinSV() {
	cin.ignore();
	cout << endl << "Hay Nhap Thong Tin SV: " << endl;
	cout << endl << "Ho va Ten SV: ";
	gets_s(HoVaTen);
	cout << "Nhap Diem Toan SV: ";
	cin >> DiemToan;
	cout << "Nhap Diem Van SV: ";
	cin >> DiemVan;
	cout << endl;
}

void ThongTinSV::TinhDTB() {
	DTB = (DiemToan + DiemVan) / 2;
}

void ThongTinSV::XuatThongTinSV() {
	cout << "Thong Tin Sinh Vien: " << endl;
	cout << "Ho va ten: " << HoVaTen << endl;
	cout << "Diem toan: " << DiemToan << endl;
	cout << "Diem van: " << DiemVan << endl;
	cout << "Diem trung binh: " << setprecision(3) << DTB << endl;
}

void ThongTinSV::Bai5_XuatThongTinSV()
{
	this->NhapThongTinSV();
	this->TinhDTB();
	this->XuatThongTinSV();
}

ThongTinSV::~ThongTinSV() {

}

//////////////////////////////////////////////////////////////////

int menu()
{
	int choice;
	cout << endl << "================================";
	cout << endl << "Vui long chon chuc nang tuong ung";
	cout << endl << "1. Nhap vao 1 phan so, rut gon phan so va xuat ket qua";
	cout << endl << "2. Nhap vao 2 phan so, tim phan so lon nhat va xuat ket qua.";
	cout << endl << "3. Nhap vao 2 phan so, Tinh tong, hieu, tich, thuong giua chung va xuat ket qua";
	cout << endl << "4. Nhap vao mot ngay, Tim ngay ke tiep va xuat ket qua.";
	cout << endl << "5. Nhap HoVaTen, Diem Toan, Diem Van cua mot hoc sinh. Tinh diem trung binh va xuat ket qua.";
	cout << endl << "6. Ket thuc";
	cout << endl << "================================" << endl;
	cout << endl << "Lua chon cua ban: ";
	cin >> choice;
	return choice;
}

//////////////////////////////////////////////////////////////////////

int main()
{
	PhanSo a, b;
	NgayThangNam x;
	ThongTinSV SV;
	Introduce();
	int choice;
	bool flag = true;
	while (flag != false)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			a.Bai1_RutGonPhanSo();
			break;
		case 2:
			a.Bai2_TimPhanSoLonHonVaRutGon(b);
			break;
		case 3:
			a.Bai3_Cong_Tru_Nhan_Chia_2PS(b);
			break;
		case 4:
			x.Bai4_FindDay();
			break;
		case 5:
			SV.Bai5_XuatThongTinSV();
			break;
		case 6:
			cout << endl << "Ket thuc chuong trinh." << endl;
			flag = false;
			break;
		default:
			cout << endl << "Lua chon cua ban khong dung, vui long nhap lai.\n";
			break;
		}

	}
}