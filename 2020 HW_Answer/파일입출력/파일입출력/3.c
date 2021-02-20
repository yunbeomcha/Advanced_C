#pragma warning(disable:4996)
#include <stdio.h>
void main() {
	FILE* fp, * fq;
	int i;
	char str[20] = { '\0' }, ch;
	fp = fopen("test1.txt", "r");
	fq = fopen("test2.txt", "w");

	if (fp == NULL) {
		return -1;
	}
	if (fq == NULL) {
		return -1;
	}
	while (!feof(fp)) {
		ch = fgetc(fp);
		fputc(ch, fq);
		printf("%c", ch);
	}

	fclose(fp);
	fclose(fq);
}