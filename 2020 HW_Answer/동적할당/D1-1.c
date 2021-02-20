#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st {
	char* str; //문자열 저장
	int cnt; //자음 수 저장
}st;
int main(void) {
	st* p, tmp, *q, *k;
	char temp[101];
	int len, n, cnt;
	scanf("%d", &n);
	p = (st*)malloc(n * sizeof(st)); //n만큼 동적할당

	for (int i = 0; i < n; i++) {
		scanf("%s", temp); //임시로 문자를 받는다.
		p[i].str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(p[i].str, temp); //임시로 받은 문자열을 복사해서 붙인다.
	}


	for (int i = 0; i < n; i++) {
		len = strlen(p[i].str);//문자 길이
		cnt = 0;
		for (int j = 0; j < len; j++) {
			if (p[i].str[j] != 'A' && p[i].str[j] != 'a' && p[i].str[j] != 'e' && p[i].str[j] != 'E'&& p[i].str[j] != 'i' && p[i].str[j] != 'I'&& p[i].str[j] != 'O' && p[i].str[j] != 'o'&& p[i].str[j] != 'u' && p[i].str[j] != 'U') {
				cnt++; //자음일때 카운팅
			}
		}
		p[i].cnt = cnt;// 카운트한걸 구조체에 대입
	}

	for (q = p + n; q >= p; q--) {
		for (k = p; k < q - 1; k++) {
			if (k->cnt < (k+1)->cnt) {
				tmp = *k;
				*k = *(k+1);
				*(k+1) = tmp;
			}
		}
	} //내림차순 정렬

	for (int i = 0; i < n; i++) {
		printf("%s\n", p[i].str);
	} //출력

	for (int i = 0; i < n; i++) {
		free(p[i].str);
	} //free 할당해제
	free(p); //free 할당해제

	return 0;
}