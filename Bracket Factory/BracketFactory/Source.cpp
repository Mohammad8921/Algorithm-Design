#include <iostream>
#include <string>
using namespace std;

char right(char ch)
{
	if (ch == ')' || ch == '}' || ch == ']' || ch == '>') { return '!'; }

	if (ch == '(') { return ')'; }
	if (ch == '{') { return '}'; }
	if (ch == '[') { return ']'; }
	if (ch == '<') { return '>'; }
}
int main()
{
	int n;
	cin >> n;
	string Ps;
	cin >> Ps;
	int *c = new int[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (Ps[i + 1] == right(Ps[i]))
		{
			c[i] = i + 1;
		}
	}
	for (int j = n - 3; j >= 0; j--)
	{
		if (c[j + 1] != 0)
		{
			if (Ps[c[j + 1] + 1] == right(Ps[j]))
			{
				c[j] = c[j + 1] + 1;
			}
		}
		if ((c[c[j] + 1] > 0 && c[j] + 1 < n) && c[j] != 0)
		{
			c[j] = c[c[j] + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (c[i] != 0)
		{
			cout << c[i] - i + 1 << " ";
		}
		else
		{
			cout << c[i] << " ";
		}
	}
	cout << endl;
	int x;
	cin >> x;
}