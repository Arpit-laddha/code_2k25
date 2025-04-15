#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Heapify the node at index i
    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Move a node up if it violates the heap property
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the maximum element (root)
    int extractMax() {
        if (heap.empty()) return -1;

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxVal;
    }

    // Print the heap
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Max Heap: ";
    h.printHeap();

    cout << "Extracted Max: " << h.extractMax() << endl;
    cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}
