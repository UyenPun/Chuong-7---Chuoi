/* 
Có 2 dạng: Đổi thành số nguyên & đổi thành số thực

Đổi thành số nguyên:
s = "123" -> 123
ta thấy 123 = 1*10^2 + 2*10^1 + 3*10^0
s[0] = '1' => có mã ascii là 49
s[1] = '2' => có mã ascii là 50
s[2] = '3' => có mã ascii là 51

"12345" -> 12345
ta thấy 12345 = 1*10^4 + 2*10^3 + 3*10^2 + 4*10^1 + 5*10^0

quy tắc:
- Từ 1 ký tự số mà muốn chuyển sang số tương
ứng thì lấy ký tự số đó - 48
vd: '1' - 48 = 1


- Từ 1 số nguyên mà muốn chuyển sang ký
tự số tương ứng thì lấy số nguyên đó + 48
vd: 1 + 48 = '1'
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int STRLEN(char *s)
{
	int dem = 0;
	while(s[dem++] != '\0'){}
	return dem - 1;
}

int ATOI(char *s)
{
	int length = STRLEN(s);
	int i = 0;
	int temp = length - 1;
	if(s[0] == '-')
	{
		i = 1;
		temp -= 1;
	}

	int number = 0;
	for(; i < length; i++)
	{
		number += (s[i] - 48) * pow(10.0, temp--);
	}
	if(s[0] == '-')
	{
		return -number;
	}
	return number;
}

double ATOF(char *s)
{
	/* 
	"12.34" => 12.34 ???
	"-12.34" => -12.34 ???
	*/

	/* 
Ý Tưởng: Bỏ dấu . đi sẽ thành 1234
=> dùng lại hàm ở trên để biến đổi thành 1234
nhận thấy sau dấu . có 2 chữ số => 1234/10^2 = 12.34
	*/

	char a[20];
	int length = STRLEN(s);
	int idx = 0;
	int k;
	for(int i = 0; i < length; i++)
	{
		if(s[i] != '.')
		{
			a[idx++] = s[i];
		}
		else
		{
			k = i; // lưu vị trí của dấu .
		}
		
	}
	a[idx] = '\0'; // kết thúc chuỗi
	//printf("\na = %s", a);
	int soluong = length - 1 - k;

	return ATOI(a) / pow(10.0, soluong);
}

int main()
{
	char s[] = "-12.34";
	double number = ATOF(s);
	printf("\nNumber = %lf", number);

	getch();
	return 0;
}