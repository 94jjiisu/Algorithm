/*

연결 리스트: 리스트를 연결 자료구조로 표현한 구조

  - 리스트 출력 printList 함수 구현
  - 마지막 노드 추가 addLastNode 함수 구현
  - 리스트 제거 freeList 함수 구현
  
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char data[20];
	struct _Node *link;
} Node;

Node *newNode(char data[]) {
	Node *p = (Node*)malloc(sizeof(Node));
	strcpy(p->data, data);
	p->link = NULL;
	return p;
}

Node *addFirstNode(Node *list, Node *p) {
	p->link = list;
	return p;
}

Node *addLastNode(Node *list, Node *p) {  // 리스트 맨 끝에 새 노드를 추가하는 함수
	Node *current = list;
	if (list == NULL) {
		list = p;
	}
	else {
		while (current->link != NULL) {
			current = current->link;
		}
		current->link = p;
	}
	return(list);
	
}


void printList(Node *list) { // 리스트 원소를 출력하는 함수
	if (list == NULL) {
		printf("NULL list");
	}
	else {
		while (list != NULL) {
			printf("[%s]->", list->data);
			list = list->link;
		}
	}
	printf("\n");
}

void freeList(Node *list) { // 리스트 제거 함수
  Node *p;
  
  while (list != NULL) {
    p = list;
    list = list ->link;
    free(p);
  }
}

void main() {
	Node *list = NULL;
  
	printList(list);
	list = addFirstNode(list, newNode("Wed"));
	printList(list);
	list = addFirstNode(list, newNode("Tue"));
	printList(list);
	list = addFirstNode(list, newNode("Mon"));
	printList(list);
	list = addLastNode(list, newNode("Thu"));
	printList(list);
	list = addLastNode(list, newNode("Fri"));
	printList(list);
  
  freeList(list);
}
