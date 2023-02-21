#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    int BFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        visited[startVertex] = true;

        q.push(startVertex);

        int ctn = 0;

        while (!q.empty())
        {
            int currVertex = q.front();
            q.pop();
            ctn++;

            for (int adjVertex : adjList[currVertex])
            {
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
        return ctn;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Graph g(n);

    int cLink;
    cin >> cLink;

    for (int i = 0; i < cLink; i++)
    {
        int a, b;
        cin >> a >> b;

        g.addEdge(a - 1, b - 1);
    }

    cout << g.BFS(0) - 1;

    return 0;
}