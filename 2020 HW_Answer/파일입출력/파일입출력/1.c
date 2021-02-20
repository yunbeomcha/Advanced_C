#pragma warning(disable:4996)
#include <stdio.h>
void main() {
	FILE* fp;
	int n, a = 0, i, cnt = 0, sum = 0;
	double avg = 0;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("open file");
		return -1;
	}
	for (i = 0;; i++) {
		sum += a;
		
		if (scanf("%d", &a) == EOF) {
			break;
		}
		cnt++;
	}
	avg = (double)sum / cnt;
	fp = fopen("data.txt", "w");
	printf("%d\n", cnt);
	printf("%d\n", sum);
	printf("%.2lf\n", avg);

	fclose(fp);
	return 0;
}