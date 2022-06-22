#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//NguyenThiMyTran-20520322-BTTH4.2

struct Date {
	int ngay;
	int thang;
	int nam;
};

class Nguoi{
protected:
	char HoTen[30];
	int Tuoi;
	Date NgaySinh;
public:
	Nguoi();
	~Nguoi();
	void Nhap();
	void Xuat();
};

Nguoi::Nguoi(){
}

Nguoi::~Nguoi(){
}

void Nguoi::Nhap(){
	cout << "Ho va Ten:";
	cin.ignore();
	gets_s(HoTen);
	cout << "Nhap tuoi ";
	cin >> Tuoi;
	cout << "Nhap ngay sinh:" << endl;
	cout << "Nhap ngay: ";
	cin >> NgaySinh.ngay;
	cout << "Nhap thang: ";
	cin >> NgaySinh.thang;
	cout << "Ngap nam: ";
	cin >> NgaySinh.nam;
}

void Nguoi::Xuat(){
	cout << "Ho va ten: " << HoTen << endl;
	cout << "Tuoi: " << Tuoi << endl;
	cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
}

class SinhVien : public Nguoi{
protected:
	string MSSV;
	float Diem;
public:
	SinhVien();
	~SinhVien();
	void Nhap();
	void Xuat();
};

SinhVien::SinhVien(){
}

SinhVien::~SinhVien(){
}

void SinhVien::Nhap(){
	Nguoi::Nhap();
	cout << "Nhap ma so sinh vien ";
	cin >> MSSV;
	cout << "Nhap diem";
	cin >> Diem;
}
void SinhVien::Xuat()
{
	cout << endl;
	Nguoi::Xuat();
	cout << "MSSV: " << MSSV << endl;
	cout << "Diem: " << Diem << endl;
	cout << endl;
}

class HocSinh :public Nguoi{
protected:
	string Lop;
	float Diem;
public:
	HocSinh();
	~HocSinh();
	void Nhap();
	void Xuat();
};

HocSinh::HocSinh(){
}

HocSinh::~HocSinh(){
}

void HocSinh::Nhap(){
	Nguoi::Nhap();
	cout << "Nhap lop cua hoc sinh ";
	cin >> Lop;
	cout << "Nhap diem";
	cin >> Diem;
}
void HocSinh::Xuat(){
	cout << endl;
	Nguoi::Xuat();
	cout << "Lop: " << Lop << endl;
	cout << "Diem: " << Diem << endl;
	cout << endl;
}

class CongNhan :public Nguoi{
protected:
	int SoNgay;
	long Luong;
public:
	CongNhan();
	~CongNhan();
	void Nhap();
	void Xuat();
};

CongNhan::CongNhan(){
}


CongNhan::~CongNhan(){
}

void CongNhan::Nhap(){
	Nguoi::Nhap();
	cout << "Nhap so ngay lam viec cua cong nhan: ";
	cin >> SoNgay;
	Luong = SoNgay * 100000;
}

void CongNhan::Xuat(){
	cout << endl;
	Nguoi::Xuat();
	cout << "So ngay lam viec cua cong nhan " << SoNgay << endl;
	cout << "Luong: " << Luong << endl;
	cout << endl;
}

class NgheSi :public Nguoi{
protected:
	char LinhVuc[30];
	char NgheDanh[30];
	int TuoiNghe;
public:
	NgheSi();
	~NgheSi();
	void Nhap();
	void Xuat();
};

NgheSi::NgheSi(){
}


NgheSi::~NgheSi(){
}

void NgheSi::Nhap(){
	Nguoi::Nhap();
	cin.ignore();
	cout << "Nhap nghe danh cua nghe Si: ";
	gets_s(NgheDanh);
	cout << "Nhap linh vuc cua nghe si: ";
	gets_s(LinhVuc);
	cout << "Nhap tuoi nghe cua nghe si: ";
	cin >> TuoiNghe;
}
void NgheSi::Xuat(){
	cout << endl;
	Nguoi::Xuat();
	cout << "Nghe danh: " << NgheDanh << endl;
	cout << "Linh Vuc: " << LinhVuc << endl;
	cout << "Tuoi nghe: " << TuoiNghe << endl;
}

class CaSi :public Nguoi{
protected:
	char NgheDanh[30];
	char GiaiThuong[30];
public:
	CaSi();
	~CaSi();
	void Nhap();
	void Xuat();
};

CaSi::CaSi(){
}


CaSi::~CaSi(){
}

void CaSi::Nhap(){
	Nguoi::Nhap();
	cin.ignore();
	cout << " Nhap nghe danh cua Ca Si: ";
	gets_s(NgheDanh);
	cout << "Nhap giai thuong ma ca si do dat duoc";
	gets_s(GiaiThuong);
}

void CaSi::Xuat(){
	cout << endl;
	Nguoi::Xuat();
	cout << " Nghe danh: " << NgheDanh << endl;
	cout << " Giai Thuong: " << GiaiThuong << endl;
	cout << endl;
}

int main(){
	int n;
	int mn;
	cout << "=============================" << endl;
	cout << "Ban muon nhap thong tin cua " << endl;
	cout << "1. Sinh vien" << endl;
	cout << "2. Hoc sinh" << endl;
	cout << "3. Cong nhan" << endl;
	cout << "4. Ca si" << endl;
	cout << "5. Nghe si" << endl;
	cout << "==============================" << endl;
	cout << "Lua chon cua ban: ";
	cin >> mn;
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	switch (mn){
		case 1:{
			cout << "Nhap thong tin sinh vien:"<<endl;
			SinhVien* s = new SinhVien[n];
			for (int i = 0; i < n; i++)
				s[i].Nhap();
			cout << "Xuat thong tin sinh vien"<<endl;
			for (int i = 0; i < n; i++)
				s[i].Xuat();
			break;
		}
		case 2:{
			cout << "Nhap thong tin hoc sinh"<<endl;
			HocSinh* hs = new HocSinh[n];
			for (int i = 0; i < n; i++)
				hs[i].Nhap();
			cout << "Xuat thong tin hoc sinh" << endl;
			for (int i = 0; i < n; i++)
				hs[i].Xuat();
			break;
		}
		case 3:{
			cout << "Nhap thong tin cong nhan"<<endl;
			CongNhan* cn= new CongNhan[n];
			for (int i = 0; i < n; i++)
				cn[i].Nhap();
			cout << "Thong tin cong nhan vua nhap la:" << endl;
			for (int i = 0; i < n; i++)
				cn[i].Xuat();
			break;
		}
		case 4:{
			cout << "Nhap thong tin ca si"<<endl;
			CaSi *cs = new CaSi[n];
			for (int i = 0; i < n; i++)
				cs[i].Nhap();
			cout << "Xuat thong tin ca si"<<endl;
			for (int i = 0; i < n; i++)
				cs[i].Xuat();
			break;
		}
		case 5: {
			cout << "Nhap thong tin nghe si"<<endl;
			NgheSi* ns = new NgheSi[n];
			for (int i = 0; i < n; i++)
				ns[i].Nhap();
			cout << "Xuat thong tin nghe si"<<endl;
			for (int i = 0; i < n; i++)
				ns[i].Xuat();
			break;
		}
	}
	system("pause");
	return 0;
}

