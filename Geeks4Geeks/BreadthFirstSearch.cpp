#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    int V;
    vector<int>* adjList;



    public:
    Graph(int V){
        this->V = V;
        adjList = new vector<int>[V];
    }
    
    void addEdge(int u, int v){

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    void BFS(int s){

        bool visited[this->V];
        for(int i =0;i <V; i++)
            visited[i] = false;

        queue<int> bfsQ;

        bfsQ.push(s);
        visited[s] = true;

        while(!bfsQ.empty()){
            
            int curr_s = bfsQ.front();
            cout<<curr_s<<" ";
            bfsQ.pop();
            
            if(!visited[curr_s]){
                
                vector<int>::iterator it;
                for(it = adjList[curr_s].begin(); it!= adjList[curr_s].end(); it++)
                    bfsQ.push(*it);
    
                visited[curr_s] = true;
            }
        }
        cout<<"\n";
    }

    void DFS(){
        
        bool visited[this->V];

        for(int i=0;i<this->V;i++)
            visited[i] = false;

        for(int i =0;i<this->V;i++){
            if(!visited[i])
                DFSUtil(i,visited);
        }

        return;


    }
    void DFSUtil(int v, bool visited[]){

        visited[v] = true;
        cout<<v<<" ";

        vector<int>::iterator it;
        for(it = adjList[v].begin(); it != adjList[v].end(); it++){

            if(!visited[v])
                DFSUtil(*it, visited);
        }

        return;
    }


};
    

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    return 0;
}
