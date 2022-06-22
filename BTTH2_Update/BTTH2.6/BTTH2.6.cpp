#include <iostream>
#include<string>
using namespace std;

//NguyenThiMyTran-20520322-BTTH2.6;

class Chuoi{
private:
	string str;
public:
	Chuoi();
	~Chuoi();
	void NhapChuoi();
	void XuatChuoi();
	int getStrlen();
	Chuoi Noi2Chuoi(Chuoi);
	string DaoChuoi();
};

Chuoi::Chuoi(){
}

Chuoi::~Chuoi(){
}

void Chuoi::NhapChuoi() {
	cin>>str;
}

void Chuoi::XuatChuoi() {
	cout << str << endl;
}

int Chuoi::getStrlen() {
	int len = 0;
	for (int i = 0;this->str[i] != '\0'; i++)
		len++;
	return len;
}

Chuoi Chuoi::Noi2Chuoi(Chuoi s1) {
	Chuoi s;
	s.str = str + s1.str;
	return s;
}

string Chuoi::DaoChuoi() {
	Chuoi s;
	s.str= str;
	int n = s.getStrlen();
	for (int i = 0;i < s.getStrlen() / 2;i++)
		swap(s.str[i], s.str[n - 1 - i]);
	return s.str;
}

int main(){
	Chuoi s1, s2, s3;
	cout << "Nhap chuoi 1: ";
	s1.NhapChuoi();
	cout << "Nhap chuoi 2: ";
	s2.NhapChuoi();
	cout << "Hai chuoi vua nhap la: " << endl;
	s1.XuatChuoi();
	s2.XuatChuoi();
	s3 = s1.Noi2Chuoi(s2);
	cout << "Noi hai chuoi tren ta duoc chuoi 3 la: ";
	s3.XuatChuoi();
	cout << "Do dai chuoi 3 la: " << s3.getStrlen() << endl;
	cout << "Dao nguoc chuoi 3 ta duoc: " << s3.DaoChuoi() << endl;
	system("pause");
	return 0;
}