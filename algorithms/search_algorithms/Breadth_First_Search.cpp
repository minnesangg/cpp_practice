#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Graph
{
private:
    unordered_map<int, unordered_set<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    vector<int> BFS(int startVertex)
    {
        vector<int> visitedOrder;
        unordered_set<int> visited;
        queue<int> queue;

        visited.insert(startVertex);
        queue.push(startVertex);

        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();
            visitedOrder.push_back(current);

            for (int neighbor : adjList[current])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        return visitedOrder;
    }
};

int main()
{
    Graph graph;

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 5);
    graph.addEdge(2, 5);

    vector<int> res = graph.BFS(0);

    cout << "BFS starting from vertex 0:" << endl;
    for (int vertex : res)
    {
        cout << vertex << " ";
    }

    return 0;
}