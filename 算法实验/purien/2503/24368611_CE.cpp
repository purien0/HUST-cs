#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string, string> dict;
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
		dict.emplace(s2, s1);
		/*unordered_map<string, string>::iterator itr;
		for (itr = dict.begin();
			itr != dict.end(); itr++)
		{
			// itr works as a pointer to  
			// pair<string, double> type  
			// itr->first stores the key part and 
			// itr->second stores the value part 
			cout << itr->first << " " <<
				itr->second << endl;
		}*/
	}
	while (1)
	{
		i = 0;
		while ((c = getchar()) != ' ' && c != '\n' )
		{
			if (c == '\r')
				continue;
			if (c == EOF)
				break;
			str[i++] = c;
		}
		str[i] = '\0';
		s1 = string(str);
		if (dict.find(s1) == dict.end())
			cout << "eh" << endl;
		else
			cout << dict[s1] << endl;
	}
	return 0;
}