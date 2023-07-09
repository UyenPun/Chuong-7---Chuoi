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

/* 
itoa, ltoa, ultoa
itoa(value, buffer, 2|8|10|16)

250 đổi sang các hệ

* hệ 2 *
250 : 2 = 125 dư 0
125 : 2 = 62 dư 1
62 : 2 = 31 dư 0
31 : 2 = 15 dư 1
15 : 2 = 7 dư 1
7 : 2 = 3 dư 1
3 : 2 = 1 dư 1
1 : 2 = 0 dư 1
phần nguyên còn 0 => dừng lại
=> đọc ngược lên các giá trị dư sẽ là: 11111010

* hệ 8 *
250 : 8 = 31 dư 2
31 : 8 = 3 dư 7
3 : 8 = 0 dư 3
=> 0 thì dừng lại
=> đọc ngược lại là 372

* hệ 16 *
250 : 16 = 15 dư 10
15 : 16 = 0 dư 15
=> 0 thì dừng lại
-> đọc ngược lên nhưng theo quy tắc sau
nếu là 10 => A, 11 => B, 12 => C, 13 => D, 14 => E, 15 => F
=> FA
*/

// "1234" => "4321"
void HoanVi(char &a, char &b)
{
	char temp = a;
	a = b; 
	b = temp;
}

void STRREV(char *s)
{
	int length = STRLEN(s);
	for(int i = 0; i < length / 2; i++)
	{
		HoanVi(s[i], s[length - 1 - i]);
	}
}

void ITOA(int number, char *vungnho, int coso)
{
	int idx = 0;
	while(number != 0)
	{
		int ketqua = number % coso;
		number /= coso; // cập nhật lại number

		if(ketqua < 10) // THÌ LÀ 1 SỐ NGUYÊN
		{
			vungnho[idx++] = ketqua + 48; // ĐỔI SỐ NGUYÊN SANG KÝ TỰ TƯƠNG ỨNG
		}
		else if(ketqua == 10)
		{
			vungnho[idx++] = 'A';
		}
		else if(ketqua == 11)
		{
			vungnho[idx++] = 'B';
		}
		else if(ketqua == 12)
		{
			vungnho[idx++] = 'C';
		}
		else if(ketqua == 13)
		{
			vungnho[idx++] = 'D';
		}
		else if(ketqua == 14)
		{
			vungnho[idx++] = 'E';
		}
		else if(ketqua == 15)
		{
			vungnho[idx++] = 'F';
		}
	}
	vungnho[idx] = '\0'; // Phải nhớ kết thúc chuỗi
	STRREV(vungnho); // đảo ngược chuỗi lại
}

int main()
{
	int number = 250;
	char vungnho[30];
	ITOA(number, vungnho, 2);
	printf("\nket qua = %s", vungnho);

	getch();
	return 0;
}