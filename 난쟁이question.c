#include<stdio.h>
int main() {
	int i, j, tmp, count = 0, sum = 0;
	int height[9];
	int result[8][2] = { 0 };

	puts("아홉 난쟁이 키 입력");
	for (i = 0; i < 9; i++) {
		scanf_s("%d", &height[i]);
		sum += height[i];
	}

	for (i = 0; i < 8; i++)
		for (j = i + 1; j < 9; j++)
			if (height[i] > height[j]) {
				tmp = height[i];
				height[i] = height[j];
				height[j] = tmp;
			}

	for (int i = 0; i < 8; i++)
		for (j = i + 1; j < 9; j++)
			if (sum - (height[i] + height[j]) == 100) {
				result[count][0] = i; result[count][1] = j;
				count++;
			}

	printf("경우의 수 : %d \n", count);
	for (i = 0; i < count - 1; i++) {
		printf("i : %d, j : %d \n", result[i][0], result[i][1]);
	}

	return 0;
}