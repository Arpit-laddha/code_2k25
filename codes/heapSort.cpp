#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr,int i,int n){//Traversing through edges
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void heapSort(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--) heapify(arr,i,n); //Converting to maxHeap O(nlogn)
    for(int i=n-1;i>=0;i--){ //O(nlogn)
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    heapSort(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}