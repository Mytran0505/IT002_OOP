#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH5.1

class Sach{
protected:
	char TenSach[50];
	int GiaTien;
public:
	Sach();
	~Sach();
	virtual void Nhap();
	virtual void Xuat();
};

Sach::Sach(){
}


Sach::~Sach(){
}

void Sach::Nhap(){
	cout << "Nhap ten cua sach:";
	cin.ignore();
	gets_s(TenSach);
	cout << "Nhap gia tien cua quyen sach:";
	cin >> GiaTien;
}

void Sach::Xuat(){
	cout << "Ten sach: " << TenSach << endl;
	cout << "Gia tien: " << GiaTien << "d" << endl;
}

class SachGK :public Sach{
protected:
	char NhaXuatBan[100];
public:
	SachGK();
	~SachGK();
	void Nhap();
	void Xuat();
};

SachGK::SachGK(){
}

SachGK::~SachGK(){
}

void SachGK::Nhap(){
	Sach::Nhap();
	cout << "Nhap ten nha xuat ban:";
	cin.ignore();
	gets_s(NhaXuatBan);
}

void SachGK::Xuat(){
	Sach::Xuat();
	cout << "Ten nha xuat ban:" << NhaXuatBan << endl;
}

class TapChi :public Sach{
protected:
	int SoBao;
public:
	TapChi();
	~TapChi();
	void Nhap();
	void Xuat();
};

TapChi::TapChi(){
}


TapChi::~TapChi(){
}

void TapChi::Nhap(){
	Sach::Nhap();
	cout << "Nhap so ki bao ";
	cin >> SoBao;
}
void TapChi::Xuat(){
	Sach::Xuat();
	cout << "Ki bao so: " << SoBao << endl;
}

class TieuThuyet :public Sach{
protected:
	char TacGia[50];
public:
	TieuThuyet();
	~TieuThuyet();
	void Nhap();
	void Xuat();
};

TieuThuyet::TieuThuyet(){
}

TieuThuyet::~TieuThuyet(){
}

void TieuThuyet::Nhap(){
	Sach::Nhap();
	cout << "Nhap ten tac gia ";
	cin.ignore();
	gets_s(TacGia);
}

void TieuThuyet::Xuat(){
	Sach::Xuat();
	cout << "Ten tac gia la:" << TacGia << endl;
}

int main(){
	Sach* DS[50];
	int menu;
	int n = 0;
	cout << endl;
	for (int i = 0;; i++)
	{
		do {
			cout << " Chon loai sach" << endl;
			cout << " 1. Sach giao khoa" << endl;
			cout << " 2. Sach tap chi " << endl;
			cout << " 3. Sach tieu thuyet " << endl;
			cout << " 4. Ket thuc" << endl;
			cout << "Lua chon cua ban: ";
			cin >> menu;
			if (menu != 1 && menu != 2 && menu != 3 && menu != 4)
				cout << "Khong hop le. Chon lai." << endl;
		} while (menu != 1 && menu != 2 && menu != 3 && menu != 4);
		if (menu == 4)
			break;
		else
			if (menu == 1) {
				n++;
				DS[i] = new SachGK;
			}
			else
				if (menu == 2) {
					n++;
					DS[i] = new TapChi;
				}
				else {
					n++;
					DS[i] = new TieuThuyet;
				}
		DS[i]->Nhap();
	}
	cout << "Danh sach vua nhap la: " << endl;
	cout << "So sach duoc nhap: " << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Sach thu: " << i + 1 << endl;
		DS[i]->Xuat();
	}
	system("pause");
	return 0;
}
