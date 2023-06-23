void Prim(AMGraph G, char u)
{
    int i, j, k;
    k = LocateVex(G, u); // k为顶点u的下标
    for (j = 0; j < G.vexnum; ++j)
        if (j != k)
            closedge[j] = {u, G.arcs[k][j]}; // 初始化
    closedge[k].lowcost = 0;
    for (i = 1; i < G.vexnum; ++i)
    {
        k = Min(G);
        printf("%c->%c\n", closedge[k].adjvex, G.vexs[k]);
        closedge[k].lowcost = 0;
        for (j = 0; j < G.vexnum; ++j)
            if (G.arcs[k][j] < closedge[j].lowcost)
                closedge[j] = {G.vexs[k], G.arcs[k][j]};
    }
}