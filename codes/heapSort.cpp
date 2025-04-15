#include <iostream>
using namespace std;

// Heapify function to maintain max heap property
void heapify(int arr[], int n, int i) {
    int largest = i;  // Assume root is the largest
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and heapify again
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move max element to end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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