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

int STRCMP(char *s1, char *s2)
{
	// s1 = "Nam"
	// s2 = "Nam Son"
	int Min = STRLEN(s1) < STRLEN(s2) ? STRLEN(s1) : STRLEN(s2);
	int i;
	for(i = 0; i < Min; i++)
	{
		if(s1[i] < s2[i])
		{
			return -1;
		}
		else if(s1[i] > s2[i])
		{
			return 1;
		}
	}
	if(s1[i] == '\0') // s1 là chuỗi ngắn
	{
		if(s2[i] == '\0')
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	if(s2[i] == '\0')
	{
		if(s1[i] == '\0')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int STRICMP(char *s1, char *s2)
{
	// Biến cả 2 thành cùng chữ hoa hay cùng chữ thường để cho đồng bộ
	STRLWR(s1);
	STRLWR(s2);

	return STRCMP(s1, s2);
}

int main()
{
	char s1[] = "nam son";
	char s2[] = "Nam Son";

	int ketqua = STRICMP(s1, s2);
	printf("\nKet qua = %d", ketqua);
	



	getch();
	return 0;
}