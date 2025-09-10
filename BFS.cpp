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

//构造简单队列结构
int front = 0;
int rear = 0;
int queue[MAXSIZE];


//记录已经访问过的结点
int visited[MAXSIZE];

//构造图矩阵
void CreateGraph(Mat_Graph* G) {

	//初始化图的相关数据
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

	//初始化边的数据
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[i][j] = 0;

	//构造上三角矩阵边的数据,技巧：先出现的结点一定和后面的结点组合过
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

	//构造下三角矩阵边的数据
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[j][i] = G->arc[i][j];

}

//打印图矩阵
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

	//初始化顶点访问数组
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

