#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V =v;
		l = new list<int>[V];
	}
	void addedge(int u, int v, bool undir=true){
		l[u].push_back(v);
		if(undir){
			l[v].push_back(u);
		}
	}

	//rec helper fun

	void dfs_helper(int node, bool*visited){
		visited[node] = true;
		cout<< node << "-> ";

		for(int nbr: l[node]){
			if(!visited[nbr]){

				dfs_helper(nbr, visited);
			}
		}
		return;
	}

	//wrapper func
	void dfs(int source){
		bool *visited = new bool[V]{0};
		dfs_helper(source, visited); //just pass the pointer, even though its an array

	}

};




int main(){
	Graph g(7);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(5,6);
	g.addedge(4,5);
	g.addedge(0,4);
	g.addedge(3,4);

	g.dfs(1);
	return 0;

}