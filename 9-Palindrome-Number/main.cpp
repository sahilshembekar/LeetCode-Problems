// https://leetcode.com/problems/palindrome-number/
        // 9. Palindrome Number
        class Solution {
        public:
        bool isPalindrome(int x) {
        // Don't Take vector because it will not store -ve sign correctly.

        string Original = to_string(x);
        string Reversed = Original;

        reverse(Reversed.begin(), Reversed.end());

        if (Original == Reversed) {
        return true;
        }
        else {
        return false;
        }

        }
        };    
    