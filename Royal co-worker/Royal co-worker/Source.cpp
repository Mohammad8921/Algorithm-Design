#include <iostream>
using namespace std;
int Max_Javad_Pick_Paper(int **x, int *t, int curr_paper_index, int free_time)
{
	if (curr_paper_index == 0)
	{
		if (free_time < 0)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		if (x[curr_paper_index][free_time] != -1)
		{
			return x[curr_paper_index][free_time];
		}
		int E = Max_Javad_Pick_Paper(x, t, curr_paper_index - 1, t[curr_paper_index]);
		int a = free_time - t[curr_paper_index];
		int p = curr_paper_index - 1;
		while (a < 0 && p > 0)
		{
				a += t[p];
				p--;
		}
		int JJ = Max_Javad_Pick_Paper(x, t, p, a) + 1;
		if (JJ >= E)
		{
			return x[curr_paper_index][free_time] = JJ;
		}
		else
		{
			return x[curr_paper_index][free_time] = E;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int *t = new int[n];
	for (int i = 0; i < n ; i++)
	{
		cin >> t[i];
	}
	int **x = new int*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int[2001];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2001; j++)
		{
			x[i][j] = -1;
		}
	}
	cout << Max_Javad_Pick_Paper(x, t, n - 1, 0);
	int y;
	cin >> y;
}