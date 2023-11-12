#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<pair<int, int>>*l;

public:
	Graph(int v){
		V=v;
		l = new list<pair<int, int>>[V];
	}

	void addEdge(int u, int v, int wt, bool undir=true){
		l[u].push_back(make_pair(wt,v));
		if(undir){
			l[v].push_back(make_pair(wt,u));
		}
	}

	void displayAdjlist(){

		for(int i=0; i<V; i++){
			cout<< i << "->";
			for(auto pair: l[i]){
				int wt = pair.first;
				int to = pair.second;
				
				// cout<< to  << " " << wt << " || "<< " ";
			}
			cout<<endl;
		}
	}



};

int main(){
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);

	g.displayAdjlist();
	return 0;
}