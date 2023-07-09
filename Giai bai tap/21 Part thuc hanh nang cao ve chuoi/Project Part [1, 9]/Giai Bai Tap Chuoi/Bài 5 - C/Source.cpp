/* 
Xuất các từ trên các dòng liên tiếp nhau
vd: "  Nguyen   Viet    Nam   Son  "

Output:
Nguyen
Viet
Nam
Son

Ý Tưởng:
Ta viết ra 1 hàm cắt ra 1 chuỗi con trong
1 chuỗi cho trước với 2 tham số truyền
vào là vị trí bắt đầu cắt và vị trí kết
thúc cắt
vd: SubStr(2, 5); // Cắt đoạn [2, 5]

Start: Duyệt chuỗi gặp ký tự khác khoảng
trắng đầu tiên

End: Từ vị trí Start đó duyệt tiếp, gặp
ký tự khoảng trắng thì lùi về trước đó
1 chỉ số thì đó chính là End

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

char* SubStr(char *s, int Start, int End)
{
	char p[100];
	int idx = 0;
	for(int i = Start; i <= End; i++)
	{
		p[idx++] = s[i];
	}
	p[idx] = '\0';
	return p;
}

void XuatCacTu(char *s)
{
	int Start, End;

	int length = strlen(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] != ' ')
		{
			Start = i;

			// Từ Start chạy tiếp nè
			for(int j = Start + 1; j <= length; j++)
			{
				if(s[j] == ' ' || s[j] == '\0')
				{
					End = j - 1;
					//printf("\nStart = %d & End = %d", Start, End);
					char p[100];
					strcpy(p, SubStr(s, Start, End));
					printf("\n%s", p);

					i = j; // Cập nhật lại vị trí chạy
					break;
				}
			}
		}
	}
}


int main()
{
	char s[] = "  Nguyen   Viet    Nam   Son  ";

	XuatCacTu(s);

	getch();
	return 0;
}