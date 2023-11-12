#include<bits/stdc++.h>
#include<set>
using namespace std;

class Graph{

	int V;
	list<pair<int, int>> *l;

public:
	Graph(int v){
		V= v;
		l = new list<pair<int, int>>[V];
	}

	void addEdge( int x, int y, int wt, bool undir = true){
		l[x].push_back({wt, y});
		if(undir){
			l[y].push_back({wt, x});
		}
	}

	int dijkshtra(int src,  int dest){

		vector<int> dist(V, INT_MAX);
		set<pair<int, int>> s; //sorted

		//initialization
		dist[src] = 0;
		s.insert({0, src}); //{dist, node}

		while(!s.empty()){
			
			auto it = s.begin();

			int node = it->second;
			int distTillNow = it->first;

			s.erase(it);
			//iterate over the neighbors of node
			for(auto nbrPair: l[node]){
				//adding like a queue adding all the level one nodes
				//node has both wt, and next node
				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first; //wt

				if(distTillNow + currentEdge < dist[nbr]){ //which is int_max

					//remove if such nbr pair is already exist..update
					auto f = s.find({dist[nbr], nbr}); // any distance, just a nbr is present then remove
					if(	f!= s.end()) // ie if present in the set.. we already found
					{
						s.erase(f);
					}
					//insert the updated value with new dist
					dist[nbr] = distTillNow + currentEdge;
					s.insert({dist[nbr], nbr});
				}

			}
		}

		//sssp to all other nodes
		for(int i=0; i<V; i++){
			cout<< "Node "<< i << " Dist " << dist[i]<<endl;
		}
		return dist[dest];
	}

};

int main(){
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout<< g.dijkshtra(0, 4) << "\n";
}