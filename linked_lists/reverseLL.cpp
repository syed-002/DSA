#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node (int data){
		this->data =data;
		next = NULL;
	}
};

void insertAtHead(node* &head, int data){
	if(head==NULL){
		head = new node(data);
		return;
	}
	node*n = new node(data);
	n->next = head;
	head = n;
}

void insertInMiddle(node * &head, int data, int pos){

	if(pos==0){
		insertAtHead(head, data);
	}
	node*temp=head;
	for(int jump=1; jump<=pos-1; jump++){
		temp = temp->next;
	}
	node*n = new node(data);
	n->next = temp-> next;
	temp->next =n;
}

void printll(node* head){
	while(head!=NULL){
		cout<< head->data << "->" ;
		head= head->next;
	}
	cout<<endl;
}
//returns the head of the reversed ll
node* recReverse(node *head){
	//basecase
	if(head==NULL or head->next==NULL){
		return head;
	}
	//otherwise
	node* smallHead=recReverse(head->next);

	head->next ->next= head;

	head->next = NULL;
	printll(smallHead);
	
	return smallHead;
}

node* iterativeReverse(node* head){
	node* prev = NULL;
	node* curr = head;
	node*temp;
	while(curr!=NULL){
		temp = curr->next;
		curr->next = prev;
		prev= curr;
		curr= temp;
	}
	return prev;
}

node* kReverse(node* head, int k){
	if(head==NULL) return NULL;

	//USING ITERATIVE TO REVERSE K ELEMENTS IN LL
	node* prev=NULL;
	node* curr=head;
	node*temp;
	int c=0;
	while(curr!=NULL and c<k){
		temp=curr->next;
		curr->next= prev;
		prev=curr;
		curr=temp;
		c++;
	}
	
	if(temp!=NULL){
		head->next= kReverse(temp, k);
	}
	return prev;
}

int main(){
	node*head = NULL;
	insertAtHead(head, 8);
	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	// insertInMiddle(head, 100, 3);
	printll(head);
	//head = recReverse(head);
	// head = iterativeReverse(head);

	
	head= kReverse(head, 3);
	
	

	printll(head);

}

