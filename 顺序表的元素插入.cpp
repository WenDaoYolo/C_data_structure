#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;        //定义ElemType类型是为了方便后续修改元素类型，当工程复杂时只需要修改ElemType的类型定义，使其更加通用和方便修改

typedef struct {
	ElemType data[MAXSIZE];  //定义数组来存放数据
	int length;              //统计顺序表中数据存储的个数
}SeqList;

void InsertList(SeqList* L, int pos, ElemType e) {
	                                         //其他的一些判断例如容量等暂时忽略
	if (pos <= L->length) {                  //对插入位置合法性的判断
		pos--;
		int end = L->length - 1;
		while (end >= pos) {
			L->data[end + 1] = L->data[end];
			end--;
		}
		L->data[pos] = e;
		L->length++;
	}
}