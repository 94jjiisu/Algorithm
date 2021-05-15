/*

ShortestPath 알고리즘을 구현하시오.

*/

#include <stdio.h>
#include <stdbool.h>

#define  MAX_VERTICES  26
#define INF 10000

int dist[MAX_VERTICES];  // 최단거리를 저장하는 배열
int visited[MAX_VERTICES];  // 방문 여부를 기록하는 배열

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

// 최단거리를 구하는 함수
int minDistance(Graph *g, int dist[], bool sptSet[]) {
	int min = INF;
	int min_index;

	for (int v = 0; v < g->nVertices; v++) {
		if (!sptSet[v] && min> dist[v]) {
			min_index = v;
			min = dist[v];
		}
	}
	return min_index;
}

// 다익스트라 알고리즘
void ShortestPath(Graph *g, int s) {
	int i, j,n, u, count;
	n = g->nVertices;
	bool sptSet[MAX_VERTICES];
	int cost[MAX_VERTICES][MAX_VERTICES];

	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++)
			if ((i != j) && (g->edge[i][j] == 0)) {
				g->edge[i][j] = INF;
			}
	}
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++)
			cost[i][j] = g->edge[i][j];
	}
	for (i = 0; i < g->nVertices; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < n; i++)
		dist[i] = INF, sptSet[i] = false;

	dist[s] = 0;
	visited[s] = 1;

	for (int count = 0; count < n - 1; count++) {
		int u = minDistance(g, dist, sptSet);
		for (int v = 0; v < n; v++) {
			if (!sptSet[v] && cost[u][v] && dist[u] != INF && dist[v] > dist[u] + cost[u][v]) {
				dist[v] = dist[u] + cost[u][v];
			}
		}
		sptSet[u] = true;
	}
	for (int i = 0; i< n; i++)
		printf("D(%c) = %d\n", g->vertex[i], dist[i]);
}

void main()
{
	Graph  G;

	printf("최단거리 탐색 201501376 박지수\n\n");

	initGraph(&G);
	
	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');
	insertVertex(&G, 'G');
	insertVertex(&G, 'H');
	insertVertex(&G, 'I');
	

	insertEdge(&G, 'A', 'B', 15);
	insertEdge(&G, 'A', 'C', 13);
	insertEdge(&G, 'A', 'D', 5);
	insertEdge(&G, 'B', 'C', 2);
	insertEdge(&G, 'B', 'F', 8);
	insertEdge(&G, 'C', 'D', 18);
	insertEdge(&G, 'C', 'E', 3);
	insertEdge(&G, 'C', 'F', 6);
	insertEdge(&G, 'D', 'E', 4);
	insertEdge(&G, 'D', 'I', 99);
	insertEdge(&G, 'E', 'F', 1);
	insertEdge(&G, 'E', 'G', 9);
	insertEdge(&G, 'E', 'I', 14);
	insertEdge(&G, 'F', 'G', 16);
	insertEdge(&G, 'F', 'H', 17);
	insertEdge(&G, 'G', 'H', 7);
	insertEdge(&G, 'G', 'I', 10);
	insertEdge(&G, 'H', 'I', 11);
	
	
	/*  강의자료 예시

     insertVertex(&G, 'A');                    
     insertVertex(&G, 'B');                    
     insertVertex(&G, 'C');                 
     insertVertex(&G, 'D');                     
     insertVertex(&G, 'E');                      
     insertVertex(&G, 'F');                   
     insertVertex(&G, 'G');                   
     insertVertex(&G, 'H');                  
     insertVertex(&G, 'I');                   
     insertVertex(&G, 'J');          
	
	 insertEdge(&G, 'A', 'B', 15);  
     insertEdge(&G, 'A', 'D', 12);  
     insertEdge(&G, 'B', 'C', 21);  
     insertEdge(&G, 'B', 'G', 7);  
     insertEdge(&G, 'C', 'H', 25);  
     insertEdge(&G, 'D', 'E', 4);  
     insertEdge(&G, 'D', 'F', 10);  
     insertEdge(&G, 'E', 'F', 3);  
     insertEdge(&G, 'E', 'I', 13);  
     insertEdge(&G, 'F', 'G', 10);  
     insertEdge(&G, 'G', 'H', 19);  
     insertEdge(&G, 'G', 'J', 9);  
     insertEdge(&G, 'H', 'J', 6);  
     insertEdge(&G, 'I', 'J', 15);  
	*/

	printGraph(&G);
	printf("\n");

	printf("\n");
	printf("<최단거리>\n");
	ShortestPath(&G, 0);


}
