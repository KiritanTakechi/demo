#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

// 简单并查集
class DisjointSet
{
public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    auto find(int i) noexcept -> int
    {
        if (parent[i] != i)
        {
            parent[i] = find(parent[i]);
        }
        else
            return parent[i];
    }

    void union_sets(int x, int y) noexcept
    {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root)
        {
            return;
        }
        else if (rank[x_root] < rank[y_root])
        {
            parent[x_root] = y_root;
        }
        else if (rank[x_root] > rank[y_root])
        {
            parent[y_root] = x_root;
        }
        else
        {
            parent[y_root] = x_root;
            ++rank[x_root];
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

typedef int A;
typedef int B;
typedef int Length;
using Road = std::pair<std::pair<A, B>, Length>;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, had_roads, ans(0);
    cin >> n;

    auto ds = DisjointSet{n};

    std::priority_queue<Road, std::vector<Road>, decltype([](Road a, Road b)
                                                          { return a.second > b.second; })>
        q;

    {
        int temp;
        for (size_t i(0); i < n; i++)
            for (size_t j(0); j < n; j++)
            {
                cin >> temp;
                auto road = Road{std::make_pair(i, j), temp};
                if (i < j)
                    q.push(road);
            }
    }

    cin >> had_roads;
    {
        int a, b;
        for (size_t i(0); i < had_roads; i++)
        {
            cin >> a >> b;

            // 刚发现题目索引起始1。。。
            a--;
            b--;

            ds.union_sets(a, b);
        }
    }

    for (int i(had_roads); i < n - 1 && !q.empty(); i++)
    {
        auto road = q.top();
        q.pop();

        int a = road.first.first;
        int b = road.first.second;

        if (ds.find(a) == ds.find(b))
        {
            i--;
            continue;
        }
        else
        {
            ans += road.second;
            ds.union_sets(a, b);
        }
    }

    if (q.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}