#include <stdio.h>
#include <conio.h>

int main()
{
	float diem;
	printf("\nNhap vao diem cua ban: ");
	scanf("%f", &diem);

	fflush(stdin); // Xóa trống bộ nhớ đệm.
	char ten[30];
	printf("\nNhap vao ten cua ban: ");
	//scanf("%s", ten);
	gets(ten);

	

	printf("\nChao ban %s, ban duoc %f diem, ban co vui khong ? vui a ?", ten, diem);

	//printf("\nChao ban: %s, hom nay ban khoe khong ? ", ten);

	getch();
	return 0;
}