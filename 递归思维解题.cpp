#define _crt_secure_no_warnings 1
#include<stdio.h>

float value = 0;
int returnresult(int n) {
	if (n == 0)
		return 1;
	else
	{
		int k = (returnresult(n - 1) * n);
		value +=(1.0 / k);                 
		return k;
	}
}

int main() {
	int n=0;
	printf("please input the n:");
	scanf("%d", &n);
	returnresult(n);
	printf("result:%f\n", value);
	return 0;
}