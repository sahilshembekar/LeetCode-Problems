/*
Time Complexity = O(m*n)
Space Complexity = O(1)
where m is the length of the haystack and n is the length of the needle.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0 ) {
            return 0;
        }
        if(haystack.length() <needle.length()) {
            return -1;
        }
        
        int m = haystack.length();
        int n = needle.length();
        int i=0;
        for (int i=0;i <= m-n; i++) {
            //go only till the elements that are left to iterate are less than needle length // 
            // if n=8 and m =13 then i goes only till 5 after 5 size <needle therefore strstr no possible
            
            int j =0;
            int k=i;
            while(j<m) {
                //go over k one by one
                if(haystack[k] == needle[j]) {
                    k++;
                    j++;
                }
                else {
                    //if the charcters dont match
                    break;
                }
                //At last we need to check this
                if(j == n) {
                    //reached the end of needle
                    //all char matched
                    return k-j; // sstaring index of strstsr
                }
            }
        }
        return -1; //Otherwise
    }
};