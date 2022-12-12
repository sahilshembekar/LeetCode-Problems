/*
Time Complexity = O(n+m)
Space Complexity = O(1)
where n is the length of the string order and m is the length of the string s.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int nums[26] = {0}; // Initialize the array with all 0 values
        for (int i =0; i<s.length(); i++) {
            //go over each char of the string s (Source) and increase the count
            nums[s[i] - 'a']++;
        }
        
        string result = "";
        
        for (int i=0; i< order.length(); i++) {
            //get the character from the string order and the correspodoing count for that char from the nums array
            int times = nums[order[i] - 'a'];
            
            nums[order[i] - 'a'] = 0; //Reset the count to 0 since we do that in the while loop next
            while(times) {
                //iterate till our count become equal to 0
                result.push_back(order[i]);
                times--;
            }
        }
        //Iterate over the remaining characters and push_back them with the result
        for (int i=0; i<26; i++) {
            
            int times = nums[i];
            while(times) {
                result.push_back((char) (i+97)); //Convert the index to the corresponding character using ASCII value an cast
                times--;
            }
        }
        return result;
    }
};