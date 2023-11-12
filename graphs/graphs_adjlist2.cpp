#include<bits/stdc++.h>
using namespace std;

class Node{

public:
	string name;
	list<string> nbrs;

	Node(string name){
		this->name =name;

	}
};

class Graph{

	//all nodes
	//hashmap(string, node*)

	unordered_map<string, Node*>m;

public:
	Graph(vector<string> cities){
		for(auto city: cities){
			m[city] = new Node(city);
		}
	}

	void addEdge(string x, string y, bool undir=false){ //dir
		//adding edges in the node itself
		m[x]->nbrs.push_back(y); //since x is city.. m[x] gives the node*.. we are pusing neighbr cities into it;
		if(undir){
			m[y]->nbrs.push_back(x);
		}
	}

	void printAdjList(){
		for(auto citypair: m){
			auto city = citypair.first;
			Node * node = citypair.second;
			cout<< city << "-> ";
			for(auto  nbrcities: node->nbrs){
				cout << nbrcities << " ";
			}
			cout<<endl;
		}
	}

};

int main(){
	vector<string> cities = {"Delhi", "London", "Paris", "Hyderabad"};
	Graph g(cities);

	g.addEdge("Delhi", "London");
	g.addEdge("Hyderabad", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "Hyderabad");

	g.printAdjList();

	return 0;
}