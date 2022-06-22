#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH5.2_3_4;

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
	void PhongThu(int k);
};
void Diem::Nhap()
{
	cout << "Nhap toa do diem" << endl;
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}
void Diem::Xuat()
{
	cout << "(" << x << ";" << y << ")" << endl;
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
void Diem::PhongThu(int k)
{
	x = k * x;
	y = k * y;
}

class DaGiac
{
protected:
	Diem* a;
	int n;
public:
	DaGiac();
	~DaGiac();
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhTien();
	virtual void PhongThu();
};
DaGiac::DaGiac()
{
}
DaGiac::~DaGiac()
{
}
void DaGiac::Nhap()
{
	cout << "nhap so luong phan tu cua lop da giac ";
	cin >> n;
	a = new Diem[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap hinh thu: " << i+1 << endl;
		a[i].Nhap();
	}
}
void DaGiac::Xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout <<"Diem thu : " << i+1 << endl;
		cout << "Diem vua nhap: ";
		a[i].Xuat();
	}
}
void DaGiac::TinhTien()
{
	int dx, dy;
	cout << "Nhap hoanh do, tung do can nhap ";
	cin >> dx >> dy;
	for (int i = 0; i < n; i++)
	{
		a[i].TinhTien(dx, dy);
	}
}
void DaGiac::PhongThu()
{
	int k;
	cout << "Nhap do thu phong " << endl;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		a[i].PhongThu(k);
	}
}
class TamGiac :public DaGiac
{
public:
	TamGiac();
	~TamGiac();
	 void Nhap();
	 void Xuat();
	 void TinhTien();
	 void PhongThu();
};

TamGiac::TamGiac(){
}


TamGiac::~TamGiac(){
}

void TamGiac::Nhap()
{
	a = new Diem[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap hinh thu: " << i+1 << endl;
		a[i].Nhap();
	}
}
void TamGiac::Xuat()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Diem thu : " << i + 1 << endl;
		cout << "Diem vua nhap: ";
		a[i].Xuat();
	}
}
void TamGiac::TinhTien()
{
	cout << "Nhap hoanh do tung do can tinh tien ";
	int dx, dy;
	cin >> dx >> dy;
	for (int i = 0; i < 3; i++)
	{
		a[i].TinhTien(dx, dy);
	}
}
void TamGiac::PhongThu()
{
	int k;
	cout << "Nhap he so phong to, thu nho ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		a[i].PhongThu(k);
	}
}

class TuGiac :public DaGiac
{
public:
	TuGiac();
	~TuGiac();
	void Nhap();
	void Xuat();
	void TinhTien();
	void PhongThu();
};

TuGiac::TuGiac()
{
}


TuGiac::~TuGiac()
{
}
void TuGiac::Nhap()
{
	a = new Diem[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "Nhap hinh thu: " << i + 1 << endl;
		a[i].Nhap();
	}
}
void TuGiac::Xuat()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Diem thu : " << i + 1 << endl;
		cout << "Diem vua nhap: ";
		a[i].Xuat();
	}
}
void TuGiac::TinhTien()
{
	cout << "Nhap hoanh do tung do can tinh tien ";
	int dx, dy;
	cin >> dx >> dy;
	for (int i = 0; i < 4; i++)
	{
		a[i].TinhTien(dx, dy);
	}
}
void TuGiac::PhongThu()
{
	int k;
	cout << "Nhap he so phong to, thu nho ";
	cin >> k;
	for (int i = 0; i < 4; i++)
	{
		a[i].PhongThu(k);
	}
}

class HinhBinhHanh :public TuGiac
{
public:
	HinhBinhHanh();
	~HinhBinhHanh();
	void Nhap();
	void Xuat();
	void TinhTien();
	void PhongThu();
};

HinhBinhHanh::HinhBinhHanh()
{
}


HinhBinhHanh::~HinhBinhHanh()
{
}
void HinhBinhHanh::Nhap()
{
	do
	{
		cout << "Phai nhap hinh binh hanh!"<<endl;
		TuGiac::Nhap();
	} while (a[0].get_y() != a[3].get_y() || a[1].get_y() != a[2].get_y());
}
void HinhBinhHanh::Xuat()
{
	TuGiac::Xuat();
}
void HinhBinhHanh::TinhTien()
{
	TuGiac::TinhTien();
}
void HinhBinhHanh::PhongThu()
{
	TuGiac::PhongThu();
}

class HinhChuNhat :public HinhBinhHanh
{
public:
	HinhChuNhat();
	~HinhChuNhat();
	void Nhap();
	void Xuat();
	void TinhTien();
	void PhongThu();
};

HinhChuNhat::HinhChuNhat()
{
}


HinhChuNhat::~HinhChuNhat()
{
}
void HinhChuNhat::Nhap()
{
	do
	{
		cout << "Phai nhap hinh chu nhat!"<<endl;
		TuGiac::Nhap();
	} while (a[0].get_y() != a[3].get_y() || a[0].get_x() != a[1].get_x());
}
void HinhChuNhat::Xuat()
{
	HinhBinhHanh::Xuat();
}
void HinhChuNhat::TinhTien()
{
	HinhBinhHanh::TinhTien();
}
void HinhChuNhat::PhongThu()
{
	HinhBinhHanh::PhongThu();
}

class HinhVuong :public HinhChuNhat
{
public:
	HinhVuong();
	~HinhVuong();
	void Nhap();
	void Xuat();
	void TinhTien();
	void PhongThu();
};

HinhVuong::HinhVuong()
{
}


HinhVuong::~HinhVuong()
{
}
void HinhVuong::Nhap()
{
	do
	{
		cout << "Phai nhap hinh vuong!"<<endl;
		TuGiac::Nhap();
	} while (abs(a[0].get_x() - a[1].get_x()) != abs(a[0].get_y() - a[2].get_y()));
}

void HinhVuong::Xuat()
{
	HinhChuNhat::Xuat();
}
void HinhVuong::TinhTien()
{
	HinhChuNhat::TinhTien();
}
void HinhVuong::PhongThu()
{
	HinhChuNhat::PhongThu();
}

int main()
{
	DaGiac* a[30];
	int n;
	cout << " Nhap so luong da giac can thao tac: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int chon = 0;
		cout << " Chon cac loai hinh sau day de nhap " << endl;
		cout << " 1. Tam Giac" << endl;
		cout << " 2. Tu Giac " << endl;
		cout << " 3. Hinh Binh Hanh " << endl;
		cout << " 4. Hinh Chu Nhat " << endl;
		cout << " 5. Hinh Vuong " << endl;
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			a[i] = new TamGiac();
			a[i]->Nhap();
			a[i]->Xuat();
			a[i]->TinhTien();
			cout << "Diem sau khi tinh tien: ";
			a[i]->Xuat();
			a[i]->PhongThu();
			cout << "Diem sau khi phong thu: ";
			a[i]->Xuat();
			break;
		}
		case 2:
		{
			a[i] = new TuGiac();
			a[i]->Nhap();
			a[i]->Xuat();
			a[i]->TinhTien();
			cout << "Diem sau khi tinh tien: ";
			a[i]->Xuat();
			a[i]->PhongThu();
			cout << "Diem sau khi phong thu: ";
			a[i]->Xuat();
			break;
		}
		case 3:
		{
			a[i] = new HinhBinhHanh();
			a[i]->Nhap();
			a[i]->Xuat();
			a[i]->TinhTien();
			cout << "Diem sau khi tinh tien: ";
			a[i]->Xuat();
			a[i]->PhongThu();
			cout << "Diem sau khi phong thu: ";
			a[i]->Xuat();
			break;
		}
		case 4:
		{
			a[i] = new HinhChuNhat();
			a[i]->Nhap();
			a[i]->Xuat();
			a[i]->TinhTien();
			cout << "Diem sau khi tinh tien: ";
			a[i]->Xuat();
			a[i]->PhongThu();
			cout << "Diem sau khi phong thu: ";
			a[i]->Xuat();
			break;
		}
		case 5:
		{
			a[i] = new HinhVuong();
			a[i]->Nhap();
			a[i]->Xuat();
			a[i]->TinhTien();
			cout << "Diem sau khi tinh tien: ";
			a[i]->Xuat();
			a[i]->PhongThu();
			cout << "Diem sau khi phong thu: ";
			a[i]->Xuat();
			break;
		}
		}
	}
	system("pause");
	return 0;

}










