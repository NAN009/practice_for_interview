#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ComputeTheLastWord(string str)
{
	if (str.empty())
		return 0;
	bool b = false;
	int count = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			b = true;
			count++;
		}
		if (str[i] == ' '&&b)
			break;

	}
	return count;
}
string StrSort(string str)
{
	vector<int> num(str.size(),0);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			num[i] = str[i] - '0';
		if (str[i] >= 'A'&&str[i] <= 'Z')
			num[i] = str[i] - 'A' + 65;
		if (str[i] >= 'a'&&str[i] <= 'z')
			num[i] = str[i] - 'a' + 97;
	}
	sort(num.begin(), num .end());
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i]>= 0&&num[i] <= 9)
			str[i] = num[i] + '0';
		if (num[i] >= 65 && num[i] <= 90)
			str[i] = num[i]-65 + 'A'; 
		if (num[i] >= 97 && num[i] <= 122)
			str[i] = num[i]-97 + 'a';
	}
	return str;
}
//×Ö·û´®¼Ó½âÃÜ
void Encrypt(char aucPassword[], char aucResult[])
{
	if (aucPassword == nullptr)
		return ;
	for (int i = 0; i < strlen(aucPassword); ++i)
	{
		if (aucPassword[i] >= 'a'&&aucPassword[i] <= 'y')
			aucResult[i] = aucPassword[i] - 32 + 1;
		else if (aucPassword[i] == 'z')
			aucResult[i] = 'A';
		else if (aucPassword[i] >= 'A'&&aucPassword[i] <= 'Y')
			aucResult[i] = aucPassword[i] + 32 + 1;
		else if (aucPassword[i] == 'Z')
			aucResult[i] = 'a';
		else if (aucPassword[i] >= '0'&&aucPassword[i] <= '8')
			aucResult[i] = aucPassword[i] + 1;
		else if (aucPassword[i] == '9')
			aucResult[i] = '0';
		else
			aucResult[i] = aucPassword[i];
	}
}
void unEncrypt(char aucResult[], char aucPassword[])
{
	for (int i = 0; i < strlen(aucPassword); ++i)
	{
		if (aucPassword[i] >= 'b'&&aucPassword[i] <= 'z')
			aucResult[i] = aucPassword[i] - 32 - 1;
		else if (aucPassword[i] == 'a')
			aucResult[i] = 'Z';
		else if (aucPassword[i] >= 'B'&&aucPassword[i] <= 'Y')
			aucResult[i] = aucPassword[i] + 31;
		else if (aucPassword[i] == 'Z')
			aucResult[i] = 'a';
		else if (aucPassword[i] >= '1'&&aucPassword[i] <= '9')
			aucResult[i] = aucPassword[i] - 1;
		else if (aucPassword[i] == '0')
			aucResult[i] = '9';
		else
			aucResult[i] = aucPassword[i];
	}
}
