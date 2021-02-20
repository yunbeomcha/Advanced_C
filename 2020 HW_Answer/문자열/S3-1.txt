#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	char a[101], b[101];
	int i, j, lena, lenb, flag, cnt = 0;

	gets(a);
	gets(b);

	lena = strlen(a);
	lenb = strlen(b);

	for (i = 0; i < lena; i++) {
		flag = 0;
		if (a[i] == b[0]) {
			for (j = 0; j < lenb; j++) {
				if (a[i + j] == b[j])
					flag++;
			}
			if (flag == lenb) cnt++;
		}
	}

	printf("%d", cnt);

}
