#include<iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH4.1

struct Date{
	int ngay;
	int thang;
	int nam;
};

class NhanVien
{
protected:
	char HoVaTen[100];
	Date NgaySinh;
public:
	NhanVien();
	~NhanVien();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};

NhanVien::NhanVien(){
}

NhanVien::~NhanVien(){
}

void NhanVien::Nhap(){
	cout << "Ho va Ten:";
	cin.ignore();
	gets_s(HoVaTen);
	cout << "Nhap ngay sinh:" << endl;
	cout << "Nhap ngay: ";
	cin >> NgaySinh.ngay;
	cout << "Nhap thang: ";
	cin >> NgaySinh.thang;
	cout << "Ngap nam: ";
	cin >> NgaySinh.nam;
	cout << endl;
}

void NhanVien::Xuat(){
	cout << "Ho va ten: " << HoVaTen << endl;
	cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
}
long NhanVien::Luong(){
	return 0;
}

class SanXuat : virtual public NhanVien{
private:
	long luongcanban, sosp;
public:
	SanXuat();
	~SanXuat();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};

SanXuat::SanXuat(){
}


SanXuat::~SanXuat(){
}

void SanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap Luong can ban:";
	cin >> luongcanban;
	cout << "Nhap so san pham:";
	cin >> sosp;
}
void SanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "Luong can ban: " << luongcanban << endl;
	cout << "So san pham : " << sosp << endl;
}
long SanXuat::Luong()
{
	return luongcanban + sosp * 5000;
}

class VanPhong : virtual public NhanVien
{
private:
	int songaylamviec;
public:
	VanPhong();
	~VanPhong();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};

VanPhong::VanPhong(){
}


VanPhong::~VanPhong(){
}
void VanPhong::Nhap(){
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> songaylamviec;
}

void VanPhong::Xuat()
{
	NhanVien::Xuat();
	cout << "So ngay lam viec:" << songaylamviec << endl;
}
long VanPhong::Luong()
{
	return songaylamviec * 100000;
}

int main() {
	NhanVien** nv;
	nv= new NhanVien*[100];
	int chon;
	int n = 0;
	cout << "Nhap vao danh sach nhan vien." << endl;
	for (int i = 0;;i++)
	{
		do {
			cout << "Loai nhan vien:" << endl;
			cout << "1 -Nhan viem van phong" << endl;
			cout << "2 -Nhan vien san xuat" << endl;
			cout << "3 -Ket thuc." << endl;
			cout << "Lua chon: ";
			cin >> chon;
			if (chon != 1 && chon != 2 && chon != 3)
				cout << "Khong hop le. Chon lai." << endl;
		} while (chon != 1 && chon != 2 && chon != 3);
		if (chon == 3)
			break;
		else 
			if (chon == 1){
			n++;
			nv[i] = new VanPhong;
		}
		else
		{
			n++;
			nv[i] = new SanXuat;
		}
		nv[i]->Nhap();
	}
	cout << "Xuat danh sach." << endl;
	cout << "So nhan vien = " << n << endl;
	for (int i = 0;i < n;i++)
	{
		cout << "Nhan vien thu: " << i + 1 << endl;
		nv[i]->Xuat();
		cout << "Luong = " << nv[i]->Luong();
		cout << endl;
	}
}