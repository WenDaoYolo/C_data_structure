#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef char VertexType;
typedef int EdgeType;
typedef struct Mat_Graph {
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

//����򵥶��нṹ
int front = 0;
int rear = 0;
int queue[MAXSIZE];


//��¼�Ѿ����ʹ��Ľ��
int visited[MAXSIZE];

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
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[i][j] = 0;

	//���������Ǿ���ߵ�����,���ɣ��ȳ��ֵĽ��һ���ͺ���Ľ����Ϲ�
	//A-B,A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;
	//B-C,B-I,B-G
	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;
	//C-I,C-D
	G->arc[2][8] = 1;
	G->arc[2][3] = 1;
	//D-G,D-H,D-E,D-I
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][4] = 1;
	G->arc[3][8] = 1;
	//E-H,E-F
	G->arc[4][7] = 1;
	G->arc[4][5] = 1;
	//F-G 
	G->arc[5][6] = 1;
	//G-H
	G->arc[6][7] = 1;

	//���������Ǿ���ߵ�����
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[j][i] = G->arc[i][j];

}

//��ӡͼ����
void PrintGraph(Mat_Graph* G) {
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++)
			printf("%d ", G->arc[j][i]);
		putchar('\n');
	}
}

void BFS(Mat_Graph G) {
	int i = 0;
	visited[i] = 1;
	printf("%c\n", G.vertex[i]);
	queue[rear] = i;
	rear++;
	while (front != rear)
	{
		i = queue[front];
		front++;
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				printf("%c\n", G.vertex[j]);
				queue[rear] = j;
				rear++;
			}
		}
	}

}

int main() {
	Mat_Graph G;
	CreateGraph(&G);

	//��ʼ�������������
	for (int i = 0; i < (&G)->vertex_num; i++)
		visited[i] = 0;

	printf("Matrix Result:\n");
	PrintGraph(&G);
	putchar('\n');
	printf("BFS Result:\n");
	BFS(G);
	putchar('\n');

	return 0;
}

