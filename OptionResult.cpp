#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//后缀表达式求值:"82/2+56*-"

//定义顺序栈
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	int top;
	ElemType data[MAXSIZE];
}Stack;

//栈的创建及初始化
Stack* InitStack() {
	Stack* e = (Stack*)malloc(sizeof(Stack));
	if (e == NULL)
	{
		perror("main");
		return 0;
	}
	e->top = -1;
	return e;
}

//判断栈空
int CheckStackEmpty(Stack* stack) {
	if (stack->top == -1)
	{
		printf("StackEmpty!\n");
		return 1;
	}
	else
		return 0;
}

//判断栈满
int CheckStackOverFlow(Stack* stack) {
	if (stack->top == MAXSIZE)
	{
		printf("StackOverFlow!\n");
		return 1;
	}
	else
		return 0;
}

//进栈
void Push(Stack* stack, ElemType e) {
	if (CheckStackOverFlow(stack))
		return;
	stack->top++;
	stack->data[stack->top] = e;
}

//出栈
void Pop(Stack* stack, ElemType* e) {
	if (CheckStackEmpty(stack))
		return;
	*e = stack->data[stack->top];
	stack->top--;
}

//销毁栈
void DestroyStack(Stack* stack) {
	free(stack);
	stack = NULL;
}

//显示栈元素
void DisplayContent(Stack* stack) {
	int position = stack->top;
	while (position != -1) {
		printf("%d ", stack->data[position]);
		position--;
	}
	printf("\n");
}

//定义表达式元素类型
typedef enum {
	LeftC,
	RightC,
	Add,
	Sub,
	Mul,
	Div,
	Num,
	Eos
}Symbol;

//获取表达式元素类型
Symbol GetContentType(char* ch) {
	switch (*ch) {
	case '(':
		return LeftC;
	case ')':
		return RightC;
	case '+':
		return Add;
	case '-':
		return Sub;
	case '*':
		return Mul;
	case '/':
		return Div;
	case '\0':
		return Eos;
	default:
		return Num;
	}
}

//处理表达式
int Process(Stack* stack,char* ch) {
	Symbol symbol;
	int pos1, pos2,result;
	while ((symbol = GetContentType(ch)) != Eos) {
		if (symbol == Num)
			Push(stack, *ch - '0');
		else if(symbol!=LeftC&&symbol!=RightC)
		{
			Pop(stack, &pos1);
			Pop(stack, &pos2);
			switch (symbol) {
			case Add:
				Push(stack, pos2 + pos1);
				break;
			case Sub:
				Push(stack, pos2 - pos1);
				break;
			case Mul:
				Push(stack, pos2 * pos1);
				break;
			case Div:
				Push(stack, pos2 / pos1);
				break;
			default:
				break;
			}
		}
		ch++;
	}
	Pop(stack, &result);
	return result;
}

int main(){
	char expr[] = "82/2+56*-";
	Stack* s=InitStack();
	int result=Process(s, expr);
	printf("Final Result:%d\n", result);
	DestroyStack(s);

	return 0;
}


