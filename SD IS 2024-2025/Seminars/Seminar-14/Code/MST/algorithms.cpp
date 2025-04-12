#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 

class UnionFind
{
	std::vector<int> parent;
	std::vector<int> sizes;

	int UnionFind::getRoot(int n)
    {
        while (parent[n] != n)
            n = parent[n];
        return n;
    }
public:
    UnionFind::UnionFind(int n) : parent(n), sizes(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    bool UnionFind::areInOneSet(int n, int k)
    {
        return getRoot(n) == getRoot(k);
    }

    bool UnionFind::Union(int n, int k)
    {
        int root1 = getRoot(n);
        int root2 = getRoot(k);
        if (root1 == root2)
            return false;
        if (sizes[root1] > sizes[root2])
            std::swap(root1, root2);

        parent[root1] = root2;
        sizes[root2] += sizes[root1];
        return true;
    }
};

struct Edge
{
	size_t from;
	size_t to;
	int weight;

	bool operator<(const Edge& other) const
	{
		return weight < other.weight;
	}

	bool operator>(const Edge& other) const
	{
		return weight > other.weight;
	}
};

void printEdge(const Edge& e)
{
	size_t start = e.from;
	size_t dest = e.to;
	int weight = e.weight;

	std::cout << start << " " << dest << " " << weight << std::endl;
}

class Graph
{
	bool isOriented;
	size_t V;
	std::vector<std::vector<std::pair<size_t, int>>> adj;

public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end, int weight);

	size_t Prim(std::vector<Edge>& MST) const;
	size_t Kruskal(std::vector<Edge>& MST) const;
};

Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), isOriented(isOriented)
{}
void Graph::addEdge(size_t start, size_t end, int weight)
{
	adj[start].push_back(std::make_pair(end, weight));
	if (!isOriented)
		adj[end].push_back(std::make_pair(start, weight));
}

size_t Graph::Prim(std::vector<Edge>& MST) const
{
	std::priority_queue<Edge, std::vector<Edge>, std::greater<>> q;

	std::vector<bool> visited(V);

	q.push({0, 0, 0});
	size_t addedEdges = 0;
	size_t result = 0;

	bool isFirst = true;

	while (addedEdges < V - 1)
	{
		auto current = q.top();
		q.pop();

		size_t start = current.from;
		size_t dest = current.to;
		int weight = current.weight;

		if (visited[dest])
			continue;

		visited[dest] = true;

		for (int i = 0; i < adj[dest].size(); i++)
		{
			q.push({dest, adj[dest][i].first, adj[dest][i].second});
		}

		if (isFirst)
		{
			isFirst = false;
			continue;
		}

		MST.emplace_back(start, dest, weight);
		result += weight;
		addedEdges++;
		isFirst = false;
	}
	return result;

}

size_t Graph::Kruskal(std::vector<Edge>& MST) const
{

	std::vector<Edge> edges;
	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			edges.emplace_back(i, adj[i][j].first, adj[i][j].second);
	}
	std::sort(edges.begin(), edges.end());

	size_t resultMSTWeight = 0;
	size_t edgesIncluded = 0;

	UnionFind uf(V);

	for (int i = 0; i < edges.size() && edgesIncluded < V - 1; i++)
	{
		auto& currentEdge = edges[i];
		size_t start = currentEdge.from;
		size_t dest = currentEdge.to;
		int weight = currentEdge.weight;

		if (!uf.Union(start, dest))
			continue;

		resultMSTWeight += weight;

		MST.emplace_back(start, dest, weight);
	}

	return resultMSTWeight;
}


int main()
{
	Graph g(9, false);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(1, 2, 8);
	g.addEdge(7, 8, 7);
	g.addEdge(7, 6, 1);
	g.addEdge(8, 6, 6);
	g.addEdge(8, 2, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(6, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);
	g.addEdge(5, 4, 10);

	{ // Prim example
		std::vector<Edge> MST;
		std::cout << "MST(Prim): " << g.Prim(MST) << std::endl;
		std::cout << "Edges: " << std::endl;

		for (int i = 0; i < MST.size(); i++)
			printEdge(MST[i]);
		std::cout << std::endl << std::endl << std::endl;
	}

	{ // Kruskal example
		std::vector<Edge> MST;
		std::cout << "MST(Kruskal): " << g.Prim(MST) << std::endl;
		std::cout << "Edges: " << std::endl;

		for (int i = 0; i < MST.size(); i++)
			printEdge(MST[i]);
	}
}