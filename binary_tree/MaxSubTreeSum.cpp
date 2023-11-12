#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data =d;
		left = NULL;
		right = NULL;
	}
	
};

// 1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1
node* build_tree(){
	// preorder build, the order which it is given
	//depth first insertion
	int d;
	cin>>d;
	if(d==-1) return NULL;
	node* n = new node(d);
	n->left =  build_tree();
	n->right = build_tree();
	return n;
}

void levelorderprint(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node *temp = q.front();		
		q.pop();
		if(temp==NULL){
			cout<<"\n";
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
	}
	return;
}

class Pair{
public:
	int inc;
	int exc;
	//for readebility
};

Pair maxSubsetSum(node* root){
	Pair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}

	//rec
	Pair l, r;
	l = maxSubsetSum(root->left);
	r = maxSubsetSum(root->right);

	p.inc = root->data + l.exc + r.exc;
	p.exc = max(l.inc, l.exc) + max (r.inc, r.exc);

	return p;
}



int main(){
	node* root = build_tree();
	levelorderprint(root);
	
	Pair p = maxSubsetSum(root);
	cout << max(p.inc, p.exc) << endl; 

}