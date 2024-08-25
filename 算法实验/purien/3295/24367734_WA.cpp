#include<iostream>
#include<cstring>
#define TRUE  1;
#define FALSE  0;
#define UN  -1;
using namespace std;
inline int K(int x, int y)
{
	if (x == 1 && y == 1)
		return 1;
	return 0;
}
inline int A(int x, int y)
{
	if ((!x) && (!y))
		return 0;
	return 1;
}
inline int N(int x)
{
	if (!x)
		return 1;
	else return 0;
}
inline int C(int x, int y)
{
	if (x == 1 && !y)
		return 0;
	return 1;
}
inline int E(int x, int y)
{
	return x == y;
}
int check(char* str)
{
	char stack[101];
	int top = 0;
	int a, b;
	int j = 0;
	int p, q, r, s, t;
	int res = -1;
	for (p = 0; p <= 1; p++)
		for (q = 0; q <= 1; q++)
			for (r = 0; r <= 1; r++)
				for (s = 0; s <= 1; s++)
					for (t = 0; t <= 1; t++)
					{
						top = 0;
						for (int i = strlen(str) - 1; i >= 0; i--)
						{
							switch (str[i])
							{
							case 'K':
								b = stack[--top];
								a = stack[--top];
								stack[top++] = K(a, b);
								break;
							case 'A':
								b = stack[--top];
								a = stack[--top];
								stack[top++] = A(a, b);
								break;
							case 'N':
								b = stack[--top];
								stack[top++] = N(b);
								break;
							case 'C':
								b = stack[--top];
								a = stack[--top];
								stack[top++] = C(a, b);
								break;
							case 'E':
								b = stack[--top];
								a = stack[--top];
								stack[top++] = E(a, b);
								break;
							case 'p':
								stack[top++] = p;
								break;
							case 'q':
								stack[top++] = q;
								break;
							case 'r':
								stack[top++] = r;
								break;
							case 's':
								stack[top++] = s;
								break;
							case 't':
								stack[top++] = t;
								break;
							}
						}
						if (!j)
						{
							res = stack[--top];
						}
						else if (res != stack[--top])
						{
							return UN;
						}
						j++;
					}
	return TRUE;
}
int main()
{
	char  str[101];
	int len ;
	int a;
	while (scanf_s("%s", str,101)&&str[0]!='0')
	{
		a = check(str);
		if (a == -1)
			cout << "not" << endl;
		else cout << "tautology" << endl;
	}
	return 0;
}