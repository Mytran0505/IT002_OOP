#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH2.4

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
	int get_x();
	int get_y();
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
	cout << "Huy bo doi tuong. ";
}

void Diem::Nhap() {
	cout << "Nhap toa do diem" << endl;
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
	cout << endl;
}

void Diem::Xuat() {
	cout << "(" << x << ", " << y << ")" << endl;
}

void Diem::set_x(float xx) {
	x = xx;
}

void Diem::set_y(float yy) {
	y = yy;
}

int Diem::get_x() {
	return x;
}

int Diem::get_y() {
	return y;
}

void Diem::TinhTien(float dx, float dy) {
	x = x + dx;
	y = y + dy;
}

int main() {
	Diem z;
	float h, t;
	z.Nhap();
	cout << "Diem vua nhap la: ";
	z.Xuat();
	cout << "Hoanh do cua diem nay la: " << z.get_x() << endl;
	cout << "Tung do cua diem nay la: " << z.get_y() << endl;
	cout << "Nhap hoanh do muon thay doi: ";
	cin >> h;
	cout << "Nhap tung do muon thay doi: ";
	cin >> t;
	z.set_x(h);
	z.set_y(t);
	cout << "Toa do diem sau khi thay doi la: ";
	z.Xuat();
	Diem x;
	cout << "Nhap toa do de tinh tien diem: " << endl;
	x.Nhap();
	z.TinhTien(x.get_x(), x.get_y());
	cout << "Toa do diem sau khi tinh tien: ";
	z.Xuat();
	return 0;
}