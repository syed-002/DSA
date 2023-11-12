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

node* inorderSucc(node* root, node* target){
	//since data can be same in multiple nodes
	//we are passing the node instead of data..ie node* target

	//if right subtree exists
	if(target->right!=NULL){
		node* temp = target->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		return temp;
		//min value in the right subtree
	}
	//if right subtree doesnt exist

	node*temp= root;
	node* succ= NULL;

	while(temp!=NULL){
		if(temp->key > target-> key){
			succ= temp; //updating the succ
			temp = temp->left;
		}
		else if(temp->key < target->key){
			temp = temp->right;
		}
		else{
			break; //break the loop
		}
	}

	return succ;

}

void inorder(node* root){
	//inorder should give in ascendin order, so formed tree is correct
	if(root==NULL) return;

	inorder(root->left);
	cout<< root->key<<" ";
	inorder(root->right);
	return;
}

node* insert(node*root, int x){
	if(root==NULL) {
		return new node(x);
	}
	if(root->key < x){
		root->right = insert(root->right, x);
	}
	else{
		root->left = insert(root->left, x);
	}
	return root;
}

int main(){
	node*root = NULL;
	int arr[]= {8,3,10,1,6,14,4,7,13};

	for(int x:arr){
		root=insert(root,x);
	}
	inorder(root);
	cout<< endl;
	node* succ = inorderSucc(root, root->left->right->right);
	cout<< succ->key<<" ";
	succ = inorderSucc(root, root->right->right->left);
	cout<< succ->key;

	return 0;
}
