/*

다음 6가지 정렬 알고리즘을 구현하여 올바로 동작하는지 확인한다.

  - 선택 정렬(Seletion Sort)
  - 버블 정렬(Bubble Sort)
  - 삽입 정렬(Insertion Sort)
  - 쉘 정렬(Shell Sort)
  - 병합 정렬(Merge Sort)
  - 퀵 정렬(Quick Sort)

입력 데이터의 크기를 1000, 2000, 3000, ... , 10000까지 늘려가며
정렬 중에 실행된 데이터 비교 횟수와 데이터 이동 횟수를 측정한다.

 데이터 비교 횟수: if문 또는 while문의 데이터 비교 부분 실행 횟수
 데이터 이동 횟수: 배열에 값을 저장하는 경우 이동 1회,
  swap으로 배열의 두 데이터를 교환하는 경우 이동 2회로 간주
  (임시 변수의 사용은 고려하지 않음)
 동일한 입력 데이터 크기에 대해 10회 측정한 결과의 평균 사용
 원소 값이 중복되지 않는 입력 데이터 사용

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//배열 원소의 개수를 정의
#define MAX 10000

//SWAP함수
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

//원본 배열
int original[MAX];

//사용 데이터 배열
int a[MAX];

//데이터 개수를 받을 변수
int n;

//합병정렬에서 사용할 데이터를 저장할 배열
int sorted[MAX];

//데이터의 이동,비교회수를 세기 위한 변수 
int move, compare;


//선택 정렬
void selectionSort(int a[], int n)
{
	int i, j, min, tmp;
	
	printf("\n");
	printf("선택 정렬\n");
	for (i = 0; i<n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++) {
			compare++;
			if (a[j] < a[min]) {			
				min = j;
			}
		}
		move += 2;
		SWAP(a[i], a[min], tmp);	
	}	
}


//버블 정렬
void bubbleSort(int a[], int n)
{
	int i, j, tmp;
	
	printf("버블 정렬\n");
	for (i = n - 1; i>0; i--)
	{
		for (j = 0; j < i; j++) {
			compare++;
			if (a[j] > a[j + 1]) {
				move += 2;
				SWAP(a[j], a[j + 1], tmp);
			}
		}
	}
}


//삽입 정렬
void insertionSort(int a[], int n)
{
	int i, pos, val;
	
	printf("삽입 정렬\n");
	for (i = 1; i<n; i++)
	{
		val = a[i];
		for (pos = i; pos > 0 ; pos--) {
			compare++;
			if (val < a[pos - 1]) {
				move++;
				a[pos] = a[pos - 1];
			}
			else
				break;
		}
		move++;
		a[pos] = val;
	}
}


//쉘 정렬 insertionSort2
insertionSort2(int a[], int first, int last, int h)
{
	int i, pos, val;

	for (i = first + h; i <= last; i = i + h) {
		val = a[i];
		for (pos = i; pos > first; pos -= h) {
			compare++;
			if (val < a[pos - h]) {
				move++;
				a[pos] = a[pos - h];
			}
			else
				break;
		}
		move++;
		a[pos] = val;
	}
}

//쉘 정렬
void shellSort(int a[], int n) 
{
	int i, h;

	for (h = n / 2; h>0; h = h / 2) {
		for (i = 0; i < h; i++) {
			insertionSort2(a, i, n - 1, h);
		}
	}
}


 //병합 정렬 merge
void merge(int a[], int m, int mid, int n)
{

	int i, j, k, l;
	i = m, j = mid + 1; k = m;

	
	while (i <= mid && j <= n) 
	{
		compare++;
		compare++;
		if (a[i] <= a[j]) {
			move++;
			sorted[k++] = a[i++];
		}
		else {
			move++;
			sorted[k++] = a[j++];
		}
	}

	compare++;
	if (i > mid) {
		for (l = j; l <= n; l++) {
			sorted[k++] = a[l];
		}
	}
	else
		for (l = i; l <= n; l++) {
			sorted[k++] = a[l];
		}

	for (l = m; l <= n; l++)
		a[l] = sorted[l];
}
//병합정렬
void mergeSort(int a[], int m, int n)
{
		int mid;

		compare++;
		if (m < n)
		{	
			move++;
			mid = (m + n) / 2;
			mergeSort(a, m, mid);
			mergeSort(a, mid + 1, n);
			merge(a, m, mid, n);
		}
}

//퀵정렬 피봇을 기준으로 분할하는 함수
int partition(int a[], int begin, int end)
{

	int pivot = a[begin], tmp, low = begin, high = end + 1;

	do {
		compare++;

		do {
			compare++;
			low++;
		}
		while (low <= end && a[low] < pivot);

		
		do {
			compare++;
			high--;
		}
		while (high >= begin && a[high]>pivot);

		compare++;
		if (low < high) {
			move += 2;
			SWAP(a[low], a[high], tmp);
		}
	} while (low<high);

	move += 2;
	SWAP(a[begin], a[high], tmp);
	return high;
}

//퀵 정렬
void quickSort(int a[], int begin, int end)
{
	compare++;
	if (begin<end)
	{
		move++;
		int pivot = partition(a, begin, end);
		quickSort(a, begin, pivot - 1);
		quickSort(a, pivot + 1, end);
	}

}

//배열 원소를 섞는 함수 (셔플)
 void Shuffle(int *arr, int num) {

	 srand(time(NULL));

	 int temp; int rn; 

	 for (int i=0; i < num; i++) { 
		 rn = rand() % (num - i) + i;
		 temp = arr[i];
		 arr[i] = arr[rn];
		 arr[rn] = temp; } 
 }


//원본 배열을 복사하는 함수
void copyArr(void)
{
	int i;
	for (i = 0; i<n; i++)
		a[i] = original[i]+1;
}


//메인함수 
//배열을 무작위로 섞고 복사하여 각 함수들이 사용하게 함
void main(void)
{
	int i;
	srand((unsigned int)time(NULL));
	n = MAX;
	for (i = 0; i <n; i++)
		original[i] = i;

	Shuffle(original, n);

	

	printf("데이터의 개수 : %d\n\n", n);

	copyArr();
	move = 0;
	compare = 0;
	selectionSort(a, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");


	copyArr();
	move = 0;
	compare = 0;
	bubbleSort(a, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");


	copyArr();
	move = 0;
	compare = 0;
	insertionSort(a, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");


	copyArr();
	move = 0;
	compare = 0;
	printf("쉘 정렬\n");
	shellSort(a, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");


	
	copyArr();
	move = 0;
	compare = 0;
	printf("병합 정렬\n");
	mergeSort(a, 0, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");


	copyArr();
	printf("퀵 정렬\n");
	move = 0;
	compare = 0;
	quickSort(a, 0, n);
	printf("compare = %d\n", compare);
	printf("move = %d\n", move);
	printf("\n");

}
