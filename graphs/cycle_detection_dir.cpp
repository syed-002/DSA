// #include<bits/stdc++.h>
// using namespace std;

// class Graph{

// 	int V;
// 	list<int> *l;

// public:
// 	Graph(int v){
// 		V=v;
// 		l = new list<int>[V];
// 	}

// 	void addEdge(int x, int y){
// 		l[x].push_back(y);
// 	}

// 	bool dfs(int node, vector<bool> &visited,  vector<bool> &presentinS, stack<int> s, int parent){

// 		s.push(node);
// 		presentinS[node] = true;
// 		visited[node] = true;
// 		for(auto nbr: l[node]){

// 			if(!visited[nbr]){

// 				bool nbrFoundCycle = dfs(nbr, visited, presentinS, s, node);
// 				if(nbrFoundCycle) return true; 
// 			}
// 			//base case
// 			else if(visited[nbr] and nbr!= parent and presentinS[nbr]) return true; //ie this is visited and its neighbor its not a parent
// 			else{
// 				s.pop();
// 				presentinS[nbr] = false;
// 				return false;
// 			}
// 		}
// 		s.pop();
// 		presentinS[node] = false;
// 		return false; //cycle not poresent//linear or smthn

// 	}

// 	bool contains_cycle(){
// 		//graph is single componenet, nodes are all connected

// 		vector<bool> visited(V, false);
// 		vector<bool> presentinS(V, false);
// 		stack<int> s;
// 		return dfs(0, visited, presentinS, s, -1);

// 	}

// };

// bool contains_cycle(int V,vector<pair<int,int> > edges){
//     //Complete this method
//     Graph g(V);
//     for(int i=0; i<edges.size(); i++){
//     	g.addEdge(edges[i].first, edges[i].second);
//     }
//     return g.contains_cycle();
    
// }

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
	}

	bool dfs(int node, vector<bool> &visited,  vector<bool> &presentinS, stack<int> s){

		s.push(node);
		presentinS[node] = true;
		visited[node] = true;
		for(auto nbr: l[node]){

			if(!visited[nbr]){

				bool nbrFoundCycle = dfs(nbr, visited, presentinS, s);
				if(nbrFoundCycle) return true; 
			}
			//base case
			else if(visited[nbr] and presentinS[nbr]) return true; //ie this is visited and its neighbor its not a parent
			else{
				s.pop();
				presentinS[nbr] = false;
				return false;
			}
		}
		s.pop();
		presentinS[node] = false;
		return false; //cycle not poresent//linear or smthn

	}

	bool contains_cycle(){
		//graph is single componenet, nodes are all connected

		vector<bool> visited(V, false);
		vector<bool> presentinS(V, false);
		stack<int> s;
		return dfs(0, visited, presentinS, s);

	}

};

bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for(int i=0; i<edges.size(); i++){
    	g.addEdge(edges[i].first, edges[i].second);
    }
    return g.contains_cycle();
    
}


int main(){

	// Graph g(3);
	// g.addEdge(0,1);
	// g.addEdge(1,2);
	// g.addEdge(0,2);


	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	cout<<g.contains_cycle() <<endl;

}