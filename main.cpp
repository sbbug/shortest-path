
//https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include<stdio.h>
#include<limits.h>
#include<iostream>
using namespace std;
//ͼ�Ķ������
#define V 9

/*
����һ�������������ӻ�û���߹��Ķ��㼯���У�
Ѱ�Ҿ�����С����ֵ�ö���
*/
int minDistance(int dist[], bool sptSet[]){

	//��ʼ����Сֵ
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++){
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	}

	return min_index;
}
/*
����һ��������������������е���Ϣ
*/

void printSolution(int dist[], int n){

	cout << "�������\n";
	for (int i = 0; i < V; i++){
		cout << i << "\t" << dist[i] << endl;
	}

}
/*
�������·���ķ���ʵ��
*/
void dijkstra(int graph[V][V], int src){

	//����������������Դ�㵽ÿ����������·��
	int dist[V];
	//�������飬��Ϊtrue��ʾԴ�㵽�õ����̾����Ѿ��ҵ�Ŷ
	bool sptSet[V];
	//�������ݳ�ʼ��
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX, sptSet[i] = false;
	}

	//Դ�㵽����ľ���������
	dist[src] = 0;
	//�ҵ������е�����·��
	for (int count = 0; count < V - 1; count++){

		//�ҵ����¸��������̾���Ķ���
		int u = minDistance(dist, sptSet);
		//����Ѿ�������
		sptSet[u] = true;
	    //�������ݸ���
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

	//��0�Ŷ��㿪ʼѰ�ҵ�ÿ���������̾���
	dijkstra(graph,0);

	system("pause");

	return 0;
}