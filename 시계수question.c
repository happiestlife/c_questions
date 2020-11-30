#include<stdio.h>
int* lineup(int* array);
int making(int* array, int i);		//1000���ڸ��� �����
int compare(int* array);			//���� ���� �ð�����ϱ�
void check(int* array, int num);	// �ð������ ���� �ð���� ã��
int main() {
	int factor[4];
	int n[4];

	puts("4���� ���� �Է��Ͻÿ�.(0�� ����)");
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &factor[i]);
		if (factor[i] == 0) {
			puts("�Է¿���");
			return -1;
		}
	}

	lineup(factor);
	for (int i = 0; i < 4; i++)		//����ī�带 �������鼭 4���� �ð���� �����
		n[i] = making(factor, i);
	check(factor, compare(n));		//4���� �ð�� �߿��� ���� ���� �ð���� ���Ѵ��� ����ã�� 

	return 0;
}

int* lineup(int* array) {
	int tmp;
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			if (array[i] > array[j]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
	return array;
}

int making(int* array, int i) {
	int num = 0;
	for (int x = 0; x < 4; x++) {
		if (i >= 4)
			i = 0;
		switch (x) {
		case 0:
			num += 1000 * array[i++];
			break;
		case 1:
			num += 100 * array[i++];
			break;
		case 2:
			num += 10 * array[i++];
			break;
		case 3:
			num += array[i++];
			break;
		}
	}
	//printf("%d \n", num);
	return num;
}

int compare(int* array) {
	int i, least = array[0];
	for (i = 1; i < 3; i++)
		if (array[i] < least)
			least = array[i];
	printf("���� ������ : %d\n", least);
	return least;
}

void check(int* array, int num) {
	int count = 0;
	int check1 = 0, check2 = 0, tmp, least_num;
	int n[4], real[1000] = { num };

	for (int i = 1111; i < num; i++) {		
		tmp = i;
		while (1) {							//���� õ���ڸ�, �����ڸ�, �����ڸ�, �����ڸ� ���ϴ� ����
			n[check1] = tmp % 10;
			if (n[check1] == 0)					//����ī�忡�� 0�� ���� ����
				break;
			tmp /= 10;
			check1++;
			if (tmp < 10) {
				n[check1] = tmp % 10;
				break;
			}
		}

		lineup(n);
		least_num = making(n, 0);
		for (int j = 0; j <= count; j++) 
			if (least_num == real[j])
				check2++;

		if (check1 == 3 && check2 == 0) 
			real[++count] = least_num;
		
		check1 = 0;
		check2 = 0;
	}
	printf("%d \n", count);
}