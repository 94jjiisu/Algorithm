/*

동적 계획 방법으로 동전 거스름돈 알고리즘을 구현하시오.
  - 동전 종료의 개수를 입력받는다.
  - 동전의 액면가를 내림차순으로 입력받는다.
  - 거스름돈을 입력한다.
  - 알고리즘 실행과정을 부분 문제 20개 단위로 나누어 출력한다.
  
*/

#include <stdio.h>
#define INFI 999999  // 무한대 설정
int n; // 거스름돈 n원, 거스름돈의 액수는 최소 1원 부터 최대 99원 까지
int k; // k 개의 동전의 액면
int d[99]; // k 가 들어갈 배열
int C[99]; // 부분문제들이 들어갈 배열
int arr1[100]; // 1~100 까지를 저장할 배열

int main(void) {
	int i,j;
	
	printf("Coin Change Dynamic-Programming 201501376 박지수\n\n");

	printf("동전의 종류: ");
	scanf("%d", &k);

	printf("동전의 액면가(내림차순): "); // 액면가의 마지막 수는 반드시 1이어야 한다. 전제 조건이다. 만약 1이 포함되어 있지 않을경우
										 // 돈을 거스르지 못한 경우는 초기화 해둔 무한대 값이 출력된다.
	for (i = 0; i < k; i++) {
		scanf_s("%d", &d[i]);
	}

	while (1) {
		printf("거스름돈 액수: ");
		scanf("%d", &n);

		if ((n > 99) || (n < 1)) {
			printf("1 ~ 99 사이의 금액을 입력하시오\n");
		}
		else {
			break;
		}
	}

	printf("\n"); 

	//거스름 계산 알고리즘
	for (i = 1; i <= n; i++) {
		C[i] = INFI;
	}
	C[0] = 0;

	for (j = 1; j <= n; j++) {
		for (i = 0; i < k; i++) {
			if ((d[i] <= j) && (C[j - d[i]] + 1 < C[j]))
				C[j] = C[j - d[i]] + 1;

		}
	}

	for (i = 1; i <= n; i++)
		arr1[i] = i;

	if (n <= 20) {		// 거스름 액수가 20원 이하일 경우
		printf("j = ");
		for (i = 1; i <= n; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 1; i <= n; i++)
			printf(" %2d", C[i]);
		printf("\n");
	}

	else if (n <= 40) {		// 거스름 액수가 40원 이하일 경우
		printf("j = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 21; i <= n; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 21; i <= n; i++)
			printf(" %2d", C[i]);
		printf("\n");
	}

	else if (n <= 60) {		// 거스름 액수가 60원 이하일 경우
		printf("j = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 41; i <= n; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 41; i <= n; i++)
			printf(" %2d", C[i]);
		printf("\n");
	}

	else if (n <= 80) {		// 거스름 액수가 80원 이하일 경우
		printf("j = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 41; i <= 60; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 41; i <= 60; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 61; i <= n; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 61; i <= n; i++)
			printf(" %2d", C[i]);
		printf("\n");
	}

	else if (n <= 100) {		// 거스름 액수가 100원 이하일 경우
		printf("j = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 1; i <= 20; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 21; i <= 40; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 41; i <= 60; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 41; i <= 60; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 61; i <= 80; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 61; i <= 80; i++)
			printf(" %2d", C[i]);
		printf("\n");
		printf("\n");
		printf("j = ");
		for (i = 81; i <= n; i++)
			printf(" %2d", arr1[i]);
		printf("\n");
		printf("C = ");
		for (i = 81; i <= n; i++)
			printf(" %2d", C[i]);
		printf("\n");
	}

	printf("\n");
	printf("거스름돈 동전의 최소 개수 = %d\n", C[n]);

	return 0;
}
