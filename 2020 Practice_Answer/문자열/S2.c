#pragma warning (disable:4996)
#include <stdio.h>
int main() {
	char str[10];
	int n, temp;
	scanf("%s", str);
	for (int i = 10; i >= 0; i--) {
		if(str[i] >= '0' && str[i] <= '9')
		printf("%d", str[i] - '0');
	}
}