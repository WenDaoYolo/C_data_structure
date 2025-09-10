#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
#define MAX 0x7ffffff   //���������
typedef char VertexType;
typedef int EdgeType;
typedef struct Mat_Graph {
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;


//����ͼ����
void CreateGraph(Mat_Graph* G) {

	//��ʼ��ͼ���������
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	//��ʼ���ߵ�����
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = MAX;
		}
	}

	//���������Ǿ���ߵ�����,���ɣ��ȳ��ֵĽ��һ���ͺ���Ľ����Ϲ�
	//A-B,A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	//B-C,B-I,B-G
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	//C-I,C-D
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	//D-G,D-H,D-E,D-I
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[3][8] = 21;
	//E-H,E-F
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	//F-G 
	G->arc[5][6] = 17;
	//G-H
	G->arc[6][7] = 19;

	//���������Ǿ���ߵ�����
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[j][i] = G->arc[i][j];

}

//��ӡͼ����
void PrintGraph(Mat_Graph* G) {
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++)
			printf("%-10d ", G->arc[j][i]);
		putchar('\n');
	}
}

void Prime(Mat_Graph* G) {
	int i, j, k;
	int min;               //�洢��ѡ������С�ߵ�Ȩֵ
	int weight[MAXSIZE];   //�洢��ѡ��
	int ver_index[MAXSIZE];//��ʾ�����붥�������ıߣ�ֵ��������㣬�±�������
	                       //����ver_index[2]=1,��ʾ����B�붥��C�����ߣ��������BC
	
	ver_index[0] = 0;      //�Ӷ���A��ʼ
	weight[0] = 0;         //��ѡ���㣬������Ϊ0��������ѡ

	for (i = 1; i < G->vertex_num; i++) {
		weight[i] = G->arc[0][i];  //������A������ı߼����ѡ��
		ver_index[i] = 0;          //��ʼ������֮��Ĺ�ϵ����������ȫ������ΪA������ʾ�붥��A��صĶ���
	}
	for (int i = 1; i < G->vertex_num; i++) {
		min = MAX;                 //��ʼĬ�Ͻ�������Ϊ��С��
		j = 0;
		k = 0;                     
		//����Ȩֵ�ıߣ�������Ӧ�Ķ����������
		while (j < G->vertex_num) {
			if (weight[j] != 0 && weight[j] < min) {
				min = weight[j];
				k = j;             //���ڴ洢ÿ����ѡ�����¶���
			}
			j++;
		}
	
	printf("(%d,%d)\n", ver_index[k], k);                      //�������뵽������Ӧ������
	printf("%c->%c\n", G->vertex[ver_index[k]],G->vertex[k]);  //��������Ӧ�Ķ���

	weight[k] = 0;                                             //����ѡ������0�����ų�

	//�ײ������ɣ���ʼѰ���µĶ���·��
	for (int j = 0; j < G->vertex_num; j++) {
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
			weight[j] = G->arc[k][j];
			ver_index[j] = k;
			}
		}
	}
}

int main() {
	Mat_Graph G;
	CreateGraph(&G);


	printf("Matrix Result:\n");
	PrintGraph(&G);
	putchar('\n');
	printf("Prime Result:\n");
	Prime(&G);
	putchar('\n');

	return 0;
}

