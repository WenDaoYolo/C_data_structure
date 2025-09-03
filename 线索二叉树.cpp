#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//定义线索二叉树的存储结构
typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	ThreadNode* lchild;
	ThreadNode* rchild;
	int ltag;               //0表示孩子
	int rtag;               //1表示线索
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
ThreadTree Prev;
int idx = 0;

//这里的prev是全局变量，每次遍历过一个节点后就把结点赋值给prev
// 最后遍历完就把最后一个结点的值赋值给prev了
//建议画图配合代码走一遍流程，更便于理解


void CreateThreadTree(ThreadTree* T){
	ElemType ch;
	ch= str[idx++];
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));   //需要修改指针本身的指向，使当前指针指向新开辟的空间
		(*T)->data = ch;

		CreateThreadTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
			(*T)->ltag = 0;

		CreateThreadTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
			(*T)->rtag = 0;
	}
}


//实现具体线索化的步骤,同理无需修改指针本身
void threading(ThreadTree T) {
	if (T != NULL) {
		threading(T->lchild);
		if (T->lchild == NULL)    //第一次Prev指向头结点，当左边走到头是会让第一个结点T指向头结点
		{
			T->ltag = 1;
			T->lchild=Prev;
		}
		if (Prev->rchild == NULL)       
		{
			Prev->rtag = 1;
			Prev->rchild = T;     //让上一个结点的空指针指向其后继
			                      //第一次Prev指向头结点，所以头结点右指针会指向当前结点(第一个结点)，最后需要处理
		}
		Prev = T;                 //第一次,会将第一个结点赋值给Prev
		threading(T->rchild);
	}
}

//具体线索化二叉树，不需要修改树中指针本身，所以无需二级指针
void InOrderThreading(ThreadTree T,ThreadTree* head) { 
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag=0;
	(*head)->rtag = 1;
	(*head)->rchild = *head;   //没有进行遍历无法获取最后一个结点，所以先让其右指针指向自己
	if (T == NULL)             //判断是否为空树
		(*head)->lchild = (*head);
	else
	{
		(*head)->lchild = T;
		Prev = (*head);        //头结点是第一个遍历的结点，所以让Prev先指向头结点
		threading(T);

		Prev->rchild = (*head);//最后一个结点的线索化
		Prev->rtag = 1;
		(*head)->rchild = Prev;//头结点的右指针指向最后一个结点
	}
}



//中序线索遍历
//原来是通过递归的方式来回溯调整结点访问的位置，现在通过线索来回溯调整结点访问的位置
//不是线索则表明还没访问完继续访问，是线索则说明一边已经访问到头了，遍历完后回跳到上一层继续向另一边继续访问
//最终直至回到头结点

void InOrder(ThreadTree T) {
	ThreadTree curr;
	curr = T->lchild;
	while (curr != T) {
		while (curr->ltag == 0) {
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rtag == 1 && curr->rchild != T) {
			curr = curr->rchild;               //回跳
			printf("%c ", curr->data);
		}
		curr = curr->rchild;                   //向右边行进
	}
}






int main() {
	//以先序的方式创建二叉树，以中序的方式线索化二叉树，然后基于线索遍历二叉树

	//创建头结点
	ThreadTree head;

	//创建线索二叉树
	ThreadTree T;
	CreateThreadTree(&T);
	//具体线索化
	InOrderThreading(T, &head);
	//基于线索遍历
	InOrder(head);

	return 0;
}

