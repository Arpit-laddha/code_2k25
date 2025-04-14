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
class stackOfQueue{
public:
	queue S;
	
	bool isEmpty(){
		if(S.isEmpty()) return true;
		return false;
	}
	
	void push(int ele){
		S.enqueue(ele);
	}
	int pop(){
		int val=S.rear->val;
		queue newStack;
		Node* temp = S.top;
		while(S.top && temp->next){
			newStack.enqueue(temp->val);
			temp=temp->next;
		}
		S=newStack;
		return val;
	}
	void display(){
	 	S.display();
	}
};
int main(){
	stackOfQueue st;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		st.push(ele);
	}
	st.display();
	cout<<st.pop()<<endl;
	st.display();
	return 0;	
}
