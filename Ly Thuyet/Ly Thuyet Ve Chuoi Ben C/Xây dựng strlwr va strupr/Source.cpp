#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int STRLEN(char *s)
{
	int dem = 0;
	while(s[dem++] != '\0'){}
	return dem - 1;

	/*while (true)
	{
		if(s[dem] == '\0')
		{
			return dem - 1;
		}
		dem++;
	}*/
}

void STRLWR(char *s)
{
	int length = STRLEN(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}

void STRUPR(char *s)
{
	int length = STRLEN(s);

	for(int i = 0; i < length; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}


int main()
{
	char s1[] = "Nam Son";
	
	// strlwr(s1) => s1 = "nam son";
	// strupr(s1) => s1 = "NAM SON";

	// nhớ nguyên tắc: ký tự hoa sang thường => lấy ký tự + 32
	// ký tự thường sang hoa => lấy ký tự - 32

	STRLWR(s1);
	printf("\ns1 = %s", s1);

	STRUPR(s1);
	printf("\ns1 = %s", s1);



	getch();
	return 0;
}