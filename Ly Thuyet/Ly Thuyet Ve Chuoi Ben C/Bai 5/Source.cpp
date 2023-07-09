/* 

Viết hàm nhận vào một chuỗi s và xuất
các từ trên các dòng liên tiếp

vd:
s = "  Nguyen    Viet    Nam    Son   "

Nguyen
Viet
Nam
Son

Cần tìm ra vị trí bắt đầu & kết thúc của 1 từ
=> xuất các ký tự trong đoạn đó
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

void XuatTuTrenDong(char *s)
{
	int start = -1, end;

	int length = strlen(s);

	if(s[0] != ' ')
	{
		start = 0;
	}

	for(int i = 0; i < length - 1; i++)
	{
		// tìm bắt đầu
		if((s[i] == ' ' && s[i + 1] != ' ') || start == 0)
		{
			start = i + 1;

			// chơi chiêu nè
			if(start == 1)
			{
				start = 0;
			}

			// từ vị trí bắt đầu duyệt tiếp tục để tìm ra vị trí kết thúc của từ
			for(int j = start + 1; j < length - 1; j++)
			{
				if(s[j] != ' ' && s[j + 1] == ' ')
				{
					end = j;
					i = j; // cập nhật lại vị trí duyệt
					break; // thoát ra
				}
			}

			// in ra các ký tự trong đoạn start -> end
			for(int k = start; k <= end; k++)
			{
				printf("%c", s[k]);
			}
			start = -1; // cập nhật lại start
			printf("\n");
		}
	}
}

int main()
{
	char s[] = "   Trang    de    thuong    ";

	XuatTuTrenDong(s);

	getch();
	return 0;
}

