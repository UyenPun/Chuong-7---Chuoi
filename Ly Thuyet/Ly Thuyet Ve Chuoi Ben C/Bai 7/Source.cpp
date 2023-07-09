/* 
substring(vị trí bắt đầu, số lượng ký tự cần lấy)

s = "Nguyen Viet Nam Son";

substring(7, 4) => "Viet"

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

char* SubString(char *s, int start, int count)
{
	char p[30];
	int k = 0;
	for(int i = start; i < start + count; i++)
	{
		p[k++] = s[i];
	}
	p[k] = '\0'; // kết thúc chuỗi
	return p;
}

int main()
{
	char s[] = "Son handsome";

	char p[30];
	strcpy(p, SubString(s, 4, 8));

	printf("\np = %s", p);
	

	getch();
	return 0;
}

