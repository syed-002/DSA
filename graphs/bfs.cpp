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

	void bfs(int source){
		queue<int> q;
		bool *visited = new bool[V]{0}; //initialized with zeroes
		q.push(source);
		visited[source] = true;

		while(!q.empty()){
			int f = q.front();
			cout<<f<<endl;
			q.pop();

			//push the neighbors of current node
			//if not already visited

			for(auto nbr: l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
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

	g.bfs(1);
	return 0;

}