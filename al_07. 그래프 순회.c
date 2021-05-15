/*

인접 행렬을 이용한 그래프 구현
  - 정점의 최대 개수는 26개이고, 'A' ~ 'Z'로 표현
  - 무방향 그래프를 가정한다.
  - 즉, 간선 (v1, v2)를 추가하면 간선 (v2, v1)도 함께 추가된다.
  - 간선은 1이상의 weight 값을 갖는다.
  - 단, weight 그래프가 아닌 경우 weight는 1의 값을 지정한다.
  - weight가 0이면 간선이 없음을 의미한다
  
  
- 위에서 구현한 그래프를 사용하여
  깊이 우선 탐색(DFS) 함수와
  너비 우선 탐색(BFS) 함수를 작성하시오.
  
*/

#include <stdio.h>
#include <stdbool.h>

#define  MAX_VERTICES  26

typedef struct _Graph {
	int nVertices;		// 정점의 개수
	int nEdges;			// 간선의 개수
	int vertex[MAX_VERTICES];
	// 그래프에 존재하는 vertex를 구분
	// ex) vertex[0] = 1 --> 정점 A 있음
	//     vertex[1] = 1 --> 정점 B 있음
	//     vertex[4] = 0 --> 정점 E 없음
	int edge[MAX_VERTICES][MAX_VERTICES];
	// 그래프에 존재하는 edge의 weight 값
	// ex) edge[0][1] = 4  --> 간선 <A, B>의 weight는 4
	//     edge[1][3] = 13 --> 간선 <B, D>의 weight는 13
	//     edge[2][1] = 0  --> 정점 C에서 B로 향하는 간선 없음
} Graph;

// Graph g를 초기화한다.
void initGraph(Graph *g)
{
	int i, j;

	g->nVertices = 0;
	g->nEdges = 0;

	for (i = 0; i < MAX_VERTICES; i++) {
		g->vertex[i] = 0;
		for (j = 0; j < MAX_VERTICES; j++)
			g->edge[i][j] = 0;
	}
}

// Graph g에 vertex v를 추가한다.
int insertVertex(Graph *g, char v)
{
	if (g->nVertices > MAX_VERTICES) {
		printf("정점의 개수 초과");
		return 0;
	}
	g->vertex[g->nVertices] = v;
	g->nVertices++;

	return -1; // SUCCESS
}

// Graph g에 v1-v2를 연결하는 edge를 추가한다. weight는 edge weight
int insertEdge(Graph *g, char v1, char v2, int weight)
{

	g->edge[v1 - 65][v2 - 65] = weight;
	g->edge[v2 - 65][v1 - 65] = weight;
	g->nEdges++;

	return -1; // SUCCESS
}

// Graph g의 vertex 리스트와 edge 리스트를 출력한다.
void printGraph(Graph *g)
{
	int i, j, n, k,l, count;
	n = 1;
	k = 0;
	printf("V(G) = ");
	printf("{ ");
	for (i = 0; i < g->nVertices - 1; i++) {
		printf("%c, ", g->vertex[i]);
	}
	printf("%c ", g->vertex[i]);
	printf("}");
	printf("\n");

	printf("E(G) = ");
	printf("{");
	i = 0;
	j = 1;
	count = 0;
	for (j = 1; j < MAX_VERTICES; j++){
		if (g->edge[i][j] != 0) {
			printf(" (%c,%c)", g->vertex[i], g->vertex[j]);
			count++;
		}
		l = j;
		if (count >= 1)
			break;
	}
	
	k = i;
	for (j = l+1; j < MAX_VERTICES; j++) {
		if (g->edge[i][j] != 0) {
			printf(", (%c,%c)", g->vertex[i], g->vertex[j]);
		}
	}
	for (i = k + 1; i < MAX_VERTICES; i++) {
		for (j = n; j <= MAX_VERTICES - 1; j++) {
			if (g->edge[i][j] != 0) {
				printf(", (%c,%c)", g->vertex[i], g->vertex[j]);
			}
		} n++;
	}
	printf(" }");
	printf("\n");
}



// 방문 이력 관리
int visited[MAX_VERTICES];

// stack 자료구조
int stack[MAX_VERTICES];
int top;

#define	INIT_STACK()	{ top = -1; }
#define IS_EMPTY()		(top == -1)
#define	PUSH(v)			{ stack[++top] = v; }
#define	POP()			(stack[top--])

// queue 자료구조
int queue[MAX_VERTICES];
int front, rear;
bool isEmpty() { if (front == rear) { return true; }
else { return false; }} // 큐가 비었는지 검사하는 함수

#define	INIT_QUEUE()	{ front = rear = -1; }
#define	ENQUEUE(v)		{ queue[++front] = v; }
#define	DEQUEUE()		((front > rear) ? queue[++rear] : -1)

// 깊이 우선 탐색(DFS: depth first search)
void depthFirstSearch(Graph *g, int v)
{
	int i = 0;
	visited[v] = 1;
	printf("%c ", g->vertex[v]);
	for (i = 0; i<MAX_VERTICES; i++) {
		if (g->edge[v][i] == 1 && visited[i] == 0) {
			depthFirstSearch(g, i);
		}
	}

}


// 너비 우선 탐색(BFS: breadth first search) 
void breadthFirstSearch(Graph *g, int v)
{
	INIT_QUEUE(queue);
	int i = 0;

	for (i; i < MAX_VERTICES; i++) {
		visited[i] = 0;
	}
	visited[v] = 1;
	printf("%c ", g->vertex[v]);
	ENQUEUE(v);
	while (!(isEmpty(queue))) {
		v = DEQUEUE();
		for (i = 0; i<MAX_VERTICES; i++) {
			if (!visited[i] && g->edge[v][i] == 1) {
				visited[i] = 1;
				ENQUEUE(i);
				printf("%c ", g->vertex[i]);
			}
		}
	}
}


void main()
{
	Graph  G;

	printf("배열로 그래프 구현 201501376 박지수\n\n");

	initGraph(&G);
	
	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');

	insertEdge(&G, 'A', 'B', 1);
	insertEdge(&G, 'A', 'D', 1);
	insertEdge(&G, 'A', 'E', 1);
	insertEdge(&G, 'B', 'C', 1);
	insertEdge(&G, 'B', 'D', 1);
	insertEdge(&G, 'C', 'D', 1);
	insertEdge(&G, 'C', 'E', 1);
	insertEdge(&G, 'D', 'F', 1);
	insertEdge(&G, 'E', 'F', 1);
	
	
	/*
	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');
	insertVertex(&G, 'G');
	insertVertex(&G, 'H');
	insertVertex(&G, 'I');

	/*
	insertEdge(&G, 'G', 'H', 1);
	insertEdge(&G, 'C', 'I', 1);
	insertEdge(&G, 'F', 'G', 1);
	insertEdge(&G, 'A', 'B', 1);
	insertEdge(&G, 'C', 'F', 1);
	insertEdge(&G, 'G', 'I', 0);
	insertEdge(&G, 'C', 'D', 1);
	insertEdge(&G, 'H', 'I', 0);
	insertEdge(&G, 'A', 'H', 1);
	insertEdge(&G, 'B', 'C', 0);
	insertEdge(&G, 'D', 'E', 1);
	insertEdge(&G, 'E', 'F', 0);
	insertEdge(&G, 'B', 'H', 0);
	insertEdge(&G, 'D', 'F', 0);
	*/

	/*
	insertEdge(&G, 'A', 'B', 1);
	insertEdge(&G, 'A', 'D', 1);
	insertEdge(&G, 'A', 'E', 1);
	insertEdge(&G, 'B', 'C', 1);
	insertEdge(&G, 'B', 'D', 1);
	insertEdge(&G, 'C', 'D', 1);
	insertEdge(&G, 'C', 'E', 1);
	insertEdge(&G, 'D', 'F', 1);
	insertEdge(&G, 'E', 'F', 1);
	
	insertEdge(&G, 'A', 'B', 1);
	insertEdge(&G, 'A', 'C', 1);
	insertEdge(&G, 'B', 'D', 1);
	insertEdge(&G, 'B', 'E', 1);
	insertEdge(&G, 'C', 'E', 1);
	insertEdge(&G, 'D', 'G', 1);
	insertEdge(&G, 'E', 'G', 1);
	insertEdge(&G, 'F', 'G', 1);

	*/
	
	




	printGraph(&G);
	printf("\n");

	printf("Depth First Search : ");
	depthFirstSearch(&G, 0);
	printf("\n");
	printf("Breadth First Search : ");
	breadthFirstSearch(&G, 0);
	printf("\n");
	printf("\n");
}
