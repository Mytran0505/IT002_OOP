#include<iostream>
using namespace std;

// NguyenThiMyTran-20520322-BTTH2.2

struct Date {
	int Ngay;
	int Thang;
	int Nam;
};

class ThiSinh {
private:
	string  MSSV;
	char HoVaTen[30];
	Date NgaySinh;
	float DiemToan;
	float DiemVan;
	float DiemAnh;
public:
	void Nhap();
	void Xuat();
	float TongDiem();
};

void ThiSinh::Nhap(){
	cin.ignore();
	cout << "Nhap Ho va ten: ";
	gets_s(HoVaTen);
	cout << "Nhap MSSV: ";
	cin >> MSSV;
	cout << "Nhap Ngay Thang Nam sinh: "<<endl;
	cout << "Ngay: "; cin >> NgaySinh.Ngay;
	cout << "Thang: "; cin >> NgaySinh.Thang;
	cout << "Nam: "; cin>>NgaySinh.Nam;
	cout << "Nhap diem toan: ";
	cin >> DiemToan;
	cout << "Nhap diem van: ";
	cin >> DiemVan;
	cout << "Nhap diem anh: ";
	cin >> DiemAnh;
	cout << endl;
}

float ThiSinh::TongDiem(){
	return DiemToan + DiemVan + DiemAnh;
}

void ThiSinh::Xuat(){
	cout << "Ho va ten: " << HoVaTen << endl;
	cout << "MSSV: " << MSSV << endl;
	cout << "Ngay sinh: " << NgaySinh.Ngay << "/" << NgaySinh.Thang << "/" << NgaySinh.Nam << endl;
	cout << "Diem toan: " << DiemToan << endl;
	cout << "Diem van: " << DiemVan << endl;
	cout << "Diem anh: " << DiemAnh << endl;
	cout << "Tong Diem: " << this->TongDiem() << endl;
	cout << endl;
}

class MangThiSinh{
	int n;
	ThiSinh dsThiSinh[100];
public:
	void NhapDS();
	void XuatDSCoTongDiemLonHon15();
};

void MangThiSinh::NhapDS(){
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin thi sinh thu: " << i + 1 << endl;
		dsThiSinh[i].Nhap();
	}
}

void MangThiSinh::XuatDSCoTongDiemLonHon15(){
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (dsThiSinh[i].TongDiem() > 15) {
			dem++;
			cout << "Thi sinh thu: " << dem << endl;
			dsThiSinh[i].Xuat();
		}
}

int main(){
	MangThiSinh sv;
	sv.NhapDS();
	cout << "Danh sach thi sinh co diem tren 15: "<<endl;
	cout << endl;
	sv.XuatDSCoTongDiemLonHon15();
	return 0;
}