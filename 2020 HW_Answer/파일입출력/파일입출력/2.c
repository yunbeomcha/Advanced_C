#pragma warning(disable:4996)
#include <stdio.h>
void main() {
	FILE* fp, * fq;
	int i;
	char str[10] = { '\0' };
	fp = fopen("test1.txt", "r");
	fq = fopen("test2.txt", "w");

	if (fp == NULL) {
		return -1;
	}
	if (fq == NULL) {
		return -1;
	}
	fscanf(fp, "%s", str);
	//fgets(str, 10, fp);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = 'A' + str[i] - 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = 'a' + str[i] - 'A';
		}
	}
	
	fprintf(fq, "%s", str);
	//fputs(str, fq);
	printf("%s", str);
	fclose(fp);
	fclose(fq);

}