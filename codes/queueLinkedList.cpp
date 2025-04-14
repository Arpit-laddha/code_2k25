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
class queue{
public:
	Node* top;
	Node* rear;
	queue(){
		top=rear=nullptr;	
	}
	
	bool isEmpty(){
		if(top==nullptr) return true;
		return false;
	}
	
	void enqueue(int ele){
		Node* new_node = new Node(ele);
		if(top==nullptr){
			top=rear=new_node;
			return;
		}
		rear->next=new_node;
		rear=rear->next;
	}
	
	int dequeue(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
		int val=top->val;
		top=top->next;
		return val;
	}
	
	void display(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return;	
		}
		Node* temp=top;
		while(temp!=nullptr){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
};
int main(){
	queue* Q = new queue();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		Q->enqueue(ele);
	}
	Q->display();
	cout<<Q->dequeue()<<endl;
	Q->display();
	Q->enqueue(4);
	Q->display();
}
