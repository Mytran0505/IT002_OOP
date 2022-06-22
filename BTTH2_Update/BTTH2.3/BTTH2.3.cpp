#include <iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH2.3

class Dongho{
private:
	long gio;
	long phut;
	long giay;
public:
	Dongho();
	~Dongho();
	void Nhap();
	void Xuat();
	void CongGiay(long , long &);
};

Dongho::Dongho(){
	gio = 0;
	phut = 0;
	giay = 0;
}

Dongho::~Dongho(){
	cout <<endl<< "Ket thuc";
}

void Dongho::Nhap(){
	do{
		cout << " Nhap gio:";
		cin >> gio;
		if((gio < -1 || gio>23))
			cout<<"Gio khong dung, nhap lai"<<endl;
	} while (gio < -1 || gio>23);

	do{
		cout << "Nhap phut:";
		cin >> phut;
		if(phut < -1 || phut>59)
			cout << "Phut khong dung, nhap lai" << endl;
	} while (phut < -1 || phut>59);
	
	do{
		cout << "Nhap giay: ";
		cin >> giay;
		if(giay < -1 || giay>59)
			cout << "Giay khong dung, nhap lai" << endl;
	} while (giay < -1 || giay>59);

	cout << endl;
}

void Dongho::Xuat(){
	cout << gio << "h" << phut << "m" << giay<<"s";
}

void Dongho::CongGiay(long sec, long &day){
	giay += sec;
	day = giay / (3600 * 24);
	while (giay >= 60) {
		++phut;
		giay -= 60;
	}
	while (phut >= 60) {
		++gio;
		phut -= 60;
	}
	while (gio >= 24) {
		gio -= 24;
	}
}

int main(){
	Dongho b;
	long n;
	b.Nhap();
	cout << "Gio vua nhap la: ";
	b.Xuat();
	cout <<endl;
	cout << "Nhap so giay can cong them vao: ";
	cin >> n;
	long day;
	b.CongGiay(n, day);
	cout << "Thoi gian sau khi cong " << n << " sec vao la: ";
	b.Xuat();
	if (day > 0)
		cout<<" cua " << day << " ngay sau.";
	return 0;
}