#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memory");exit(EXIT_FAILURE);}


int main() {
	int n;
	scanf("%d", &n);

	int key = 1000;
	int num = 666;
	int val = num;
	int check = 0;
	int a = 100;

	for (int i = 0; i < n; i++) {
		
		if (i ==5) {
			key = 1;
			val = num * 10-1;
			check = i;
		}
		
		if (i == check + 10 && val % 10 == 9) {
			key = 1000;
			val = val / 1000 * 1000 + num;
			check = i;
		}
		if (i == check + 9 && val % 10 == 6) {
			key = 1;
			a = 100;
			if (val / (a * 100) == 6 && val % (10 * a) / a == 6) {
				while (val / (a * 100) != 0) {
					if (val / (a * 100) == 6 && val % (10 * a) / a == 6) {
						val = val / (a * 1000) + num * a - 1;
						key = 1;
						continue;
					}

					a *= 10;
				}
			}
			else {
				val = val / 10000 * 10000 + num * 10 - 1;
				check = i;
			}
			
			
		}
		
		val += key;
		printf("%d\n", val);
	}





	return 0;
}