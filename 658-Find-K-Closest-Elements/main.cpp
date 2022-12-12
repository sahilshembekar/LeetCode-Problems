// 2 pointer approach

/*
Time Complexity = O(log(n-k))
Space Complexity = O(1)
where N is the number of elements in array.
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <int> result;
        if (arr.size() == 0) return result;
        
        int low =0, high =arr.size()-1;
        while(high-low+1>k) { // it will stop when distance between h and l has reached just 1 greater than k
            int distLow = abs(arr[low]-x); //absolute distance/difference between number at low and x= number
            int distHigh = abs(arr[high]-x); //absolute distance/difference between number at low and x= number
            
            if (distLow > distHigh) {
                low++; //if low is farther from number move low closer to the number
            }
            else {
                high--; //else move high closer
            }
        }
        for (int i =low; i<=high; i++) { //include numbers between and at low and high index
            result.push_back(arr[i]);
        }
        return result;
    }
};

// to find the start of the range/window and then iterate

/*
Time Complexity = O(log(n-k))
Space Complexity = O(1)
where N is the number of elements in array.
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <int> result;
        if (arr.size() == 0) return result;
        
        int low =0, high =arr.size()-k;
        while (low<high) {
            int mid = low +(high-low)/2;
            int dist_start = x - arr[mid];
            int dist_end = arr[mid+k] - x;
            if (dist_start > dist_end) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }

        for (int i =low; i<low+k; i++) { //include numbers between low and low +k
            result.push_back(arr[i]);
        }
        return result;
    }
};