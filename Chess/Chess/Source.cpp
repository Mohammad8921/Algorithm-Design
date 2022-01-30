#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func_for_sort(pair<pair<int, int>, int> a1, pair<pair<int, int>, int> a2)
{
	return a2.second < a1.second;
}
bool canPlace(char **A,int r,int c,int row,int col)
{
	int i;
	int C, _C;
	int R, _R;
	if (A[r][c] == 'X' || A[r][c] == '1')
	{
		return false;
	}
	for ( C = c + 1; C < col; C++)
	{
		if ( A[r][C] == '1')
		{
			break;
		}
	}
	for (_C = c-1; _C > -1; _C--)
	{
		if(  A[r][_C] == '1')
		{
			break;
		}
	}
	if (C < col)
	{
		for (i = c + 1; i < C; i++)
		{
			if (A[r][i] == 'X')
			{
				break;
			}
		}
		if (i == C)
		{
			return false;
		}
	}
	if (_C > -1)
	{
		for (i = c - 1; i > _C; i--)
		{
			if (A[r][i] == 'X')
			{
				break;
			}
		}
		if (i == _C)
		{
			return false;
		}
	}

	for (R = r + 1; R < row; R++)
	{
		if (A[R][c] == '1')
		{
			break;
		}
	}
	for (_R = r - 1; _R > -1; _R--)
	{
		if (A[_R][c] == '1')
		{
			break;
		}
	}
	if (R < row)
	{
		for (i = r + 1; i < R; i++)
		{
			if (A[i][c] == 'X')
			{
				break;
			}
		}
		if (i == R)
		{
			return false;
		}
	}
	if (_R > -1)
	{
		for (i = r - 1; i > _R; i--)
		{
			if (A[i][c] == 'X')
			{
				break;
			}
		}
		if (i == _R)
		{
			return false;
		}
		
	}
	return true;
}
int func(char **A, int r, int c, int row, int col)
{
	int R_counter = 0, C_counter = 0;
	for (int C = 0; C < col; C++)
	{
		if (A[r][C] == 'X')
		{
			R_counter++;
		}
	}
	for (int R = 0; R < row; R++)
	{
		if (A[R][c] == 'X')
		{
			C_counter++;
		}
	}
	return R_counter + C_counter;
}
int main()
{
	char **A;
	char ch;
	int r, c;
	int row, col;
	int k = 0;
	cin >> row >> col;
	A = new char*[row];
	for (int i = 0; i < row; i++)
	{
		A[i] = new char[col];
	}
	vector <pair< pair<int, int>, int> > B(row*col);
	int counter = 0;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cin >> ch;
			if (ch == 'X')
			{
				A[r][c] = 'X';
			}
			else
			{
				A[r][c] = '.';
			}
		}
	}
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			B[k].first.first = r;
			B[k].first.second = c;
			B[k].second = func(A, r, c, row, col);
			k++;
		}
	}

	sort(B.begin(), B.end(), func_for_sort);

	for (int j = 0; j < B.size(); j++)
	{
		if (canPlace(A, B[j].first.first, B[j].first.second, row, col))
		{
			A[B[j].first.first][B[j].first.second] = '1';
			counter++;
		}
	}
	cout << counter << endl;
	int x;
	cin >> x;
}