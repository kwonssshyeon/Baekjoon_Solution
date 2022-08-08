#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memmory");exit(EXIT_FAILURE);}


int main() {
	int n, cnt = 0, flag = 0;
	int* list = NULL;
	scanf_s("%d", &n, sizeof(int));
	MALLOC(list, sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &list[i], sizeof(list[i]));

	for (int i = 0; i < n; i++) {
		flag = 0;
		if (list[i] == 1)
			flag = 1;

		for (int j = list[i] - 1; j > 1; j--)
			if (list[i] % j == 0) {
				flag = 1;
				break;
			}

		if (flag == 0)cnt++;
	}

	printf("%d", cnt);




	return 0;
}