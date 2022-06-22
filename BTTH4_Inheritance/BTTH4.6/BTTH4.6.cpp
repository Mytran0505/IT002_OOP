#include <time.h>
#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//NguyenThiMyTran-20520322-BTTH4.6

class GiaSuc
{
public:
	GiaSuc();
	~GiaSuc();
	int SinhCon();
	int ChoSua();
	void Keu();
};

GiaSuc::GiaSuc()
{
}


GiaSuc::~GiaSuc()
{
}
int GiaSuc::SinhCon()
{
	return 0;
}
int GiaSuc::ChoSua()
{
	return 0;
}
void GiaSuc::Keu()
{
}

class Bo :public GiaSuc
{
public:
	Bo();
	~Bo();
	int SinhCon();
	int ChoSua();
	void Keu();
};

Bo::Bo()
{
}


Bo::~Bo()
{
}
int Bo::SinhCon()
{
	srand((unsigned)time(0));
	return rand() % 7;
}
int Bo::ChoSua()
{
	srand((unsigned)time(0));
	return rand() % 20;
}
void Bo::Keu()
{
	cout << "Bo";
}

class Cuu :public GiaSuc
{
public:
	Cuu();
	~Cuu();
	int SinhCon();
	int ChoSua();
	void Keu();
};

Cuu::Cuu()
{
}


Cuu::~Cuu()
{
}
int Cuu::SinhCon()
{
	srand((unsigned)time(0));
	return rand() % 9;
}
int Cuu::ChoSua()
{
	srand((unsigned)time(0));
	return rand() % 5;
}
void Cuu::Keu()
{
	cout << "Cuu";
}

class De :public GiaSuc
{
public:
	De();
	~De();
	int SinhCon();
	int ChoSua();
	void Keu();
};

De::De()
{
}


De::~De()
{
}
int De::SinhCon()
{
	srand((unsigned)time(0));
	return rand() % 5;
}
int De::ChoSua()
{
	srand((unsigned)time(0));
	return rand() % 10;
}
void De::Keu()
{
	cout << "De";
}

int main()
{
	int TongBo = 0;
	int litSuaBo = 0;
	int TongDe = 0;
	int litSuaDe = 0;
	int TongCuu = 0;
	int litSuaCuu = 0;
	Bo b[15];
	De d[15];
	Cuu c[15];
	int soBo;
	int soDe;
	int soCuu;
	cout << "Nhap so luong bo: ";
	cin >> soBo;
	cout << "Tieng keu cua: " << soBo << " con bo" << endl;
	for (int i = 0; i < soBo; i++)
	{
		TongBo += i + b[i].SinhCon();
		litSuaBo += b[i].ChoSua();
		b[i].Keu();
		cout << endl;
	}
	cout << "Tong so con Bo la " << TongBo << endl;
	cout << "Tong so lit sua la " << litSuaBo << endl;
	cout << "Nhap so luong de: ";
	cin >> soDe;
	cout << "Tieng keu cua: " << soDe << " con de" << endl;
	for (int i = 0; i < soDe; i++)
	{
		TongDe += i + d[i].SinhCon();
		litSuaDe += d[i].ChoSua();
		d[i].Keu();
		cout << endl;
	}
	cout << "Tong so con De la " << TongDe << endl;
	cout << "Tong so lit sua la " << litSuaDe << endl;
	cout << "Nhap so luong de: ";
	cin >> soCuu;
	cout << "Tieng keu cua: " << soCuu << " con cuu" << endl;
	for (int i = 0; i < soCuu; i++)
	{
		TongCuu += i + c[i].SinhCon();
		litSuaCuu += c[i].ChoSua();
		c[i].Keu();
		cout << endl;
	}
	cout << "Tong so con Cuu la " << TongCuu << endl;
	cout << "Tong so lit sua la " << litSuaCuu << endl;
	system("pause");
	return 0;
}





