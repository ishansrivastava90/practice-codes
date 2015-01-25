#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <set>
#include <queue>

#define INT_MAX 10000000;

using namespace std;
typedef struct Vertex{
	int v_num;
	int weight;
} Vertex;

typedef struct Graph {
	int V;
	int E;
	vector< Vertex > adjMat[100];
} Graph;


typedef struct compare {
	bool operator()(const Vertex & a, const Vertex & b){
		return a.weight > b.weight;
	}
} compare;

int minKey(bool inc_v[], int curr_weights[]){

	// Returns the minimum from the not included
}

void primMST(Graph *const graph){

	if(graph == NULL)
		cout<<"Graph is not PROPER\n";

	bool parent[graph->V];
	bool inc_v[graph->V];

	int curr_weights[graph->V];
	for(int i = 0; i<graph->V; i++)
		curr_weights[i] = INT_MAX;
	
	inc_v[0] = true;
	curr_weights[0] = 0;
	parent[0] = -1;

	

	// priority_queue <Vertex, vector<Vertex>, compare> min_heap;

	// Vertex v;
	// v.v_num = 0;
	// v.weight = 0;

	// min_heap.push(v);

	cout<<"0\n";

	int c = 0;
	while(c < graph->V){

		int min_Vertex = minKey(inc_v, curr_weights);
		inc_v[min_Vertex] = true;

		cout<<min_Vertex<<"\n";

		vector <Vertex>::iterator it;
		for(it = graph->adjMat[min_Vertex].begin(); it != graph->adjMat[min_Vertex].end(); it++){
		
			if(!inc_v[(*it).v_num] && (*it).weight < curr_weights[(*it).v_num])
				curr_weights[(*it).v_num] = (*it).weight;	

		}
		c++;
		
	}
}

int main(){

	Graph graph;
	scanf("%d%d",&graph.V,&graph.E);

	int u,v,w;
	for(int i =0; i<graph.E;i++){

		scanf("%d%d%d",&u,&v,&w);

		Vertex ver;
		ver.v_num = v;
		ver.weight = w;
		graph.adjMat[u].push_back(ver);

		ver.v_num = u;
		graph.adjMat[v].push_back(ver);
	}

	primMST(&graph);

	return 0;
 
}