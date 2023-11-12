#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int u, int v, bool undir){
		l[u].push_back(v);
		if(undir){
			l[v].push_back(u);
		}
	}

	int bfs(int source, int dest){
		queue<int> q;
		q.push(source);

		bool* visited = new bool[V]{false};
		int* dist = new int[V]{0};
		

		visited[source] = true;
		dist[source] = 0;

		while(!visited[dest]){
			int f = q.front();
			q.pop();

			for(auto i: l[f]){
				if(!visited[i]){
					q.push(i);
					visited[i] = true;
					dist[i] = dist[f]+1;
				}
				
			}
			
		}
		return dist[dest];
	}

};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders){

	vector<int> board(n+1, 0);
	//we are creating graph and running a bfs shortest path algo to find min steps

	for(auto i: snakes){
		int s = i.first;
		int e = i.second;
		board[s] = e-s; //-ve [15,3] --> 3-15 = -12 gets added in board .. b[15] = -12
	}

	for(auto i: ladders){
		int s = i.first;
		int e = i.second;
		board[s] = e-s; //+ve [3, 12] --> b[3] = 9 ..this is edge added to graph later
	}

	Graph g(n+1);
	for(int u=1; u<n; u++){ //will add until 35 only.. what to add on 36
		for(int i=1; i<=6; i++){
			int v = u+i; // adding all the edges no matter what
			v+= board[v]; //adding snakes or ladders steps
			if(v<=n){
				g.addEdge(u, v, false);
			}
		}
	}

	return g.bfs(1,n);
}

int main(){



 	return 0;
}