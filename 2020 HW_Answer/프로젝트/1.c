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
	//���� 1 : 100 �ʰ��� �� 
	if (cnt >= 100) {
		printf("OVERVIEW\n");
		return 0;
	}

	STUDENT *q = p + cnt;
	//���
	printf("Name:");
	scanf("%s", q->n);
	printf("Phone_number:");
	scanf("%s", q->ph);
	printf("Birth:");
	scanf("%s", q->bir);
	//���� 2 ��ϿϷ�Ǹ� �ش� ����� ���
	printf("<<%d>>\n", cnt + 1);

	STUDENT *ap;
	//���� 3 �ԷµǴ� ��� �̸��� ����
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

	//���� ��ϵ� �ο��� ������ ���
	STUDENT *q;
	for (q = p; q < p + cnt; q++) {
		printf("%s %s %s\n", q->n, q->ph, q->bir);
	}
}

int del_ete(STUDENT *p, int cnt) {
	if (cnt == 0) {
		 //�ο��� ���� ���
		printf("NO MEMBER\n");
		return 0;
	}
	char name[21] = { 0 };
	printf("Name:");
	scanf("%s", name);

	// �ϳ��� ��ܼ� ����
	STUDENT *q, *x;
	for (q = p; q < p + cnt; q++) {
		if (strcmp(name, q->n) == 0) {
			for (x = q; x < p + cnt; x++) {
				*x = *(x + 1);
			}
		}
	}
	//���������� cnt �� �ϳ��� ���ҽ�Ű�� return ���� cnt ���� �ٲ۴�.
	--cnt;
	return cnt;
}

void fbirth(STUDENT *p, int cnt) {
	STUDENT *q;
	int month;
	//���� ���� �̾Ƽ� �迭�� ����
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
	//���ڷ� �ٲ㼭 �Էµ� �ް� ���Ͽ� ������ ���
	for (q = p; q < p + cnt; q++) {
		if (month == atoi(q->day)) {
			printf("%s %s %s\n", q->n, q->ph, q->bir);
		}
	}
}