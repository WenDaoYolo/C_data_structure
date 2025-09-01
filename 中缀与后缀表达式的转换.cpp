#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��׺���ʽx/(i-j)*yתΪ��׺���ʽ

//����˳��ջ
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	int top;
	ElemType data[MAXSIZE];
}Stack;

//ջ�Ĵ�������ʼ��
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

//�ж�ջ��
int CheckStackEmpty(Stack* stack) {
	if (stack->top == -1)
	{
		printf("StackEmpty!\n");
		return 1;
	}
	else
		return 0;
}

//�ж�ջ��
int CheckStackOverFlow(Stack* stack) {
	if (stack->top == MAXSIZE)
	{
		printf("StackOverFlow!\n");
		return 1;
	}
	else
		return 0;
}

//��ջ
void Push(Stack* stack, ElemType e) {
	if (CheckStackOverFlow(stack))
		return;
	stack->top++;
	stack->data[stack->top] = e;
}

//��ջ
void Pop(Stack* stack, ElemType* e) {
	if (CheckStackEmpty(stack))
		return;
	*e = stack->data[stack->top];
	stack->top--;
}

//����ջ
void DestroyStack(Stack* stack) {
	free(stack);
	stack = NULL;
}

//��ʾջԪ��
void DisplayContent(Stack* stack) {
	int position = stack->top;
	while (position != -1) {
		printf("%d ", stack->data[position]);
		position--;
	}
	printf("\n");
}

//������ʽԪ������
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

//��ȡ���ʽԪ������
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
	//ջ��ѹ��һ����СԪ��-1
	Push(s, -1);
	Symbol symbol;
	int e;
	//����������ֱ��ʾ����ö��Ԫ�ص�ջ�������ȼ�
	//ͨ��ö��Ԫ�ص�ֵ�������±����ӳ�䣬�Ӷ�����ö��Ԫ�����ȼ�
	//��Խ�����ȼ�Խ��
	//ջ�����ȼ�
	int in_stack[] = {0,16,12,12,13,13};
	//ջ�����ȼ�
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



