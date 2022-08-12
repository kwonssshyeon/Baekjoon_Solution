#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(p,s)if(!((p)=malloc(s))){fprintf(stderr,"insufficient memmory");exit(EXIT_FAILURE);}

int check(char** data, int col, int row);
int reverse(char** data, int col, int row);

int main() {
	int col, row;
	char** data = NULL;
	int min = 1000;
	int value, value2;

	scanf("%d %d", &col, &row);

	MALLOC(data, sizeof(char*) * col);

	int i = 0, j = 0;
	for (i = 0; i < col; i++) {
		MALLOC(data[i], sizeof(char) * row);
		for (j = 0; j < row; j++) {
			scanf("%c", &data[i][j]);
			if (data[i][j] == '\n')j--;
		}
	}

	
	for (int i = 0; i < col-7; i++)
		for (int j = 0; j < row-7; j++) {
			value = check(data, i, j);
			value2 = reverse(data, i, j);

			if (min > value) 
				min = value;
			
			if (min > value2)
				min = value2;
		}
	




	printf("%d",min);

	return 0;
}

int check(char** data, int col, int row) {
	int i = 0, j = 0;
	int cnt = 0;
	char** copy = NULL;


	MALLOC(copy, sizeof(char*) * 8);
	for (i = col; i < col + 8; i++) {
		MALLOC(copy[i - col], sizeof(char) * 8);
		for (j = row; j < row + 8; j++) {
			copy[i - col][j - row] = data[i][j];
		}
	}




	for (i = 0; i < 8; i++) {


		if (i >= 1) {
			if (copy[i - 1][0] == 'W' && copy[i][0] == 'W') {
				copy[i][0] = 'B';
				cnt++;
			}
			else if (copy[i - 1][0] == 'B' && copy[i][0] == 'B') {
				copy[i][0] = 'W';
				cnt++;
			}
		}


		for (j = 0; j < 7; j++) {

			if (copy[i][j] == 'W' && copy[i][j + 1] == 'W') {
				copy[i][j + 1] = 'B';
				cnt++;
			}
			else if (copy[i][j] == 'B' && copy[i][j + 1] == 'B') {
				copy[i][j + 1] = 'W';
				cnt++;
			}
		}

		

	}


	return cnt;

}



int reverse(char** data, int col, int row) {
	int i = 0, j = 0;
	int cnt = 0;
	char** copy = NULL;


	MALLOC(copy, sizeof(char*) * 8);
	for (i = col; i < col + 8; i++) {
		MALLOC(copy[i - col], sizeof(char) * 8);
		for (j = row; j < row + 8; j++) {
			copy[i - col][j - row] = data[i][j];
		}
	}



	if (copy[0][0] == 'W') {
		copy[0][0] = 'B';
		cnt++;
	}
	else if (copy[0][0] == 'B') {
		copy[0][0] = 'W';
		cnt++;
	}



	for (i = 0; i < 8; i++) {


		if (i >= 1) {
			if (copy[i - 1][0] == 'W' && copy[i][0] == 'W') {
				copy[i][0] = 'B';
				cnt++;
			}
			else if (copy[i - 1][0] == 'B' && copy[i][0] == 'B') {
				copy[i][0] = 'W';
				cnt++;
			}
		}


		for (j = 0; j < 7; j++) {

			if (copy[i][j] == 'W' && copy[i][j + 1] == 'W') {
				copy[i][j + 1] = 'B';
				cnt++;
			}
			else if (copy[i][j] == 'B' && copy[i][j + 1] == 'B') {
				copy[i][j + 1] = 'W';
				cnt++;
			}
		}



	}


	return cnt;

}