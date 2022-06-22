#include<iostream>
#include<time.h>

using namespace std;

//NguyenThiMYTran-20520322-BTTH5.5

class GiaSuc
{
public:
	virtual int SinhCon() = 0;
	virtual int ChoSua() = 0;
	virtual void Keu() = 0;
	GiaSuc();
	~GiaSuc();
};
GiaSuc::GiaSuc()
{
}

GiaSuc::~GiaSuc()
{
}

class Bo :public GiaSuc
{
public:
	int SinhCon();
	int ChoSua();
	void Keu();
	Bo();
	~Bo();
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
	cout << "Bo ";
}

class Cuu :public GiaSuc
{
public:
	int SinhCon();
	int ChoSua();
	void Keu();
	Cuu();
	~Cuu();
};

Cuu::Cuu()
{
}


Cuu::~Cuu()
{
}
int Cuu::SinhCon()
{
	srand(unsigned(time(0)));
	return rand() % 5;
}
int Cuu::ChoSua()
{
	srand(unsigned(time(0)));
	return rand() % 15;
}
void Cuu::Keu()
{
	cout << "Cuu ";
}

class De :public GiaSuc
{
public:
	int ChoSua();
	int SinhCon();
	void Keu();
	De();
	~De();
};

De::De()
{
}


De::~De()
{
}
int De::SinhCon()
{
	srand(unsigned(time(0)));
	return rand() % 5;
}
int De::ChoSua()
{
	srand(unsigned(time(0)));
	return rand() % 10;
}
void De::Keu()
{
	cout << "De ";
}



void main()
{
	int n;
	GiaSuc* gs[50];
	cout << " Nhap so luong gia suc: ";
	cin >> n;
	int menu;
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap gia suc thu: " << i+1 << endl;
		cout << "1. BO " << endl;
		cout << "2. CUU " << endl;
		cout << "3. DE " << endl;
		cout << "Lua chon: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			gs[i] = new Bo();
			break;
		case 2:
			gs[i] = new Cuu();
			break;
		case 3:
			gs[i] = new De();
			break;
		}
	}
	//Cau a;
	for (int i = 0; i < n; i++)
	{
		cout << "Tieng keu cua con vat thu: " << i + 1 << endl;
		gs[i]->Keu();
		cout << endl;
	}

	//cau b;
	long tongsua = 0;
	for (int i = 0; i < n; i++)
	{
		tongsua += gs[i]->ChoSua();
	}
	cout << "So lit sua la " << tongsua << endl;

	//cau c;
	long tongcon = 0;
	for (int i = 0; i < n; i++)
	{
		tongcon += gs[i]->SinhCon();
	}
	cout << "Tong so con la " << tongcon << endl;
	system("pause");
}