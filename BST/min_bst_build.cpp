#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int key;
	node*left;
	node*right;

	node(int key){
		this->key=key;
		left=right=NULL;
	}
};

node* min_bst(int s, int e, vector<int> arr){

	if(s>e) return NULL;

	int mid=s+(e-s)/2;
	node* root = new node(arr[mid]);

	root->left = min_bst(s,mid-1, arr);
	root->right = min_bst(mid+1, e, arr);
	
	return root;
}

void inorder(node* root){
	//inorder should give in ascendin order, so formed tree is correct
	if(root==NULL) return;

	inorder(root->left);
	cout<< root->key<<" ";
	inorder(root->right);
	return;
}

int main(){
	vector<int>arr;
	int n=7;
	for(int i=0; i<n; i++){
		arr.push_back(i+1);
	}
	node*root = min_bst(0, arr.size()-1, arr);
	inorder(root);
}