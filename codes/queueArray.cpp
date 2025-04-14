#include<iostream>
using namespace std;
class queue{
public:
	int *arr;
	int top,rear;
	int capacity;
	queue(int n){
		arr = new int[n];
		top=0;
		rear=-1;
		capacity=n;
	}
	void enqueue(int ele){
		if(rear==capacity-1){
			cout<<"Queue is full."<<endl;
			return;
		}
		arr[++rear]=ele;	
	}
	bool isEmpty(){
		if(rear==-1) return true;
		return false;	
	}
	int dequeue(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
		int val=arr[top];
		for(int i=top+1;i<=rear;i++){
			arr[i-1]=arr[i];
		}
		--rear;
		return val;
		
	}
	void display(){
		if(isEmpty()){
			cout<<"Queue is Empty."<<endl;
			return;
		}
		for(int i=top;i<=rear;i++) cout<<arr[i]<<" ";
		cout<<endl;
		return;	
	}
};
int main(){
	queue* Q = new queue(5);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		Q->enqueue(ele);	
	}
	Q->display();
	Q->dequeue();
	Q->display();
	return 0;
}
