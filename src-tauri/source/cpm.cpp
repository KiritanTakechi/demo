#include <bits/stdc++.h>

using namespace std;

#define MAX_LENGTH 1010

struct Edge
{
    int indexA;
    int indexB;
    int length;
};

struct Node
{
    int index;
    int length;
};

int n, m, s, t;
vector<Node> G1[MAX_LENGTH];
vector<Node> G2[MAX_LENGTH];
int inDegree1[MAX_LENGTH];
int inDegree2[MAX_LENGTH];
int dis1[MAX_LENGTH];
int dis2[MAX_LENGTH];
bool mark[MAX_LENGTH];

void read()
{
    Edge e;
    Node node;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &e.indexA, &e.indexB, &e.length);
        node.index = e.indexB;
        node.length = e.length;
        G1[e.indexA].push_back(node);
        inDegree1[e.indexB]++;
        node.index = e.indexA;
        G2[e.indexB].push_back(node);
        inDegree2[e.indexA]++;
    }
}

void reset()
{
    for (int i = 0; i <= n + 1; i++)
        G1[i].clear();
    for (int i = 0; i <= n + 1; i++)
        G2[i].clear();
    memset(inDegree1, 0, sizeof(inDegree1));
    memset(inDegree2, 0, sizeof(inDegree2));
    memset(mark, 0, sizeof(mark));
}

bool ForwardKeyPath()
{
    int num = 0;
    queue<int> q;
    memset(dis1, 0, sizeof(dis1));
    for (int i = 1; i <= n; i++)
    {
        if (inDegree1[i] == 0)
        {
            s = i;
            q.push(i);
            break;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G1[u].size(); i++)
        {
            Node v = G1[u][i];
            inDegree1[v.index]--;
            dis1[v.index] = max(dis1[v.index], v.length + dis1[u]);
            if (inDegree1[v.index] == 0)
            {
                q.push(v.index);
            }
        }
        num++;
    }
    if (num == n)
        return true;
    else
        return false;
}

bool BackKeyPath()
{
    int num = 0;
    queue<int> q;
    memset(dis2, 127, sizeof(dis2));
    for (int i = 1; i <= n; i++)
    {
        if (inDegree2[i] == 0)
        {
            q.push(i);
            t = i;
            dis2[i] = dis1[i];
            break;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G2[u].size(); i++)
        {
            Node v = G2[u][i];
            inDegree2[v.index]--;
            dis2[v.index] = min(dis2[v.index], dis2[u] - v.length);
            if (inDegree2[v.index] == 0)
            {
                q.push(v.index);
            }
        }
        num++;
    }
    if (num == n)
        return true;
    else
        return false;
}

pair<int, int> ans[MAX_LENGTH];

int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        reset();
        read();
        int cnt = 0;
        if (ForwardKeyPath() && BackKeyPath())
        {
            for (int i = 1; i <= n; i++)
                if (dis1[i] == dis2[i])
                    mark[i] = true;
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < G1[i].size(); j++)
                    if (mark[i] && mark[G1[i][j].index] && dis1[i] + G1[i][j].length == dis1[G1[i][j].index])
                        ans[++cnt] = make_pair(i, G1[i][j].index);
            sort(ans + 1, ans + cnt + 1);
            cout << dis1[t] << endl;
            for (int i = 1; i <= cnt; i++)
            {
                cout << ans[i].first << "->" << ans[i].second << endl;
            }
        }
        else
        {
            cout << "unworkable project" << endl;
        }
    }
    return 0;
}