#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//二叉树的结构定义
typedef char ElemType;
typedef struct TreeNode{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";//将数据按照先序遍历的方式排列
int idx = 0;
                           
void CreateTree(BiTree* T) { //要修改结点，而结点本身又是一个指针，所以采用二级指针
	ElemType ch = str[idx++];
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode)); //以先序的方式创建树
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

	printf("前序遍历：");
	PreOrder(T);
	putchar('\n');

	printf("中序遍历：");
	InOrder(T);
	putchar('\n');

	printf("后序遍历：");
	PosOrder(T);
	putchar('\n');

	return 0;
}

