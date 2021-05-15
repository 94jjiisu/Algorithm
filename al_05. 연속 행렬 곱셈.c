/*

동적 계획 알고리즘으로 연속 행렬 곱셈 문제를 구현하시오.
  - 알고리즘에 따라 최소 곱셈회수만 구하면 된다.
  
*/

#include <stdio.h>
#include<limits.h>
#define INFY 999999999 // 무한값 설정
// 배열,번수 선언
long int m[20][20]; // 최종 계산 결과가 담길 배열
int s[20][20];
int p[20]; //곱셈관련 정보가 들어있는 배열
int i, j;
int n; // 배열의 개수

// 행렬 곱셈을 하는 함수
void MatrixChain(void);
// 각 과정마다 곱셈회수를 계산하는 함수
int MatrixChain2(int p[], int i, int j);
// 곱셈 표를 그리는 함수 - 5자리까지 모양 유지 가능
int DrawChart(int i, int j, int n);

void main()
{
	printf("Chained Matrix Multiplications 201510376 박지수\n\n");
	int k;
	printf("# of Matrices : ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
		{
			m[i][i] = 0;
			m[i][j] = INFY;
			s[i][j] = 0;
		}
	printf("Enter d0 d1 ... d%d : ", n);
	for (k = 0; k <= n; k++)
	{
		scanf_s("%d", &p[k]);
	}
	MatrixChain();
	printf("\n");

	printf("Problem is ");
	for (i = 0; i < n-1; i++) {
		printf("[%d:%d]x", p[i],p[i+1]);
	}
	printf("[%d:%d]", p[n-1], p[n]);
	printf("\n");
	printf("\n");

	// 표 출력
	DrawChart(i,j,n);

	printf("\n");
	//최소 계산 회수 출력
	printf("Final solution is : %d \n",
		MatrixChain2(p, 1, n));

}
void MatrixChain(void)
{
	long int q;
	int k;
	for (i = n; i>0; i--) {
		for (j = i; j <= n; j++) {
			if (i == j)
				m[i][j] = 0;
			else {
				for (k = i; k<j; k++) {
					q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
					if (q<m[i][j]) {
						m[i][j] = q;
						s[i][j] = k;
					}
				}
			}
		}
	}
}

int MatrixChain2(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k <j; k++)
	{
		count = MatrixChain2(p, i, k) +
			MatrixChain2(p, k + 1, j) +
			p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}
	return min;
}

int DrawChart(int i, int j, int n)
{
	printf("   C   ");
	for (j = 1; j < n + 1; j++) {
		printf("[ %d ] ", j);
	}
	printf("\n");
	for (i = 1; i < n + 1; i++) {
		printf(" [ %d ] ", i);
		for (j = 1; j < n + 1; j++) {
			printf("%5d ", m[i][j]);
		}
		printf("\n");
	}
}
