
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define rep(i, k, n) for (int i = k; i < (n); i++)
#define Clear(x, y) memset(x, y, sizeof(x))
using namespace std;
int num1[26], num2[26];
string s1, s2;
bool solve()
{
	Clear(num1, 0);
	Clear(num2, 0);
	int len = (int)s1.length();
	rep(i, 0, len)
	{
		num1[s1[i] - 'A']++;
		num2[s2[i] - 'A']++;
	}
	sort(num1, num1 + 26);
	sort(num2, num2 + 26);
	rep(i, 0, 26)
	{
		if (num1[i] != num2[i]) return false;
	}
	return true;
}
int main()
{
	while (cin >> s1 >> s2)
	{
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
