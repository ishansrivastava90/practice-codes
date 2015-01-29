#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

//MACROS
#define INT_MAX 10000000

using namespace std;

typedef struct Edge {
	int src;
	int dest;
	int weight;
} Edge;

typedef struct Graph {
	int V;
	int E;
	Edge *edge;
} Graph;

void printGraph(Graph * graph, int parent[], int src){
	if(graph == NULL){
		cout<<"Graph is not proper\n";
		return;
	}

	// Use queue to print from the source
}

void printDist(int dist[], int V)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void shortestPath_BellmanFord(Graph* graph, int src){

	if(graph == NULL){
		cout<<"Graph is not proper\n";
		return;
	}

	int dist[graph->V];
	int parent[graph->V];

	for(int i =0; i <graph->V;i++){
		dist[i] = INT_MAX;
		parent[i] = -1;
	}

	dist[src] = 0;
	parent[src] = src;

	for(int v =0; v < graph->V - 1; v++){

		for(int e=0;e < graph->E; e++){

			if(dist[graph->edge[e].dest] > (dist[graph->edge[e].src] + graph->edge[e].weight) )
				dist[graph->edge[e].dest] = dist[graph->edge[e].src] + graph->edge[e].weight;
				parent[graph->edge[e].dest] = graph->edge[e].src;
		}
	}

	printDist(dist, graph->V);

	return;
}

Graph* createGraph(int V, int E){

	Graph *graph = (Graph*) malloc(sizeof(Graph));
	graph->V = V;
	graph->E =E;

	graph->edge = (Edge*)malloc(sizeof(Edge)*E);

	return graph;
}
int main (){

	 /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    shortestPath_BellmanFord(graph, 0);
	return 0;
}