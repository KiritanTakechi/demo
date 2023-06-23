#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[18], b[18], pos[18], // a顺序存放输入散列表的序列，b按散列函数计算出的地址存放输入元素
	arr1[18], arr2[18];	   // arr1按顺序存放查找元素，arr2顺序存放输入散列表序列的各元素的冲突值
int main()
{
	int d, i, j, n, temp, m, k, count;
	// 将a,b,pos数组中的内容初始化为-1
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	memset(pos, -1, sizeof(pos));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		temp = a[i] % 17; // 用散列函数计算散列地址
		d = 1;
		while (b[temp] != -1)
		{
			temp = (a[i] % 17 + d * d) % 18; // 平方探测法解决冲突
			arr2[i] = d;
			d++;
		}
		b[temp] = a[i];
		pos[i] = temp;
	}
	scanf("%d", &m); // 输入待查找的元素个数
	for (i = 0; i < m; i++)
		scanf("%d", &arr1[i]); // 输入待查找元素
	for (i = 0; i < n; i++)
	{ // 输出顺序存入散列表的元素地址
		if (i != 0)
			printf(" ");
		printf("%d", pos[i]);
	}
	printf("\n");
	for (i = 0; i < m; i++)
	{
		count = 0;
		d = 0;
		for (j = arr1[i] % 17; j < 18; j = (arr1[i] % 17 + d * d) % 18)
		{
			d++;
			count++;
			if (arr1[i] == b[j])
			{
				for (k = 0; k < n; k++)
				{ // 在顺序输入散列表的元素中找到与b[j]相等的元素a[k]
					if (b[j] == a[k])
					{
						// 查找成功的查找次数等于该元素存放时产生冲突的次数+1
						printf("%d pos:%d,try %d\n", arr1[i], pos[k], arr2[k] + 1);
						break;
					}
				}
				break;
			}
			else if (b[j] == -1 || count == 18)
			{
				// 若查找元素应该放入散列表中的位置处没有该元素或遍历一遍散列表未发现此元素则查找失败
				printf("%d not found,try %d\n", arr1[i], count);
				break;
			}
			if (j == 18)
				j = 0; // 因为j是从arr1[i] % 17开始的，若j==18则让j从0开始继续查找
		}
	}
	system("pause");
	return 0;
}