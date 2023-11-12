#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this->data=data;
		next=NULL;
	}
};

void insertAtTail(node* &tail, int data){
	if(tail == NULL){
		tail=new node(data);
		return;
	}
	node*n = new node(data);
	tail->next = n;
	tail=n;
}

void printll(node* tail){
	while(head!=NULL){
		cout<<head->data<<"->";
		head= head->next;
	}
	cout<<endl;
}

int main(){
	node* tail=NULL;
	
	insertAtTail(tail, 1);
	insertAtTail(tail, 3);
	insertAtTail(tail, 5);
	printll(head);

}