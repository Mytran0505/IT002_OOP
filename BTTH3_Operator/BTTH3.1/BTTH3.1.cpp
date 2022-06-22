#include<iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH3_bai1.

class CPhanSo {
private:
	int Tu;
	int Mau = 1;//so nguyen co mau so = 1
public:
	friend istream& operator>>(istream&, CPhanSo&);
	friend ostream& operator<<(ostream&, CPhanSo&);
	CPhanSo operator+(CPhanSo);
	CPhanSo operator-(CPhanSo);
	CPhanSo operator*(CPhanSo);
	CPhanSo operator/(CPhanSo);
	int operator==(const CPhanSo&);
	int operator!=(const CPhanSo&);
	int operator>(const CPhanSo&);
	int operator>=(const CPhanSo&);
	int operator<(const CPhanSo&);
	int operator<=(const CPhanSo&);
};


istream& operator>>(istream& is, CPhanSo& x) {
	cout << "Nhap tu so: ";
	is >> x.Tu;
	x.Mau = 1;
	return is;
}

ostream& operator<<(ostream& os, CPhanSo& x) {
	os << x.Tu << "/" << x.Mau;
	return os;
}

CPhanSo CPhanSo::operator+(CPhanSo x) {
	CPhanSo temp;
	temp.Tu = Tu * x.Mau + Mau * x.Tu;
	temp.Mau = Mau * x.Mau;
	return temp;
}

CPhanSo CPhanSo::operator-(CPhanSo x) {
	CPhanSo temp;
	temp.Tu = Tu * x.Mau - Mau * x.Tu;
	temp.Mau = Mau * x.Mau;
	return temp;
}

CPhanSo CPhanSo::operator*(CPhanSo x) {
	CPhanSo temp;
	temp.Tu = Tu *x.Tu;
	temp.Mau = Mau * x.Mau;
	return temp;
}

CPhanSo CPhanSo::operator/(CPhanSo x) {
	CPhanSo temp;
	temp.Tu = Tu * x.Mau;
	temp.Mau = Mau * x.Tu;
	return temp;
}

int CPhanSo::operator==(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau == 0)
		return 1;
	return 0;
}

int CPhanSo::operator!=(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau != 0)
		return 1;
	return 0;
}

int CPhanSo::operator>(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau > 0)
		return 1;
	return 0;
}

int CPhanSo::operator>=(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau >= 0)
		return 1;
	return 0;
}

int CPhanSo::operator<(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau < 0)
		return 1;
	return 0;
}

int CPhanSo::operator<=(const CPhanSo &x) {
	if ((float)(*this - x).Tu / (*this - x).Mau <= 0)
		return 1;
	return 0;
}

int main(){
	CPhanSo a, b,c;
	cout << "Nhap PS1: " << endl;
	cin >> a;
	cout << "Nhap PS2: " << endl;
	cin >> b;
	cout << "Hai phan so vua nhap la: " << a << ", " << b <<endl;
	c = a + b;
	cout << "Tong 2 PS la: " << c<<endl;
	c = a - b;
	cout << "Hieu 2 PS la: " << c << endl;
	c = a * b;
	cout << "Tich 2 PS la: " << c << endl;
	c = a / b;
	cout << "Thuong 2 PS la: " << c << endl;

	cout << "Cac gia tri so sanh: " << endl;
	cout << a << " == " << b << " : " << (a == b) << endl;
	cout << a << " != " << b << " : " << (a != b) << endl;
	cout << a << " > " << b << " : " << (a > b) << endl;
	cout << a << " >= " << b << " : " << (a >= b) << endl;
	cout << a << " < " << b << " : " << (a < b) << endl;
	cout << a << " <= " << b << " : " << (a <= b) << endl;
}






