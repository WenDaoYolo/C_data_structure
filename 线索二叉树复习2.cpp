//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef char ElemType;
//typedef struct ThreadNode {
//	ElemType data;
//	ThreadNode* lchild;
//	ThreadNode* rchild;
//	int ltag;
//	int rtag;
//}ThreadNode;
//
//typedef ThreadNode* ThreadTree;
//
//char str[] = "ABDH##I##EJ###CF##G##";
//int idx = 0;
//ThreadTree Prev;
//
//void CreateThreadTree(ThreadTree* T) {
//	ElemType ch;
//	ch = str[idx++];
//	if (ch == '#')
//	{
//		(*T) = NULL;
//	}
//	else
//	{
//		*T = (ThreadTree)malloc(sizeof(ThreadNode));
//		(*T)->data = ch;
//		CreateThreadTree(&(*T)->lchild);
//		if ((*T)->lchild != NULL)
//			(*T)->ltag = 0;
//		CreateThreadTree(&(*T)->rchild);
//		if ((*T)->rchild != NULL)
//			(*T)->rtag = 0;
//	}
//}
//
//void InOrder(ThreadTree T){
//	ThreadTree Curr = T->lchild;
//	while (Curr != T) {
//		while (Curr->ltag == 0) {
//			Curr = Curr->lchild;
//		}
//		printf("%c ", Curr->data);
//		while (Curr->rtag == 1 && Curr->rchild != T) {
//			Curr = Curr->rchild;
//			printf("%c ",Curr->data);
//		}
//		Curr = Curr->rchild;
//	}
//}
//
//void threading(ThreadTree T) {
//	if (T != NULL) {
//		threading(T->lchild);
//		if (T->lchild == NULL)
//		{
//			T->ltag = 1;
//			T->lchild = Prev;
//		}
//		if (Prev->rchild == NULL)
//		{
//			Prev->rtag = 1;
//			Prev->rchild = T;
//		}
//		Prev = T;
//		threading(T->rchild);
//	 }
//}
//
//void InOrderThreading(ThreadTree T,ThreadTree* head) {
//	*head =(ThreadTree) malloc(sizeof(ThreadNode));
//	(*head)->ltag = 0;
//	(*head)->rtag = 1;
//	(*head)->rchild = (*head);
//	if (T == NULL) {
//		(*head)->lchild = *head;
//	}
//	else
//	{
//		(*head)->lchild = T;
//		Prev = *head;
//		threading(T);
//		Prev->rchild = *head;
//		Prev->rtag = 1;
//		(*head)->rchild = Prev;
//	}
//}
//
//
//int main() {
//	ThreadTree T;
//	ThreadTree head;
//	CreateThreadTree(&T);
//	InOrderThreading(T, &head);
//	InOrder(head);
//	return 0;
//}