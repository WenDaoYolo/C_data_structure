#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//单链表的头插法

typedef int ElemType;

typedef struct Node {
	ElemType data;
	Node* next;
}Node;

Node* initList() {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		perror("initList");
		return 0;
	}
	p->data = 0;
	p->next = NULL;
	return p;
}

void addList(Node* L, ElemType e) {
	Node* t = (Node*)malloc(sizeof(Node));
	if (t == NULL) {
		perror("addList");
	}
	t->data = e;
	t->next = L->next;
	L->next = t;
}

void DisplayList(Node* L) {
	Node* p = L->next;
	if (p == NULL) {
		perror("DisplayList");
		return;
	}
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int main() {
	Node* list = initList();
	addList(list, 10);
	addList(list, 20);
	addList(list, 30);
	DisplayList(list);
	return 0;
}