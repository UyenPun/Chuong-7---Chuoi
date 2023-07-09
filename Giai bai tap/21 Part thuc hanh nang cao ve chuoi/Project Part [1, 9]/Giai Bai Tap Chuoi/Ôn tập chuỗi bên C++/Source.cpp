#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "abcdefghi";
	//cout << "\nKich thuoc that su: " << str.capacity();
	//str.erase(4, 3); // Xóa đi 3 ký tự từ vị trí 4
	str.erase(str.begin() + 2); // Xóa đi ký tự 2
	cout << "\nstr = " << str;

	//atoi((char *)str.c_str());

	system("pause");
	return 0;
}