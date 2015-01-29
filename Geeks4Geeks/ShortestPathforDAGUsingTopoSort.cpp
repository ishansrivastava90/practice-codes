#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define INT_MAX 100000

using namespace std;

typedef struct Graph {
	int V;
	int E;
	int adjMat[100][100];
} Graph;

int findMin(int * indegree, bool * visited, int V){

	int min = INT_MAX;
	int min_ind = 0;
	for(int i =0; i<V;i++){
		if(!visited[i] && indegree[i] < min){
			min = indegree[i];
			min_ind = i;
		}
	}
	return min_ind;
}

void topologicalSort(Graph * graph, int sorted[]){
	if(graph == NULL){
		cout<<"Graph is not PROPER\n";
		return;
	}

	int indegree[graph->V];
	bool visited[graph->V];

	for(int v = 0 ;v < graph->V;v++){
		indegree[v] = 0;
		visited[v] = false;

		for(int j = 0 ;j < graph->V;j++){

			if(graph->adjMat[j][v] != 0)
				indegree[v]++;
		}
	}

	int ind = 0;

	for(int it=0; it <graph->V;it++){

		int min_V = findMin(indegree, visited, graph->V);
		visited[min_V] = true;
		sorted[ind++] = min_V;

		for(int v=0;v<graph->V;v++){
			if(graph->adjMat[min_V][v] != 0 )
				indegree[v]--;
		}

	}

	for(int it=0; it <graph->V;it++){
	 	cout<<sorted[it]<<" ";
	 }
	cout<<"\n";


	return;

}

void shortestPathForAcyclicDirected(Graph * graph, int src){

	if(graph == NULL){
		cout<<"Graph is not PROPER\n";
		return;
	}

	int sorted[graph->V];
	topologicalSort(graph,sorted);

	bool srcFound = false;
	
	int dist[graph->V];
	for(int i =0; i < graph->V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for(int i =0;i < graph->V; i++){
		if(sorted[i] == src)
			srcFound = true;

		if(!srcFound)
			continue;

		for(int j =0 ;j< graph->V;j++){
			if(graph->adjMat[sorted[i]][j] != 0 && dist[j] > dist[sorted[i]] + graph->adjMat[sorted[i]][j])
				dist[j] = dist[sorted[i]] + graph->adjMat[sorted[i]][j];
		}

	}

	for(int i =0; i < graph->V; i++)
		cout<<"Dist of Vertex "<<i<<" from "<<src<<" = "<<dist[i]<<"\n";

	return;

}

int main(){

	Graph graph;
	graph.V = 6;
	graph.E = 9;

	for(int i = 0 ;i < graph.V ; i++){
		for(int j = 0 ;j < graph.V ; j++){
			graph.adjMat[i][j] = 0;
		}
	}
	graph.adjMat[0][1] = 5;
	graph.adjMat[0][2] = 3;
	graph.adjMat[1][3] = 6;
	graph.adjMat[2][4] = 4;
	graph.adjMat[2][5] = 2;
	graph.adjMat[2][3] = 7;
	graph.adjMat[3][4] = -1;
	graph.adjMat[3][5] = 1;
	graph.adjMat[4][5] = -2;
	graph.adjMat[1][2] = 2;

	shortestPathForAcyclicDirected(&graph,1);
	return 0;
} 