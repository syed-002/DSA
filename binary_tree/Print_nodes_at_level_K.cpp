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

void Recursion_printLevelK(node* root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<< root->data<< " ";
		return;
	}
	Recursion_printLevelK(root->left, k-1);
	Recursion_printLevelK(root->right, k-1);
	return;
}



int main(){
	node* root = build_tree();
	levelorderprint(root);
	cout<<"using queue: ";
	printAtLevelK(root, 2);
	cout<<endl;
	cout<<"using recursion: ";
	Recursion_printLevelK(root, 2);
	
	

}