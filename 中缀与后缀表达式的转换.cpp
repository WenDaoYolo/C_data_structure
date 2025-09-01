#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//中缀表达式x/(i-j)*y转为后缀表达式

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
	LeftC ,
	RightC,
	Add ,
	Sub ,
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

void PrintSymbol(ElemType symbol) {
	switch (symbol) {
	case LeftC:
		printf("(");
		break;
	case RightC:
		printf(")");
		break;
	case Add:
		printf("+");
		break;
	case Sub:
		printf("-");
		break;
	case Mul:
		printf("*");
		break;
	case Div:
		printf("/");
		break;
	default:
		break;
	}
}

void Process(char* ch) {
	Stack* s = InitStack();
	//栈底压入一个最小元素-1
	Push(s, -1);
	Symbol symbol;
	int e;
	//用两个数组分别表示各个枚举元素的栈内外优先级
	//通过枚举元素的值与数组下标进行映射，从而赋予枚举元素优先级
	//数越大优先级越高
	//栈内优先级
	int in_stack[] = {0,16,12,12,13,13};
	//栈外优先级
	int out_stack[] = {17,16,12,12,13,13};

	while ((symbol = GetContentType(ch))!=Eos) {
		if (symbol == Num)
			printf("%c", *ch);
		else if (symbol == RightC) {
			while (s->data[s->top] != LeftC)
			{
				Pop(s, &e);
				PrintSymbol(e);
			}
			Pop(s, &e);
		}
		else
		{
			if (out_stack[symbol] > in_stack[s->data[s->top]])
				Push(s, symbol);
			else
			{
				Pop(s, &e);
				PrintSymbol(e);
				Push(s, symbol);
			}
		}
		ch++;
	}
	while (s->data[s->top] != -1) {
		Pop(s, &e);
		PrintSymbol(e);
	}
}

int main() {
	char expr[] = "x/(i-j)*y";
	Stack* s = InitStack();
	printf("Before:%s\n", expr);
	printf("After:");
	Process(expr);

	return 0;
}



