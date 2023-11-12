#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node * left;
	Node* right;

	Node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

vector<int> ans;
void runner(Node * root,int level, int &max_level){
	if(root==NULL) return;
	if(max_level<level){
		max_level++;
		ans.push_back(root->key);
	}
	runner(root->left, level+1, max_level);
	runner(root->right, level+1, max_level);

	return;
}

vector<int> leftView(Node* root){
    //Complete the function
    int max_level=0;
    runner(root, 1, max_level);
	return ans; 
}

void printpath(Node *root, vector<int> path){
	if(root==NULL) return;
	path.push_back(root->key);
	if(root->left == NULL and root->right==NULL){
		for(auto i:path) cout<< i << " ";
			cout<<"\n";
	}
	else{
		printpath(root->left, path);
	printpath(root->right, path);
	}
	
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	//root->left->right = new Node(4);
	// root->left->right->right = new Node(5);
	root->right->right = new Node(6);
	vector<int> path;
	cout<<"PRINT ALL THE PATHS: \n";
	printpath(root, path);
	cout<<"PRINTING THE LEFT VIEW: \n";
	leftView(root);
	for(auto i:ans){
		cout<< i << " ";
	}

}