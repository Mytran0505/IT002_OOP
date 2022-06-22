#include <iostream>
#include <string>
using namespace std;

//Nguyen Thi My Tran-20520322-BTTH3_Bai5

class CString {
private:
	string str;
public:
	CString() {

	}

	~CString() {

	}
	friend istream& operator>>(istream& is, CString &s) {
		getline(is, s.str);
		return is;
	}
	friend ostream& operator<<(ostream& os,  CString &s) {
		os << s.str;
		return os;
	}

	CString operator+(CString &s) {
		CString st;
		st.str = str;
		st.str += s.str;
		return st;
	}

	int myStrlen() {
		int len=0;
		for (int i = 0;this->str[i] != '\0'; i++)
			len++;
		return len;
	}
	
	CString DaoChuoi() {
		int n = this->myStrlen();
		for (int i = 0;i < this->myStrlen() / 2 ;i++)
			swap(this->str[i], this->str[n - 1 - i]);
		return *this;
	}

	CString UppercaseString() {
		int n = this->myStrlen();
		for (int i = 0;i < this->myStrlen();i++)
			if (this->str[i] >= 97 && this->str[i] <= 122)
				this->str[i] -= 32;
		return *this;

	}

	CString LowercaseString() {
		for (int i = 0;i < this->myStrlen();i++)
			if (this->str[i] >= 65 && this->str[i] <= 90)
				this->str[i] += 32;
		return *this;
	}
	
	CString operator+(const CString &s) {
		CString  st;
		st.str = this->str;
		st.str += s.str;
		return st;
	}
	CString operator=(CString s) {
		this->str = s.str;
		return *this;
	}

	int operator==(CString s){
		if (this->str == s.str)
			return 1;
		return 0;
	}

	int operator!=(CString s) {
		if (this->str != s.str)
			return 1;
		return 0;
	}

	int operator<(CString s){
		if (this->str < s.str)
			return 1;
		return 0;
	}

	int operator<=(CString s) {
		if (this->str <= s.str)
			return 1;
		return 0;
	}

	int operator>(CString s) {
		if (this->str > s.str)
			return 1;
		return 0;
	}

	int operator>=(CString s) {
		if (this->str >= s.str)
			return 1;
		return 0;
	}
};

int main() {
	CString Str1, Str2, Str;
	cout << "Nhap chuoi 1: ";
	cin >> Str1;
	cout << "Nhap chuoi 2: ";
	cin>>Str2;
	cout << "Hai chuoi vua nhap la " << Str1 << " va " << Str2 << endl;

	cout << "So sanh hai chuoi :" << endl;
	cout << Str1 << " == " << Str2 << ": " << (Str1 == Str2) << endl;
	cout << Str1 << " != " << Str2 << ": " << (Str1 != Str2) << endl;
	cout << Str1 << " > " << Str2 << ": " << (Str1 > Str2) << endl;
	cout << Str1 << " >= " << Str2 << ": " << (Str1 >= Str2) << endl;
	cout << Str1 << " < " << Str2 << ": " << (Str1 < Str2) << endl;
	cout << Str1 << " <= " << Str2 << ": " << (Str1 <= Str2) << endl;
	
	Str = Str1 + Str2;
	cout << "Noi hai chuoi " << Str1 << " va " << Str2 << " = "<<Str<< endl;
	int len = Str.myStrlen();
	cout << "Do dai chuoi nay la: " << len<< endl;
	Str = Str.UppercaseString();
	cout << "Uppercase => " << Str << endl;
	Str = Str.LowercaseString();
	cout << "Lowercase => " << Str << endl;
	Str = Str.DaoChuoi();
	cout << "Dao nguoc chuoi nay ta duoc: " << Str << endl;
}