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

void HoanVi(char &x, char &y)
{
	char Temp = x;
	x = y;
	y = Temp;
}

void STRREV(char *s)
{
	int length = STRLEN(s);
	for(int i = 0; i < length / 2; i++)
	{
		HoanVi(s[i], s[length - 1 - i]);
	}
}

int main()
{
	char s1[] = "Nam Son";
	
	/* 
	strrev(s1);
	=> s1 = "noS maN"
	*/
	STRREV(s1);
	printf("\ns1 = %s", s1);



	getch();
	return 0;
}