#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
	Graph(int vertices, int k)
	{
		adj = new list<int>[vertices + 1];
		dist = new int[vertices + 1];
		H = new int[k];
		set_H(k);
		N_vertices = vertices;
	}
	void set_H(int k)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> H[i];
		}
		for (int j = 0; j < k; j++)
		{
			dist[H[j]] = 0;
		}
	}
	void addEdge(int u, int v)
	{
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	void func(int k)
	{
		bool *visited = new bool[N_vertices + 1];
		for (int i = 1; i < N_vertices + 1; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < k; i++)
		{
			visited[H[i]] = true;
		}
		int u;
		queue<int> q;
		list<int>::iterator it;
		for (int i = 0; i < k; i++)
		{
			q.push(H[i]);
		}
		while (!q.empty())
		{
			u = q.front();
			q.pop();
			
			for (it = adj[u].begin(); it != adj[u].end(); it++)
			{
				if (visited[*it] == false)
				{
					q.push(*it);
					visited[*it] = true;
					dist[*it] = dist[u] + 1;
				}
			}
		}
	}
	void print()
	{
		for (int i = 1; i < N_vertices + 1; i++)
		{
			cout << dist[i] << endl;
		}
	}
private:
	list<int> *adj;
	int *dist;
	int *H;
	int N_vertices;
};
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	Graph g(n, k);
	int u, v;
	for (int j = 0; j < m; j++)
	{
		cin >> u >> v;
		g.addEdge(u, v);
	}
	g.func(k);
	g.print();
	int x;
	cin >> x;
}