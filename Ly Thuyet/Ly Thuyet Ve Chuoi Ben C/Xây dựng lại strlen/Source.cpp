#include <stdio.h>
#include <conio.h>

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


int main()
{
	char s[] = "Nam Son";

	int length = STRLEN(s);
	printf("\nDo dai la: %d", length);

	getch();
	return 0;
}