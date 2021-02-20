#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

typedef struct st {
	char n[21];
	char ph[16];
	char bir[9];
	char day[3];
}STUDENT;

void re_gister(STUDENT *p, int cnt);
void show_all(STUDENT *p, int cnt);
int del_ete(STUDENT *p, int cnt);
void fbirth(STUDENT *p, int cnt);

int main() {

	STUDENT s[MAX_NUM];
	int key, cnt = 0;

	while (1) {
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &key);

		getchar();
		switch (key) {
			//registeration
		case 1:
			re_gister(s, cnt);
			++cnt;
			break;
			//showall
		case 2:
			show_all(s, cnt);
			break;
			//delete
		case 3:
			cnt = del_ete(s, cnt);
			break;
			//findbirth
		case 4:
			fbirth(s, cnt);
			break;
			//exit
		case 5:
			return 0;
		}
	}


}

void re_gister(STUDENT *p, int cnt) {
	//조건 1 : 100 초과할 시 
	if (cnt >= 100) {
		printf("OVERVIEW\n");
		return 0;
	}

	STUDENT *q = p + cnt;
	//등록
	printf("Name:");
	scanf("%s", q->n);
	printf("Phone_number:");
	scanf("%s", q->ph);
	printf("Birth:");
	scanf("%s", q->bir);
	//조건 2 등록완료되면 해당 명수를 출력
	printf("<<%d>>\n", cnt + 1);

	STUDENT *ap;
	//조건 3 입력되는 대로 이름순 정렬
	STUDENT *r, swap;

	for (q = p; q <= p + cnt; q++) {
		for (r = q + 1; r <= p + cnt; r++) {
			if (strcmp(q->n, r->n) > 0) {
				swap = *q;
				*q = *r;
				*r = swap;
			}
		}
	}
}


void show_all(STUDENT *p, int cnt) {

	//현재 등록된 인원의 정보를 출력
	STUDENT *q;
	for (q = p; q < p + cnt; q++) {
		printf("%s %s %s\n", q->n, q->ph, q->bir);
	}
}

int del_ete(STUDENT *p, int cnt) {
	if (cnt == 0) {
		 //인원이 없을 경우
		printf("NO MEMBER\n");
		return 0;
	}
	char name[21] = { 0 };
	printf("Name:");
	scanf("%s", name);

	// 하나씩 당겨서 삭제
	STUDENT *q, *x;
	for (q = p; q < p + cnt; q++) {
		if (strcmp(name, q->n) == 0) {
			for (x = q; x < p + cnt; x++) {
				*x = *(x + 1);
			}
		}
	}
	//지워졌으면 cnt 를 하나를 감소시키고 return 시켜 cnt 값을 바꾼다.
	--cnt;
	return cnt;
}

void fbirth(STUDENT *p, int cnt) {
	STUDENT *q;
	int month;
	//월을 따로 뽑아서 배열로 저장
	int i, j, m = 0;
	for (j = 0; j < cnt; j++) {
		for (i = 4; i < 6; i++) {
			p[j].day[m++] = p[j].bir[i];
		}
		p[j].day[m] = 0;
		m = 0;
	}

	printf("Birth:");
	scanf("%d", &month);
	//숫자로 바꿔서 입력된 달과 비교하여 같으면 출력
	for (q = p; q < p + cnt; q++) {
		if (month == atoi(q->day)) {
			printf("%s %s %s\n", q->n, q->ph, q->bir);
		}
	}
}