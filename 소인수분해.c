#include<stdio.h>
int main() {
	int i, j, num;
	int count = 0, stream = 1;
	int prime[10000] = { 2 };

	for (i = 3; i <= 10000; i++) {
		for (j = 2; j <= i - 1; j++) {
			if (i % j == 0)
				count++;
		}
		if (count == 0)
			prime[stream++] = i;
		count = 0;
	}

	for (i = 0; i < stream; i++)
		printf("%d ", prime[i]);
	printf("10000������ �Ҽ��� ������ %d�� �Դϴ�.\n", stream);

	puts("���μ������� ���� �Է��Ͻʽÿ�.");
	scanf_s("%d", &num);

	for (i = 0; i < stream; i++)
		if (num % prime[i] == 0) {
			num = num / prime[i];
			printf("%d ", prime[i--]);
			continue;
		}

	return 0;
}