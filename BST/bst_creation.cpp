#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int key;
	node* left;
	node* right;

	node(int key){
		this->key=key;
		left=right=NULL;
	}
};

node* insert(node*root, int key){
	if(root==NULL){
		return new node(key);
	}
	//rec case
	if(key< root->key){
		root->left = insert(root->left, key);
	}

	else{
		root->right = insert(root->right, key);
	}

	return root;
}

void inorder_print(node*root){
	//we get sorted output in the order traversal of bst
	if(root==NULL){
		return;
	}
	inorder_print(root->left);
	cout<<root->key<<" ";
	inorder_print(root->right);
	return;
}

void preorder_print(node*root){
	//we get sorted output in the order traversal of bst
	if(root==NULL){
		return;
	}
	cout<<root->key<<" ";
	preorder_print(root->left);
	preorder_print(root->right);
	return;
}

void postorder_print(node*root){
	//we get sorted output in the order traversal of bst
	if(root==NULL){
		return;
	}
	postorder_print(root->left);
	postorder_print(root->right);
	cout<<root->key<<" ";
	return;
}

bool isPresent(node * root,int key){
    //Complete this method
    if(root==NULL) {
    	return false;
    }
    if(root->key==key){
    	return true;
    }
    if(root->key > key){
    	return isPresent(root->left, key);
    }
    else{
    	return isPresent(root->right, key);
    }
}

int main(){
	node*root = NULL;
	int arr[]= {8,3,10,1,6,14,4,7,13};

	for(int x:arr){
		root=insert(root,x);
	}
	inorder_print(root);
	cout<<endl;
	preorder_print(root);
	cout<<endl;
	postorder_print(root);
	cout<<endl;
	cout<<isPresent(root,13)<<endl;
	cout<<isPresent(root,6)<<endl;
	cout<<isPresent(root,20)<<endl;

	return 0;
}