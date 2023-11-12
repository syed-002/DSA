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

pair<int, bool> isHeightBalanced(node * root){

	pair<int, bool> p, left, right;
	if(root==NULL){
		p.first = 0; //height
		p.second = true; //balanced
		return p;
	}
	left = isHeightBalanced(root->left);
	right = isHeightBalanced(root->right);

	int height = max(left.first , right.first) + 1;

	//3 cond for p.second
	if(abs(left.first - right.first)<=1 and left.second and right.second){
		return make_pair(height, true);
	}
	else return make_pair(height, false);
}

int main(){
	node* root = build_tree();
	levelorderprint(root);
	pair<int, bool> p = isHeightBalanced(root);
	if(p.second) cout<<"balanced";
	else cout<< "not balanced";

}