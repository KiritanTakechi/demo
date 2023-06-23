#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

class Graph
{
public:
    explicit Graph(int V) : V(V), adj(std::make_unique<std::list<int>[]>(V)) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool Kahn();

private:
    int V;
    std::unique_ptr<std::list<int>[]> adj;
};

bool Graph::Kahn()
{
    std::vector<int> in_degree(V, 0);

    for (int u(0); u < V; u++)
    {
        for (const auto &item : adj[u])
            in_degree[item]++;
    }

    std::queue<int> q;
    for (int i(0); i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    int cnt = 0;
    // 排序数组，留用
    std::vector<int> top_order;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (const auto &item : adj[u])
            if (--in_degree[item] == 0)
                q.push(item);

        cnt++;
    }

    return cnt == V;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    std::cin >> n;

    auto g = Graph{n + 1};

    for (int i(0); i < n; i++)
    {

        int m;
        cin >> m;

        while (m--)
        {
            int task;
            cin >> task;
            g.addEdge(task - 1, i);
        }
    }

    cout << static_cast<int>(g.Kahn()) << endl;

    return 0;
}