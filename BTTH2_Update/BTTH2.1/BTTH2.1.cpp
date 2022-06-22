#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH2.1

class PhanSo{
private:
	int TuSo;
	int MauSo;
public:
	void RutGonPS();
	void Nhap();
	void Xuat();
	PhanSo Tong(PhanSo);
	PhanSo Hieu(PhanSo);
	PhanSo Tich(PhanSo);
	PhanSo Thuong(PhanSo);
	float DinhGiaTri();
};

void PhanSo::Nhap(){
	cout << "Nhap tu so: ";
	cin >> TuSo;
	cout << "Nhap mau so: ";
	cin >> MauSo;
}

void PhanSo::Xuat(){
	cout << TuSo << "/" << MauSo << endl;
}

void PhanSo::RutGonPS() {
	int ucln;
	int a = abs(TuSo);
	int b = abs(MauSo);
	if (TuSo == 0) {
		ucln = TuSo + MauSo;
	}
	else {
		while (a>0 && b>0) {
			if (a > b) {
				a %= b;
			}
			else
			{
				b %= a;
			}
		}
		ucln = a+b;
	}
	if (MauSo < 0) {
		TuSo /= -ucln;
		MauSo /= -ucln;
	}
	else {
		TuSo /= ucln;
		MauSo /= ucln;
	}
}

PhanSo PhanSo::Tong(PhanSo ps){
	PhanSo Tong;
	Tong.TuSo = TuSo * ps.MauSo + MauSo * ps.TuSo;
	Tong.MauSo = MauSo * ps.MauSo;
	Tong.RutGonPS();
	return Tong;
}

PhanSo PhanSo::Hieu(PhanSo ps){
	PhanSo Hieu;
	Hieu.TuSo = TuSo * ps.MauSo - MauSo * ps.TuSo;
	Hieu.MauSo = MauSo * ps.MauSo;
	Hieu.RutGonPS();
	return Hieu;
}

PhanSo PhanSo::Tich(PhanSo ps){
	PhanSo Tich;
	Tich.TuSo = TuSo * ps.TuSo;
	Tich.MauSo = MauSo * ps.MauSo;
	Tich.RutGonPS();
	return Tich;
}

PhanSo PhanSo::Thuong(PhanSo ps){
	PhanSo Thuong;
	Thuong.TuSo = TuSo * ps.MauSo;
	Thuong.MauSo = MauSo * ps.TuSo;
	Thuong.RutGonPS();
	return Thuong;
}

float PhanSo::DinhGiaTri(){
	float GiaTri;
	GiaTri = ((float(TuSo) / MauSo));
	return GiaTri;
}

int main() {
	PhanSo a, b;
	cout << "Nhap Ps 1: " << endl;
	a.Nhap();
	cout << "Nhap ps 2: " << endl;
	b.Nhap();
	PhanSo tong = a.Tong(b);
	PhanSo hieu = a.Hieu(b);
	PhanSo tich = a.Tich(b);
	PhanSo thuong = a.Thuong(b);
	cout << endl << "Hai phan so vua nhap la: " << endl;
	a.Xuat();
	b.Xuat();
	cout << endl;
	cout << "Tong la ";
	tong.Xuat();
	cout << "Hieu la ";
	hieu.Xuat();
	cout << "Tich la ";
	tich.Xuat();
	cout << "Thuong la";
	thuong.Xuat();
	cout << "Phan so thu nhat dinh gia tri la " << a.DinhGiaTri() << endl;
	cout << "Phan so thu hai dinh gia tri la " << b.DinhGiaTri() << endl;
}