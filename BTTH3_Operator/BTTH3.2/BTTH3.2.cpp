#include<iostream>
using namespace std;

//NguyenThiMyTran-20520322-BTTH3_bai2.

class CTimeSpan {
private:
	int day;
	int hour;
	int minute;
	int second;
public:
	CTimeSpan() {
		this->day = this->hour = this->minute = this->second = 0;
	}

	int getTotalHour() {
		return this->day * 24 + this->hour;
	}

	int getTotalMinute() {
		return this->day * 24 * 60 + this-> hour * 60 + this->minute;
	}

	int getTotalSecond() {
		return this->day * 24 * 60 * 60 + this->hour * 60 * 60 + this->minute * 60 + this->second;
	}
	
	friend istream& operator>>(istream& is, CTimeSpan& T) {
		do {
			cout << "Nhap so ngay: ";
			is >> T.day;
			cout << "Nhap so gio: ";
			is >> T.hour;
			cout << "Nhap sp phut: ";
			is >> T.minute;
			cout << "Nhap so giay: ";
			is >> T.second;
			if (T.day < 0 || T.hour < 0 || T.minute < 0 || T.second < 0)
				cout << "Nhap khong hop le => Nhap lai: " << endl;
		} while (T.day < 0 || T.hour < 0 || T.minute < 0 || T.second < 0);
		return is;
	}

	friend ostream& operator<<(ostream& os, CTimeSpan& T) {
		os << T.day << "d" << T.hour << "h" << T.minute << "m" << T.second << "s";
		return os;
	}

	CTimeSpan operator+(CTimeSpan T) {
		CTimeSpan T1;
		T1.day = (this->getTotalHour() + T.getTotalHour()) / 24;
		T1.hour = (this->getTotalHour() + T.getTotalHour()) % 24;
		T1.minute = (this->getTotalMinute() + T.getTotalMinute()) % 60;
		T1.second = (this->getTotalSecond() + T.getTotalSecond()) % 60;
		return T1;
	}
	
	CTimeSpan operator-(CTimeSpan T) {
		CTimeSpan T1;
		T1.day = (this->getTotalHour() - T.getTotalHour()) / 24;
		T1.hour= (this->getTotalHour() - T.getTotalHour()) % 24;
		T1.minute = (this->getTotalMinute() - T.getTotalMinute()) % 60;
		T1.second = (this->getTotalSecond() - T.getTotalSecond()) % 60;
		return T1;
	}

	int operator==( CTimeSpan& T) {
		if (this->getTotalSecond()== T.getTotalSecond())
			return 1;
		return 0;
	}

	int operator!=( CTimeSpan& T) {
		if (this->getTotalSecond() - T.getTotalSecond())
			return 1;
		return 0;
	}

	int operator>( CTimeSpan& T) {
		if (this->getTotalSecond() > T.getTotalSecond())
			return 1;
		return 0;
	}

	int operator>=( CTimeSpan& T) {
		if (this->getTotalSecond() >= T.getTotalSecond())
			return 1;
		return 0;
	}

	int operator<( CTimeSpan& T) {
		if (this->getTotalSecond() < T.getTotalSecond())
			return 1;
		return 0;
	}

	int operator<=( CTimeSpan& T) {
		if (this->getTotalSecond() <= T.getTotalSecond())
			return 1;
		return 0;
	}
};

int main() {
	CTimeSpan T1, T2,T3;
	cout << "Nhap time 1" << endl;
	cin >> T1;
	cout << "Nhap time 2" << endl;
	cin >> T2;
	cout << "Time 1: " << T1 << ", co tong " << T1.getTotalHour() << " gio, " << T1.getTotalMinute() << " phut, " << T1.getTotalSecond()<<" giay " << endl;
	cout << "Time 2: " << T2 << ", co tong " << T2.getTotalHour() << " gio, " << T2.getTotalMinute() << " phut, " << T2.getTotalSecond()<<" giay " << endl;
	T3 = T1 + T2;
	cout << "Tong cua: " << T1 << " + " << T2 << " = "<<T3<<endl;
	if (T1 >= T2) {
		T3 = T1 - T2;
		cout << "Hieu cua: " << T1 << " - " << T2 << " = " << T3 << endl;
	}
	else {
		T3 = T2 - T1;
		cout << "Hieu cua: " << T2 << " - " << T1 << " = " << T3 << endl;
	}
	
	cout << "Cac gia tri so sanh giua time 1: " << T1 << " va time 2: " << T2 << endl;
	cout << T1 << " == " << T2 <<" : "<< (T1 == T2) << endl;
	cout << T1 << " != " << T2 <<" : " <<(T1 != T2) << endl;
	cout << T1 << " > " << T2 << " : " << (T1 > T2) << endl;
	cout << T1 << " >= " << T2 << " : " << (T1 >= T2) << endl;
	cout << T1 << " < " << T2 << " : " << (T1 < T2) << endl;
	cout << T1 << " <= " << T2 << " : " << (T1 <= T2) << endl;
}