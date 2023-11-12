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


void printAtLevelK(node*root, int k){
	//k=2
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(k>=0 and !q.empty()){
		node*temp= q.front();
		q.pop();
		//cout<< k << "\n";
		if(temp==NULL){
			if(!q.empty()){
				q.push(NULL);
			}
			k--; //one level down.. 
		}
		else{
			if(k==0){
				//if level is zero, then desired level reached
				cout<<temp->data<<" ";
			}
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return;
}

int printNodesAtDistanceK(node*root,node* target, int k){
	//print at level k given target..very imp
	//base case
	if(root==NULL)
		return -1;
	//reached the target node
	if(root==target){
		printAtLevelK(target, k);
		return 0;//end here coz reached the target
	}
	//other case
	//where target node is present inleft subtree
	int DL = printNodesAtDistanceK(root->left, target, k);
	if(DL!=-1){
		//2 cases
		//print the current node
		if(DL + 1 == k){
			cout<<root-> data;
		}
		//ie if its not the root node, go and print
		//from the right subtree
		else{
			printAtLevelK(root->right, k-2-DL);
		}
		return 1+DL; //present at distance 1+dl
	}
	//similarly if the target is found in right subtree
	int DR = printNodesAtDistanceK(root->right, target, k);
	if(DR!=-1){
		//2 cases
		//print the current node
		if(DR + 1 == k){
			cout<<root-> data;
		}
		//ie if its not the root node, go and print
		//from the right subtree
		else{
			printAtLevelK(root->left, k-2-DR);
		}
		return 1+DR; //present at distance 1+dl
	}
	//din find node in left or sub tree
	return -1;

}



int main(){
	// node* root = build_tree();

	node*root = new node(1);
	root->left = new node(2);
	root-> right = new node(3);
	root->left->left = new node(4);
	root->left ->right = new node (5);
	root-> right-> right = new node(6);
	root->left->right ->left = new node(7);
	root->left->right ->right = new node(8);
	root->left->right ->right->left = new node(9);
	root->left->right ->right->right = new node(10);
	
 	levelorderprint(root);
	printNodesAtDistanceK(root-, root->left ->right, 2);
	
	

}