/* 
Từ là 1 hoặc nhiều ký tự khác khoảng trắng
vd: Nam Son
=> có 2 từ là từ "Nam" & từ "Son"

*/
#include <iostream>
#include <string>
using namespace std;

int DemSoTu(string s)
{
	int length = s.length();
	int dem = 0;
	// [] => toán tử lấy chỉ số
	if(s[0] != ' ')
	{
		dem = 1;
	}

	for(int i = 0; i < length - 1; i++)
	{
		if(s[i] == ' ' && s[i + 1] != ' ')
		{
			dem++;
		}
	}
	return dem;
}


int main()
{
	string s = "Nam Son";

	int sotu = DemSoTu(s);
	cout << "\nSo tu " << sotu;

	system("pause");
	return 0;
}