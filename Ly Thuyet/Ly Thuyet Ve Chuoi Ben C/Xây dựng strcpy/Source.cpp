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


int main()
{
	char s1[] = "Nam Son";
	char s2[100];
	STRCPY(s2, s1); // gán s1 qua s2

	/* 
	strcpy(s1, s2); // gán s2 qua s1. Lưu ý: s1 phải đủ lớn để chứa s2
	*/
	printf("\ns2 = %s", s2);

	getch();
	return 0;
}