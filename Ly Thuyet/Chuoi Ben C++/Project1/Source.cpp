#include <iostream>
#include <string>
using namespace std;

void Nhap(string &s)
{
	cout << "\nNhap s: ";
	getline(cin, s);
}

// string s = "Son" => s[s.length() + 1] = '\0' 

int main()
{
	//fflush(stdin); // Xóa bộ nhớ đệm.
	//string s;
	//cout << "\nNhap ten hoc sinh: ";
	//cin >> s; // <=> scanf
	//getline(cin, s); // <=> gets

	//cout << "\nTen: " << s;

	string s = "Son dep trai";
	
	int dodai = s.length();
	cout << "\nDo dai = " << dodai;

	s.erase(s.begin() + 4); // xóa ký tự tại vị trí 4

	cout << "\ns = " << s;

	s.insert(s.begin() + 4, 'd');
	cout << "\ns = " << s;

	string a = "Son";
	string b;

	b = a; // gán a sang b

	cout << "\nb = " << b;

	string c = " dep trai";

	a += c; // nối c vào sau a

	cout << "\na = " << a;

	// strrev
	// atoi, itoa
	// Làm sao có thể lấy hàm ở bên C và đem áp dụng cho C++ ?

	string s1 = "Son dep trai";
	strrev((char *)s1.c_str());
	cout << "\ns1 = " << s1;

	string s2 = "123";
	int number = atoi((char *)s2.c_str());
	cout << "\nnumber = " << number;

	int kichthuocthatsu = s2.capacity();
	cout << "\nKich thuoc that su = " << kichthuocthatsu;

	/*string s3;
	Nhap(s3);
	cout << "\ns3 = " << s3;*/

	system("pause");
	return 0;
}