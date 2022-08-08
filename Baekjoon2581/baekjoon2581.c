#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memmory");exit(EXIT_FAILURE);}


int main() {
	int start, end, n, flag = 0, cnt = 0, sum = 0, min = 0, val;
	scanf("%d %d", &start, &end);

	int* list = NULL;
	n = end - start + 1;
	MALLOC(list, sizeof(int) * n);

	for (int i = start; i <= end; i++) {
		list[i-start] = i;
	}

	for (int i = 0; i < n; i++) {

		flag = 0;
		if (list[i] == 1)
			flag = 1;

		for (int j = list[i] - 1; j > 1; j--)
			if (list[i] % j == 0) {
				flag = 1;
				break;
			}

		if (flag == 0) {
			cnt++;
			sum += list[i];
			if (min == 0) {
				val = list[i];
				min = 1;
			}

		}

	}
	if (sum == 0)printf("%d", -1);
	else
		printf("%d\n%d", sum, val);

}