#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

Node* inorder_succ(Node*root, Node*target){

    if(target->right){
        Node*temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    
    Node* temp = root;
    Node*succ= NULL;
    
    while(temp!= NULL){
        if(root->key > target->key){
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key < target->key){
            temp = temp->right;
        }
        else{
            break;//reached the target
        }
    }
    return succ;
}

Node* findInOrderSuccessor( Node *inputNode ){
    //Complete this Method, return the pointer to the inorder successor
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree
    //traversing to parent
    Node* target = inputNode;
    if(inputNode->parent){
        inputNode = inputNode->parent;
    }
    
    if(inputNode->parent==NULL){
        Node*root = inputNode;
    }

    
}


int main(){
    node*root = NULL;
    int arr[]= {8,3,10,1,6,14,4,7,13};

    for(int x:arr){
        root=insert(root,x);
    }
    
    node* succ = inorderSucc(root, root->left->right->right);
    cout<< succ->key<<" ";
    succ = inorderSucc(root, root->right->right->left);
    cout<< succ->key;

    return 0;
}
