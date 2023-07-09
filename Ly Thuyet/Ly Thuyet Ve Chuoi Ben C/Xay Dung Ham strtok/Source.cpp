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

int main()
{
	/* 
	s = "Tu, Quang, Duy, Dang, Thien, Linh";
	
	char ten[20];
	strtok(s, ", ") => Tu
	strtok(0, ", ") => Quang
	strtok(0, ", ") => Duy

	*/




	getch();
	return 0;
}