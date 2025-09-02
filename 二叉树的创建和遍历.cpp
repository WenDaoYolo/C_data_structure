#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�������Ľṹ����
typedef char ElemType;
typedef struct TreeNode{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";//�����ݰ�����������ķ�ʽ����
int idx = 0;
                           
void CreateTree(BiTree* T) { //Ҫ�޸Ľ�㣬����㱾������һ��ָ�룬���Բ��ö���ָ��
	ElemType ch = str[idx++];
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode)); //������ķ�ʽ������
		(*T)->data = ch;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
}

void PreOrder(BiTree T){
	if (T == NULL)
		return;

		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
}

void InOrder(BiTree T) {
	if (T == NULL)
		return;

	InOrder(T->lchild);
	printf("%c ", T->data);
	InOrder(T->rchild);
}

void PosOrder(BiTree T) {
	if (T == NULL)
		return;

	PosOrder(T->lchild);
	PosOrder(T->rchild);
	printf("%c ", T->data);
}

int main() {
	BiTree T;
	CreateTree(&T);

	printf("ǰ�������");
	PreOrder(T);
	putchar('\n');

	printf("���������");
	InOrder(T);
	putchar('\n');

	printf("���������");
	PosOrder(T);
	putchar('\n');

	return 0;
}

