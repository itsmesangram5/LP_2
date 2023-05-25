#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

// depth first search algorithm and Breadth First Search algorithm

template <typename T>

class Graph
{
    // Adjacency List
    map<T, list<T>> adjList;

public:
    // Add Edge
    void addEdge(T src, T dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    void dfs(T v, map<T, bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (T n : adjList[v])
        {
            if (!visited[n])
            {
                dfs(n, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    queue<int> q;
    map<int, bool> visited;

    int ch;
    cout << "DFS Output ";

    for (int i = 0; i < 6; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited);
        }
    }

    return 0;
}