/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // first find the size of the arrayReader (roughly)
        int high = 1;
        int low = 0;
        while(reader.get(high) < target) {
            low = high;
            high = high*2;
        }
        return binarySearch(low, high, reader, target);
    }
    
    // binary search to find the element
    int binarySearch(int low, int high, const ArrayReader& reader, int target) {
        int l = low;
        int h = high;
        int mid;
        while (low <= high) {
            
            mid = low + (high-low)/2;
            if(reader.get(mid) == target) {
                return mid;
            }
            else if (reader.get(mid) < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }
};