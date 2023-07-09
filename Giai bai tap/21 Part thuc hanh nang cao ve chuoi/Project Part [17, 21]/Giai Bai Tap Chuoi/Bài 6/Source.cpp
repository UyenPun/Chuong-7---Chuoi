/*
Tìm từ có chiều dài lớn nhất, xuất ra từ
đó và độ dài tương ứng của nó

Định nghĩa:
Từ là 1 hoặc nhiều ký tự khác khoảng trắng
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	/*
	"    Nguyen   Viet   Nam   Son   "

	=> Nguyen 
	=> 6
	*/

	char s[] = 	"    Nguyen   Viet   Nam   Son hahahahihi";
	int length = strlen(s);
	int Start, End;
	int max = 1;
	int StartMax, EndMax;
	for(int i = 0; i < length; i++)
	{
		if(s[i] == ' ' && s[i + 1] != ' ')
		{
			Start = i + 1;
			for(int j = Start + 1; j <= length; j++)
			{
				if(s[j] == ' ' || s[j] == '\0')
				{
					End = j - 1;
					i = End;
					break;
				}
			}
			int dodai = End - Start + 1;
			if(dodai > max)
			{
				max = dodai;
				StartMax = Start;
				EndMax = End;
			}
		}
	}

	printf("\nKet qua la: ");
	for(int i = StartMax; i <= EndMax; i++)
	{
		printf("%c", s[i]);
	}

	printf("\nDo dai la: %d", max);

	getch();
	return 0;
}