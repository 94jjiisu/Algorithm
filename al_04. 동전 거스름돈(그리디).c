/*

그리디 알고리즘을 사용하여 동전 거스름돈 알고리즘을 구현하시오.

  - 동전의 종류를 입력받는다.(최대 10가지)
  - 거스름돈을 입력 받아 동전의 개수를 출력한다.
  - 입력 데이터는 항상 올바른 범위의 데이터가 입력된다고 가정한다.
  - 동전의 액면가는 큰 순서로 입력한다.
  - 동전의 가장 작은 액면가는 항상 1이라 가정한다.
  
*/

#include <stdio.h>
#include <stdlib.h>

//거스름 동전 종류의 최대값
#define MAX 10
//동전의 액면가를 받는 배열
int faces[MAX];
//각 액면가별 동전의 개수를 받는 배열
int number[MAX];
//거스름 동전을 하나하나 받는 배열 동전 최대 1000개
int coins[1000];


int main(void) {

	//동전 종류,액면가를 받을 변수 선언
	int n; 
	int i;
	int money;

	printf("Coin Change Greedy 201501376 박지수\n");

	//거스름 동전 종류의 개수가 1~10 사이에 있지 않을경우 다시 입력하도록 함
	while (1) {
		printf("동전의 종류(최대 10개) : ");
		scanf("%d", &n);
		
		if ((n > MAX) || (n < 1)) {
			printf("동전의 종류 개수를 다시 입력하시오\n");
		}

		else {
			break;
		}
	}
	

	printf("동전의 액면가(내림차순) : ");
	
	for (i = 0;  i < n; i++) {
		scanf_s("%d", &faces[i]);
	}

	printf("거스름돈 액수 : ");
	scanf("%d", &money);

	// 액면가별 동전의 개수를 0으로 초기화
	for (i = 0; i < MAX; i++) {
		number[i] = 0;
	}
	
	//거스름 계산을 하기 위한 변수 선언
	int change = money;

	//거스름 계산 그리디 알고리즘
	for (i = 0; i < n; i++) {
		while (change >= faces[i]) {
			change = change - faces[i];
			number[i]++;
			coins[i] = faces[i];
		
		}
	}

	for (i = 0; i < 1000; i++) {
		
		if (coins[i] == 0) {
			printf("");
		}
		//거슬러진 동전을 하나하나 출력함
		else {
			for (int j = 0; j < number[i]; j++) {
				printf(" (%d) ", coins[i]);
			}
		}
	}
	printf("\n");

	//총 동전 수 출력
	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += number[i];
	}
	printf("거스름 동전의 개수 = %d\n", sum);

}
