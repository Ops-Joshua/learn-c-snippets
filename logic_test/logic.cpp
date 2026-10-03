#include <stdio.h>
int main(void)
{

  	int x = 0x7, y = 19;
	printf("%d    %d\n", x&y, x&&y);
	printf("%d   %d\n", x|y, x||y);
	printf("%x\n\n", x^y);

	x = 0x7, y = 9;
	printf("%d    %d\n", x&y, x&&y);
	printf("%d   %d\n", x|y, x||y);
	printf("%x\n\n", x^y);

	x = 0x6, y = 9;
	printf("%d    %d\n", x&y, x&&y);
	printf("%d   %d\n", x|y, x||y);
	printf("%x\n\n", x^y);

	return 0;
}