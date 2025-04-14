#include<iostream>
using namespace std;
class Node{
public:
	int val;
	Node* next;
	
	Node(int data){
		val=data;
		next=nullptr;
	}
};
class stack{
public:
	Node* head;
	Node* tail;
	int top;
	stack(){
		head=tail=nullptr;
		top=-1;	
	}
	
	bool isEmpty(){
		if(top==-1) return true;
		return false;
	}
	
	void push(int ele){
		Node* new_node = new Node(ele);
		top++;
		if(head==nullptr){
			head=tail=new_node;
			return;
		}
		tail->next=new_node;
		tail=tail->next;
	}
	
	int pop(){
		if(isEmpty()){
			cout<<"Stack Overflow!"<<endl;
			return -1;
		}
		Node* temp = head;
		while(temp->next->next!=nullptr){
			temp=temp->next;
		}
		Node* temp1=temp->next;
		temp->next=nullptr;
		free(temp1);
		return top--;
	}
	
	void display(){
		if(isEmpty()){
			cout<<"Stack is Empty."<<endl;
			return;	
		}
		Node* temp=head;
		while(temp!=tail->next){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
};
int main(){
	stack* s = new stack();
	int n;
	cin>>n;
	while(n--){
		int ele;
		cin>>ele;
		s->push(ele);
	}
	cout<<s->isEmpty()<<endl;
	s->pop();
	s->pop();
	s->display();
	s->pop();
	s->pop();
	s->pop();
	s->display();
	cout<<s->isEmpty();
	return 0;
}
