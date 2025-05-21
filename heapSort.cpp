class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int num: arr)
        {
            heap.push(num);
        }
        int i = 0;
        while(!heap.empty())
        {
            arr[i] = heap.top();
            heap.pop();
            i++;
        }
    }
};