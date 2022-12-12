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
    
    int binarSearch(const ArrayReader& reader, int l, int h, int target) {
        int low = l, high = h, mid;
        while(low <= high) {
            mid = low +(high-low)/2;
            if (reader.get(mid)== target) {
                return mid;
            }
            else if (reader.get(mid) > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
    int search(const ArrayReader& reader, int target) {
        int low = 0, high =1;
        while(reader.get(high) < target) {
            low = high;
            high = high*2;
        }
        return binarSearch(reader, low, high, target);
    }
};