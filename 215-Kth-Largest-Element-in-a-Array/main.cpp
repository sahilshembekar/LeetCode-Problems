/*
Max Heap Approach
Time Complexity = O(NLog k)
Space Complexity = O(N-K)
where N is the number of elements in the array and k is the height of the heap.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq; //default is max heap
        int result = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > nums.size()-k ) {
                //max size of heap is n-k
                result = min(result,pq.top());
                pq.pop();
            }
        }
        return result;
    }
};

/*
Min Heap Approach
Time Complexity = O(NLog k)
Space Complexity = O(K)
where N is the number of elements in the array and k is the height of the heap.
log k is the time complexity coming due to the heapify of new element. i.e- when we arrange the new element in the heap such that it follows the Min heap property.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector <int>, greater <int>> pq; //syntax for min heap
        
        for (int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                // if the size exceeds k remove the topmost that is the smallest
                pq.pop();
            }
        }
        return pq.top();
        
    }
};


//Another good way to implement min heap 
//source: https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// // C++ Program to implement min heap
// // using default priority_queue(max-heap)
 
// #include <iostream>
// #include <queue>
// using namespace std;
 
// int main()
// {
//     // data
//     int arr[] = { 25, 7, 9, 15, 20, 36, 50 };
   
//       // default priority_queue using max-heap
//     priority_queue<int> pq;
   
//       // size of the array
//     int n = sizeof(arr) / sizeof(arr[0]);
 
//     // multiply -1 with all elements while
//     // inserting
//     for (int i = 0; i < n; i++) {
//         pq.push((-1) * arr[i]);
//     }
 
//     // multiply all elements with -1 while
//     // retrieve the elements
//     while (!pq.empty()) {
//         cout << (pq.top()) * (-1) << " ";
//         pq.pop();
//     }
 
//     return 0;
// }