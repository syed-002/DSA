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

int height(node* root){
	if(root==NULL) return 0;
	int h1 = height(root->left);
	int h2 = height(root-> right);
	 return max(h1, h2)+1;

}

//O(n^2) diameter finding
int diameter(node* root){
	if(root==NULL) return 0;
	int D1 = height(root->left)+ height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);
	return max(D1, max(D2, D3));

}

//optimised height and diameter pair to reduce to TC
class HDPair{
public:
	int height;
	int diameter;
};

HDPair optDiamter(node* root){

	HDPair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}
	HDPair left = optDiamter(root->left);
	HDPair right = optDiamter(root->right);
	p.height=max(left.height, right.height)+1;

	int D1 = left.height + right.height;
	int D2 = left.diameter;
	int D3 = right.diameter;

	p.diameter = max(D1, max(D2, D3));
	return p;
}


int main(){
	node* root = build_tree();
	
	cout<< "diam: " << diameter(root)<< "\n";
	cout<< "Opt_diam: " << optDiamter(root).diameter << "\n";

}