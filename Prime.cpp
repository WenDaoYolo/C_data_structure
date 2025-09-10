#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
#define MAX 0x7ffffff   //定义无穷大
typedef char VertexType;
typedef int EdgeType;
typedef struct Mat_Graph {
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;


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
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = MAX;
		}
	}

	//构造上三角矩阵边的数据,技巧：先出现的结点一定和后面的结点组合过
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

	//构造下三角矩阵边的数据
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[j][i] = G->arc[i][j];

}

//打印图矩阵
void PrintGraph(Mat_Graph* G) {
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++)
			printf("%-10d ", G->arc[j][i]);
		putchar('\n');
	}
}

void Prime(Mat_Graph* G) {
	int i, j, k;
	int min;               //存储待选边中最小边的权值
	int weight[MAXSIZE];   //存储待选边
	int ver_index[MAXSIZE];//表示顶点与顶点相连的边，值代表出发点，下标代表到达点
	                       //例如ver_index[2]=1,表示顶点B与顶点C有连线，即代表边BC
	
	ver_index[0] = 0;      //从顶点A开始
	weight[0] = 0;         //已选顶点，将其标记为0即不可再选

	for (i = 1; i < G->vertex_num; i++) {
		weight[i] = G->arc[0][i];  //将顶点A相关联的边加入待选边
		ver_index[i] = 0;          //初始化顶点之间的关系，将出发点全部设置为A，即表示与顶点A相关的顶点
	}
	for (int i = 1; i < G->vertex_num; i++) {
		min = MAX;                 //初始默认将无穷作为最小边
		j = 0;
		k = 0;                     
		//找最权值的边，并与相应的顶点进行连接
		while (j < G->vertex_num) {
			if (weight[j] != 0 && weight[j] < min) {
				min = weight[j];
				k = j;             //用于存储每轮中选出的新顶点
			}
			j++;
		}
	
	printf("(%d,%d)\n", ver_index[k], k);                      //出发点与到达点相对应的坐标
	printf("%c->%c\n", G->vertex[ver_index[k]],G->vertex[k]);  //输出坐标对应的顶点

	weight[k] = 0;                                             //将已选顶点置0进行排除

	//首层遍历完成，开始寻找新的顶点路径
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

