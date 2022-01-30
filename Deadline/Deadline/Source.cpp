#include <iostream>

using namespace std;
float indicator(int x[][3][100], int i, int k_i)
{
	float sum1 = 0;
	float sum2 = 0;
	for (int j = 0; j < k_i; j++)
	{
		sum1 += x[i][1][j];
	}
	for (int j = 0; j < k_i; j++)
	{
		sum2 += x[i][0][j];
	}
	return sum1 / sum2;
}
int find_max_1(int x[][3][100], int n, int *k)
{
	int max_i = 0;
	for (int i = 1; i < n; i++)
	{
		if (indicator(x, i, k[i]) > indicator(x, max_i, k[max_i]))
		{
			max_i = i;
		}
	}
	return max_i;
}
int find_max_2(int x[][3][100], int i, int k_i)
{
	int max_c = 0;
	for (int j = 1; j < k_i; j++)
	{
		if (((float)x[i][1][max_c] / (x[i][0][max_c])) < ((float)x[i][1][j] / (x[i][0][j])))
		{
			max_c = j;
		}
	}
	return max_c;
}
int main()
{
	int n;
	cin >> n;
	int *k = new int[n];
	int p;
	int w;
	int time = 0;
	long long int forfeit = 0;
	int sum = 0;
	int counter = 0;
	int x[500][3][100];
	for (int i = 0; i < n; i++)
	{
		cin >> k[i];
		sum += k[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			cin >> p;
			x[i][0][j] = p;
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			cin >> w;
			x[i][1][j] = w;
			x[i][2][j] = ++counter;
		}

	}
	int  index_1, index_2;
	int *answer = new int[sum];
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		index_1 = find_max_1(x, n, k);
		for (int j = 0; j < k[index_1]; j++)
		{
			index_2 = find_max_2(x, index_1, k[index_1]);
			time += x[index_1][0][index_2];
			forfeit += time * x[index_1][1][index_2];
			answer[r++] = x[index_1][2][index_2];
			x[index_1][1][index_2] = -1;
			x[index_1][0][index_2] = 1;
		}

	}
	cout << forfeit << endl;
	for (int i = 0; i < sum; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	int y;
	cin >> y;
}