void ShortestPath_Floyed(AMGraph G)
{
	int i, j, k, n = G.vexnum;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			D[i][j] = G.arcs[i][j];
			if (D[i][j] < MaxInt && i != j)
				Path[i][j] = i;
			else
				Path[i][j] = -1;
		}
	}
	for (k = 0; k < n; ++k)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j]; // 更新最短距离
					Path[i][j] = Path[k][j];	 // 更改路径
				}
			}
		}
	}
}