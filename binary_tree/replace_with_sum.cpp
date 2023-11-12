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

	node * n = new node(d);
	n-> left = build_tree();
	n-> right = build_tree();
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

int replaceWithSum(node * root){

//base case
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}

	//recur
	int ls = replaceWithSum(root->left);
	int rs = replaceWithSum(root->right);
	int temp = root->data;
	root->data = ls + rs;
	return temp+ root->data;

}
//repeat
int new_replace(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right == NULL) return root->data;
	int ls = new_replace(root->left);
	int rs = new_replace(root->right);
	int temp = root-> data;
	root->data = ls+rs;
	return temp + root->data;
}


int main(){
	node* root = build_tree();
	levelorderprint(root);
	cout<<endl;
	replaceWithSum(root);
	levelorderprint(root);

}