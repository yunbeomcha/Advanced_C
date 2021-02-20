#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
typedef struct student
{
	char name[10];
	char studentid[11];
	char grade;
}Student; //typedef로 사용자 형정의한다.
int main(void) {
	Student p[5];
	int idyear = 0, tempid = 0, flag = 0, num;
	char inputname[10]; //찾을 이름 선언
	for (int i = 0; i < 5; i++) {
		scanf("%s %s %c", p[i].name, p[i].studentid, &p[i].grade);
	} //5명의 학생이름, 학번, 학점 입력
	scanf("%s", inputname); //찾을 학생이름 입력
	for (int i = 0; i < 5; i++) {
		if (strcmp(inputname, p[i].name) == 0) { //입력한 이름과 같을 경우
			num = i; //배열의 몇번째인지 num으로 받는다.
			for (int j = 0; j < 4; j++) { //입학년도 year로 받기
				idyear *= 10;
				idyear += p[i].studentid[j] - '0';
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i == num) //i가 num과 같다면 비교를 계속
			continue;
		tempid = 0;
		for (int j = 0; j < 4; j++) { //i를 바꿔가며 입학년도 받기
			tempid *= 10;
			tempid += p[i].studentid[j] -'0';
		}
		if (idyear == tempid && p[num].grade == p[i].grade) { // 입학년도와 학번이 같으면
			printf(" %s\n", p[i].name); //해당 학생을 출력
			flag = 1; //있을경우엔 flag에 1을 넣고
		}
	}
	if (flag == 0) { //만약 없으면 flag가 0이니
		printf("0"); //0이면 0을 출력
	}
	return 0;
}