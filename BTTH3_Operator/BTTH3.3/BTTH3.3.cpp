#include<iostream>
using namespace std;

//Nguyen Thi My Tran-20520322-BTTH3_Bai3

class CTime {
private:
	int hour;
	int minute;
	int second;
public:
	CTime() {
		this->hour = this->minute = this->second = 0;
	}
	int getTotalMinute() {
		return this->hour * 60 + this->minute;
	}

	int getTotalSecond() {
		return this->hour * 60 * 60 + this->minute * 60 + this->second;
	}

	friend istream& operator>>(istream& is, CTime& T) {
		do {
			cout << "Nhap gio: ";
			is >> T.hour;
			cout << "Nhap phut: ";
			is >> T.minute;
			cout << "Nhap giay: ";
			is >> T.second;
			if (T.hour < 0 || T.minute < 0 || T.second < 0)
				cout << "Thoi gian khong hop le => Nhap lai." << endl;
		} while (T.hour < 0 || T.minute < 0 || T.second < 0);
		return is;
	}

	friend ostream& operator<<(ostream& os, CTime& T) {
		os << T.hour << "h" << T.minute << "m" << T.second << "s";
		return os;
	}

	CTime operator+(CTime T) {
		CTime T1;
		T1.hour = (this->getTotalSecond() + T.getTotalSecond()) / 3600;
		T1.minute = (this->getTotalMinute() + T.getTotalMinute() + (this->second +T.second)/60) % 60;
		T1.second = (this->getTotalSecond() + T.getTotalSecond()) % 60;
		return T1;
	}

	CTime operator-(CTime T) {
		CTime T1;
		T1.hour = (this->getTotalSecond() - T.getTotalSecond()) / 3600;
		T1.minute = (this->getTotalMinute() - T.getTotalMinute() - (this->second + T.second) / 60) % 60;
		T1.second = (this->getTotalSecond() - T.getTotalSecond()) % 60;
		return T1;
	}

	CTime operator+(int sec) {
		CTime T;
		T.second = this->second + sec;
		T.minute = this->minute + T.second/60;
		T.hour = this->hour + T.minute / 60;
		T.minute %= 60;
		T.second %= 60;
		return T;
	}

	CTime operator-(int sec) {
		CTime T;
		if (this->getTotalSecond() - sec < 0) {
			cout << "khong thuc hien duoc.=> ";
			return T;
		}
		int temp = this->getTotalSecond() - sec;
		T.hour= temp / 3600;
		T.minute = (temp - T.hour* 3600) / 60;
		T.second = temp % 60;
		return T;
	}

	CTime operator++(int a) {
		if (hour == 23 && minute == 59 && second == 59) {
			hour = 0;
			minute = 0;
			second = 0;
			return *this;
		}
		if (minute == 59 && second == 59) {
			hour++;
			minute = 0;
			second = 0;
			return *this;
		}
		if (second == 59) {
			minute++;
			second = 0;
			return *this;
		}
		second++;
		return *this;
	}

	CTime operator--(int a) {
		if(hour == 0 && minute == 0 && second == 0) {
			hour = 23;
			minute = 59;
			second = 59;
			return *this;
		}
		if (minute == 0 && second == 0) {
			hour--;
			minute = 59;
			second = 59;
			return *this;
		}
		if (second == 0) {
			minute--;
			second = 59;
			return *this;
		}
		second--;
		return*this;
	}
};

int main() {
	CTime T1, T2, T3;
	int sec;
	cout << "Nhap time 1:"<<endl;
	cin >> T1;
	cout << "Nhap time 2: " << endl;
	cin >> T2;

	cout << "Time 1: " << T1 << ", co tong " << T1.getTotalMinute() << " phut, " << T1.getTotalSecond() << " giay " << endl;
	cout << "Time 2: " << T2 << ", co tong " << T2.getTotalMinute() << " phut, " << T2.getTotalSecond() << " giay " << endl;

	T3 = T1 + T2;
	cout << "Tong: " << T1 << " + " << T2 << " = " << T3 << endl;

	if (T1.getTotalSecond() >= T2.getTotalSecond()) {
		T3 = T1 - T2;
		cout << "Hieu: " << T1 << " - " << T2 << " = " << T3 << endl;
	}
	else {
		T3 = T2 - T1;
		cout << "Hieu: " << T2 << " - " << T1 << " = " << T3 << endl;
	}

	cout << "Nhap sec muon cong vao time 1 va time 2: ";
	cin >> sec;
	T3 = T1 + sec;
	cout << T1 << " + " << sec << "s = " << T3 << endl;
	T3 = T2 + sec;
	cout << T2 << " + " << sec << "s = " << T3 << endl;

	cout << "Nhap sec muon time 1 va time 2 tru ra: ";
	cin >> sec;
	T3 = T1 - sec;
	cout << T1 << " - " << sec << "s = " << T3 << endl;
	T3 = T2 - sec;
	cout << T2 << " - " << sec << "s = " << T3 << endl;

	cout << "Tang time 1 len 1s, giam time 2 xuong 1s:" << endl;
	cout << T1 << "++ = ";
	T1++;
	cout <<T1 << endl;
	cout << T2 << "-- = ";
	T2--;
	cout << T2 << endl;
}