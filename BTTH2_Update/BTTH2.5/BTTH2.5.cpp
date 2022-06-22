#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH2.5

class Diem {
	float x;
	float y;
public:
	Diem();
	Diem(float, float);
	void Nhap();
	void Xuat();
	void set_x(float);
	void set_y(float);
	float get_x();
	float get_y();
	void TinhTien(float, float);
	~Diem();
};

Diem::Diem() {
	x = 0;
	y = 0;
}

Diem::Diem(float xx, float yy) {
	x = xx;
	y = yy;
}

Diem::~Diem() {
}

void Diem::Nhap() {
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
	cout << endl;
}

void Diem::Xuat() {
	cout << "(" << x << ", " << y << ")";
}

void Diem::set_x(float xx) {
	x = xx;
}

void Diem::set_y(float yy) {
	y = yy;
}

float Diem::get_x() {
	return x;
}

float Diem::get_y() {
	return y;
}

void Diem::TinhTien(float dx, float dy) {
	x = x + dx;
	y = y + dy;
}

class TamGiac
{
private:
	Diem a[4];
public:
	TamGiac();
	~TamGiac();
	void NhapTG();
	void XuatTG();
	void TinhTienTG(Diem);
	Diem getTrongTamTG();
	friend class Diem;
};

TamGiac::TamGiac() {
}

TamGiac::~TamGiac() {
	cout << "Huy bo doi tuong";
}

void TamGiac::NhapTG() {
	cout << "Nhap 3 toa do 3 dinh cua tam giac: " << endl;
	for (int i = 1; i <= 3; i++) {
		cout << "Nhap toa do dinh thu: " << i << endl;
		a[i].Nhap();
	}
}
void TamGiac::XuatTG() {
	cout << "Toa do 3 dinh cua tam giac: { ";
	for (int i = 1; i <= 3; i++) {
		a[i].Xuat();
		if (i < 3)
			cout << "; ";
	}
	cout << " }" << endl;
}

void TamGiac::TinhTienTG(Diem z) {
	for (int i = 1; i <= 3; i++)
		a[i].TinhTien(z.get_x(), z.get_y());
}

Diem TamGiac::getTrongTamTG() {
	float td = 0;
	float hd = 0;
	Diem x;
	for (int i = 1; i <= 3; i++) {
		hd += a[i].get_x();
		td += a[i].get_y();
	}
	hd = hd / 3;
	td = td / 3;
	x.set_x(hd);
	x.set_y(td);
	return x;
}

int main() {
	TamGiac tg;
	Diem diem1, diem2;
	tg.NhapTG();
	tg.XuatTG();

	diem1 = tg.getTrongTamTG();
	cout << "Trong tam TGiac la: ";
	diem1.Xuat();

	cout << endl << "Tinh tien tam giac: " << endl;
	cout << "Nhap diem can tinh tien: " << endl;
	diem2.Nhap();
	tg.TinhTienTG(diem2);
	cout << "Tam giac da duoc tinh tien:" << endl;
	tg.XuatTG();

	system("pause");
	return 0;
}