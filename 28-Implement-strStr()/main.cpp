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


/*
Time Complexity = O(m+n)
Space Complexity = O(n)
where m is the length of the haystack and n is the length of the needle.
KMP Algorithm used
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
        
        vector<int> lps (n,0); //(size,default_value)
        
        //Make the LPS array for the needle string
        int i=1,j=0;
        
        while(i<n) { //Traverse the needle
            //3 scenarios are possible 
            if (needle[i] == needle[j]) {
                j++;
                lps[i] =j;
                i++;
            }
            
            else if (needle[i] != needle[j] && j>0) {
                //squeeze the window
                j = lps[j-1];
            }
            
            else { // when needle[i] != needle[j] && j==0
                lps[i] =0;
                i++;
            }
        } //lps array created
        
        //logic
        
        i=0,j=0; //reset to start
        
        while (i<m) { //Traverse the haystack to search
            if (needle[j] == haystack[i]) {
                i++;
                j++;
                if (j==n) {
                    //If everything has matched
                    return i-n; //returns first index from where we matched 
                }
            }
            else if(needle[j] != haystack[i] && j>0) {
                j = lps[j-1]; 
                //move the j to left side
                //check what is the longest suffix & prefix on the element the the left of where we found the mismatch 
            }
            
            else { // when needle[j] != haystack[i] && j==0
                i++;
            }
        }
        
        
        return -1; //Otherwise
    }
};