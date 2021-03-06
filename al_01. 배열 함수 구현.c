/*

배열 관련 함수를 만들어보자.

  - 배열 이름과 모든 원소를 출력하는 함수
  - 배열의 지정된 위치에 원소를 추가하는 함수
  - 배열의 지정된 위치의 원소를 제거하는 함수
  
*/

#include <stdio.h>
#define MAX_LENGTH 100

void printArray(int a[], int len); // 원래 함수와 다른점 : char *name 매개변수를 뺏습니다.
int insertElem(int a[], int size, int index, int value);
int deleteElem(int a[], int size, int index);


void main() {
	int list[MAX_LENGTH];
	int size = 5;

	for (int j = 0; j < size; j++)
		list[j] = 10 + j * 10;

	printf("HW 1. Insert & Delete Element\n");
	printArray(list, size);
	size = insertElem(list, size, 3, 200);
	printArray(list, size);
	size = insertElem(list, size, 0, 300);
	printArray(list, size);
	size = deleteElem(list, size, 3);
	printArray(list, size);
	size = deleteElem(list, size, 0);
	printArray(list, size);
}

void printArray(int a[], int len) {

	printf("list[%d] = ", len);
	printf("{");
	for (int i = 0; i < len - 1; i++)
		printf(" %d,", a[i]);
	printf(" %d ", a[len - 1]);
	printf("}");
	printf("\n");
}
int insertElem(int a[], int size, int index, int value) {
	if (index == 0) {
		for (int i = size; i >= index; i--)
			a[i] = a[i - 1];
		a[index] = value;
		size++;
	}
	else {
		for (int i = size; i >= index; i--)
			a[i] = a[i - 1];
		a[index] = value;
		size++;
	}
}

int deleteElem(int a[], int size, int index) {
	if (index == 0) {
		for (int i = index ; i < size - 1; i++)
			a[i] = a[i + 1];
		size--;
	}
	else {
		for (int i = index + 1 ; i < size ; i++)
			a[i - 1] = a[i];
		size--;
	}
}
