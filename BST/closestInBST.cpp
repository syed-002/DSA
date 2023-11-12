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

node* insert(node*root, int key){
	if(root==NULL){
		return new node(key);
	}
	if(root->key > key){
		root->left = insert(root->left, key);
	}
	else{
		root->right = insert(root->right, key);
	}
	return root;
}

int findClosest(node*root, int target){

	int closest;
	int diff = INT_MAX;

	node*temp = root;

	while(temp!=NULL){
		if(abs(temp->key - target) ==0) return root->key;
		if(abs(temp->key - target)<diff){
			closest = temp->key;
			diff = abs(temp->key - target);
		}
		if(temp->key > target){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	return closest;

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
	node*root = NULL;
	int arr[]= {8,3,10,1,6,14,4,7,13};

	for(int x:arr){
		root=insert(root,x);
	}
	inorder(root);
	cout<<endl;
	cout<< findClosest(root, 16);
}