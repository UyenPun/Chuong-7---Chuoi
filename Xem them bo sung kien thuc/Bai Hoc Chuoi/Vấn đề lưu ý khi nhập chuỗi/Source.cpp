#include <stdio.h>
#include <conio.h>

int main()
{
	int tuoi;
	char hoten[30];

	printf("\nMoi ban nhap vao so tuoi: ");
	scanf("%d", &tuoi);

	fflush(stdin); // Xóa bộ nhớ đệm.
	printf("\nMoi ban nhap vao ho ten: ");
	gets(hoten);

	
	printf("\nChao mung ban %s den voi lop hoc Ky Thuat Lap Trinh cua Son xau trai", hoten);
	printf("\nBan %s hien tai %d tuoi", hoten, tuoi);



	getch();
	return 0;
}