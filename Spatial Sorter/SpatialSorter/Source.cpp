#include <iostream>

using namespace std;


long long int merge(long long int *l,int s, int mid, int e)
{
	long long int *temp = new long long int[e - s + 1];
	int i = s, j = mid + 1, k = 0;
	long long int count = 0;
	while (i <= mid && j <= e)
	{
		if (l[i] > l[j])
		{
			temp[k++] = l[j++];
			count += mid - i + 1;
		}
		else 
		{
			temp[k++] = l[i++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = l[i++];
	}
	while (j <= e)
	{
		temp[k++] = l[j++];
	}
	for (int x = 0; x < e - s + 1; x++)
	{
		l[s + x] = temp[x];
	}
	return count;
}
long long int merge_sort(long long int *l, int s, int e)
{
	if (e <= s)
	{
		return 0;
	}
	int mid = (s + e) / 2;
	long long int Scount = 0;
	Scount += merge_sort(l, s, mid);
	Scount += merge_sort(l, mid + 1, e);
	Scount += merge(l, s, mid, e);
	return Scount;
}


int main()
{
	int n;
	cin >> n;
	long long int *l = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	cout << merge_sort(l, 0, n - 1) % 1000000007 << endl;
	int x;
	cin >> x;
}