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

	void bfs(int source, int dest=-1){
	
		queue<int> q;
		q.push(source);


		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V];

		visited[source]=true;

		for(int i=0; i<V; i++){
			parent[i] = -1; //parents
		}

		parent[source] = source;
		dist[source] = 0;

		while(!q.empty()){
			int f=q.front();
			// cout<<f <<" ";
			q.pop();

			for(auto i: l[f]){
				if(!visited[i]){
					parent[i]=f;
					dist[i] = dist[f]+1; //parent+1
					q.push(i);
					visited[i]=true;
				}
			}
		}
		//print shortest distance
		////single source shortest path algo sssp
		for(int i=0; i<V; i++){
			cout<< "Shortest dist to " << i << " is " << dist[i] <<endl;

		}

	
		//print the path from a source to any dest
		if(dest!=-1){
			int temp = dest;
			while(temp!=source){
				cout<<temp<< "-->";
				temp = parent[temp];

			}
			cout<<temp;
		}
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

	g.bfs(1, 6); 

	return 0;

}