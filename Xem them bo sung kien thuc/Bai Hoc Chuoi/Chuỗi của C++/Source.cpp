#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;

	fflush(stdin); // Xóa bộ nhớ đệm.
	cout << "\nMoi ban nhap chuoi: ";
	getline(cin, s);

	cout << "\nChuoi vua nhap la: " << s;

	

	// Tính độ dài
	int dodai = s.length();

	string a = "Son ", b = "dep trai";
	a += b; // Nối chuỗi b vào sau chuỗi a
	cout << a;

	if(a == b)
	{
		// chuỗi a = b
	}
	else if(a > b)
	{
		// chuỗi a > b
	}
	else if(a < b)
	{
		// chuỗi a < b
	}

	string s1;
	s1 = "Nam Son";

	strrev((char *)s1.c_str());
	cout << "\n\ns1 = " << s1;

	string s2 = "Nguyen Viet Nam Son";

	strlwr((char *)s2.c_str());
	cout << "\n\ns2 = " << s2;

	strupr((char *)s2.c_str());
	cout << "\n\ns2 = " << s2;

	string s3 = "Nam Son";
	string s4 = s3.substr(2, 4);
	cout << "\n\ns4 = " << s4;

	system("pause");
	return 0;
}