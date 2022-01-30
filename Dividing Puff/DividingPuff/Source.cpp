#include <iostream>

using namespace std;

void compare_and_swap(long long int &m, long long int &s)
{
	if (s > m)
		swap(m, s);
}

int main()
{
	long long int M, S;
	long long int count = -1;
	cin >> M >> S;
	compare_and_swap(M, S);

	while (M != 1)
	{
		if (M == S || S == 0) 
		{ 
			cout << "impossible" << endl; 
			break; 
		}
		count += M / S;
		M = M % S;
		swap(M, S);
	}

	if(M == 1)
		cout << count << endl;
	
	int x;
	cin >> x;
}