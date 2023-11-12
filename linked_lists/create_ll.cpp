#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data; //this is current node object
		next =  NULL;
	}

};
//--------linked list--------// 
void insertAtHead(node *&head, int data){
	//passing by ref & is imp since it wont be changed in the main func
	if(head == NULL){
		head = new node(data);
		return;
	}
	//otherwise
	node * n = new node(data);
	n-> next = head;
	head = n;
}

void insertInMiddle(node * &head, int data, int pos){
	if(pos == 0){
		insertAtHead(head, data);
	}
	else{
		node * temp = head;
		for(int jump=1; jump <=pos-1; jump++){
			temp = temp->next;
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

void printLL(node* head){
	//passing by value so the actual head stays the beginning only
	while(head!= NULL){
		cout<< head->data << "->";
		head =  head->next;
	}
	cout<<endl;
}

bool isPresent(node * head, int key){
    //Complete this function 
    
    while(head!=NULL){
        if((head->data) == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main(){
	node* head = NULL;
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertInMiddle(head, 100, 3);
	printLL(head);

}