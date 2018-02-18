
//https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include<stdio.h>
#include<limits.h>
#include<iostream>
using namespace std;
//图的顶点个数
#define V 9

/*
定义一个方法，用来从还没被走过的顶点集合中，
寻找具有最小距离值得顶点
*/
int minDistance(int dist[], bool sptSet[]){

	//初始化最小值
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++){
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	}

	return min_index;
}
/*
定义一个方法，用来输出数组中的信息
*/

void printSolution(int dist[], int n){

	cout << "顶点距离\n";
	for (int i = 0; i < V; i++){
		cout << i << "\t" << dist[i] << endl;
	}

}
/*
计算最短路径的方法实现
*/
void dijkstra(int graph[V][V], int src){

	//这个数组用来保存从源点到每个顶点的最短路径
	int dist[V];
	//定义数组，若为true表示源点到该点的最短距离已经找到哦
	bool sptSet[V];
	//数组数据初始化
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX, sptSet[i] = false;
	}

	//源点到自身的距离总是零
	dist[src] = 0;
	//找到到所有点的最短路径
	for (int count = 0; count < V - 1; count++){

		//找到到下个顶点的最短距离的顶点
		int u = minDistance(dist, sptSet);
		//标记已经被访问
		sptSet[u] = true;
	    //距离数据更新
		for (int v = 0; v < V; v++)
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];


	}

	printSolution(dist, V);
}

int main(){

	int graph[V][V] = { {0,4,0,0,0,0,0,8,0},
	                    {4,0,8,0,0,0,0,11,0},
						{0,8,0,7,0,4,0,0,2},
						{0,0,7,0,9,14,0,0,0},
						{0,0,0,9,0,10,0,0,0},
						{0,0,4,14,10,0,2,0,0},
						{0,0,0,0,0,2,0,1,6},
						{8,11,0,0,0,0,1,0,7},
						{0,0,2,0,0,0,6,7,0}
	                     };

	//从0号顶点开始寻找到每个顶点的最短距离
	dijkstra(graph,0);

	system("pause");

	return 0;
}