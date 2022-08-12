#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memmory");exit(EXIT_FAILURE);}


int main() {
	int n;
	int** data = NULL;
	int* cnt = NULL;

	scanf("%d", &n);
	MALLOC(data, sizeof(int*) * n);
	MALLOC(cnt, sizeof(int) * n);


	for (int i = 0; i < n; i++) {
		cnt[i] = 0;

		MALLOC(data[i], sizeof(int) * 2);
		scanf("%d %d", &data[i][0], &data[i][1]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (data[i][0] < data[j][0] && data[i][1] < data[j][1])
				cnt[i]++;
		}
	}

	




	for (int i = 0; i < n; i++) {
		printf("%d ", cnt[i] + 1);
	}

	return 0;

}