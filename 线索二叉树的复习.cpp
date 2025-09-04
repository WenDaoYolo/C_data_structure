//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
////定义线索二叉树
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
//ThreadTree Prev;
//int idx = 0;
//
////创建基础线索二叉树
//void CreateThreadTree(ThreadTree* T){
//	ElemType ch;
//	ch = str[idx++];
//	if (ch == '#')
//		*T = NULL;
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
//
////中序线索化遍历
//void InOrder(ThreadTree T){
//	ThreadTree Curr;
//	Curr = T->lchild;
//	while (Curr != T) {
//		while (Curr->ltag == 0) {
//			Curr = Curr->lchild;
//		}
//		printf("%c ", Curr->data);
//		while (Curr->rtag == 1 && Curr->rchild != T)
//		{
//			Curr = Curr->rchild;
//			printf("%c ", Curr->data);
//		}
//		Curr = Curr->rchild;
//	}
//}
//
////具体线索化步骤
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
//		threading(Prev->rchild);
//	}
//}
//
////线索化二叉树
//void InOrderThreading(ThreadTree* head,ThreadTree T) {
//	*head=(ThreadTree)malloc(sizeof(ThreadNode));
//	(*head)->ltag = 0;
//	(*head)->rtag = 1;
//	(*head)->rchild = (*head);
//	if (T == NULL)
//		(*head)->lchild = (*head);
//	else
//	{
//		(*head)->lchild = T;      //头结点的左指针指向根
//		Prev = (*head);          
//		threading(T);
//		Prev->rtag = 1;
//		Prev->rchild = (*head);   //最后一个结点的右指针指向头结点
//		(*head)->rchild = Prev;   //头结点的右指针指向最后一个结点
//	}
//}
//
//int main() {
//	ThreadTree T;
//	CreateThreadTree(&T);
//
//	ThreadTree head;
//	InOrderThreading(&head, T);
//	InOrder(head);
//
//
//	return 0;
//}
//
//
