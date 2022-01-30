#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

//For 150 vertices

bool func_for_check(string s1, string s2)
{
	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] = tolower(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++)
	{
		s2[i] = tolower(s2[i]);
	}
	string temp;
	int i;
	if (s1.length() + 1 == s2.length())
	{
		for (int i = 0; i < s2.length(); i++)
		{
			temp = s2;
			temp.erase(i, 1);
			if (temp == s1)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		if (s1.length() == s2.length())
		{
			for (i = 0; i < s1.length(); i++)
			{
				if (s1[i] != s2[i])
				{
					s2[i] = s1[i];
					break;
				}
			}
			if (s1 == s2 && i < s1.length())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
class Vertex
{
	friend class Graph;
public:
	Vertex(){}
private:
	string s;
};
class Graph
{
public:
	Graph(int vertices)
	{
		size = vertices;
		dist = new int*[vertices];
		for (int i = 0; i < size; i++)
		{
			dist[i] = new int[vertices];
		}
		P = new int*[vertices];
		for (int i = 0; i < size; i++)
		{
			P[i] = new int[vertices];
		}
		V = new Vertex[vertices];
	}
	void addEdges()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (func_for_check(V[i].s, V[j].s) || func_for_check(V[j].s, V[i].s))
				{
					dist[i][j] = 1;
				}
				else
				{
					if (i == j)
					{
						dist[i][j] = 0;
					}
					else
					{
						dist[i][j] = 150;
					}
				}
			}
		}
	}
	void set_p()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (dist[i][j] == 150)
				{
					P[i][j] = -1;
				}
				else
				{
					P[i][j] = i;
				}
			}
		}
	}
	int find(string temp)
	{
		for (int i = 0; i < size; i++)
		{
			if (V[i].s == temp)
			{
				return i;
			}
		}
		return -1;
	}
	void floyd_warshall()
	{
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						P[i][j] = P[k][j];
					}
				}
			}
		}
	}
	void print_path(int i, int j)
	{
		if (i == j)
		{
			cout << V[i].s << " ";
		}
		else
		{
			if (P[i][j] == -1)
			{
				cout << '*';
			}
			else
			{
				print_path(i, P[i][j]);
				cout << V[j].s << " ";
			}
		}
	}
	void assign_string_to_vertices(int id, string str)
	{
		V[id].s = str;
	}
	void print_path_q(string(*Q)[2], int q)
	{
		int index1, index2;
		for (int i = 0; i < q; i++)
		{
			index1 = find(Q[i][0]);
			index2 = find(Q[i][1]);
			if (index1 == -1 || index2 == -1)
			{
				cout << '*' << endl;
			}
			else
			{
				print_path(index1, index2);
				cout << endl;
			}

		}
	}
private:
	int **dist;
	int **P;
	Vertex *V;
	int size;
};
int main()
{
	int k, q;
	cin >> k >> q;
	string s;
	Graph g(k);
	for (int i = 0; i < k; i++)
	{
		cin >> s;
		g.assign_string_to_vertices(i, s);
	}
	g.addEdges();
	g.set_p();
	string(*Q)[2];
	Q = new string[q][2];
	for (int i = 0; i < q; i++)
	{
		cin >> Q[i][0] >> Q[i][1];
	}
	g.floyd_warshall();
	g.print_path_q(Q, q);
	int x;
	cin >> x;

}