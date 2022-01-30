#include <iostream>

using namespace std;


int main()
{
	int n;
	int q;
	cin >> n >> q;
	int *array = new int[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		cin >> array[i];
	}
	int (*indices)[2] = new int [q][2];
	for (int k = 0; k < q; k++)
	{
		cin >> indices[k][0] >> indices[k][1];
	}
	int **x = new int* [n + 2];
	for (int i = 1; i < n + 2; i++)
	{
		x[i] = new int[n + 2];
	}
	for (int i = 1; i < n + 1; i++)
	{
		x[i][i + 1] = 1;
	}
	int j;
	for (int L = 3; L < n + 2 ; L++)
	{
		for (int i = 1; i < n - L + 3; i++)
		{
			j = i + L - 1;
			if (x[i][(i + j) / 2] == 1 && x[(i + j) / 2][j] == 1 && array[(i + j) / 2 - 1] <= array[(i + j) / 2])
			{
				x[i][j] = 1;
			}
			else
			{
				x[i][j] = x[i][(i + j) / 2] + x[(i + j) / 2][j] + 1;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		cout << x[indices[i][0]][indices[i][1]] << endl;
	}
	int y;
	cin >> y;
}