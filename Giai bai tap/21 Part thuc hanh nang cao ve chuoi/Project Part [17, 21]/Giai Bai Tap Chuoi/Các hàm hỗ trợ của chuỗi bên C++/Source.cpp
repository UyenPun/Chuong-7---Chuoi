#include <iostream>
#include <string>
using namespace std;

void Nhap(string &s)
{
	cout << "\nNhap chuoi: ";
	getline(cin, s);
}

int main()
{
	string s;;

	Nhap(s);
	//strrev((char *)s.c_str());

	cout << s;

	system("pause");
	return 0;
}