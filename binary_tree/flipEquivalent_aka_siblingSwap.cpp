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

bool flipEq(node*root1, node*root2){

	if(root1==NULL and root2==NULL) return true;

	// if(root1->left==NULL and root2->left==NULL and root1->right==NULL and root2->right==NULL){
	// 	return true;
	// }
	if(root1 and root2){
		if(root1->data == root2->data){
			//if one condition is false, it goes to the other until it is true
		return ((flipEq(root1->left, root2->left) and flipEq(root1->right, root2->right)) 
			or (flipEq(root1->left, root2->right) and flipEq(root1->right, root2->left)));
		}
		//gives false only when the values are not at all equl in any way
		else return false;
	}
	//returns false if root1 and root2 are unequal ie esp null and some value 
	else return false;
}


int main(){
	node *root1 = new node(1);
	root1->left = new node(2);
	root1->left->left = new node(4);
	root1->left->right = new node(5);
	root1->left->right->left = new node(7);
	root1->left->right->right = new node(8);
	root1->right = new node(3);
	root1->right->right = new node(6);

	node* root2 = new node(1);
	root2->right = new node(2);
	root2->right->right = new node(5);
	root2->right->left = new node(4);
	root2->right->right->right = new node(7);
	root2->right->right->left = new node(8);
	root2->left = new node(3);
	root2->left->right = new node(6);

	cout<< flipEq(root1, root2)<<endl;



}