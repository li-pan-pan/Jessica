# Jessica
c语言入门练习

#include<stdio.h>
int main()
{
	//其他数都是成对出现，只有一个数出现了一次，请找出他
	int array[5] = { 1, 1, 3,3,7 };
	int i = 0;
	int ret = 0;
	while (i < 5)
	{
		ret = ret^array[i];//1^1=0,3^3=0,0^7=7
		i = i + 1;
	}
	printf("单身狗是%d\n", ret);

	

}
