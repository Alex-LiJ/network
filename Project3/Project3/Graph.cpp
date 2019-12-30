#include "Graph.h"

int Graph::getnum()
{
	return numEdges;
}

creat* Graph::getc()
{
	return &c;
}


Graph::Graph()
{
	numEdges = c.getGraph()->getsize();
}

void Graph::dijkstra(int v0) {
	int n = c.getGraph()->getsize();
	int s[200]; //判断顶点是否已被连接的数组
	int path[200];
	int minDis = 0, i = 0, j = 0, u = 0;
	int distance[200];

	for (i = 0; i <= n; i++) {
		distance[i] = c.getGraph()->arcArr[v0 - 1][i];
		s[i] = 0;
		if (i != v0 - 1 && distance[i] < infinity)
			path[i] = v0 - 1;
		else
			path[i] = -1;
	}

	s[v0 - 1] = 1;
	distance[v0 - 1] = 0;
	//在当前还未找到最短路径的顶点集中选取最短距离的顶点
	for (int o = 0; o < n; ++o) {
		minDis = infinity;
		u = -1;
		for (int a = 0; a < n; ++a) {

			if (s[a] == 0 && distance[a] < minDis) {
				u = a;
				minDis = distance[a];
			}
		}
		if (u == -1)
			break;
		s[u] = 1;
		for (int x = 0; x <= n; ++x) {
			if (s[x] == 0 && c.getGraph()->arcArr[u][x] < infinity && (distance[u] + c.getGraph()->arcArr[u][x]) <= distance[x]) {
				distance[x] = distance[u] + c.getGraph()->arcArr[u][x];
				path[x] = u;
			}
		}

	}



	j = 0;
	i = 0;
	cout << "目的路由器  下一跳路由器  距离" << endl;
	for (; i < n; i++) {
		if (i == v0 - 1) {
			cout << c.getGraph()->fsearch(v0) << "          " << "base sever" << "       " << 0 << endl;
		}
		if (i == v0 - 1)
			i++;
		j = i;
		while (path[j] != v0 - 1) {
			j = path[j];
			if (j == -1)
				break;
		}
		if (i + 1 <= getc()->getGraph()->getsize()) {
			cout << c.getGraph()->fsearch(i + 1) << "              " << c.getGraph()->fsearch(j + 1) << "            " << distance[i] << endl;
		}

	}
}