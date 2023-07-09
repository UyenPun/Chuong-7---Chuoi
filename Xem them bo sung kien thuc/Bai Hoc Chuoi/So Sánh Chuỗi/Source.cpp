#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char s1[] = "abcd";
	char s2[] = "e";

	int kq = strcmp(s1, s2);
	printf("\nKq = %d", kq);

	getch();
	return 0;
}