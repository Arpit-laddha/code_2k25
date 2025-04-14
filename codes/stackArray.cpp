#include<iostream>
using namespace std;
class stack{
public:
	int *arr;
	int top;
	int capacity;
	stack(){
		arr = new int[5];
		top=-1;
		capacity=5;
	}
	void push(int ele){
		top++;
		if(top+1<=capacity){
			arr[top]=ele;
		}else{
			int* newArr = new int[2*capacity];
			capacity*=2;
			for(int i=0;i<top;i++){
				newArr[i]=arr[i];
			}
			newArr[top]=ele;
			arr=newArr;	
		}	
	}
	int pop(){
		if(top==-1){
			cout<<"Stack Overflow"<<endl;
			return 0;
		}
		int val=arr[top];
		top--;
		return val;
	}
	bool isEmpty(){
		if(top==-1) return false;
		return true;	
	}
	void display(){
		if(top==-1){
			cout<<"Stack is Empty."<<endl;
			return;
		}
		for(int i=0;i<=top;i++) cout<<arr[i]<<" ";
		cout<<endl;
		return;	
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
	s->pop();
	s->display();
	return 0;
}
