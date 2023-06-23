#include <iostream>
using namespace std;

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

int *D = new int[MVNum];
bool *S = new bool[MVNum];
int *Path = new int[MVNum];

typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

void CreateUDN(AMGraph &G)
{
    int i, j, k;
    cin >> G.vexnum >> G.arcnum;

    for (i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vexs[i];
    }

    for (i = 0; i < G.vexnum; ++i)
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;

    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        ArcType w;
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
}

void ShortestPath_DIJ(AMGraph G, int v0);

void DisplayPath(AMGraph G, int begin, int temp)
{
    if (Path[temp] != -1)
    {
        DisplayPath(G, begin, Path[temp]);
        cout << G.vexs[Path[temp]] << "->";
    }
}

int main()
{
    AMGraph G;
    int i, j, num_start, num_destination;
    VerTexType start, destination;
    CreateUDN(G);
    cin >> start >> destination;
    num_start = LocateVex(G, start);
    num_destination = LocateVex(G, destination);
    ShortestPath_DIJ(G, num_start);
    DisplayPath(G, num_start, num_destination);
    cout << G.vexs[num_destination] << endl;
    return 0;
}
void ShortestPath_DIJ(AMGraph G, int v0)
{
    int v, i, j, min;
    int n = G.vexnum;
    for (v = 0; v < n; v++)
    {
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < MaxInt)
            Path[v] = v0;
        else
            Path[v] = -1;
    }

    S[v0] = 1;
    D[v0] = 0;
    for (i = 1; i < n; i++)
    {
        min = MaxInt;
        for (j = 0; j < n; ++j)
        {
            if (D[j] < min && !S[j])
            {
                v = j;
                min = D[j];
            }
        }

        S[v] = 1;
        for (j = 0; j < n; ++j)
        {
            if (!S[j] && (D[v] + G.arcs[v][j] < D[j]))
            {
                D[j] = D[v] + G.arcs[v][j]; // 更新D[j]
                Path[j] = v;
            }
        }
    }
}