
/*
Time Complexity = O(n1) // n1 is size of smaller array
Space Complexity = O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //NULL case
        if (nums1.size() == 0 && nums2.size() == 0) {
            return 0.0;
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        //Make the array 1 as the shorter array
        if (n1>n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = n1; //Partition is at the last therefore we have it at the last edge of small array i.e. n1
        
        while (low<=high) {
            int partX = low +(high-low)/2;
            int partY = (n1+n2)/2 - partX;
            
            double L1 = (partX ==0 ) ? INT_MIN : nums1[partX-1]; // At the index just before the position of partX
            double R1 = (partX ==n1 ) ? INT_MAX : nums1[partX]; //At the partX index itself
            double L2 = (partY ==0 ) ? INT_MIN : nums2[partY-1];
            double R2 = (partY ==n2 ) ? INT_MAX : nums2[partY];
            
            //Correct position of partition is achieved
            if(L1 <= R2 && L2 <= R1) {
                //Find Median
                
                //Even case
                if ((n1+n2)%2 == 0) {
                    return (max(L1,L2) + min(R1,R2))/2.0;
                }
                //odd case
                else {
                    return min(R1,R2); //It will lie on right side of partition
                }
            }
            
            else if (L1 > R2) {
                high = partX - 1;
            }
            else {
                low = partX +1;
            }
        }
        return 0.0;
    }
};