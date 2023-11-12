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

node* lever_order_build_tree(){
// when the input is given in level order fashion
	int d;
	cin>>d;

	node* root =new node(d);

	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();

		int c1, c2;
		cin>>c1>>c2;
		if(c1 != -1){
			curr->left = new node(c1); //creating new node
			q.push(curr->left); //also pushing it in queue
		}
		if(c2 != -1){
			curr->right = new node(c2); //creating new node
			q.push(curr->right); //also pushing it in queue
		}
	}
	return root;
}

void preorder(node* root){
	//deapth first print
	//recursive
	if(!root){
		//cout<< "\n not root: " <<"\n";
		return;
	}
	cout<< root->data<<" ";
	preorder(root->left);
	preorder(root->right);

	return;
}

void inorder(node* root){
	//using queue to implement
	//fifo
	//print nodes of the same level of the tree
	//storing the pointer to the node instead of storing the node
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<"\n";
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<< temp-> data<< " ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
	return ;
}

int main(){
	//node* root = build_tree();
	node* root = lever_order_build_tree();
	cout<<"Preorder: \n";
	preorder(root);

	cout<<"\nInorder: \n";
	inorder(root);

}