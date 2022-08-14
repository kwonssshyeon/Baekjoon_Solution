#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memmory");exit(EXIT_FAILURE);}

int sort(int* data, int n);


int main() {
	int n, max = 0, val;
	scanf("%d", &n);
	int* data = NULL;
	int cnt[8001] = { 0 };
	int flag = 1;
	double sum = 0.0;

	MALLOC(data, sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		sum += data[i];
		cnt[data[i] + 4000]++;
	}
	val = data[0];
	sort(data, n);
	
	for (int i = 0; i < 8001; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
		}
	}

	printf("\nmax = %d\n\n", max);
	for (int i = 0; i < 8001; i++) {
		if (max == cnt[i] && flag == 1) {
			flag++;
			val = i - 4000;
		}

		else if (max == cnt[i] && flag == 2) {
			val = i-4000;
			break;
		}
	}






	printf("%d\n", sum / n>0.5?(int)(sum / n + 0.5): (int)(sum / n - 0.5));
	printf("%d\n", data[(n - 1) / 2]);
	printf("%d\n", val);
	printf("%d\n", data[n - 1] - data[0]);




	return 0;
}




int sort(int* data, int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = data[i];

		for (j = i - 1; j >= 0 && data[j] > key; j--)
			data[j + 1] = data[j];
		data[j + 1] = key;
	}
}





