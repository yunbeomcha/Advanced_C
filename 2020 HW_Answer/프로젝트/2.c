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
	//구조체 동적할당
	int num;
	printf("Max_num:");
	scanf("%d", &num);

	//동적할당 선언 max_num 만큼
	s = (STUDENT*)malloc(num * sizeof(STUDENT));

	//cnt는 포인터를 이용한다.
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
			//copy 주소를 다시 s로 입력
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
	//cnt만큼의 동적할당 해제 이외의 데이터에는 동적할당된 데이터가 없음
	for (i = 0; i < cnt; i++) {
		free(s[i].n);
		free(s[i].ph);
		free(s[i].day);
	}
	//구조체 동적할당
	free(s);
}

int re_gister(STUDENT p[], int *cnt, int num) {
	//조건 1 : 100 초과할 시 
	if (*cnt >= num) {
		printf("OVERFLOW\n");
		return 0;
	}

	char temp[100] = { 0 };
	STUDENT *q = p + *cnt;
	//등록
	printf("Name:");
	scanf("%s", temp);
	//temp + 1만큼 동적할당
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
	//월을 따로 뽑아서 배열로 저장
	int i, m = 0;
	
	for (i = 4; i < 6; i++) {
		chday[m++] = q->bir[i];
	}
	chday[m] = 0;

	//해당 월만큼 chday + 1 만큼 동적할당
	q->day = (char*)malloc(strlen(chday) + 1);
	strcpy(q->day, chday);
	m = 0;
	

	//조건 2 등록완료되면 해당 명수를 출력
	printf("<<%d>>\n", (*cnt) + 1);

	//조건 3 입력되는 대로 이름순 정렬
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

	//현재 등록된 인원의 정보를 출력
	STUDENT *q;
	for (q = p; q < p + *cnt; q++) {
		printf("%s %s %s\n", q->n, q->ph, q->bir);
	}
}
//구조체 주소를 반환하는 del_ete
STUDENT *del_ete(STUDENT p[], int *cnt, int num) {
	if (*cnt == 0) {
		// 인원이 없을 경우
		printf("NO MEMBER\n");
		return p;
	}
	char name[100] = { 0 };
	printf("Name:");
	scanf("%s", name);

	
	// 복사할 copy 구조체 동적할당 생성
	STUDENT *copy = (STUDENT*)malloc(num * sizeof(STUDENT));
	STUDENT *q, *x;
	x = copy;
	// 해당 이름 데이터가 같은 부분만 빼고 복사
	for (q = p; q < p + *cnt; q++) {
		if (strcmp(name, q->n) == 0) {
			continue;
		}
		else {
			*(x++) = *q;
		}
	}
	

	//지워졌으면 cnt 를 하나를 감소시키고 return 시켜 cnt 값을 바꾼다.
	--(*cnt);
	
	return copy;
	//copy의 주소 반환
}

void fbirth(STUDENT p[], int *cnt) {
	STUDENT *q;
	int month;
	printf("Birth:");
	scanf("%d", &month);

	//숫자로 바꿔서 입력된 달과 비교하여 같으면 출력
	for (q = p; q < p + *cnt; q++) {
		if (month == atoi(q->day)) {
			printf("%s %s %s\n", q->n, q->ph, q->bir);
		}
	}
}
