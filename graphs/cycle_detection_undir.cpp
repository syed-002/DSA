#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V=v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool dfs(int node, vector<bool> &visited, int parent){

		visited[node] = true;
		for(auto nbr: l[node]){

			if(!visited[nbr]){

				bool nbrFoundCycle = dfs(nbr, visited, node);
				if(nbrFoundCycle) return true; 
			}
			//base case
			else if(nbr!= parent) return true; //ie this is visited and its neighbor its not a parent

		}

		return false; //cycle not poresent//linear or smthn

	}

	bool contains_cycle(){
		//graph is single componenet, nodes are all connected

		vector<bool> visited(V, false);
		return dfs(0, visited, -1);

	}

};

bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for(int i=0; i<edges.size(); i++){
    	g.addEdge(edges[i].first, edges[i].second);
    }
    vector<bool> visited(V, false);
    return g.contains_cycle();
    
}

int main(){

	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);

	cout<<g.contains_cycle() <<endl;

}