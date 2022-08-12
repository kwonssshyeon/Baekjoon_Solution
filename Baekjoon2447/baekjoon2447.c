#include <stdio.h>
#include <stdlib.h>


void star();


int main() {
	int n;
	scanf("%d", &n);


	star();
	
	

	return 0;
}


void star() {

	for (int i = 0; i < 3; i++) {
		printf("*");
	}puts("");
	for (int i = 0; i < 3; i++) {
		if (i == 1)printf(" ");
		else printf("*");
	}puts("");
	for (int i = 0; i < 3; i++) {
		printf("*");
	}puts("");


}