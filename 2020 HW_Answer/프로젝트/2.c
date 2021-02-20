#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st {
	char *n;
	char *ph;
	char *bir;
	char *day;
}STUDENT;

int re_gister(STUDENT p[], int *cnt, int num);
void show_all(STUDENT p[], int *cnt);
STUDENT *del_ete(STUDENT p[], int *cnt, int num);
void fbirth(STUDENT p[], int *cnt);

int main() {

	STUDENT *s; 
	STUDENT copy;
	//����ü �����Ҵ�
	int num;
	printf("Max_num:");
	scanf("%d", &num);

	//�����Ҵ� ���� max_num ��ŭ
	s = (STUDENT*)malloc(num * sizeof(STUDENT));

	//cnt�� �����͸� �̿��Ѵ�.
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
			re_gister(s, &cnt, num);
			break;
			//showall
		case 2:
			show_all(s, &cnt);
			break;
			//delete
		case 3:
			//copy �ּҸ� �ٽ� s�� �Է�
			s = del_ete(s, &cnt, num);
			break;
			//findbirth
		case 4:
			fbirth(s, &cnt);
			break;
			//exit
		case 5:
			return 0;
		}
	}

	int i;
	//cnt��ŭ�� �����Ҵ� ���� �̿��� �����Ϳ��� �����Ҵ�� �����Ͱ� ����
	for (i = 0; i < cnt; i++) {
		free(s[i].n);
		free(s[i].ph);
		free(s[i].day);
	}
	//����ü �����Ҵ�
	free(s);
}

int re_gister(STUDENT p[], int *cnt, int num) {
	//���� 1 : 100 �ʰ��� �� 
	if (*cnt >= num) {
		printf("OVERFLOW\n");
		return 0;
	}

	char temp[100] = { 0 };
	STUDENT *q = p + *cnt;
	//���
	printf("Name:");
	scanf("%s", temp);
	//temp + 1��ŭ �����Ҵ�
	q->n = (char*)malloc(strlen(temp) + 1);
	strcpy(q->n, temp);

	printf("Phone_number:");
	scanf("%s", temp);
	q->ph = (char*)malloc(strlen(temp) + 1);
	strcpy(q->ph, temp);

	printf("Birth:");
	scanf("%s", temp);
	q->bir = (char*)malloc(strlen(temp) + 1);
	strcpy(q->bir, temp);

	
	char chday[3] = { 0 };
	//���� ���� �̾Ƽ� �迭�� ����
	int i, m = 0;
	
	for (i = 4; i < 6; i++) {
		chday[m++] = q->bir[i];
	}
	chday[m] = 0;

	//�ش� ����ŭ chday + 1 ��ŭ �����Ҵ�
	q->day = (char*)malloc(strlen(chday) + 1);
	strcpy(q->day, chday);
	m = 0;
	

	//���� 2 ��ϿϷ�Ǹ� �ش� ����� ���
	printf("<<%d>>\n", (*cnt) + 1);

	//���� 3 �ԷµǴ� ��� �̸��� ����
	STUDENT *r, swap;

	for (q = p; q <= p + *cnt; q++) {
		for (r = q + 1; r <= p + *cnt; r++) {
			if (strcmp(q->n, r->n) > 0) {
				swap = *q;
				*q = *r;
				*r = swap;
			}
		}
	}

	++(*cnt);
}

void show_all(STUDENT p[], int *cnt) {

	//���� ��ϵ� �ο��� ������ ���
	STUDENT *q;
	for (q = p; q < p + *cnt; q++) {
		printf("%s %s %s\n", q->n, q->ph, q->bir);
	}
}
//����ü �ּҸ� ��ȯ�ϴ� del_ete
STUDENT *del_ete(STUDENT p[], int *cnt, int num) {
	if (*cnt == 0) {
		// �ο��� ���� ���
		printf("NO MEMBER\n");
		return p;
	}
	char name[100] = { 0 };
	printf("Name:");
	scanf("%s", name);

	
	// ������ copy ����ü �����Ҵ� ����
	STUDENT *copy = (STUDENT*)malloc(num * sizeof(STUDENT));
	STUDENT *q, *x;
	x = copy;
	// �ش� �̸� �����Ͱ� ���� �κи� ���� ����
	for (q = p; q < p + *cnt; q++) {
		if (strcmp(name, q->n) == 0) {
			continue;
		}
		else {
			*(x++) = *q;
		}
	}
	

	//���������� cnt �� �ϳ��� ���ҽ�Ű�� return ���� cnt ���� �ٲ۴�.
	--(*cnt);
	
	return copy;
	//copy�� �ּ� ��ȯ
}

void fbirth(STUDENT p[], int *cnt) {
	STUDENT *q;
	int month;
	printf("Birth:");
	scanf("%d", &month);

	//���ڷ� �ٲ㼭 �Էµ� �ް� ���Ͽ� ������ ���
	for (q = p; q < p + *cnt; q++) {
		if (month == atoi(q->day)) {
			printf("%s %s %s\n", q->n, q->ph, q->bir);
		}
	}
}
