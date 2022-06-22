#include<iostream>
using namespace std;

//Nguyen Thi My Tran-20520322-BTTH3_Bai4.

class CDate {
private:
	int Day;
	int Month;
	int Year;
public:
	CDate() {
		this->Day = this->Month = this->Year = 0;
	}
	friend istream& operator>>(istream& is, CDate& d) {
		cout << "Nhap ngay: ";
		is >> d.Day;
		cout << "Nhap thang: ";
		is >> d.Month;
		cout << "Nhap nam: ";
		is >> d.Year;
		cout << "Ngay vua nhap: " << d.Day << "/" << d.Month << "/" << d.Year << endl;
		return is;
	}

	friend ostream& operator<<(ostream& os, CDate& d) {
		os << d.Day << "/" << d.Month << "/" << d.Year;
		return os;
	}

	int CheckDate() {
		if (Day > 31 or Day <= 0)
			return 0;
		if (Month > 12 or Month <= 0)
			return 0;
		if (Year <= 0)
			return 0;
		if (Month == 4 or Month == 6 or Month == 9 or Month == 11)
			if (Day > 30)
				return 0;
		if (Month == 1 or Month == 3 or Month == 5 or Month == 7 or Month == 8 or Month == 10 or Month == 12)
			if (Day > 31)
				return 0;
		if (Month == 2) {
			if ((Year % 400 == 0) || (Year % 100 != 0 and Year % 4 == 0)) {
				if (Day > 29)
					return 0;
			}
			else
				if (Day > 28)
					return 0;
		}
		return 1;
	}
	CDate operator++(int a) {
		if (Month == 4 or Month == 6 or Month == 9 or Month == 11) {
			if (Day == 30) {
				Day = 1;
				Month++;
				return *this;
			}
			else {
				Day++;
				return *this;
			}
		}
		if (Month == 1 or Month == 3 or Month == 5 or Month == 7 or Month == 8 or Month == 10 or Month == 12) {
			if (Month == 12 and Day == 31) {
				Day = 1;
				Month = 1;
				Year++;
				return *this;
			}
			else {
				if (Day == 31) {
					Day = 1;
					Month++;
					return *this;
				}
				else {
					Day++;
					return *this;
				}
			}
		}
		if (Month == 2) {
			if ((Year % 400 == 0) || (Year % 100 != 0 and Year % 4 == 0)) {
				if (Day <= 29) {
					if (Day == 29) {
						Day = 1;
						Month = 3;
						return *this;
					}
					else {
						Day++;
						return *this;
					}
				}
			}
			else {
				if (Day <= 28) {
					if (Day == 28) {
						Day = 1;
						Month = 3;
						return *this;
					}
					else {
						Day++;
						return *this;
					}
				}
			}
		}
	}

	CDate operator+(int day) {
		for (int i = 0;i < day;i++)
			*this = this->operator++(1);
		return *this;
	}

	CDate operator--(int a) {
		if (Month ==2 or Month == 4 or Month == 6 or Month == 9 or Month == 11) {
			if (Day == 1) {
				Day = 31;
				Month--;
				return *this;
			}
			else {
				Day--;
				return *this;
			}
		}
		if (Month == 1 or Month == 5 or Month == 7 or Month == 8 or Month == 10 or Month == 12) {
			if (Month == 1 and Day == 1) {
				Day = 30;
				Month = 12;
				Year--;
				return *this;
			}
			else {
				if (Day == 1) {
					Day = 31;
					Month--;
					return *this;
				}
				else {
					Day--;
					return *this;
				}
			}
		}
		if (Month == 3) {
			if ((Year % 400 == 0) || (Year % 100 != 0 and Year % 4 == 0)) {
				if (Day == 1) {
					Day = 29;
					Month--;
					return *this;
				}
				else {
					Day--;
					return *this;
				}
			}
			else {
				if (Day == 1) {
					Day = 28;
					Month--;
					return *this;
				}
				else {
					Day--;
					return *this;
				}
			}
		}
	}
	CDate operator-(int day) {
		for (int i = 0;i < day;i++)
			*this = this->operator--(1);
		return *this;
	}

	int ChangeDateToDay() {
		if (Month < 3) {
			Year--;
			Month += 12;
		}
		return 365 * Year + Year / 4 - Year / 100 + Year / 400 + (153 * Month - 457) / 5 + Day - 306;
	}

	int operator-(CDate D) {
		return this->ChangeDateToDay() - D.ChangeDateToDay();
	}
};

int main() {
	CDate D1, D2, DTemp;
	int day;
	do {
		cout << "Nhap Ngay 1: " << endl;;
		cin >> D1;
		if (D1.CheckDate() == 0)
			cout << "Ngay " << D1 << " la ngay khong hop le => Nhap lai." << endl;
	} while (D1.CheckDate() == 0);

	cout << "Tang Ngay 1 len 1 ngay: " << endl;
	cout << "Ngay 1: " << D1 << "++ = ";
	D1++;
	cout << D1 << endl;

	cout << "Nhap so ngay muon ngay 1 hien tai: "<<D1<<" cong vao: ";
	cin >> day;
	cout << "Ngay 1 hien tai: " << D1 << " + " << day << " day = ";
	D1 = D1 + day;
	cout<< D1 << endl;

	cout << "Lui Ngay 1 hien tai" << D1<<" xuong 1 ngay: " << endl;
	cout << "Ngay 1 hien tai: " << D1 << "-- = ";
	D1--;
	cout << D1 << endl;

	cout << "Nhap so ngay muon ngay 1 hien tai: " << D1 << " tru ra: ";
	cin >> day;
	cout << "Ngay 1 hien tai: " << D1 << " - " << day << " day = ";
	D1 = D1 - day;
	cout << D1 << endl;

	do {
		cout << "Nhap ngay 2: " << endl;
		cin >> D2;
		if (D2.CheckDate() == 0)
			cout << "Ngay " << D2 << " la ngay khong hop le => Nhap lai." << endl;
	} while (D2.CheckDate() == 0);

	cout << "Khoang cach tu : " << D1 << " -> " << D2 << " la: ";
	int D = D1 - D2;
	if (D < 0)
		D = -D;
	cout << D << " day. ";
}