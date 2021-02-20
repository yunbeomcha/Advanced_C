#pragma warning(disable:4996)
#include <stdio.h>
void main() {
	FILE* fp, * fq;
	int i;
	char str[20] = { '\0' }, temp[10][100], ch, cnt = 0;
	fp = fopen("test1.txt", "a");
	fq = fopen("test2.txt", "r");

	if (fp == NULL) {
		return -1;
	}
	if (fq == NULL) {
		return -1;
	}
	fgets(str, 20, fq);

	if(!feof(fp))
		fprintf(fp, str);

	fclose(fp);
	fclose(fq);
}