#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildtree(){
	int d;
	cin>>d;
	if(d==-1) return NULL;
	node * n = new node(d);
	n->left = buildtree();
	n->right = buildtree();
	return n;
}

node* levelOrder_buildtree(){
	int d;
	cin>>d;
	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		int c1, c2;
		cin>>c1>>c2;
		if(c1!= -1){
			temp->left = new node(c1);
			q.push(temp->left);
		}			
		if(c2 != -1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}
	return root;
}

void levelOrderPrint(node*root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			q.pop();
			cout<<"\n";
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return;
}

void traverseTree(node*root, int d, map<int, vector<int>> &m){
	if(root==NULL) return;
	m[d].push_back(root->data);
	traverseTree(root->left, d-1, m);
	traverseTree(root->right, d+1, m);
	return;

}

void verticalOrderPrint(node*root){

	map<int, vector<int>> m;
	int d=0;

	traverseTree(root, d,m);

	//-1 with key of nodes
	//printing them
	//keys are all sorted
	for(auto pair: m){
		int key = pair.first;
		vector<int> line = pair.second;
		for(auto i:pair.second){
			cout<< i << " ";
		}
		cout<<endl;
	}
}



int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->right->left->right = new node(8);
	root->right->right->right = new node(9);

	levelOrderPrint(root);
	cout<<endl;

	verticalOrderPrint(root);



}