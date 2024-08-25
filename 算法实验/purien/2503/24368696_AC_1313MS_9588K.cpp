#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
map<string, string> dict;
int main()
{
	char str[100];
	string s1, s2;
	char c;
	int i ;
	while (1)
	{
		i = 0;
		while ((c = getchar()) != ' ' && c != '\n')
		{
			if (c == '\r')
				continue;
			str[i++] = c;
		}
		str[i] = '\0';
		if (str[0] == '\0')
			break;
		s1 = string(str);
		i = 0;
		while ((c = getchar()) != ' ' && c != '\n')
		{
			if (c == '\r')
				continue;
			str[i++] = c;
		}
		str[i] = '\0';
		s2 = string(str);
		dict[s2]= s1;
	}
	while (1)
	{
		i = 0;
		while ((c = getchar()) != ' ' && c != '\n' &&c!=EOF)
		{
			if (c == '\r')
				continue;
			str[i++] = c;
		}
		if (c == EOF)
			break;
		str[i] = '\0';
		s1 = string(str);
		if (dict.find(s1) == dict.end())
			cout << "eh" << endl;
		else
			cout << dict[s1] << endl;
	}
	return 0;
}