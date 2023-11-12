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

class LinkedList{
public:
	//these are bst nodes only, not of linked list
	node* head;
	node* tail;
};

LinkedList tree2LL(node* root){
	LinkedList l;

	//base case
	if(root==NULL){
		l.head =l.tail = NULL;
		return l;
	}

	//4 cases
	if(root->left==NULL and root->right==NULL){
		//leaf node
		l.head=l.tail=root;
		return l;
	}
	else if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL= tree2LL(root->left);
		leftLL.tail->right = root; 
		l.head = leftLL.head;
		l.tail=root;
	}
	else if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;
		l.head=root;
		l.tail=rightLL.tail;
	}
	else{
		//both left and right are not null
		LinkedList leftLL = tree2LL(root->left);
		LinkedList rightLL = tree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}


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
	//inorder(root);
	//cout<<endl;
	LinkedList l = tree2LL(root);
	node*temp = l.head;
	//here wer are converting the bst to linkedlist 
	//but not chaning it to innnate ll properties one
	//we arte using linked list to conbvert bst to ll
	//so the temp will be a bst only
	//which is the head of the linked list
	//which returns it
	//iterating the linked list
	while(temp!=NULL){
		cout<<temp->key<< "-> ";
		temp = temp->right;
	}
	return 0;
}
