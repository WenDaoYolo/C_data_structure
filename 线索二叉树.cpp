#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//���������������Ĵ洢�ṹ
typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	ThreadNode* lchild;
	ThreadNode* rchild;
	int ltag;               //0��ʾ����
	int rtag;               //1��ʾ����
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
ThreadTree Prev;
int idx = 0;

//�����prev��ȫ�ֱ�����ÿ�α�����һ���ڵ��Ͱѽ�㸳ֵ��prev
// ��������Ͱ����һ������ֵ��ֵ��prev��
//���黭ͼ��ϴ�����һ�����̣����������


void CreateThreadTree(ThreadTree* T){
	ElemType ch;
	ch= str[idx++];
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));   //��Ҫ�޸�ָ�뱾���ָ��ʹ��ǰָ��ָ���¿��ٵĿռ�
		(*T)->data = ch;

		CreateThreadTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
			(*T)->ltag = 0;

		CreateThreadTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
			(*T)->rtag = 0;
	}
}


//ʵ�־����������Ĳ���,ͬ�������޸�ָ�뱾��
void threading(ThreadTree T) {
	if (T != NULL) {
		threading(T->lchild);
		if (T->lchild == NULL)    //��һ��Prevָ��ͷ��㣬������ߵ�ͷ�ǻ��õ�һ�����Tָ��ͷ���
		{
			T->ltag = 1;
			T->lchild=Prev;
		}
		if (Prev->rchild == NULL)       
		{
			Prev->rtag = 1;
			Prev->rchild = T;     //����һ�����Ŀ�ָ��ָ������
			                      //��һ��Prevָ��ͷ��㣬����ͷ�����ָ���ָ��ǰ���(��һ�����)�������Ҫ����
		}
		Prev = T;                 //��һ��,�Ὣ��һ����㸳ֵ��Prev
		threading(T->rchild);
	}
}

//����������������������Ҫ�޸�����ָ�뱾�������������ָ��
void InOrderThreading(ThreadTree T,ThreadTree* head) { 
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag=0;
	(*head)->rtag = 1;
	(*head)->rchild = *head;   //û�н��б����޷���ȡ���һ����㣬������������ָ��ָ���Լ�
	if (T == NULL)             //�ж��Ƿ�Ϊ����
		(*head)->lchild = (*head);
	else
	{
		(*head)->lchild = T;
		Prev = (*head);        //ͷ����ǵ�һ�������Ľ�㣬������Prev��ָ��ͷ���
		threading(T);

		Prev->rchild = (*head);//���һ������������
		Prev->rtag = 1;
		(*head)->rchild = Prev;//ͷ������ָ��ָ�����һ�����
	}
}



//������������
//ԭ����ͨ���ݹ�ķ�ʽ�����ݵ��������ʵ�λ�ã�����ͨ�����������ݵ��������ʵ�λ��
//���������������û������������ʣ���������˵��һ���Ѿ����ʵ�ͷ�ˣ���������������һ���������һ�߼�������
//����ֱ���ص�ͷ���

void InOrder(ThreadTree T) {
	ThreadTree curr;
	curr = T->lchild;
	while (curr != T) {
		while (curr->ltag == 0) {
			curr = curr->lchild;
		}
		printf("%c ", curr->data);
		while (curr->rtag == 1 && curr->rchild != T) {
			curr = curr->rchild;               //����
			printf("%c ", curr->data);
		}
		curr = curr->rchild;                   //���ұ��н�
	}
}






int main() {
	//������ķ�ʽ������������������ķ�ʽ��������������Ȼ�������������������

	//����ͷ���
	ThreadTree head;

	//��������������
	ThreadTree T;
	CreateThreadTree(&T);
	//����������
	InOrderThreading(T, &head);
	//������������
	InOrder(head);

	return 0;
}

