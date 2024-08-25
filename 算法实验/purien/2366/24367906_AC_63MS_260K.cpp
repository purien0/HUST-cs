#include<iostream>
#include <string.h> 
using namespace std;
int main()
{
	int m, n;
	scanf("%d",&m);
	int x;
	short nump[32769];
	memset(nump, 0, sizeof(short) * 32769);
	short numn[32769];
	memset(numn, 0, sizeof(short) * 32769);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		if (x >= 0)
			nump[x] = 1;
		else
			numn[-x] = 1;
	}
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		if (10000-x>=0)
		{
			if (nump[10000 - x])
			{
				printf("YES");
				return 0;
			}
		}
		else
		{
			if (numn[x-10000])
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}
