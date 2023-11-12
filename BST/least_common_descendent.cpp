#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* lca_bt(node*root, int a, int b){
    //Complete this function and return address of the node
    
    if(root==NULL) return NULL;
    if(root->data==a || root->data==b) return root;
    node*l = lca_bt(root->left, a, b);
    node* r= lca_bt(root->right, a, b);

    if(l!=NULL and r!=NULL) return root;
    return l!=r ? l:r;
    
}

node* lca_bst(node*root, int a, int b){
	if(root->data > a && root->data >b){
		return lca_bst(root->left, a, b);
	}
	else if(root->data < a && root->data<b){
		return lca_bst(root->right, a, b);
	}
	return root; // reached to common so its on either sides

	//here to sc is o(h)
	//tc is o(n)
}

node* iterative_lca_bst(node*root, int a, int b){
	//reduce the space complexicty to O(1)
	while(root!=NULL){
		if(root->data > a && root->data >b){
			root = root->left;
		}
		else if(root->data < a && root->data<b){
			root = root->right;
		}
		else{
			break;
		}
	}
	return root;

}

node* build_bt(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node*root = new node(d);
	root->left = build_bt();
	root->right = build_bt();
	return root;
}

node* insert(node*root, int x){

	if(root==NULL){
		return new node(x);
	}
	if(root->data < x){
		root->right= insert(root->right, x);
	}
	else root->left = insert(root->left, x);
	return root;
}


void inorder(node*root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<< root->data<< " ";
	inorder(root->right);
	return;
}

int main()
{
	node*root = NULL;
	int arr[]= {3,6,2,8,11,9,5,7,13};

	for(int x:arr){
		root=insert(root,x);
	}

	inorder(root);

	// node*root = build_bt();
	// 3 6 2 -1 -1 11 9 -1 -1 5 -1 -1 8 -1 13 7 -1 -1 -1
	//inorder(root);

	node * temp = lca_bst(root, 5,7);
	cout<< temp->data;
}
