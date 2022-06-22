#include <iostream>
#include<math.h>
#include <conio.h>
using namespace std;

//NguyenThiMyTran-20520322-BTTH4.4

class Diem
{
	int x;
	int y;
public:
	Diem() { x = 0; y = 0; }
	Diem(int xx, int yy) { x = xx; y = yy; }
	~Diem()
	{
		cout << "Huy bo doi tuong ";
	}
	void Nhap();
	void Xuat();
	void set_x(int xx);
	void set_y(int yy);
	int get_x();
	int get_y();
	void TinhTien(int dx, int dy);
};

void Diem::Nhap()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}
void Diem::Xuat()
{
	cout << "(" << x << "," << y << ")" << endl;
}
void Diem::set_x(int xx)
{
	x = xx;
}
void Diem::set_y(int yy)
{
	y = yy;
}
int Diem::get_x()
{
	return x;
}
int Diem::get_y()
{
	return y;
}
void Diem::TinhTien(int dx, int dy)
{
	x = x + dx;
	y = y + dy;
}

class Ellip
{
protected:
	Diem a;
	float rdai;
	float rrong;
public:
	Ellip();
	~Ellip();
	friend class Diem;
	void Nhap();
	void Xuat();
};

Ellip::Ellip()
{
}


Ellip::~Ellip()
{
}
void Ellip::Nhap()
{
	cout << "Nhap tam " << endl;
	a.Nhap();
	cout << "Nhap ban kinh dai: ";
	cin >> rdai;
	cout << "Nhap ban kinh rong: ";
	cin >> rrong;
}
void Ellip::Xuat()
{
	cout << "Tam la";
	a.Xuat();
	cout << " Ban kinh dai la:" << rdai << endl;
	cout << " Ban kinh rong la " << rrong << endl;
}

class HinhTron :public Ellip
{
protected:
	float r;
public:
	HinhTron();
	~HinhTron();
	void Nhap();
	void Xuat();
};

HinhTron::HinhTron()
{
}

HinhTron::~HinhTron()
{
}
void HinhTron::Nhap()
{
	do
	{
		Ellip::Nhap();
		if (rdai != rrong)
			cout << "Nhap bk dai = bk rong. Nhap lai." << endl;
	} while (rdai != rrong);
	r = rdai = rrong;
}
void HinhTron::Xuat()
{
	Ellip::Xuat();
	cout << "Ve hinh tron:" << endl;
	cout << "Day la hinh tron ne: O" << endl;
	for (int i = 0; i < 2 * r; i++) {
		for (int j = 0; j < 2 * r; j++) {
			if (i == sqrt((static_cast<int> (r)) ^ 2 - j ^ 2)) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	HinhTron n;
	n.Nhap();
	n.Xuat();
	system("pause");
	return 0;
}