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

void STRCPY(char *s1, char *s2)
{
	// gán từng ký tự từ s2 qua s1
	int length_s2 = STRLEN(s2);

	for(int i = 0; i < length_s2; i++)
	{
		s1[i] = s2[i];
	}
	s1[length_s2] = '\0'; // Phải có kết thúc chuỗi
}

char *STRDUP(char *s)
{
	int length = STRLEN(s);
	char *p = (char *)malloc(length + 1); // Cấp phát bộ nhớ cho p vừa đủ chứa length + 1
	STRCPY(p, s); // gán s sang p
	return p; // trả về p
}


int main()
{
	char s1[] = "Nam Son";
	
	/* 
	char *s2 = strdup(s1);
	// s2 = "Nam Son"
	*/
	char *s2 = STRDUP(s1);
	printf("\ns2 = %s", s2);

	free(s2); // giải phóng con trỏ

	getch();
	return 0;
}